#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
char elem[26];
int G[26][26];
int deg[26];
int vis[30];
int n;
char a[26];
void topsort(int d)
{
	if(d>=n)
	{
		cout<<a<<endl;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!deg[i]&&!vis[i])
		{
			a[d]=elem[i];
			vis[i]=1;
			for(int j=0;j<n;j++)
			{
				if(G[i][j])
				{
					deg[j]--;
				}
			}
			topsort(d+1);
			vis[i]=0;
			for(int j=0;j<n;j++)
			{
				if(G[i][j])
				{
					deg[j]++;
				}
			}
		}
	}
		
			
}


int main()
{
	ios::sync_with_stdio(false);
	string s;
	int k=0;
	while(getline(cin,s,'\n'))
	{
		if(k>0)cout<<endl;
		k++;
		memset(G,0,sizeof(G));
		memset(deg,0,sizeof(deg));
		memset(vis,0,sizeof(vis));
		memset(a,'\0',sizeof(a));
		stringstream ss(s);
		char c;
		n=0;
		while(ss>>elem[n])n++;
		sort(elem,elem+n);
		getline(cin,s,'\n');
		stringstream ss2(s);
		char c1,c2;int u,v;
		while(ss2>>c1>>c2)
		{
			for(int i=0;i<n;i++)
			{
				if(elem[i]==c1)
				{
					for(int j=0;j<n;j++)
					{
						if(elem[j]==c2)
						{
							G[i][j]=1;
							deg[j]++;
						}
					}
				}
			}	
		}
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<G[i][j];
			}
			cout<<endl;
		}*/
		topsort(0);
	}
		
				
					
	
	return 0;
}

