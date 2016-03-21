#include <iostream.h>//cin, cout
#include <conio.h>//getch
#include <math.h>//absolute for float type, PI
#include <iomanip.h> //output precision

int AccuracyInput(long double *);//input of calculation accuracy
int IntegrateFunction(long double, long double *, long double);//calculating integral of function
int WeddleRule(long double *,long double, long double, long double);//calculate integral with current partition
void RowOutput(long double, long double, long double *);//output of results
long double FunctionValue(long double);//calculate result of function in a point

const DataPoints=4;//

void main()
{
	long double Counter, Result=0, Accuracy;
	long double ArrayTableResults[DataPoints]={0.4923442258714464,0.7798934003768228,0.4452611760398215,0.4882534060753408};
	AccuracyInput(&Accuracy);
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<" Lower Limit |"<<" Upper Limit |"<<" Result \n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	for (Counter = 0.5; Counter <= 2.0; Counter+=0.5)
	{
		IntegrateFunction(Counter, &Result, Accuracy);
		RowOutput(Counter, Result, ArrayTableResults);
	}
	getch();
}

int AccuracyInput(long double *Accuracy)
{
	cout<<"Enter accuracy: ";
	cin>>*Accuracy;
}

int IntegrateFunction(long double Counter, long double *Result, long double Accuracy)
{
	long double PreviousResult, LowerLimit, UpperLimit;
	int SegmentCounter=1;
	LowerLimit=0;
	UpperLimit=Counter;
	WeddleRule(Result, SegmentCounter, LowerLimit, UpperLimit);
	do
	{
		SegmentCounter++;
		PreviousResult=*Result;
		*Result=0;
		WeddleRule(Result, SegmentCounter, LowerLimit, UpperLimit);
    }
	while(fabs(*Result-PreviousResult)>Accuracy);
}

int WeddleRule(long double *Result, long double SegmentCounter, long double LowerLimitGlobal, long double UpperLimitGlobal)
{
	long double LowerLimit, UpperLimit, ElementarySegmentLength, SubsegmentLength, SegmentsQuantity;
	int Counter;
	for (Counter = 1; Counter <= SegmentCounter; Counter++)
	{
		LowerLimit=LowerLimitGlobal+(Counter-1)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;
		UpperLimit=LowerLimitGlobal+(Counter)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;
		SubsegmentLength=(UpperLimit-LowerLimit);
		ElementarySegmentLength=SubsegmentLength/6;
		*Result+=3*ElementarySegmentLength/10*(FunctionValue(LowerLimit)+5*FunctionValue(LowerLimit+ElementarySegmentLength)+FunctionValue(LowerLimit+2*ElementarySegmentLength)+6*FunctionValue(LowerLimit+3*ElementarySegmentLength)+FunctionValue(LowerLimit+4*ElementarySegmentLength)+5*FunctionValue(LowerLimit+5*ElementarySegmentLength)+FunctionValue(LowerLimit+6*ElementarySegmentLength));
	}
}

long double FunctionValue(long double x)
{
	return cos(M_PI*x*x/2);
}

void RowOutput(long double Counter, long double Result, long double *ArrayTableResults)
{
	cout<<fixed<<setprecision(1)<<"     "<<0.0<<"     |     "<<Counter<<"     | "<<setprecision(15)<<Result<<" \n"<<"               Table Result: "<<ArrayTableResults[int(Counter*2-1)]<<"\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";

}
