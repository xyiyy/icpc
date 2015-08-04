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
int a[100010*3];
int num[100010*3];
int id[100010*3];
int sz[100010*3];
int main()
{
	ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int len=1;
    while(len<n)len<<=1;
    for(int i=0;i<n;i++){
        cin>>a[len+i];
        num[len+i]=1;
        id[len+i]=len+i;
        sz[len+i]=1;
    }
    for(int i=len-1;i>0;i--){
        int lx = i<<1,rx=i<<1|1;
        sz[i]=sz[lx]+sz[rx];
        if(num[lx]*a[lx]>num[rx]*a[rx]){
            a[i] = a[lx];
            num[i]=1;
            id[i]=id[lx];
        }else if(num[lx]*a[lx]<num[rx]*a[rx]){
            a[i] = a[rx];
            num[i]=1;
            id[i]=id[rx];
        }else{
            num[i]=0;
        }

    }
    while(k){
        int lx = min(sz[1],k);
        if()
    }


	return 0;
}


