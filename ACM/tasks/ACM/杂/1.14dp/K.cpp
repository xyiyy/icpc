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

vector<int> dp[30];
int vis[30];
void ghost(int t)
{
	int d=vis[t];
	vector<int>::iterator it=find(dp[d].begin(),dp[d].end(),t)+1;
	vector<int>::iterator cd=dp[d].end();
	while(it!=cd)
	{
		int w=*it;
		dp[w].push_back(w);
		vis[w]=w;
		it=dp[d].erase(it);
		cd=dp[d].end();
	}
	return;
}

void move(int t1,int t2)
{
	int d1=vis[t1],d2=vis[t2];
	vector<int>::iterator it=find(dp[d1].begin(),dp[d1].end(),t1);
	vector<int>::iterator cd=dp[d1].end();
	while(it!=cd)
	{
		int w=*it;
		dp[d2].push_back(w);
		vis[w]=d2;
		it=dp[d1].erase(it);
		cd=dp[d1].end();
	}
	return;
}
 
int main()
{
	int n;
	while(cin >> n)
	{
		int t1,t2;
		char s1[10],s2[10];
		for(int i=0;i<n;i++)
		{
			dp[i].erase(dp[i].begin(),dp[i].end());
			dp[i].push_back(i);
			vis[i]=i;
		}
		while(scanf("%s",s1),s1[0]!='q')
		{
			scanf("%d %s %d",&t1,s2,&t2);
			getchar();
			if(t1==t2||vis[t1]==vis[t2]) continue;
			if(s1[0]=='m')
			{
				if(s2[1]=='n')
				{
					ghost(t1);
					ghost(t2);
					move(t1,t2);
				}
				else
				{
					ghost(t1);
					move(t1,t2);
				}
			}
			else
			{
				if(s2[1]=='n')
				{
					ghost(t2);
					move(t1,t2);
				}
				else
				{
					move(t1,t2);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			printf("%d:",i);
			int d=dp[i].size();
			for(int j=0;j<d;j++)
			{
				printf(" %d",dp[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
