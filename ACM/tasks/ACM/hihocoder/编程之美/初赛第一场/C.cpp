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
int V;
const int MAX_V =1010;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v)
{
   // cout<<u<<" "<<v<<endl;
	G[u].PB(v);
	G[v].PB(u);
}

bool dfs(int v)//Ôö¹ãÂ·
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}
	}
	return false ;
}

int hungary()
{
	int res=0;
	CLR(match,-1);
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			CLR(used,0);
			if(dfs(v))
			{
				res++;
			}
		}
	}
	return res;
}
int a[1011];
int b[1010];
int p[1010];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        CLR(used,0);
        int n;
        cin>>n;
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        CLR(p,0);
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=b[i];j++){
                while(b[i]%j==0){
                    b[i]/=j;
                    p[i]++;
                }
            }
            if(b[i]!=1)p[i]++;
        }
        V=n;
        for(int i=0;i<n;i++){
              //  cout<<p[i]<<" ";
            if(p[i]%2==1){
            for(int j=0;j<n;j++){
                if(abs(p[i]-p[j])==1&&(a[j]%a[i]==0||a[i]%a[j]==0))add_edge(i,j);
            }
            }
        }
      //  cout<<endl;
        cout<<"Case #"<<cas++<<": ";
        cout<<n-hungary()<<endl;
    }
	return 0;
}



