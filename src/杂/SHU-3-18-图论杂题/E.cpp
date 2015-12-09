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
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int n,m;
int G[110][110];
int deg[110];
int ddd[110];
int vis[26];
char ans[26];
int check()
{
	int num;
	for(int i=0;i<n;i++)
	{
		if(!deg[i])
		num++;
	}
	if(num==1) return 1;
	if(num==0)return 0;
	return 2;
}

int toposort()
{
	int ret;
	int k;
	int mark;
	int flag=check();
	if(flag==0)
	{
		return 2;
	}
	else if(flag==1)
	{
		CLR(vis,0);
		k=0;
		while(k<n)
		{
			for(int i=0;i<n;i++)
			{
				mark=0;
				if(!ddd[i]&&!vis[i])
				{
					ans[k++]=i+'A';
					vis[i]=1;
					for(int j=0;j<n;j++)
					{
						if(ddd[j]&&!vis[j])
						return 2;
					}
					for(int j=0;j<n;j++)
					{
						if(G[i][j])
						{
							ddd[j]--;
							mark=1;
						}
					}
					
				}
				if(!mark)return 2;
			}
		}		
		return 1;		
	}
	else
	{
		CLR(vis,0);
		k=0;
		while(1)
		{
			for(int i=0;i<n;i++)
			{
				if(!ddd[i]&&!vis[i])
				{
					vis[i]=1;
				//	k++;
					for(int j=0;j<n;j++)
					{
						if(G[i][j])
						{
							ddd[j]--;
							mark=1;
						}
					}
				}
			}
			int num1=0,num2=0;
			for(int i=0;i<n;i++)
			{
				if(vis[i])num1++;
				if(ddd[i])num2++;
				if(num2)return 2;
				if(num1==n)return 0;
			}
		}
	}
	return 0;
}
		
		
	
int main()
{
	ios::sync_with_stdio(false);
	char a,b,c;
	int res;
	int flag;
	while(cin>>n>>m)
	{
		CLR(deg,0);
		CLR(G,0);
		CLR(ddd,0);
		flag=0;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			if(flag==0&&!G[a-'A'][c-'A'])
			{
				deg[c-'A']++;
				for(int j=0;j<26;j++)
				{
					ddd[j]=deg[j];
				}
				G[a-'A'][c-'A']=1;
				flag=toposort();
				if(flag)
				{
					res=i+1;
				}
			}
		}
		if(flag==1)
		{
			cout<<"Sorted sequence determined after "<<res<<" relations: "<<ans<<"."<<endl;
			
		}
		else if(flag==2)
		{
			cout<<"Inconsistency found after "<<res<<" relations."<<endl;
		}
		else if(flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;	
		}
	}
	return 0;
}

