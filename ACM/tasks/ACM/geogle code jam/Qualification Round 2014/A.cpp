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
int a[4][4],b[4][4]; 
int m,n;
int v[4];
int vis[4];
int main()
{
	ios::sync_with_stdio(false);
	int t,num,cho,k=1;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>m;
		memset(vis,0,sizeof(vis));
		memset(v,0,sizeof(v));
		num=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cin>>a[i][j];
				if(i==m-1)v[j]=a[i][j];
			}
		}
		cin>>n;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cin>>b[i][j];
			}
		}
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				//if(i==j)continue;
				if(v[i]==b[n-1][j])vis[i]=1;
			}
		}	
		for(int i=0;i<4;i++)
		{
			if(vis[i]==1){num++;cho=v[i];}
		}
		cout<<"Case #"<<k++<<": ";
		if(num==1)cout<<cho<<endl;
		else if(num>1)cout<<"Bad magician!"<<endl;
		else if(num==0)cout<<"Volunteer cheated!"<<endl;
	}
		
		
	return 0;
}

