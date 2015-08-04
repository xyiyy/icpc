#include<iostream>
#include<stdio.h>
using namespace std;

double MIN(double a,double b)
{
	if(a>b)
	return b;
	return a;
}
double MAX(double a,double b)
{
	if(a>b)
	return a;
	return b;
}

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,temp;
	while (cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		if(MIN(x3,x4)>=MAX(x1,x2)||MIN(x1,x2)>=MAX(x3,x4)||MIN(y3,y4)>=MAX(y1,y2)||MIN(y1,y2)>=MAX(y3,y4))
		{
			printf("%.2lf\n",0.00);
		}
		else
		{
			if(x1>x2){temp=x1;x1=x2;x2=temp;}
			if(x2>x3){temp=x2;x2=x3;x3=temp;}
			if(x3>x4){temp=x3;x3=x4;x4=temp;}
			if(x1>x2){temp=x1;x1=x2;x2=temp;}
			if(x2>x3){temp=x2;x2=x3;x3=temp;}
			if(x1>x2){temp=x1;x1=x2;x2=temp;}
			if(y1>y2){temp=y1;y1=y2;y2=temp;}
			if(y2>y3){temp=y2;y2=y3;y3=temp;}
			if(y3>y4){temp=y3;y3=y4;y4=temp;}
			if(y1>y2){temp=y1;y1=y2;y2=temp;}
			if(y2>y3){temp=y2;y2=y3;y3=temp;}
			if(y1>y2){temp=y1;y1=y2;y2=temp;}
			double s=(x3-x2)*(y3-y2);
			printf("%.2lf\n", s);
		}
	}
	return 0;
}

		
		
		
	 
