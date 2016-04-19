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
bool vis[10];
int main()
{
    ios::sync_with_stdio(false);
    freopen("Alarge.in","r",stdin);
    freopen("Alarge.out","w",stdout);
    int t;
    int cas =1;
    cin >> t;
    while(t--){
        clr(vis,0);
        ll n;
        cin >> n ;
        cout << "Case #" << cas ++ << ": ";
        if(!n){
            cout << "INSOMNIA" <<endl;
            continue;
        }
        ll now = n;
        bool ok = false;
        rep2(i,2,1000000){
            ll tmp = now ;
            while(tmp){
                vis[tmp%10] = 1;
                tmp /= 10;
            }
            ok = true;
            rep(j,10)ok &= vis[j];
            if(ok)break;
            now = i * n;

        }
        if(ok)cout << now << endl;
        else cout << "INSOMNIA" <<endl;
        //cout << str << endl;

    }
    return 0;
}

