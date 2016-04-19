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
string str;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    freopen("Al.in","r",stdin);
    freopen("Al.out","w",stdout);
    int cas = 1;
    cin >> t;
    string ans;
    while(t--){
        cin >>str;
        ans = "";
        int len = str.length();
        ans = ans + str[0];
        for(int i =1;i<len;i++){
            if(str[i] < ans[0])ans = ans + str[i];
            else ans = str[i] + ans;
        }
        cout << "Case #" << cas ++ << ": ";
        cout << ans << endl;

    }
    return 0;
}

