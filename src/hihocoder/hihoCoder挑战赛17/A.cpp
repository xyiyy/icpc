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
const int MAXN = 2000010;
struct node{
    int ch[26],sz;
}T[MAXN];
int root[100010];
int tot = 100010;
string str;
void Insert(){
    int len = str.length();
    int now = root[len];
    rep(i,len){
        int c = str[i] - 'a';
        if(!T[now].ch[c])T[now].ch[c]=++tot;
        //if(i==len-1)T[now].sz++;
        now = T[now].ch[c];
    }
    T[now].sz++;
}
int ans = 0;
int flag =0 ;
int gao = 0;
void dfs(int now,int d){
    //cout << gao << endl;
    if(d==gao){
        //cout << now << " " << d <<endl;
        ans+=T[now].sz;
        return;
    }
    //cout << now << " " << d <<endl;
    int c = str[d - flag] - 'a';
    if(flag){
        if(!T[now].ch[c])return;
        dfs(T[now].ch[c],d+1);
    }else{
        rep(i,26){
            if(!T[now].ch[i])continue;
            //cout << (char)('a' + i) <<endl;
            if(i!=c){
                flag = 1;
                dfs(T[now].ch[i],d+1);
                flag = 0;
            }else{
                dfs(T[now].ch[i],d+1);
            }
        }
    }
}
void query(){
    gao = str.length() + 1;
    int now = root[gao];
    ans  = 0;
    flag = 0;
    dfs(now,0);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    rep(i,100010)root[i] = i;
    rep(i,n){
        cin>>str;
        int len = str.length();
        //rep(i,len)if(str[i]>='A'&&str[i]<='Z')str[i] += 'a' - 'A';
        Insert();
    }
    rep(i,m){
        cin>>str;
        query();
    }
    return 0;
}
