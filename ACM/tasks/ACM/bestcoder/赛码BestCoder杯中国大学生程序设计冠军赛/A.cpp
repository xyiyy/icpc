
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
#define maxn 10000010
unsigned int L[maxn];
unsigned int R[maxn];
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n;
		unsigned int a,b,c,d;
		cin>>n>>L[0]>>R[0]>>a>>b>>c>>d;
		for(int i=1;i<n;++i){
			L[i]=L[i-1]*a+b;
			R[i]=R[i-1]*c+d;
		}
		for(int i=0;i<n;++i){
			if(L[i]>R[i])swap(L[i],R[i]);
		}
		if(n<3){
			cout<<"NO"<<endl;
			continue;
		}
		unsigned int ml=R[0],mr=L[0];
		int l=0,r=0;
		for(int i=0;i<n;++i){
			if(R[i]<ml){
				ml=R[i];
				l=i;
			}
			if(L[i]>mr){
				mr=L[i];
				r=i;
			}
		}
		if(l==r || R[l]>=L[r]){
			cout<<"NO"<<endl;
			continue;
		}
		bool flag=0;
		for(int i=0;i<n;++i){
			if(i!=l && i!=r && L[i]>R[l] && R[i]<L[r]){
				flag=1;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

