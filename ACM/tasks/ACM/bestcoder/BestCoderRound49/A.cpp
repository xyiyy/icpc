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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
int b[110];
int main()
{
    ios::sync_with_stdio(false);
int t;
		cin>>t;
		while(t--){
			int n,a;
			cin>>n>>a;
			rep(i,n)cin>>b[i];
			sort(b,b+n);
			reverse(b,b+n);
			int ans = INF;
			int tot = (1<<n);
			rep(i,tot){
				int tmp = a;
				int num =0;
				rep(j,n){
					if((1<<j)&i)tmp=tmp%b[j],num++;
				}
				if(!tmp)
				ans = min(num,ans);
			}
			if(ans==INF)ans= -1;
			cout<<ans<<endl;
		}
    return 0;
}
