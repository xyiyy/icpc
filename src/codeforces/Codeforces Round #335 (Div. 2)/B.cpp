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
bool vis[510][510];
int x,y;
bool in(int sx,int sy){
    if(!sx||!sy||sx>x||sy>y)return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int sx,sy;
    while(cin>>x>>y>>sx>>sy){
        string str;
        cin>>str;
        int len = str.length();
        cout<< 1 << " ";
        int num = 1;
        vis[sx][sy] = 1;
        rep(i,len-1){
            if(str[i]=='L'&&in(sx,sy-1)){
                sy--;
            }else if(str[i]=='R'&&in(sx,sy+1)){
                sy ++;
            }else if(str[i]=='U'&&in(sx-1,sy)){
                sx--;
            }else if(str[i]=='D'&&in(sx+1,sy)){
                sx ++;
            }
            if(!vis[sx][sy]){
                vis[sx][sy] = 1;
                cout << 1<<" ";
                num ++;
            }else cout << 0 << " ";
        }
        cout << x * y - num << endl;
    }
    return 0;
}

