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
int G[11][11];
int a[11];
int b[11];
int tot,n,times;
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
void Havel()
{
	for(int i=times+1;i<=times+a[b[times]];i++)
	{
		if(a[b[i]]==0)tot=1;
		a[b[i]]--;
		G[b[i]][b[times]]=G[b[times]][b[i]]=1;
	}
	a[b[times]]=0;
	
}


int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		tot=0;
		times=0;
		cin>>n;
		memset(G,0,sizeof(G));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=i;
			tot+=a[i];
		}
		b[n]=n;
		sort(b,b+n,cmp);
		if(a[b[0]]>=n)tot=1;
		if(tot%2==0)
		{
			for(int i=0;i<n;i++)
			{
				sort(b+i,b+n,cmp);
				if(a[b[i]]>n-i-1)tot=1;
				
				times=i;
				Havel();
			}
			int k1=a[b[n-1]];
		//	int k2=a[b[n]];
			if(tot%2==0)
			{
				cout<<"YES"<<endl;
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n-1;j++)
					{
						cout<<G[i][j]<<" ";
					}
					cout<<G[i][n-1]<<endl;
				}
			}
			else 
			{
				cout<<"NO"<<endl;
			}
		}
		else 
		{
			cout<<"NO"<<endl;
		}
		if(T)
		cout<<endl;
		
	}
			
		
	return 0;
}

