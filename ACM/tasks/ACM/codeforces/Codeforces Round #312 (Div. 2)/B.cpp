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
int vis[1000010];
int l[1000010];
int r[1000010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!vis[a[i]])l[a[i]]=i;
        r[a[i]]=i;
        //cout<<r[a[i]]<<endl;
        vis[a[i]]++;
    }
    int maxx = 1;
    int len =INF;
    int ansl,ansr;
    for(int i=0;i<1000010;i++){
        if(vis[i]>maxx){
            //cout<<i<<endl;
            maxx = vis[i];
            len = r[i]-l[i]+1;
             ansl=l[i]+1;
            ansr=r[i]+1;
        }
        if(vis[i]==maxx&&len>(r[i]-l[i]+1)){
            len = r[i]-l[i]+1;
            ansl=l[i]+1;
            ansr=r[i]+1;
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
    return 0;
}

