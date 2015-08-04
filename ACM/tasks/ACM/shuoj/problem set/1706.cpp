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
//char a[10]="{}<>()[]";
char b[100010];
int num[10];
int main()
{
	ios::sync_with_stdio(false);
	int len,flag;
	while(cin.getline(b,100010))
	{
		flag=0;
		CLR(num,0);
		len=strlen(b);
		for(int i=0;i<len;i++)
		{
			if(b[i]=='{')num[0]++;
			else if(b[i]=='}')
				num[0]--;
			else if(b[i]=='<')num[1]++;
			else if(b[i]=='>')num[1]--;
			else if(b[i]=='(')num[2]++;
			else if(b[i]==')')num[2]--;
			else if(b[i]=='[')num[3]++;
			else if(b[i]==']')num[3]--;
			for(int i=0;i<4;i++)
			{
				if(num[i]<0)
				{
					flag=1;
					break;
				}
			}
			if(flag)break;
		}
		for(int i=0;i<4;i++)
		{
			if(num[i]!=0)flag=1;
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}


