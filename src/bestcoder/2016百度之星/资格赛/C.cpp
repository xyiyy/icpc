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
typedef vector<PII> VII;
typedef vector<int> VI;

struct Trie{
    int Next[3000010][30],tail[3000010];
    bool ok[3000010];
    int root,L;
    int newnode(){
        ok[L] = 0;
        rep(i,30)Next[L][i] = 0;
        tail[L++] = 0;
        return L - 1;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(string buf){
        int len = buf.length();
        int now = root;
        ok[root] = true;
        for(int i = 0 ; i < len ; i++){
            buf[i] -= 'a' - 1;
            if(!Next[now][buf[i]])Next[now][buf[i]] = newnode();
            now = Next[now][buf[i]];
            ok[now] = true;
        }
        tail[now] = 1;
    }
    void Delete(string buf){
        int len = buf.length();
        int now = root;
        stack<int>st;
        for(int i = 0;i < len ; i++){
            st.push(now);
            buf[i] -= 'a' - 1;
            if(!Next[now][buf[i]])return;
            now = Next[now][buf[i]];
        }
        rep(i,30){
            Next[now][i] = 0;
        }
        tail[now] = 0;
        ok[now] = false;
        while(!st.empty()){
            int p = st.top();st.pop();
            len--;
            bool flag = 0;
            Next[p][buf[len]] = 0;
            if(tail[p])return;
            rep(i,30){
                if(Next[p][i] && ok[Next[p][i]])flag = 1;
            }
            if(flag)return;
            ok[p] = false;
        }
    }
    bool query(string buf){
        int len = buf.length();
        int now = root;
        for(int i = 0 ; i < len ; i++){
            buf[i] -= 'a' - 1;
            if(!Next[now][buf[i]])return false;
            now = Next[now][buf[i]];
            if(!ok[now])return false;
        }
        return true;
    }

}ac;
string op,str;
int main(){
    ios::sync_with_stdio(false);
    #ifdef LOCAL

    #endif // LOCAL
    int n;
    while(cin >> n){
        ac.init();
        rep(i,n){
            cin >> op >> str;
            if(op[0] == 'i')ac.insert(str);
            else if(op[0] == 's'){
                if(ac.query(str)){
                    cout << "Yes" << endl;
                }else cout << "No" <<endl;
            }
            else ac.Delete(str);
        }

    }
    return 0;
}

