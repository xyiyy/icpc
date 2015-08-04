#include<iostream>
using namespace std;

int fun(double *x,double *y,int n)
{
	double z1,z2,z3,x1,y1,x2,y2,x3,y3,fx,fy,fx1,fx2,fx3,fy1,fy2,fy3;
	cin>>fx>>fy;
	for(int i=0;i<n;i++)
	{
		fx2=fx-x[i];
		fy2=fy-y[i];
		for(int j=i+1;j<n;j++)
		{
			x1=x[i]-x[j];
			y1=y[i]-y[j];
			fx1=fx-x[j];
			fy1=fy-y[j];
			z1=x1*fy1-y1*fx1;
			for(int k=i+2;k<n;k++)
			{
				x2=x[k]-x[i];
				y2=y[k]-y[i];
				z2=x2*fy2-y2*fx2;
				if(z1*z2>=0)
				{
					x3=x[j]-x[k];
					y3=y[j]-y[k];
					fx3=fx-x[k];
					fy3=fy-y[k];
					z3=x3*fy3-y3*fx3;
					if(z1*z3>=0)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
				

int main()
{
	int n,k=1;
	while(cin>>n)
	{
		double x[n],y[n];
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		cout<<"Case "<<k<<":"<<endl;
		if(fun(x,y,n))
		{
			cout<<"Yes!"<<endl;
		}
		else
		{
			cout<<"No!"<<endl;
		}
		k++;
	}
	return 0;
}
		
			 
