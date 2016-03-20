#include <iostream.h>
#include <conio.h>

int AccuracyInput(float *);
int IntegrateFunction(float, float *);
int WeddleRule();
int RowOutput(float, float);

void main()
{
	float Counter, Result, Accuracy;
	cout<<"hello";
	AccuracyInput(&Accuracy);
	for (Counter = 0.5; Counter <= 2.0; Counter+=0.5)
	{
		IntegrateFunction(Counter, &Result);
		RowOutput(Counter, Result);
	}
	getch();
}

int AccuracyInput(float *Accuracy)
{
	cout<<"Enter accuracy"
	cin>>*Accuracy;
}

int IntegrateFunction(float Counter, float *Result)
{
	cout<<"kek";
}

int WeedleRule()
{
	cout<<"azaza";
}

int RowOutput(float Counter, float Result)
{
	cout<<"mde";
}
