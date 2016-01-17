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

struct Trie
{
    short next[256*110][256],fail[256*110],end[256*110];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 256;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(string s)
    {
        int len = s.length();
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]] == -1)
                next[now][s[i]] = newnode();
            now=next[now][s[i]];
        }
        end[now]=1;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 256;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 256;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    bool query(string buf)
    {
        int len = buf.length();
        int now = root;
        for(int i = 0;i < len;i++){
            now = next[now][buf[i]];
            int temp = now;
            while(temp != root){
                if(end[temp] != -1)return true;
                temp = fail[temp];
            }
        }
        return false;
    }
};
Trie ac;
int gao(string S,vector<string>dics,int n){
    ac.init();
    for(int i=0;i<n;i++){
        ac.insert(dics[i]);
    }
    ac.build();
    int ans =0 ;
    int len = S.length();
    string temp = "";
    for(int i=0;i<len;i++){
        temp = temp + S[i];
        if(ac.query(temp)){
            ans++;
            temp="";
        }
       // for(int j=0;j<n;j++){
       //     if(temp.find(dics[j])){
        //        ans++;
        //        temp = "";
        //        break;
         //   }
        //}
    }
    if(ans == 0)ans = 1;
    return ans;


}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    string s= "aabbccdd";
    vector<string>dics;
    dics.pb("a");
    dics.pb("b");
    dics.pb("c");
    dics.pb("d");
    cout << gao(s,dics,4);
    return 0;
}

