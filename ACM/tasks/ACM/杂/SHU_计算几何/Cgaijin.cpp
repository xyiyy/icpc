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
#define maxx 25010
int X[maxx+maxx],Y1[maxx+maxx],Y2[maxx+maxx],id1[maxx+maxx];
int Y[maxx+maxx],X1[maxx+maxx],X2[maxx+maxx],id2[maxx+maxx];
bool cmpx(const int a,const int b)
{
	if(X[a]!=X[b])
		return X[a]<X[b];
	else
		return Y1[a]<Y1[b];
}
bool cmpy(const int a,const int b)
{
	if(Y[a]!=Y[b])
		return Y[a]<Y[b];
	else
		return X1[a]<X1[b];
}
int vis[maxx];

int main()
{
	//ios::sync_with_stdio(false);
	int N;
	while(cin>>N)
	{
	int a,b,c,d;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++)
	{
		//cin>>a>>b>>c>>d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		X[2*i]=a;
		X[2*i+1]=c;
		Y1[2*i]=Y1[2*i+1]=b;
		Y2[2*i]=Y2[2*i+1]=d;
		
		Y[2*i]=b;
		Y[2*i+1]=d;
		X1[2*i]=X1[2*i+1]=a;
		X2[2*i]=X2[2*i+1]=c;
		
		id1[2*i]=id2[2*i]=2*i;
		id1[2*i+1]=id2[2*i+1]=2*i+1;
	}
	sort(id1,id1+N+N,cmpx);
	sort(id2,id2+N+N,cmpy);
	int up,right;
	int l=-1,r=-1;

REP(i,N+N-1)
	{
		int j=id1[i];
		int k=id1[i+1];
		
		if(X[j]==X[k])
		{
			//if()
		if(l==-1)up=Y2[j];else up=Y2[l];
		//	cin>>a;
			//if(j&1) r=j; else l=j;	
			//if(k&1&&l!=-1&&Y2[l]>=Y1[k])vis[l/2]=vis[k/2]=1;
			//if(!(k&1)&&r!=-1&&Y2[r]>=Y1[k])vis[r/2]=vis[k/2]=1;
			if(up>=Y1[k])vis[l/2]=vis[k/2]=1;
			if(Y2[k]>up) l=k;
		}
		else{l=r=-1;}
	}
//	cin>>a;
l=r=-1;
	REP(i,N+N-1)
	{
		int j=id2[i],k=id2[i+1];
		if(Y[j]==Y[k])
		{
		//	if(j&1)r=j; else l=j;
			if(r==-1)right=X2[j];else right=X2[r];
			if(right>=X1[k])vis[r/2]=vis[k/2]=1;
		//	if(k&1&&l!=-1&&X2[l]>=X1[k])vis[l/2]=vis[k/2]=1;
		//	if(!(k&1)&&r!=-1&&X2[r]>=X1[k])vis[r/2]=vis[k/2]=1;
			if(X2[k]>right)r=k;
		}
		else l=r=-1;
	}
	int ans=0;
	REP(i,N)
	if(!vis[i])ans++;
	cout<<ans<<endl;}	
	return 0;
}
