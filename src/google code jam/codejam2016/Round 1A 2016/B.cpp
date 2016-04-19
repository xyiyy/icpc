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
int a[2600];

int main()
{
    ios::sync_with_stdio(false);
    int t;
    freopen("Bl.in","r",stdin);
    freopen("Bl.out","w",stdout);
    cin >> t;
    int cas = 1;
    while(t--){
        int n,m;
        cin >> n;
        m = n + n - 1;
        int x;
        clr(a,0);
        rep(i,m){
            rep(i,n){
                cin >> x;
                a[x]++;
            }
        }
        cout <<"Case #" << cas ++ << ":";
        rep(i,2600){
            if(a[i]&1)cout << " " << i;
        }
        cout << endl;


    }


    return 0;
}
