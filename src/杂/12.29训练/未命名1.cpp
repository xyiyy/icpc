#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)return 0;
		int a[n-2],b[n-2],c[n-2];
		for(int i=0;i<n-2;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		int x,y,z;
		x=a[0];y=b[0];z=c[0];
		int temp;
		if(x>y)
		{
			temp=y;y=x;x=temp;
		}
		if(y>z)
		{
			temp=z;z=y;y=temp;
		}
		if(x>y)
		{
			temp=y;y=x;x=temp;
		}
		if((x==0&&y==1&&z==n-1)||(x==0&&y==n-2&&z==n-1)||(x==y-1&&y==z-1))
		{
			cout<<"Yes"<<endl; 
		}
		else
		{
			if(n%2==0)
			{
				cout<<"Yes"<<endl; 
			}
			else
			{
				cout<<"No"<<endl;  
			}
		}
	}
	return 0;
}
				
			
			
			
