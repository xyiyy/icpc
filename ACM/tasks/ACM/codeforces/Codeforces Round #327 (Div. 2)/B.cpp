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
int pa[1110];
int find(int x){
    if(pa[x]!=x)pa[x] = find(pa[x]);
    return pa[x];

}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    while(cin>>n>>m){
        string str;
        string str1,str2;
        cin>>str;
        rep(i,1110)pa[i] = i;
        rep(i,m){
            cin>>str1>>str2;
            int x = str1[0];
            int y = str2[0];
            rep2(i,'a','z'){
                if(pa[i]==x)pa[i] = y;
                else if(pa[i]==y)pa[i] = x;
            }
         //   rep(i,n){
         //   cout << (char)pa[str[i]];
        //}
        //cout << endl;
        }
        rep(i,n){
            cout << (char)pa[str[i]];
        }
        cout << endl;
    }
    return 0;
}

