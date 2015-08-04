#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
	int f,k=1;
	cin>>f;
	while(f--)
	{
		cin.ignore();
		double U=0,I=0,P=0;
		char a[1000];
		cin.getline(a,1000);
		cout << "Problem #" <<k<<endl;
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i]=='=')
			{
				if(a[i-1]=='U')
				{
					double temp=0;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp*=10;
						temp+=a[i]-'0';
					}
					if(a[i]=='.')	i++;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp+=(a[i]-'0')/10;
					}
					if(a[i]=='m')	temp/=1000;
					else if(a[i]=='k')	temp*=1000;
					else if(a[i]=='M')	temp*=1000000;
					U=temp;
				}
				else if(a[i-1]=='I')
				{
					double temp=0;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp*=10;
						temp+=a[i]-'0';
					}
					if(a[i]=='.')	i++;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp+=(a[i]-'0')/10;
					}
					if(a[i]=='m')	temp/=1000;
					else if(a[i]=='k')	temp*=1000;
					else if(a[i]=='M')	temp*=1000000;
					I=temp;
				}
				else if(a[i-1]=='P')
				{
					double temp=0;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp*=10;
						temp+=a[i]-'0';
					}
					if(a[i]=='.')	i++;
					for(;a[i]>='0'&&a[i]<='9';i++)
					{
						temp+=(a[i]-'0')/10;
					}
					if(a[i]=='m')	temp/=1000;
					else if(a[i]=='k')	temp*=1000;
					else if(a[i]=='M')	temp*=1000000;
					P=temp;
				}
			}
		}
		if(U==0)	
		{
			U=P/I;
			cout<<"U="<<U<<endl;
		}
		else if(I==0)
		{
			I=P/U;
			cout<<"I="<<I<<endl;
		}
		else if(P==0)
		{
			P=I*U;
			cout<<"P="<<P<<endl;
		}
		cout<<endl;
	}
	return 0;
}
						
