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
int  a[100010];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int p,q;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<m;i++)
		{
		//	cin>>b[i]>>c[i];
			cin>>p>>q;
			int j;int k=0;
			for(j=0;j<n;j++)
			{
				if(q==a[j])
				{
					k++;
					if(k==p)
					{
						cout<<j+1<<endl;
						break;
					}
					
				}
			}
			if(j==n)cout<<0<<endl;
		}
		/*int j;
		for(int i=0;i<m;i++)
		{
			int k=0;
			for(j=0;j<n;j++)
			{
				if(c[i]==a[j])
				{
					k++;
					if(b[i]==k)
					{
						cout<<j+1<<endl;
						break;
					}
				}
				if(j==n-1)
				cout<<"0"<<endl;
			}
		
		}*/
	}
	return 0;
}

