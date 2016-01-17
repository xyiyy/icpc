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

int a[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in1.txt","r",stdin);
        freopen("out1.txt","w",stdout);

    #endif // LOCAL
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        clr(a,0);
        rep(i,n){
            scanf("%d",&a[i]);
        }
        int now = 0;
        int last = 0;
        int ans = 0;
        rep(i,n){
            if(i){
                if(now){
                   if(a[i]<=last){
                        now = 1;
                        ans++;
                   }else{
                        while(a[i]>last + 10){
                            last = last + 10;//min(last+10,100);
                            now++;
                        }
                        if(now>=4){
                            now = 0;
                            ans++;
                        }
                        now++;
                        if(now == 4)ans++,now = 0;
                   }
                }else{
                    now = 1;
                }
            }else{
                if(a[i] == 100){
                    ans = 1;
                    now = 0;
                }else now = 1;
            }
            last = a[i];
            //cout << i << " " << now << " " << ans << endl;
        }
        if(now)ans++;
        cout << "Case #"<<cas ++ << ": "<< 4 * ans - n << endl;

    }

    return 0;
}
