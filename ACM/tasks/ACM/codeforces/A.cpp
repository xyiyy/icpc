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
set<ll> sx1,sy1;
map<ll,int> sx2;
map<ll,int> sy2;
int main()
{
	ios::sync_with_stdio(false);
	ll w,h,n;
	cin>>w>>h>>n;
	ll lx,ly,rx,ry;
	char c;
	ll x,y,t;
	lx=0,ly=0;
	ry=w,rx=h;
	ll ans=w*h;
	sx1.insert(0);
	sx1.insert(h);
	sx2.insert(MP(h,1));
	sy1.insert(0);
	sy1.insert(w);
	sy2.insert(MP(w,1));
	set<ll> ::iterator it;
	priority_queue<ll>q1,q2;
	q1.push(h);
	q2.push(w);
	for(int i=0;i<n;i++){
		cin>>c>>t;
		if(c=='H'){
		it=sx1.lower_bound(t);
		ll tx=*it;
		it--;
		ll tx2=*it;
		sx1.insert(t);
		ll tmp=tx-tx2;
		sx2[tmp]--;
		sx2[tx-t]++;
		sx2[t-tx2]++;
		q1.push(tx-t);
		if(t-tx2!=tx-t)
		q1.push(t-tx2);
		ll tempx=q1.top();
		ll tempy=q2.top();
		while(sx2[tempx]==0){
				q1.pop();
			tempx=q1.top();
		
		}
		ans=tempx*tempy;
			
		}else{
			it=sy1.lower_bound(t);
			ll ty=*it;
			it--;
			ll ty2=*it;
			sy1.insert(t);
			ll tmp=ty-ty2;
			sy2[tmp]--;
			sy2[ty-t]++;
			sy2[t-ty2]++;
			q2.push(ty-t);
			if(t-ty2!=ty-t)
			q2.push(t-ty2);
			ll tempx=q1.top();
			ll tempy=q2.top();
			while(sy2[tempy]==0){
				q2.pop();
			tempy=q2.top();
			
			}
			ans=tempx*tempy;
		}
		cout<<ans<<endl;
	}
		
		
		
	return 0;
}



