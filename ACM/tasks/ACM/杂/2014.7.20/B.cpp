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
char a[10010];
int b[30];
char c[10010];
//stack<char >s;
int main()
{
	ios::sync_with_stdio(false);
	int T,len,cas=1;
	int flag=0;
	cin>>T;
	while(T--)
	{
		CLR(a,0);
		cin>>a;
		CLR(b,0);
		CLR(c,0);
		flag=1;
		len=strlen(a);
	//	while(!s.empty())s.pop();
		for(int i=0;i<len;i++)
		{
			if(flag==1||c[flag-1]!=a[i])
			{
				if(flag>1)
				{
					b[c[flag-1]-'A']++;
				}
				c[flag++]=a[i];
				b[c[flag-1]-'A']++;
			}
			else flag--;
			/*if(s.empty()||s.top()!=a[i])
			{
				s.push(a[i]);
				b[a[i]-'A']++;
			}
			else 
			{
				if(a[i]==a[i-1])
				{
					s.pop();
					flag++;
				}
				else if(flag)
				{
					b[a[i]-'A']+=flag;
					s.pop();
					flag=0;
				}
			}*/
		}
		b[a[0]-'A']--;
		cout<<"Case "<<cas++<<endl;
		for(int i=0;i<26;i++)
		{
			if(b[i])cout<<char(i+'A')<<" = "<<b[i]<<endl;
		}
	}
	return 0;
}


