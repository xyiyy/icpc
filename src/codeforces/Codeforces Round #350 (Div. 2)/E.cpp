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
char str[500010];
char s[500010];
stack <int> st;
int L[500010],R[500010],Next[500010],pre[500010],match[500010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m,p;
    while(cin >> n >> m >> p){
        cin >> str + 1;
        cin >> s + 1;
        while(!st.empty())st.pop();
        st.push(0);
        Next[0] = 1;
        pre[n+1] = n;
        rep2(i,1,n){
            if(str[i] == '('){
                L[i] = i - 1;
                st.push(i);
            }else{
                match[i] = st.top();
                match[st.top()] = i;
                L[i] = L[st.top()];
                R[i] = i + 1;
                R[st.top()] = R[i];
                st.pop();
            }
            pre[i] = i - 1;
            Next[i] = i + 1;
        }
        int l,r;
        rep2(i,1,m){
            if(s[i] == 'L'){
                p = pre[p];
            }else if(s[i] == 'R'){
                p = Next[p];
            }else{
                if(str[p] == '('){
                    l = pre[p];
                    r = Next[match[p]];
                }else{
                    r = Next[p];
                    l = pre[match[p]];
                }
                Next[l] = r;
                pre[r] = l;
                p = (r == n + 1 ? l : r);
            }
        }
        int now = Next[0];
        while(now != n + 1){
            cout << str[now];
            now = Next[now];
        }
        cout << endl;

        //rep2(i,1,n)cout << L[i] << " " << R[i] << endl;
    }
    return 0;
}

