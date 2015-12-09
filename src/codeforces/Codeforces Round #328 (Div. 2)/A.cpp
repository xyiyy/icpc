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

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    char a[10][10];//
    rep(i,8){
        rep(j,8){
            cin>>a[i][j];
        }
    }
    int ans  =8;
    rep(i,8){
        int j = 0;
        while(j<8&&a[j][i]=='.')j++;
        if(j==8||a[j][i]=='B')continue;
        else ans = min(j,ans);
    }
    int y = 8;
    rep(i,8){
        int j = 7;
        while(j>=0&&a[j][i]=='.')j--;
        if(j==-1||a[j][i]=='W')continue;
        else y = min(7-j,y);
        //cout << a[i][j]<<j<<endl;
        //cout <<i<< y << endl;
    }
   // cout << ans << " "<<y << endl;
    if(ans <= y)cout << "A" << endl;
    else cout << "B"<<endl;
    return 0;
}

