#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int m[1001][1001];

int main()
{
    //ios::sync_with_stdio(false);
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        if(n%4==3) {
            int s=1;
            int k=n/4;
            for(int x=0;x<n && k>=0;x+=2,k--) {
                VII v;
                REP(i,(k+1)*2) {
                    v.PB(MP(x+i*2,x));
                    v.PB(MP(x+i*2,x+1));
                    v.PB(MP(x+i*2+1,x+1));
                    v.PB(MP(x+i*2+1,x));
                }
                v.pop_back();
                v.pop_back();
                REP(i,(k+1)*2-1) {
                    v.PB(MP(n-x-1,x+i*2+2));
                    v.PB(MP(n-x-2,x+i*2+2));
                    v.PB(MP(n-x-2,x+i*2+1+2));
                    v.PB(MP(n-x-1,x+i*2+1+2));
                }
                v.pop_back();
                v.pop_back();
                REP(i,(k+1)*2-1) {
                    v.PB(MP(n-(x+i*2+2)-1,n-x-1));
                    v.PB(MP(n-(x+i*2+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-1));
                }
                v.pop_back();
                v.pop_back();
                REP(i,(k+1)*2-2) {
                    v.PB(MP(x,n-(x+i*2+2)-1));
                    v.PB(MP(x+1,n-(x+i*2+2)-1));
                    v.PB(MP(x+1,n-(x+i*2+1+2)-1));
                    v.PB(MP(x,n-(x+i*2+1+2)-1));
                }
                v.pop_back();
                v.pop_back();
                REP(i,v.size()) {
                    //cout<<v[i].X<<' '<<v[i].Y<<endl;
                    m[v[i].X][v[i].Y]=s++;
                }
            }
            k=n/4;
            m[k*2][n-1-k*2]=s++;
        }else if(n%4==1){
            int s=1;
            int k=n/4;
            for(int x=0;x<n && k>0;x+=2,k--) {
                VII v;
                REP(i,2*k+1) {
                    v.PB(MP(x+i*2,x));
                    v.PB(MP(x+i*2,x+1));
                    v.PB(MP(x+i*2+1,x+1));
                    v.PB(MP(x+i*2+1,x));
                }
                v.pop_back();
                v.pop_back();
                REP(i,k*2) {
                    v.PB(MP(n-x-1,x+i*2+2));
                    v.PB(MP(n-x-2,x+i*2+2));
                    v.PB(MP(n-x-2,x+i*2+1+2));
                    v.PB(MP(n-x-1,x+i*2+1+2));
                }
                v.pop_back();
                v.pop_back();
                REP(i,k*2) {
                    v.PB(MP(n-(x+i*2+2)-1,n-x-1));
                    v.PB(MP(n-(x+i*2+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-1));
                }
                v.pop_back();
                v.pop_back();
                REP(i,k*2-1) {
                    v.PB(MP(x,n-(x+i*2+2)-1));
                    v.PB(MP(x+1,n-(x+i*2+2)-1));
                    v.PB(MP(x+1,n-(x+i*2+1+2)-1));
                    v.PB(MP(x,n-(x+i*2+1+2)-1));
                }
                v.pop_back();
                v.pop_back();
                REP(i,v.size()) {
                    //cout<<v[i].X<<' '<<v[i].Y<<endl;
                    m[v[i].X][v[i].Y]=s++;
                }
            }
            k=n/4;
            m[k*2][n-1-k*2]=s++;
        }else if(n%4==0){
            int s=1;
            int k=n/4-1;
            for(int x=0;x<n && k>=0;x+=2,k--) {

                VII v;
                REP(i,2*k+1) {
                    v.PB(MP(x+i*2,x));
                    v.PB(MP(x+i*2,x+1));
                    v.PB(MP(x+i*2+1,x+1));
                    v.PB(MP(x+i*2+1,x));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,k*2+2) {
                    v.PB(MP(n-x-2,x+i*2));
                    v.PB(MP(n-x-1,x+i*2));
                    v.PB(MP(n-x-1,x+i*2+1));
                    v.PB(MP(n-x-2,x+i*2+1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,(k==0?1:k*2)) {
                    v.PB(MP(n-(x+i*2+2)-1,n-x-1));
                    v.PB(MP(n-(x+i*2+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,(k==0?0:k*2+1)) {
                    v.PB(MP(x+1,n-(x+i*2)-1));
                    v.PB(MP(x,n-(x+i*2)-1));
                    v.PB(MP(x,n-(x+i*2+1)-1));
                    v.PB(MP(x+1,n-(x+i*2+1)-1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,v.size()) {
                    //cout<<v[i].X<<' '<<v[i].Y<<endl;
                    m[v[i].X][v[i].Y]=s++;
                }
            }
        }else{
            int s=1;
            int k=n/4;
            for(int x=0;x<n && k>=0;x+=2,k--) {
                VII v;
                REP(i,(k?2*k:1)) {
                    v.PB(MP(x+i*2,x));
                    v.PB(MP(x+i*2,x+1));
                    v.PB(MP(x+i*2+1,x+1));
                    v.PB(MP(x+i*2+1,x));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,(k?k*2+1:0)) {
                    v.PB(MP(n-x-2,x+i*2));
                    v.PB(MP(n-x-1,x+i*2));
                    v.PB(MP(n-x-1,x+i*2+1));
                    v.PB(MP(n-x-2,x+i*2+1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,k*2-1) {
                    v.PB(MP(n-(x+i*2+2)-1,n-x-1));
                    v.PB(MP(n-(x+i*2+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-2));
                    v.PB(MP(n-(x+i*2+1+2)-1,n-x-1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,k*2) {
                    v.PB(MP(x+1,n-(x+i*2)-1));
                    v.PB(MP(x,n-(x+i*2)-1));
                    v.PB(MP(x,n-(x+i*2+1)-1));
                    v.PB(MP(x+1,n-(x+i*2+1)-1));
                }
                //v.pop_back();
                //v.pop_back();
                REP(i,v.size()) {
                    //cout<<v[i].X<<' '<<v[i].Y<<endl;
                    m[v[i].X][v[i].Y]=s++;
                }
            }
        }
        int c=0;
        REP(i,n) {
            REP(j,n) {
                if(j) printf(" ");
                printf("%d",m[i][j]);
                int _1=i&&abs(m[i-1][j]-m[i][j])==1;
                int _2=j&&abs(m[i][j-1]-m[i][j])==1;
                int _3=i!=n-1&&abs(m[i+1][j]-m[i][j])==1;
                int _4=j!=n-1&&abs(m[i][j+1]-m[i][j])==1;
                if(_1+_2+_3+_4==1) c++;
                else if(_1&&_3) c++;
                else if(_2&&_4) c++;
            }
            printf("\n");
        }
        //cout<<c<<endl;
    }
    return 0;
}
