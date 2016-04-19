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
typedef vector<PII> vii;
typedef vector<int> vi;
bitset<1000000>dp;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        dp.reset();
        int x;
        priority_queue<int,vector<int>,greater<int> >q;
        rep(i,n){
            cin >> x;
            q.push(x);
        }
        int m;
        cin >> m;
        dp[0] = 1;
        int y;
        while(q.size() >= 2){
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            q.push(x+y);
            dp = (dp << x) | (dp << y);
        }
        if(dp[m])cout << "Yes" << endl;
        else cout << "No" << endl;


    }
    return 0;
}
