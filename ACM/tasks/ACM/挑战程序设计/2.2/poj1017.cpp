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
int box[7];
int a[4]={0,5,3,1};
int b[4]={0,7,6,5};
int main()
{
	ios::sync_with_stdio(false);
	int maxn=0;
	while(cin>>box[1])
	{
		maxn=box[1];
		for(int i=2;i<7;i++)
		{
			cin>>box[i];
			maxn=max(box[i],maxn);
		}
		if(maxn==0)break;
		ll sum;
		sum=box[6]+box[5]+box[4]+(box[3]+3)/4;
		int n1,n2;
		int k=0;
		n1=5*box[4]+a[box[3]%4];
		if(n1<box[2])
		{
			sum+=(box[2]-n1+8)/9;
			k=(box[2]-n1)%9;
			//n2=11*box[5]+b[box[3]%4]+(9-k)*4;
		}
		n2=36*sum-(36*box[6]+25*box[5]+16*box[4]+9*box[3]+4*box[2]);
		if(n2<box[1])
		{
			sum+=(box[1]-n2+35)/36;
		}
		cout<<sum<<endl;
	}
		
	return 0;
}


