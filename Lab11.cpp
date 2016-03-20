#include <iostream.h>
#include <conio.h>
#include <math.h>

int AccuracyInput(float *);
int IntegrateFunction(float, float *, float);
int WeddleRule(float *,float);
void RowOutput(float, float);
float FunctionValue(float);

const DataPoints=4;

void main()
{
	float Counter, Result, Accuracy;
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
	float PreviousResult;
	int SegmentCounter=1;
	*Result=1;
	do
	{
		SegmentCounter++;
		PreviousResult=*Result;
		*Result/=10;
		cout<<fabs(*Result-PreviousResult);
    }
	while(fabs(*Result-PreviousResult)>Accuracy);
	cout<<"kek";
}

int WeedleRule(float *Result, float SegmentCounter, float LowerLimitNumber, float UpperLimitNumber)
{
	float LowerLimit, UpperLimit, ElementarySegmentLength, SubsegmentLength;
	SubsegmentLength=(UpperLimit-LowerLimit)/SegmentsQuantity;
	ElementarySegmentLength=Subsegment/6;
	*Result=3*ElementarySegmentLength/10*(FunctionValue(LowerLimit)+5*FunctionValue(LowerLimit+ElementarySegmentLength)+FunctionValue(LowerLimit+2*ElementarySegmentLength)+6*FunctionValue(LowerLimit+3*ElementarySegmentLength)+f(LowerLimit+4*ElementarySegmentLength)+5*FunctionValue(LowerLimit+5*ElementarySegmentLength)+FunctionValue(LowerLimit+6*ElementarySegmentLength));
	cout<<"azaza";
}

float FunctionValue(float x)
{
	return cos(pi*x*x/2);
}

void RowOutput(float Counter, float Result)
{
	cout<<"mde";
}
