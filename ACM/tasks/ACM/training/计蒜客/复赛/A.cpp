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

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,x,y,z;
		cin>>a>>x>>b>>y>>c>>z;
		int hz,hf,kz,kf,wz,wf;
		int sx = 0,sy = 0,sz = 0;
		int gx = 0,gy = 0,gz = 0;
		sx = max(0,a);
		gx = max(0,x);
		hz = gx - sx;
		hf = max(x-a-hz,0);
		sy = max(0,b);
		gy = max(0,y);
		kz = gy - sy;
		kf = max(y-b-kz,0);
		sz = max(0,c);
		gz = max(0,z);
		wz = gz - sz;
		wf = max(z-c-wz,0);
		cout<<hz*kz*wz<<" "<<hf*kz*wz<<" "<<hf*kf*wz<<" "<<hz*kf*wz<<" ";
		cout<<hz*kz*wf<<" "<<hf*kz*wf<<" "<<hf*kf*wf<<" "<<hz*kf*wf<<endl;
		
	}
	return 0;
}



