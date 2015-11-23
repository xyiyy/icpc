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
char a[110],b[110];
vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    while(cin>>t){
        cin>>a>>b;
        int x,y;
        x = y = 0;
        ans.clear();
        stack<int>s;
        int f = 1;
        while(y<t){
            if(!s.empty()){
                if(s.top()==b[y]){
                    s.pop();
                    ans.pb(0);
                    y++;
                }else{
                    if(x==t){
                        f = 0;
                        break;
                    }
                    s.push(a[x]);
                    ans.pb(1);
                    x++;
                }
            }else{
                if(x==t){
                    f = 0;
                    break;
                }
                s.push(a[x]);
                ans.pb(1);
                x++;
            }
        }
        if(s.size())f = 0;
        if(!f){
            puts("No.");
        }else{
            puts("Yes.");
            rep(i,ans.size()){
                if(ans[i])puts("in");
                else puts("out");
            }
        }
        puts("FINISH");
    }
    return 0;
}
