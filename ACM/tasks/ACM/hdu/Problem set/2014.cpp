#include<iostream>
#include<iomanip>
using namespace std;
int a[1000];

int main()
{
	int n;
	while(cin>>n&&n)
	{
		int minn=0x7ffffff,maxx=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(a[i]<minn)minn=a[i];
			if(a[i]>maxx)maxx=a[i];
		}
		sum-=minn+maxx;
		double ave=(sum*1.0)/(n-2.0);//×¢Òâ:¼Ó.0;
		cout<<fixed<<setprecision(2)<<ave<<endl;
	}
	return 0;
}
		
