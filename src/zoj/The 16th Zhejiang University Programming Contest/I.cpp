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
int a[100010];
int b[100010];
bool ok(int x){
    if(x % 400 == 0 || (x % 100 !=0 && x % 4 == 0))return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    int n= 0 ;
    rep2(i,1,INF){
        a[i] = (i + 1) * i / 2;
        if(a[i] > 990528){
            n = i;
            break;
        }
    }
    int m;
    rep2(i,1,INF){
        b[i] = i * (2 * i - 1);
        if(b[i] > 990528){
            m = i;
            break;
        }
    }
    rep2(i,2016,990528){
        if(ok(i)){
            int x = *lower_bound(a+1,a+n,i);
            int y = *lower_bound(b+1,b+n,i);
            if(x == y && x == i){
                printf("%d\n",x);
            }
        }
    }
    return 0;
}

