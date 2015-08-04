#include <iostream>
#include <sstream>
#include <strstream>
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
const int N=10010;
char a[N];
int ans[N];
int x[N],y[N];
int main()
{
	ios::sync_with_stdio(false);
	int k=1,num1,num2,i,j,index;
	while(cin.getline(a,N,'\n'))
	{
		istrstream ss(a,N);
		num1=0;
		while(ss>>x[num1])num1++;
		CLR(a,'\0');
		cin.getline(a,N,'\n');
		num2=0;
		istrstream s(a,N);
		while(s>>y[num2])num2++;
		CLR(a,'\0');
	//	sort(x,x+num1);
	//	sort(y,y+num2);
		i=0;j=0;index=0;
		while(i+j<num1+num2)
		{
			if(i==num1)ans[index++]=y[j++];
			else if(j==num2)ans[index++]=x[i++];
			else if(x[i]<=y[j])ans[index++]=x[i++];
			else if(x[i]>y[j])ans[index++]=y[j++];
		}
		cout<<"Case "<<k++<<":";
		for(int id=0;id<index;id++)
		{
			cout<<" "<<ans[id];
		}
		cout<<endl;
		CLR(x,0);
		CLR(y,0);
		CLR(ans,0);
	}
	
		
			
	return 0;
}

