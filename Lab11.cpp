#include <iostream.h>//cin, cout
#include <conio.h>//getch
#include <math.h>//absolute for float type, PI
#include <iomanip.h> //output precision

int AccuracyInput(long double *);//input of calculation accuracy
int IntegrateFunction(long double, long double *, long double);//calculating integral of function
int WeddleRule(long double *,long double, long double, long double);//calculate integral with current partition
void RowOutput(long double, long double, long double *);//output of results
long double FunctionValue(long double);//calculate result of function in a point

const DataPoints=4;//quantity of points to calculate integral

void main()//main function
{
	long double Counter, Result=0, Accuracy;
	long double ArrayTableResults[DataPoints]={0.4923442258714464,0.7798934003768228,0.4452611760398215,0.4882534060753408};//known results of integral values in our points
	AccuracyInput(&Accuracy);//enter accuracy of calculation
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";//header of table
	cout<<" Lower Limit |"<<" Upper Limit |"<<" Result \n";
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	for (Counter = 0.5; Counter <= 2.0; Counter+=0.5)//calculate integral in points equal to counter value
	{
		IntegrateFunction(Counter, &Result, Accuracy);//calculate integral
		RowOutput(Counter, Result, ArrayTableResults);//output result
	}
	getch();//waiting for user action
}

int AccuracyInput(long double *Accuracy)//input of calculation accuracy
{
	cout<<"Enter accuracy: ";
	cin>>*Accuracy;
}

int IntegrateFunction(long double Counter, long double *Result, long double Accuracy)//calculating integral of function
{
	long double PreviousResult, LowerLimit, UpperLimit;
	int SegmentCounter=1;
	LowerLimit=0;//lower limit of integral
	UpperLimit=Counter;//upper limit of integral
	WeddleRule(Result, SegmentCounter, LowerLimit, UpperLimit);//integration result without dividing interval
	do
	{
		SegmentCounter++;//increase quantity of interval partitions
		PreviousResult=*Result;//save previous result to compare later
		*Result=0;//reset result value
		WeddleRule(Result, SegmentCounter, LowerLimit, UpperLimit);//integration with current number of partitions
    }
	while(fabs(*Result-PreviousResult)>Accuracy);//repeat while difference between last two results is bigger than given accuracy
}

int WeddleRule(long double *Result, long double SegmentCounter, long double LowerLimitGlobal, long double UpperLimitGlobal)//calculate integral with current partition
{
	long double LowerLimit, UpperLimit, ElementarySegmentLength, SubsegmentLength, SegmentsQuantity;
	int Counter;
	for (Counter = 1; Counter <= SegmentCounter; Counter++)//calculation for all partitions of interval
	{
		LowerLimit=LowerLimitGlobal+(Counter-1)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;//current partition lower limit
		UpperLimit=LowerLimitGlobal+(Counter)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;//current partition upper limit
		SubsegmentLength=(UpperLimit-LowerLimit);//partition length
		ElementarySegmentLength=SubsegmentLength/6;//length between points where function will be calculated
		*Result+=3*ElementarySegmentLength/10*(FunctionValue(LowerLimit)+5*FunctionValue(LowerLimit+ElementarySegmentLength)+
			FunctionValue(LowerLimit+2*ElementarySegmentLength)+6*FunctionValue(LowerLimit+3*ElementarySegmentLength)+
			FunctionValue(LowerLimit+4*ElementarySegmentLength)+5*FunctionValue(LowerLimit+5*ElementarySegmentLength)+
			FunctionValue(LowerLimit+6*ElementarySegmentLength));//calculating function value in points and summarize result of integral value on current partition with previous partitions
	}
}

long double FunctionValue(long double x)//calculate result of function in a point
{
	return cos(M_PI*x*x/2);
}

void RowOutput(long double Counter, long double Result, long double *ArrayTableResults)//output of results
{
	cout<<fixed<<setprecision(1)<<"     "<<0.0<<"     |     "<<Counter<<"     | "<<setprecision(15)<<Result<<" \n"<<"               Table Result: "<<ArrayTableResults[int(Counter*2-1)]<<"\n"; //output of limits, result and table result
	cout<<"------------------------------------------------------------------------------------------------------------------------";

}
