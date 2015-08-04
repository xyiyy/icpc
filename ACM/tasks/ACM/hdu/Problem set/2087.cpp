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
int next[2010];
int main()
{
	ios::sync_with_stdio(false);
	string s1,s2;
	while(cin>>s1)
	{
		if(s1=="#")break;
		cin>>s2;
		next[0]=-1;
		int j=0,k=-1;
		int len2=s2.length();
		while(j<len2-1)
		{
			if(k==-1||s2[j]==s2[k])
			{
				j++;
				k++;
				next[j]=k;
			}
			else 
			{
				k=next[k];
			}
		}
		int i=0;
		j=0;
		int num=0;
		int len=s1.length();
		while(i<len)
		{
			if(j==-1||s1[i]==s2[j])
			{
				i++;
				j++;
			}
			else 
			{
				j=next[j];
			}
			if(j==len2)
			{
				num++;
				j=0;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}



