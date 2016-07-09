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

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans = 0;
        int maxz = min(a/2,b);
        for(int z = 0 ; z <= maxz; z++){
            int lp = max(0,z-1);
            int rp = a-2*z;
            int p = 0;
            int tp = -1;
            while(lp <= rp){
                p = (lp + rp) >> 1;
                int ly = max(p-c,0);
                int ry = p;
                ry = min(ry,b - z - p);
                ly = max(ly,(p - z)/2);
                ry = min(ry,(p+z+1)/2);
                //cout << ly <<" " << ry << " " << p << endl;
                if(ly <= ry){
                    lp = p + 1;
                    tp = p;
                }else{
                    rp = p - 1;
                }
            }
            if(tp == -1){
                continue;
            }else{
               // cout << z << " ";
                ans = max(ans,tp+z);
               // cout << ans << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
