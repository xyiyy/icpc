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

int a[10001000];
//int ch[100010];
int main()
{
	int m;
	while(cin>>m)
	{
		int i=0;
		while(m--)
		{
			int b,c,d;
			cin>>b>>c;
			if(b==1)
			{
				a[i++]=c;
			}
			if(b==2)
			{
				cin>>d;
				for(int j=0;j<d;j++)
				{
					for(int k=0;k<c;k++)
					{
						a[i++]=a[k];
					}
				}
			}
		}
		int n,cho;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			//cin>>ch[j];
			cin>>cho;
			if(j<n-1)
			cout<<a[cho-1]<<" ";
			else
			cout<<a[cho-1]<<endl;
		}
	}return 0;
}











