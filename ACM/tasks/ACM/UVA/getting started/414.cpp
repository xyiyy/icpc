#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

int main()
{
	char a[10000];
	int n=1;
	while (cin>>n&&n)
	{
		for(int i=0;i<25*n;i++)
		{
			cin>>a[i];
		}
		int num,min=25,m=0;
		for(int i=0;i<n;i++)
		{
			num=0;
			for(int j=0;j<25;j++)
			{
				if(a[i*25+j]==66)
				{num++;m++;}
			}
			if(num<min)min=num;

		}
		cout<<(m-n*min)<<endl;
		memset(a,'\0',10000);
	}
	return 0;
}
			
			
			
			
			
			
			
