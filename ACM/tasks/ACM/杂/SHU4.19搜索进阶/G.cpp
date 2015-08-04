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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int k,m,n;
struct node 
{
	int cur;
	int pre;
	char sign;
	int step;
}N[1010];
bool vis[1010];
char s[1010];
inline int mod(int a,int b)
{
	a%=b;
	return a<0?a+b:a;
}

void output(int rear)
{
	int pos=rear;
	for(int i=N[rear].step-1;i>=0;i--,pos=N[pos].pre)
	{
		s[i]=N[pos].sign;
		
	}
	cout<<N[rear].step<<endl;
	cout<<s<<endl;
}
void bfs()
{
	int ini=mod(n+1,k);
	int front=0,rear=0;
	N[front].pre=-1;
	N[front].step=0;
	N[front].cur=n;
	vis[mod(n,k)]=1;
	bool flag;
	++rear;
	flag=false;
	while(front<rear)
	{
		int res;
		res=N[front].cur+m;
		res=mod(res,k);
		if(vis[res]==false)
		{
			vis[res]=true;
			N[rear].cur=res;
			N[rear].step=N[front].step+1;
			N[rear].pre=front;
			N[rear].sign='+';
			if(res==ini)
			{
				output(rear);
				flag=true;
			}
			++rear;
		}
		res=N[front].cur-m;
		res=mod(res,k);
		if(vis[res]==false)
		{
			vis[res]=true;
			N[rear].cur=res;
			N[rear].step=N[front].step+1;
			N[rear].pre=front;
			N[rear].sign='-';
			if(res==ini)
			{
				output(rear);
				flag=true;
			}
			++rear;
		}
		res=N[front].cur*m;
		res=mod(res,k);
		if(vis[res]==false)
		{
			vis[res]=true;
			N[rear].cur=res;
			N[rear].step=N[front].step+1;
			N[rear].pre=front;
			N[rear].sign='*';
			if(res==ini)
			{
				output(rear);
				flag=true;
			}
			++rear;
		}
		if(front==0||front==3)
		{
			res=mod(N[front].cur,m);
			res=mod(res,k);
			if(front==3)
			{
				res=0;
			}
			if(vis[res]==false)
			{
				vis[res]=true;
				N[rear].cur=res;
				N[rear].step=N[front].step+1;
				N[rear].pre=front;
				N[rear].sign='%';
				if(res==ini)
				{
					output(rear);
					flag=true;
				}
				++rear;
			}
		}
		if(flag)break;
		++front;
	}
	if(!flag)
	cout<<"0"<<endl;
}
	

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>k>>m&&(n||m||k))
	{
		memset(vis,0,sizeof(vis));
		memset(s,'\0',sizeof(s));
		bfs();
	}
		
		
	return 0;
}

