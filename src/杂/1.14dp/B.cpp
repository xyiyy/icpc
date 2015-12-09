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
int rec[110][110];
int main()
{
	int n,sum,x,maxn;
	while(cin>>n)
	{
		memset(rec,0,sizeof(rec));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<n;j++)
			{
				//cin>>rec[i][j];
				cin>>x;
				rec[i][j]=rec[i-1][j]+x;
			}
		}
		maxn=-0x7ffffff;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				sum=0;
				for(int k=0;k<n;k++)
				{
					sum+=rec[j][k]-rec[i][k];
					if(sum<0)
					sum=0;
					if(sum>maxn)
					maxn=sum;
				}
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
					
		





