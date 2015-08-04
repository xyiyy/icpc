//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define MP(X,Y,Z) make_pair(X,make_pair(Y,Z))
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,pair<int,int> > PII;
typedef vector<PII> VII;
typedef vector<int> VI;
vector<PII> shu;
vector<PII> heng;
bool cmp1(int x,int y){
    return shu[x].first<shu[y].first;
}
bool cmp2(int x,int y){
    return heng[x].first<heng[y].first;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int n;
        cin>>n;
        shu.clear();
        heng.clear();
        int a,b,c,d;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c>>d;
            if(a>c)swap(a,c);
            if(b>d)swap(b,d);
            if(a==c){
                shu.PB(MP(a,b,d));
            }else{
                heng.PB(MP(b,a,c));
            }
        }
        //sort(shu.begin(),shu.end());
        //sort(heng.begin(),heng.end());
        ll ans=0;
        for(int i=0;i<shu.size();i++){
            int x,y,z;
            x=shu[i].first;
            y=shu[i].second.first;
            z=shu[i].second.second;
            for(int j=0;j<shu.size();j++){
                int tx=shu[j].first;
                if(tx<=x)continue;
                int ty=shu[j].second.first;
                int tz=shu[j].second.second;
                if(ty>=z||tz<=y)continue;
                int minn=max(ty,y);
                int maxx=min(tz,z);
                ll num=0;
                for(int k=0;k<heng.size();k++){
                    int gy,gx1,gx2;
                    gy=heng[k].first;
                    if(gy<minn||gy>maxx)continue;
                    gx1=heng[k].second.first;
                    gx2=heng[k].second.second;
                    if(gx1<=x&&gx2>=tx)num++;
                }
                if(num>=2){
                    ans+=num*(num-1)/2;
                }
            }
        }
        cout<<"Case #"<<cas++<<":"<<endl;
        cout<<ans<<endl;
	}
	return 0;
}


