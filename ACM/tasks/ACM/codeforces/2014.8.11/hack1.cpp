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
ll arr[100001];
char str1[100001],str2[100001];
const double val=(sqrt(5)+1)/2;
int main()
{
	ios::sync_with_stdio(false);
	freopen("a.in","r",stdin);
	cin>>str1;
	cin>>str2;
	int n=strlen(str1);
	int m=strlen(str2);
	reverse(str1,str1+n);
	reverse(str2,str2+m);
	while(n>0&&str1[n-1]=='0')
	{
		str1[--n]=0;
	}
	while(m>0&&str2[m-1]=='0')
	{
		str2[--m]=0;
	}
	int mx=max(n,m);
	int i;
	for(i=0;i<n;i++)
	{
		arr[i]=str1[i]-48;
	}
	for(i=0;i<mx;i++)
	{
		if(i<m)
		{
			arr[i]=arr[i]-(str2[i]-48);
		}
	}
	for(i=mx;i>1;i--)
	{
		if(arr[i]>1LL<<40)
		{
			cout<<"yes";
			cout<<">";
			return 0;
		}
		if(arr[i]<-1LL<<40)
		{
			cout<<"yes";
			cout<<"<";
			return 0;
		}
		arr[i-1]+=arr[i];
		arr[i-2]+=arr[i];
	}
	if(arr[1]==0&&arr[0]==0)
	{
		cout<<"=";
	}
	else if(arr[1]*val+arr[0]>0)
	{
		cout<<">";
	}
	else
	{
		cout<<"<";
	}
	return 0;
}


