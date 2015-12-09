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
int a[100010];
void gao(int l,int r,int k){
    int tmp = a[r];
    int x = l;
    int y = r;
    if(x>=y)return;
    do{
        while(x<y&&a[x]<=tmp)x++;
        while(x<y&&a[y]>=tmp)y--;
        if(x<y)swap(a[x],a[y]);
    }while(x<y);
    a[r] = a[x];
    a[x] = tmp;
    if(x==k)return;
    if(x>k)gao(l,x-1,k);
    else gao(x+1,r,k);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        //nth_element(a,a+(n-1)/2,a+n);
        gao(0,n-1,(n-1)/2);
        cout<<a[(n-1)/2]<<endl;
    }
    return 0;
}

