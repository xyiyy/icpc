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
char b[110];
int main()
{
	ios::sync_with_stdio(false);
    ll a;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&a);
        int s1,s2;
        scanf("%d%d",&s1,&s2);
        ll tmp = a;
        int tot = 0;
        int num = 0;
        while(tmp){
            b[tot] = (tmp&1) + '0';
            tmp>>=1;
            if(b[tot]=='1')num++;
            tot++;
        }


    }
	return 0;
}


