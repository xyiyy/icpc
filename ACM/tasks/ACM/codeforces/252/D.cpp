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

int vis[3001];
int a[3001];

vector<VI> group;

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n)
	{
		CLR(vis,0);
		group.clear();
		REP(i,n) cin>>a[i];
		cin>>m;
		int now=0;
		REP(i,n) if(!vis[i])
		{
			int c=0;
			VI v;
			for(int j=i;!vis[j];j=a[j]-1,c++)
			{
				vis[j]=1;
				v.PB(j+1);
			}
			group.PB(v); 
			now+=c-1;
		}
		if(now==m)
		{
			cout<<0<<endl;
		}else if(now>m){
			cout<<now-m<<endl;
			REP(i,group.size()) if(now>m)
			{
				REP2(j,1,group[i].size()-1) if(now>m)
				{
					cout<<group[i][0]<<' '<<group[i][j]<<' ';
					now--;
				}
			}
			cout<<endl;
		}else{
			cout<<m-now<<endl;
			REP2(i,1,group.size()-1) if(now<m)
			{
				cout<<group[0][0]<<' '<<group[i][0]<<' ';
				now++;
			}
			cout<<endl;
		}
	}
	return 0;
}

