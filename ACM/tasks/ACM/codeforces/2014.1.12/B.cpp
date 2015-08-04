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
int num[100000],a[100000],vis[100000],b[100000];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(vis,0,100000);
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		}	
		sort(num,num+n-1);
		a[0]=num[n-1];
		vis[n-1]==1;
		int j=1;
		for(int i=n-2;i>=0;i--)
		{
			if(num[i]!=a[j-1])
			{
			a[j++]=num[i];
			vis[i]=1;
			}
		}
		b[0]=0;
		int k=0;
		for(int i=0;i<n&&num[i]<num[n-1];i++)
		{
			if(b[0]==0&&vis[i]==0)
			{
				b[0]=num[i];
				k++;
			}
			if(num[i]!=b[k-1]&&vis[i]==0)
			{
				b[k++]=num[i];
			}
		}
		cout<<j+k<<endl;
		for(int i=0;i<k;i++)
		{
			cout<<b[i]<<" ";
		}
		for(int i=0;i<j;i++)
		{
			if(i<j-1)
		cout<<a[i]	<<" ";
		else
		cout<<a[i]<<endl;
	}		
	}
	return 0;
}
	
	
	


