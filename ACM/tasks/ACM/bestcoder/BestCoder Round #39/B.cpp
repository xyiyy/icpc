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
vector<int>vec[10010];
int pos[10010];
int a[10010];
int gao[10010];
int main()
{
	ios::sync_with_stdio(false);
	for(int i=2;i<10001;i++){
        vec[i].PB(1);
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                vec[i].PB(j);
                vec[i].PB(i/j);
            }
        }
	}
	int n;
	while(cin>>n){
        CLR(pos,0);
        CLR(gao,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)pos[a[i]]=i;
        for(int i=1;i<=10000;i++)gao[i]=10010;
        for(int i=1;i<=n;i++){
            for(int j=0;j<vec[a[i]].size();j++){
                int v=vec[a[i]][j];
                if(pos[v]==0)continue;
                if(pos[v]<pos[a[i]]){
                    gao[v]=min(pos[a[i]],gao[v]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(gao[a[i]]!=10010){
                ans+=gao[a[i]];
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
	}
	return 0;
}



