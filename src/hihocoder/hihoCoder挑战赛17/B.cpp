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
    int ch[26];
    int sz;
}T[MAXN];
int root[100010];
int tot = 100010;
string str;
void Insert(int n){
    int len = str.length();
    int now = root[len];
    rep(i,len){
        int c = str[i] - 'a';
        if(!T[now].ch[c])T[now].ch[c]=++tot;
        //if(i==len-1)T[now].sz++;
        now = T[now].ch[c];
    }
    T[now].sz = n + 1;
    //T[now].sz.insert(n+1);
    //T[now].sz++;
}
vector<int>ans;
int flag =0 ;
int gao = 0;
void dfs(int now,int d){
    if(d==gao){
        ans.pb(T[now].sz);
        return;
    }
    int c = str[d - flag] - 'a';
    if(flag == 2){
        if(!T[now].ch[c])return;
        dfs(T[now].ch[c],d+1);
    }else if(flag<2){
        rep(i,26){
            if(!T[now].ch[i])continue;
            if(i!=c){
                flag++;
                dfs(T[now].ch[i],d+1);
                flag--;
            }else{
                dfs(T[now].ch[i],d+1);
            }
        }
    }
}
void dfs2(int now,int d){
    if(d==gao){
        ans.pb(T[now].sz);
        return;
    }
    int c = str[d] - 'a';
    if(flag == 2){
        if(!T[now].ch[c])return;
        dfs2(T[now].ch[c],d+1);
    }else if(flag < 2){
        rep(i,26){
            if(!T[now].ch[i])continue;
            if(i!=c){
                flag++;
                dfs2(T[now].ch[i],d+1);
                flag--;
            }else{
                dfs2(T[now].ch[i],d+1);
            }
        }
    }
}
void dfs3(int now,int d){
    if(d==gao){
        ans.pb(T[now].sz);
        //return;
    }
    if(d>gao)return;
    int c = str[d + flag] - 'a';
    if(flag == 2){
        if(!T[now].ch[c])return;
        dfs3(T[now].ch[c],d+1);
    }else if(flag<2){
        rep(i,26){
            //if(!T[now].ch[i])continue;
            //if(i!=c){
            flag++;
            dfs3(now,d);
            flag--;
            //}else{
            if(i==c){
                if(!T[now].ch[i])continue;
                dfs3(T[now].ch[i],d+1);
            }
        }
    }
}
void query(){
    gao = str.length() + 2;
    int now = root[gao];
    flag = 0;
    ans.clear();
    dfs(now,0);
    sort(ans.begin(),ans.end());
    int sz = ans.size();
    rep(i,3){
        if(i)cout << " ";
        if(i>=sz)cout << -1;
        else cout << ans[i];
    }
    cout <<endl;
    gao = str.length();
    flag =0 ;
    now = root[gao];
    ans.clear();
    dfs2(now,0);
    sort(ans.begin(),ans.end());
    sz = ans.size();
    rep(i,3){
        if(i)cout << " ";
        if(i>=sz)cout << -1;
        else cout << ans[i];
    }
    cout <<endl;
    gao = str.length() - 2;
    now = root[gao];
    ans.clear();
    dfs3(now,0);
    sort(ans.begin(),ans.end());
    sz = unique(ans.begin(),ans.end()) - ans.begin();
    rep(i,3){
        if(i)cout << " ";
        if(i>=sz)cout << -1;
        else cout << ans[i];
    }
    cout <<endl;
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
        Insert(i);
    }
    rep(i,m){
        cin>>str;
        query();
    }
    return 0;
}
