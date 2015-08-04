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
int a[1010];
int main()
{
	ios::sync_with_stdio(false);
    freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int n,b;
        cin>>b>>n;
        ll fuc=0;
        for(int i=0;i<b;i++){
            cin>>a[i];
        }
        if(n<=b){
            cout<<"Case #"<<cas++<<": "<<n<<endl;
            continue;
        }
        ll l=0,r=1LL<<60;
        ll tmp=0;
        while(l<=r){
            ll mid=(l+r)>>1;
            tmp=0;
            for(int i=0;i<b;i++){
                tmp+=mid/a[i]+1;
            }
            if(tmp>=n){
                fuc=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int ans=0;
        tmp=0;
        for(int i=0;i<b;i++){
            tmp+=(fuc+a[i]-1)/a[i];
        }
        //cout<<tmp<<endl;
        for(int i=0;i<b;i++){
            if(fuc%a[i]==0){
                tmp++;
                if(tmp==n){
                    ans=i;
                    break;
                }
            }
        }
        /*priority_queue<PII,vector<PII>,greater<PII> >q;
        for(int i=0;i<b;i++){
            q.push(MP((fuc/a[i]+1)*a[i],i));
        }
        cout<<fuc<<endl;
        tmp=n-b;
        while(tmp<n){
            PII p=q.top();
            q.pop();
            p.first+=a[p.second];
            q.push(p);
            tmp++;
        }
        ans=q.top().second;*/
        ans++;
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
	}
	return 0;
}



