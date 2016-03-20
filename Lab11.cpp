#include <iostream.h>
#include <conio.h>
#include <math.h>

int AccuracyInput(float *);
int IntegrateFunction(float, float *, float);
int WeddleRule(float *,float, float, float);
void RowOutput(float, float);
float FunctionValue(float);

const DataPoints=4;

void main()
{
	float Counter, Result=0, Accuracy;
	float ArrayTableResults[DataPoints]={0.492344,0.779893,0.445261,0.488253};
	cout<<"hello";
	AccuracyInput(&Accuracy);
	cout<<Accuracy;
	for (Counter = 0.5; Counter <= 2.0; Counter+=0.5)
	{
		IntegrateFunction(Counter, &Result, Accuracy);
		RowOutput(Counter, Result);
	}
	getch();
}

int AccuracyInput(float *Accuracy)
{
	cout<<"Enter accuracy";
	cin>>*Accuracy;
}

int IntegrateFunction(float Counter, float *Result, float Accuracy)
{
	float PreviousResult, LowerLimit, UpperLimit;
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
		cout<<fabs(*Result-PreviousResult);
    }
	while(fabs(*Result-PreviousResult)>Accuracy);
	cout<<"kek";
}

int WeddleRule(float *Result, float SegmentCounter, float LowerLimitGlobal, float UpperLimitGlobal)
{
	float LowerLimit, UpperLimit, ElementarySegmentLength, SubsegmentLength, SegmentsQuantity;
	int Counter;
	for (Counter = 1; Counter <= SegmentCounter; Counter++)
	{

		LowerLimit=LowerLimitGlobal+(Counter-1)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;
		UpperLimit=LowerLimitGlobal+(Counter)*(UpperLimitGlobal-LowerLimitGlobal)/SegmentCounter;
		//SubsegmentLength=(UpperLimit-LowerLimit)/SegmentCounter;
		SubsegmentLength=(UpperLimit-LowerLimit);
		ElementarySegmentLength=SubsegmentLength/6;
		*Result+=3*ElementarySegmentLength/10*(FunctionValue(LowerLimit)+5*FunctionValue(LowerLimit+ElementarySegmentLength)+FunctionValue(LowerLimit+2*ElementarySegmentLength)+6*FunctionValue(LowerLimit+3*ElementarySegmentLength)+FunctionValue(LowerLimit+4*ElementarySegmentLength)+5*FunctionValue(LowerLimit+5*ElementarySegmentLength)+FunctionValue(LowerLimit+6*ElementarySegmentLength));
	}

	cout<<"azaza";
}

float FunctionValue(float x)
{
	return cos(M_PI*x*x/2);
}

void RowOutput(float Counter, float Result)
{
	cout<<"mde";
	cout<<Result;
}
