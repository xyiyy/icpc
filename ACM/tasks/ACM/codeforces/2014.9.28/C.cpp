//gaoshenbaoyou  ------ pass system test
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
string s[100010][2];
int a[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		string temp;
		for(int i=0;i<n;i++)
		{
			cin>>s[i][0]>>s[i][1];
		}
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			a[i]--;
		}
		int j=1;
		if(s[a[0]][0]<s[a[0]][1])temp=s[a[0]][0];
		else temp=s[a[0]][1];
		string t1,t2;
		bool flag=1;
		while(j<n&&flag)
		{
			if(s[a[j]][0]<s[a[j]][1])
			{
				t1=s[a[j]][0];
				t2=s[a[j]][1];
			}
			else
			{
				t1=s[a[j]][1];
				t2=s[a[j]][0];
			}
			if(t1<temp&&t2<temp)
			{
				flag=0;
				break;
			}
			else if(t1<temp&&t2>temp) 
			{
				temp=t2;
			}
			else
			{
				temp=t1;
			}
			j++;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
			
	return 0;
}



