#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int t1=0,t2=2,t3=1,t4=1;
		char a[50],b[50];
		scanf("%s%s",&a,&b);
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			t1++;
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]=='1')
			t2++;
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]=='0')
			t3++;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i])
			t4++;
		}
		int temp=min(t1,t2);
		temp=min(temp,t3);
		temp=min(temp,t4);
		cout<<temp<<endl;
	}
	return 0;
}
		
