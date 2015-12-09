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
int x[110];
int p[110];
int a[110];
bool cmp(int i,int j){
    return x[i]<x[j];
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>a[i];
        p[i]=i;
    }
    sort(p,p+n,cmp);
    int i=0;
    while(i<n&&x[p[i]]<0)i++;
    int l=i-1;
    int r=i;
    int d=1;
    int ans = 0;
    int m;
    while(1){
        if(d){
            if(r==n)break;
            m=r;
            r++;
        }else {
            if(l<0)break;
            m=l;
            l--;
        }
        ans+=a[p[m]];
        d^=1;
    }
    int gao=0;
    d=0;
    l=i-1;r=i;
    while(1){
        if(d){
            if(r==n)break;
            m=r;
            r++;
        }else {
            if(l<0)break;
            m=l;
            l--;
        }
        gao+=a[p[m]];
        d^=1;
    }
    cout<<max(ans,gao)<<endl;
    return 0;
}

