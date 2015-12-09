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
#define MAXN 500010
int p[MAXN][26];
int fail[MAXN];
int num[MAXN];
int root;
int L ;
int newnode()
{
	REP(i,26)
		p[L][i]=-1;
	num[L++]=0;
	return L-1;
}
void init()
{
	L=0;
	root=newnode();
}
void insert(char *s)
{
	int len=strlen(s);
	int now=root;
	REP(i,len){
		if(p[now][s[i]-'a']==-1){
			p[now][s[i]-'a']=newnode();
		}
		now=p[now][s[i]-'a'];
	}
	num[now]++;
}
void build()
{
	queue<int>q;
	//q.push(root);
	fail[root]=root;
	REP(i,26){
		if(p[root][i]==-1){
			p[root][i]=root;
		}
		else
		{
			fail[p[root][i]]=root;
			q.push(p[root][i]);
		}
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		REP(i,26)
		{
			if(p[now][i]==-1)
			{
				p[now][i]=p[fail[now]][i];
			}
			else
			{
				fail[p[now][i]]=p[fail[now]][i];
				q.push(p[now][i]);
			}
		}
	}
}
char str[MAXN*2];
int query()
{
	int now=root;
	int len=strlen(str);
	int res=0;
	REP(i,len){
		now=p[now][str[i]-'a'];
		int tmp=now;
		while(tmp!=root)
		{
			res+=num[tmp];
			num[tmp]=0;
			tmp=fail[tmp];
		}
	}
	return res;
}
	
	
		
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		init();
		for(int i=0;i<n;i++)
		{
			cin>>str;
			insert(str);
		}
		build();
		cin>>str;
		cout<<query()<<endl;
	}
	return 0;
}



