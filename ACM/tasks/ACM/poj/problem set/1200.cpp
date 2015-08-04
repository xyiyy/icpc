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
const int B=16000057;
char s[B];
bool a[B];
bool c[26];
map<char,int>m;
int main()
{
	ios::sync_with_stdio(false);
	int n,nc;
	while(scanf("%d%d",&n,&nc)!=EOF){
	scanf("%s",s);
	int len=strlen(s);
	int b=0;
	memset(a,0,sizeof(a));
	for(int i=0;i<len;i++)
	{
		if(c[s[i]-'a']==0)c[s[i]-'a']=1;
	}
	int t=0;
	for(int i=0;i<26;i++)
	{
		if(c[i])
		{
			m[i+'a']=t;
			t++;
		}
	}
	b=1;
	int bl=0;
	//for(int i=0;i<len;i++)cout<<m[s[i]]<<endl;
	for(int i=0;i<n;i++)b=(b*nc)%B;
	for(int i=0;i<n;i++)
	{
		bl=((bl*nc)%B+m[s[i]])%B;
	}
	a[bl]=1;
	for(int i=n;i<len;i++)
	{
		bl=((bl*nc-m[s[i-n]]*b+B)%B+m[s[i]])%B;
		a[bl]=1;
	}
	int ans=0;
	for(int i=0;i<B;i++)
	{
		if(a[i])ans++;
	}
	printf("%d\n",ans);
	}
	return 0;
}



