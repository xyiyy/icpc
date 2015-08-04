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
int a[60000];
int main()
{
	int k=1,n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<"Case "<<k<<":"<<endl;
		string b;
		while(cin>>b)
		{
			if(b[0]=='E')
			{
				break;
			}
			else
			{
				int c,d;
				cin>>c>>d;
				if(b[0]=='Q')
				{
					int sum=0;
					for(int i=c;i<=d;i++)
					{
						//cout<<i<<" ";
						sum+=a[i];
						//cout<<sum<<" ";
					}
					cout<<sum<<endl;
				}
				if(b[0]=='A')
				{
					a[c]+=d;
				}
				if(b[0]=='B')
				{
					a[c]-=d;
				}
			}
		}
	}
	cin>>n;
	return 0;
}
					
	
