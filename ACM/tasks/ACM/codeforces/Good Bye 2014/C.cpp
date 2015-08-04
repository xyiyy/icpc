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
int w[1010];
int b[1010];
int vis[1010];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(int j=0;j<m;j++)
		{
			cin>>b[j];
		}
		stack<int>s1;
		stack<int>s2;
		ll ans=0;
		ll tmp;
		CLR(vis,0);
		ll sum=0;
		int d;
		for(int i=0;i<m;i++)
		{
			if(!vis[b[i]])
			{
				ans+=(ll)sum;
				s1.push(b[i]);
				sum+=(ll)w[b[i]];
				vis[b[i]]=1;
			}
			else 
			{
				tmp=0;
				while(s1.top()!=b[i])
				{
					s2.push(s1.top());
					s1.pop();
					tmp+=w[s2.top()];
				}
				d=s1.top();
				//cout<<"ok"<<endl;
				s1.pop();
				while(!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
				s1.push(d);
				ans+=tmp;
			}
			
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
				
	}
					
			
	return 0;
}



