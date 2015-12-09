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
int l[5010],w[5010],id[5010],use[5010];
bool cmp(int x,int y)
{
	if(l[x]==l[y])return w[x]<w[y];
	return l[x]<l[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int t,ans,n;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l[i]>>w[i];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		int last;
		CLR(use,0);
		for(int i=0;i<n;i++){
			last=w[id[i]];
			if(!use[i]){
				for(int j=i+1;j<n;j++){
					if(last<=w[id[j]]&&!use[j]){
						use[j]=1;
						last=w[id[j]];
					}
				}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


