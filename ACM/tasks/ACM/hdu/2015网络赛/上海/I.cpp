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

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        double ax,ay,bx,by,cx,cy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        double mx = (bx+cx)/2;
        double my = (by+cy)/2;
        double a = (ax - mx)*(ax-mx)+(ay-my)*(ay-my);
        double b = (bx - mx)*(bx-mx)+(by-my)*(by-my);
        double r = (b + b*b/a);
        a = sqrt(a);
        r = sqrt(r);
        //b = sqrt(b);
        double y = b / a;
        double theta = y / r;
        theta = acos(theta);
        theta = theta * 2;
        double ans = theta * r + a;
        cout << "Case #"<<cas++<<": " << fixed << setprecision(4)<<ans<<endl;

    }

    return 0;
}

