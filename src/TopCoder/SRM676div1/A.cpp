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

class WaterTank{
public :
    double minOutputRate(vector <int> t, vector <int> x, int C){
        int n = t.size();
        double l = 0,r = 1e18;
        double ans = r;
        for(int i=0;i<=1000;i++){
            double mid = ( l+r) /2;
            ans = mid;
            bool ok = 1;
            double now = 0;
            double maxx = 0;
            for(int i=0;i<n;i++){
                now = max(0.0,now - (mid - x[i]) * t[i]);
                maxx = max(now,maxx);
            }
            if(maxx>=C)ok = 0;
            if(ok)r = mid;
            else l = mid;
        }
        return ans;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL

    return 0;
}

