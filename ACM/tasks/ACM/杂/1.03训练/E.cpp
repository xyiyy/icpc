#include<iostream>
#include<cmath>
using namespace std;

int a[50];


int main()
{
	int n,k=1,j;
	while(cin>>n&&n!=0)
	{
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		a[n]=a[0];
		int times=0;
		cout<<"Case "<<k++<<": ";
		for(int i=0;i<n;i++)
		{
			if(a[i]!=a[i+1])
			{
				times++;
				break;
			}
			
		}
		if(times==0)
		cout<<"0 iterations"<<endl;
		else
		{
			for(times=1;times<=1000;times++)
			{
				a[n]=a[0];
				for(int i=0;i<n;i++)
				{
					a[i]=abs(a[i]-a[i+1]);
				}
				for(j=0;j<n-1;j++)
				{
					if(a[j]!=a[j+1])break;
				}
				if(j>=n-1)break;
			}
			if(times<=1000)cout<<times<<" iterations"<<endl;
			else cout<<"not attained"<<endl;
		}
	}
	return 0;
}
			
				
				
				
				
				
				
				
				
