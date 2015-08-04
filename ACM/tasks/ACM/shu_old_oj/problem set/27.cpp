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
const int N=100010;
char a[N];
int b[1010];
int c[1010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	int T,cas=1;
	int i,j;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		CLR(b,0);
		CLR(a,0);
		CLR(c,0);
		cin.getline(a,N,'\n');
		while(strlen(a)==0)
		{
			cin.getline(a,N,'\n');
		}
		istrstream ss(a,N);
		i=0;
		while(ss>>c[i]) i++;
		for(j=i-1;j>=0;j--)b[i-1-j]=c[j];
		cout<<"Case "<<cas++<<":"<<endl;
		cout<<"Before sorting:"<<endl;
		for(j=0;j<i;j++)
		{
			if(j%10==9)cout<<" "<<b[j]<<endl;
			else if(j%10==0)cout<<b[j];
			else cout<<" "<<b[j];
		}
		if(j%10!=0)
		cout<<endl;
		sort(b,b+i,cmp);
		cout<<"After sorting:"<<endl;
	//	cout<<b[0];
		for(j=0;j<i;j++)
		{
			if(j%10==9)cout<<" "<<b[j]<<endl;
			else if(j%10==0)cout<<b[j];
			else cout<<" "<<b[j];
		}
		if(j%10!=0)
		cout<<endl;
	}
	
	return 0;
}


