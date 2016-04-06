//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
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
typedef vector<PII> vii;
typedef vector<int> vi;
bool vis[100010];
struct Trie
{
    int Next[5000010][2],tail[5000010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 2;i++)
            Next[L][i] = -1;
        tail[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int num)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(Next[now][buf[i]-'0'] == -1)
                Next[now][buf[i]-'0'] = newnode();
            now = Next[now][buf[i]-'0'];
        }
        if(!tail[now])
        tail[now] = num;
    }
    bool query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        bool res = 1;
        int f = 100010;
        //cout << "              "<< endl;
        if(tail[now] > 0){
                //cout << tail[now] << endl;
                if(tail[now] < f){
                    f = tail[now];
                    res = vis[f];
                }
            }
        for(int i = 0;i < len;i++)
        {
            now = Next[now][buf[i]-'0'];
            if(tail[now] > 0){
                //cout << tail[now] << endl;
                if(tail[now] < f){
                    f = tail[now];
                    res = vis[f];
                }
            }else if(now <= 0)break;
        }
        return res;
    }
};
char buf[33];
Trie ac;
int tmp[4];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    ac.init();
    string str;
    int gao = 0;
    rep(i,n){
        cin >> str;
        bool ok = true;
        if(str[0] == 'd')ok = false;
        int now = 0;
        cin >> str;
        int len = str.length();
        int mask = -1;
        clr(tmp,0);
        bool flag = 0;
        rep(j,len){
            if(str[j] == '/'){//break;
                flag = 1;
                continue;
            }
            else if(str[j] == '.'){
                now++;
                continue;
            }
            if(flag){
                if(mask == -1)mask = 0;
                mask = mask * 10 + str[j] - '0';
            }else{
                tmp[now] = tmp[now] * 10 + str[j] - '0';
            }

        }
        if(mask == -1)mask = 32;
        now = 0;
        clr(buf,0);
        rep(j,4){
            dep(k,7,0){
                buf[now] = ((tmp[j] >> k) & 1) + '0';
                now++;
            }
        }
        buf[mask] = 0;
        gao++;
        vis[gao] = ok;
        ac.insert(buf,gao);
    }
    rep(i,m){
        int now = 0;
        cin >> str;
        int len = str.length();
        int mask = -1;
        clr(tmp,0);
        bool flag = 0;
        rep(j,len){
            if(str[j] == '/'){
                flag = 1;
                continue;
            }
            else if(str[j] == '.'){
                now++;
                continue;
            }
            if(flag){
                if(mask == -1)mask = 0;
                mask = mask * 10 + str[j] - '0';
            }else{
                tmp[now] = tmp[now] * 10 + str[j] - '0';
            }

        }
        if(mask == -1)mask = 32;
        now = 0;
        clr(buf,0);
        rep(j,4){
            dep(k,7,0){
                buf[now] = ((tmp[j] >> k) & 1) + '0';
                now++;
            }
        }
        buf[mask] = 0;
        if(ac.query(buf)){
            cout << "YES" <<endl;
        }else cout << "NO" << endl;
    }

    return 0;
}

