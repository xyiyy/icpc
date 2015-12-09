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
int f[110];
int main()
{
	int p,i,c;
	long long len;
	while(cin>>p)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		len=(long long)(p*log10(2.0)+1);
		for(i=1;i<=p/10;i++)
		{
			c=0;
		//	len=log10(pow(2,i));
			for(int j=0;j<=100;j++)
			{
			//	int s=f[j]*2+c;
			//	f[j]=s%10;
			//	c=s/10;
			//	if(j+1>len)len=j+1;
				f[j]<<=10;
			}
			for(int j=0;j<=101;j++)
			{
				if(f[j]>=100000)
				{
					f[j+1]+=f[j]/100000;
					f[j]=f[j]%100000;
				}
			}
		}
		int forget=p%10;
		for(i=1;i<=forget;i++)
		{
			for(int j=0;j<=101;j++)
			{
				f[j]<<=1;
			}
			for(int j=0;j<=100;j++)
			{
				if(f[j]>=100000)
				f[j+1]+=f[j]/100000;
				f[j]=f[j]%100000;
			}
		}	
		f[0]--;
	//	for(i=999999;f[i]==0;i--)
	//	;
	    for(i=1; i<100; i++) 
    	{ 
    		if(f[i-1]<0) 
    		{ 
        		f[i] -= 1; 
        		f[i-1]+=100000; 
      		} 
      		else 
        		break; 
    	} 
		cout<<len<<endl;
		for(i=99;i>=0;i--)
		{
			printf("%05d",f[i]) ;
			if(i%10==0)
			cout<<endl;
		}
	//	for(i=499;i>=0;i--)
	//	{
	//		cout<<f[i];
	//		if(i%50==0)
	//		cout<<endl;
	//	}
	//	cout<<endl;
	}
	return 0;
}
