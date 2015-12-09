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
char a[1000];
int vis[1000];
int main()
{
	int N;
	cin>>N;
	cin.ignore();
	while(N--)
	{
	//	cin.ignore();
		memset(vis,0,1000);
		memset(a,'\0',1000);
		cin.getline(a,1000);
		//cout<<a<<endl;
		int len =strlen(a);
		int i;
		for(i=0;i<len;i++)
		{
			if(vis[i]==0&&(a[i]==40||a[i]==91))
			{
				
				for(int j=i;j<len;j++)
				{
					if((vis[j]==0)&&(a[j]==a[i]+2||a[j]==a[i]+1))
					{
						vis[i]=1;
						vis[j]=1;
					//	cout<<i<<"  "<<j<<"  ";
						break;
					}
				}
			}
			if(vis[i]==0)
			{
				cout<<"No"<<endl;
				break;
			}
		}
		if(i==len)
		cout<<"Yes"<<endl;
	//	for(int i=0;i<len;i++)
	//	cout<<vis[i]<<" ";
		//cout<<endl;
	}
	//cin>>N;
	return 0;
}









