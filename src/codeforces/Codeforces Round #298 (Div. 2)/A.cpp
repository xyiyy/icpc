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
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n==4){
        cout<<4<<endl;
        cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;
        return 0;
	}
	int t=(n+1)/2;
	for(int i=1;i<=n;i++){
        if(i&1)a[i]=(i+1)/2;
        else a[i]=a[i-1]+t;
	}
	a[0]=INF;
	if(abs(a[n]-a[n-1])==1)n--;
	else if(a[n]>n)n--;
	cout<<n<<endl;
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}



