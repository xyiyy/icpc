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
int main()
{
	ios::sync_with_stdio(false);
    int n,k,p,x,y;
    int temp =0;
    cin>>n>>k>>p>>x>>y;
    for(int i=0;i<k;i++){
        cin>>a[i];
        temp +=a[i];
    }
    sort(a,a+k);
    int m= lower_bound(a,a+k,y)-a;
    int cha = n/2;
    if(m>cha){
        cout<<"-1"<<endl;
        return 0;
    }
    int gao1=min(cha - m,n-k);
    int gao2=n-k-gao1;
    if(temp+gao1+y*gao2>x){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<gao1;i++){
        cout<<1<<" ";
    }
    for(int i=0;i<gao2;i++){
            cout<<y<<" ";
    }
    cout<<endl;
	return 0;
}



