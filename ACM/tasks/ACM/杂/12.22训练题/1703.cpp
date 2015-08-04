#include<iostream>
#include<cmath>
using namespace std;

int fun(double *x,double *y,int n)
{
	double z1,z2,z3,x1,y1,x2,y2,x3,y3,fx,fy,fx1,fx2,fx3,fy1,fy2,fy3;
	cin>>fx>>fy;
	for(int i=0;i<n-2;i++)
	{
		fx2=fx-x[i];
		fy2=fy-y[i];
		int j=i+1;
		x1=x[i]-x[j];
		y1=y[i]-y[j];
		fx1=fx-x[j];
		fy1=fy-y[j];
		z1=x1*fy1-y1*fx2;
		int k=j+1; 	
		x2=x[k]-x[i];
		y2=y[k]-y[i];
		z2=x2*fy2-x3*fx3;
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
	x1=x[n-2]-x[n-1];
	y1=x[n-2]-x[n-1];
	x2=x[0]-x[n-2];
	y2=y[0]-y[n-2];
	x3=x[n-1]-x[0];
	y3=y[n-1]-y[0];
	fx1=fx-x[n-1];
	fy1=fy-y[n-1];
	fx2=fx-x[n-2];
	fy2=fy-y[n-2];
	fx3=fx-x[0];
	fy3=fy-y[0];
	z1=x1*fy1-y1*fx2;
	z2=x2*fy2-x3*fx3;
	if(z1*z2>=0)
	{
		z3=x3*fy3-y3*fx3;
		if(z1*z3>=0)
		{
			return 1;
		}
	}
	x1=x[n-1]-x[0];
	y1=y[n-1]-y[0];
	x2=x[1]-x[n-1];
	y2=y[1]-y[n-1];
	x3=x[0]-x[1];
	y3=y[0]-y[1];
	fx1=fx-x[0];
	fy1=fy-y[0];
	fx2=fx-x[n-1];
	fy2=fy-y[n-1];
	fx3=fx-x[1];
	fy3=fy-y[1];
	z1=x1*fy1-y1*fx2;
	z2=x2*fy2-x3*fx3;
	if(z1*z2>=0)
	{
		z3=x3*fy3-y3*fx3;
		if(z1*z3>=0)
		{
			return 1;
		}
	}
	
	return 0;
}
				
void Qsort1(double *a,int size)
{
	double pivot,temp;
	int left=0;int right=size-1;
	if(size<=1)return ;
	pivot=a[right];
	do
	{
		while (left<right && a[left]<=pivot)left++;
		while (left<right && a[right]>=pivot)right--;
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}while(left<right);
	a[size-1]=a[left];
	a[left]=pivot;
	Qsort1(a,left);
	Qsort1(a+left+1,size-left-1);
}



int main()
{
	int n,k=1;
	while(cin>>n)
	{
		double a[n],b[n],a1[n],b1[n],a2[n],b2[n],a3[n],b3[n],a4[n],b4[n],x[n],y[n],k1[n],k2[n],k3[n],k4[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}
		int n1=0,n2=0,n3=0,n4=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>0&&b[i]>=0||a[i]==0&&b[i]==0)
			{
				a1[n1]=a[i];b1[n1]=b[i];
				k1[n1]=b[i]/a[i];
				n1++;
			}
			if(a[i]<=0&&b[i]>0)
			{
				a2[n2]=a[i];b2[n2]=b[i];
				k2[n2]=b[i]/a[i];
				n2++;
			}
			if(a[i]<0&&b[i]<=0)
			{
				a3[n3]=a[i];b3[n3]=b[i];
				k3[n3]=b[i]/a[i];
				n3++;
			}	
			if(a[i]>=0&&b[i]<0)
			{
				a4[n4]=a[i];b4[n4]=b[i];
				k4[n4]=b[i]/a[i];
				n4++;
			}
		}
		Qsort1(k1,n1);
		Qsort1(k2,n2);
		Qsort1(k3,n3);
		Qsort1(k4,n4);
		for(int i=0;i<n1;i++)
		{
			for(int j=0;(b1[j]/a1[j])==k1[i]&&j<n1&&x[i-1]!=a1[j];j++)
			{
				x[i]=a1[j];y[i]=b1[j];
			}
		}
		for(int i=n1;i<n1+n2;i++)
		{
			for(int j=0;(b2[j]/a2[j])==k2[i-n1]&&j<n2&&x[i-1]!=a2[j];j++)
			{
				x[i]=a2[j];y[i]=b2[j];
			}
		}
		for(int i=n1+n2;i<n1+n2+n3;i++)
		{
			for(int j=0;(b3[j]/a3[j])==k3[i-n1-n2]&&j<n3&&x[i-1]!=a3[j];j++)
			{
				x[i]=a3[j];y[i]=b3[j];
			}
		}
		for(int i=n1+n2+n3;i<n;i++)
		{
			for(int j=0;(b4[j]/a4[j])==k4[i-n1-n2-n3]&&j<n4&&x[i-1]!=a4[j];j++)
			{
				x[i]=a4[j];y[i]=b4[j];
			}
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
		
			 
