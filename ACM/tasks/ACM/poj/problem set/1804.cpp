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
int a[10010];
int b[10010];
ll ans = 0;
void Merge(int l,int r){
    if(l<r){
        int mid = (l+r)>>1;
        Merge(l,mid);
        Merge(mid+1,r);
        int x = l;
        int y = mid + 1;
        int tot = l;
        while(x <= mid && y <= r){
            if(a[x] <= a[y]) b[tot++] = a[x++];
            else{
                ans += mid - x + 1;
                b[tot++] = a[y++];
            }
        }
        while(x<=mid)b[tot++] = a[x++];
        while(y<=r)b[tot++] = a[y++];
        for(int i=l;i<=r;i++)a[i] = b[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        int n;
        cin>>n;
        ans = 0;
        for(int i=0;i<n;i++)cin>>a[i];
        Merge(0,n-1);
        cout<<"Scenario #"<<cas++<<":"<<endl;
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}


