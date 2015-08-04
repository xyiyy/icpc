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
int ans[500010];
omt a[500010];
int vis[500010];
int b[500010];
int main()
{
	ios::sync_with_stdio(false);
    int n,k;
    CLR(vis,-1);
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    int l =1,r=n;
    int lx=0,rx=n-1;
    for(int i=0,j=0;i<n;i++,j++){
        if(j>=k)j-=k;
        int x = r[j]%(n-i);
        if(!vis[lx]){
            if(!r[i]){
                ans[lx]=l;
                lx++;
            }
            else{
                ans[b[r[i]+lx]=r;
                b[lx+r[i]]=l;
                vis[lx+r[i]]=1;
                b[lx]=rx;
                rx--;
                r--;
            }
            l++;
        }else{

        }


    }
	return 0;
}


