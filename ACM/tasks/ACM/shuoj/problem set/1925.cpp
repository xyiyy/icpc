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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
map<int,int>ms;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas  = 1;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        int x,r,g,b;
        ms.clear();
        ms.insert(MP(0,n));
        mp.clear();
        printf("Case #%d:\n",cas++);
        for(int i=0;i<q;i++){
            scanf("%d%d%d%d",&x,&r,&g,&b);
            int c = r*256*256+g*256+b;
            if(!mp.count(x)&&mp[x]==0){
                ms[0]--;
                ms[c]++;
            }else{
                ms[mp[x]]--;
                ms[c]++;
            }
            mp[x] = c;
            printf("%d\n",ms.size());

        }
    }
    return 0;
}
