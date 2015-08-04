
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
ll a[100];
int b[110];
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll l;
    cin>>l;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=51;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=1;i<=50;i++){
        b[i]=i;
    }
    if(l==1){
        for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
   // a[0]=0;
    while(l){
        for(int i=n;i>0;i--){
            if(a[i-1]<l||a[i]==l){
                if(i==1){
                    l--;
                    break;
                }
                swap(b[n+1-i],b[n+2-i]);
                l-=a[i]-a[i-2];
                /*if(i==1)
                l-=a[i-1]+1;
                else l-=a[i-1];*/
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;



	return 0;
}


