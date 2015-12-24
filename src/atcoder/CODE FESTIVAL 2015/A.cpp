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
char a[110][110];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int h,w,k;
    while(cin>>h>>w>>k){
        rep(i,h)rep(j,w)a[i][j] = '.';
        int num = 0;
        int flag = 0;
        for(int i=0;i<h;i+=2){
            for(int j=0;j<w;j+=2){
                if(num==k){
                    flag = 1;
                }
                if(flag)break;
                a[i][j] = '#';
                num++;
            }
            if(flag)break;
        }
        if(num==k)flag = 1;
        if(flag){
            rep(i,h){
                rep(j,w){
                    cout << a[i][j];
                }
                cout<<endl;
            }
        }else cout <<"IMPOSSIBLE"<<endl;
    }
    return 0;
}


