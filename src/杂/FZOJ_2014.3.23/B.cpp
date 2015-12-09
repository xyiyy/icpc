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
char a[600000],b[600000];
//int vis[6000000];
int main()
{
	int flag,n;
	while(cin>>a>>b)
	{
		n=strlen(a);
		flag=0;
		if(n!=strlen(b))
		{
			cout<<"No"<<endl;
			continue;
		}
		char *p=a;
		//cin.getline(b,6000000);
		for(int i=0;i<n;i++)
		{
			
			if(strcmp(p,b)==0)
			{
				flag=1;
				break;
			}
			else
			{
				p[n]=p[0];
				p[n+1]=0;
				p++;
			}
		}
		if(flag==1)
		{
			cout<<"Yes"<<endl;
		}
		else 
		{
			cout<<"No"<<endl;		
		}
			
		
				
				
		
	}
	return 0;
}

