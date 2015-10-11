//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const double eps = 1.0/120;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin>>t;
    while(t--){
        double n;
        cin>>n;
        double h = 0,m = 0;
        double x = 360.0 / 720.0;
        double y = 360.0 / 60.0;
        rep(i,720){
            if(fabs(fabs(h-m) - n)<eps || fabs(360.0 - fabs(h-m) - n)<eps){//|| fabs(fabs(360-h+m) - n)<eps || fabs(fabs(360+h-m)-n)<eps){
                //cout << i<<" " << h << " " << m<< endl;
                int hh = i / 60;
                if(hh<10)cout<<0;
                cout << hh << ":";
                int mm = i % 60;
                if(mm == 0)cout << "00";
                else if(mm < 10) cout << 0 << mm;
                else cout << mm;
                cout << endl;
            }
            h += x;
            m += y;
            if(i%60==59)m -= 360.0;
        }
    }



    return 0;
}
