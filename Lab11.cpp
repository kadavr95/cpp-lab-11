#include <iostream.h>
#include <conio.h>
#include <math.h>

int AccuracyInput(float *);
int IntegrateFunction(float, float *, float);
int WeddleRule();
int RowOutput(float, float);
int FunctionValue(float, float*);

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
	*Result=1;
	do
	{
		PreviousResult=*Result;
		*Result/=10;
		cout<<fabs(*Result-PreviousResult);
    }
	while(fabs(*Result-PreviousResult)>Accuracy);
	cout<<"kek";
}

int WeedleRule()
{
	Result=3*(b-a)/n/6/10*(f(x1)+5*f(x2)+f(x3)+6*f(x4)+f(x5)+5*f(x6)+f(x7));
	cout<<"azaza";
}

int FunctionValue(float x, float *Result)
{
	*Result=cos(pi*x*x/2);
}

int RowOutput(float Counter, float Result)
{
	cout<<"mde";
}
