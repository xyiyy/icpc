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
int a[200010],x[200010];
int ans[200010];
ll num[200010];
bool f[200010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int n;
        clr(num,0);
        clr(ans,0);
        clr(f,0);
        scanf("%d",&n);
        int maxx = 0;
        rep(i,n){
            scanf("%d %d",&a[i],&x[i]);
            maxx = max(a[i],maxx);
            num[a[i]] += x[i];
        }
        rep2(i,0,maxx){
            if(num[i]>=2){
                num[i+1] += num[i]/2;
                num[i] = (num[i]&1);
                f[i+1] = 1;
            }
        }
        int now = 0;
        dep(i,maxx,0){
            if((num[i]&1)&&!f[i]){
                now = i;
                break;
            }
        }
        printf("Case #%d: ",cas++);
        if(!now){
            if(num[0])puts("1");
            else puts("0");
            continue;
        }
        ans[0] = 1;
        dep(i,now-1,0){
            ans[i]+= (1-(num[i]&1));
        }
        rep2(i,0,now){
            if(ans[i]==2){
                ans[i] = 0;
                ans[i+1]++;
            }
        }
        int ff = now + 1;
        dep(i,now+1,0){
            if(ans[i]){
                ff = i;
                break;
            }
        }
        dep(i,ff,0){
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}

