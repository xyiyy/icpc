//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define X first
#define Y second
int n,m;
bool check(int *x,int *y){
	int t1 = 0;
	int t2 = 0;
	REP(i,n)t1 = max(t1,x[i]);
	REP(i,m)t2 = max(t2,y[i]);
	if(t1>=t2)return 1;
	return 0;
}
int a[100010],b[100010],c[100010],d[100010];
PII p[100010];
PII ch[100010];
PII poly[100010];
int tot = 0;
PII Sub(PII A,PII B){
	return MP(A.X-B.X,A.Y-B.Y);
}
ll Cross(PII A,PII B){
	return (ll)A.X*B.Y-(ll)A.Y*B.X;	
}
ll Dot(PII A,PII B){
	return (ll)A.X*B.X + (ll)A.Y*B.Y;
}
bool isonseg(PII tmp,PII a1,PII a2){
	return Cross(Sub(a1,tmp),Sub(a2,tmp))==0 && Dot(Sub(a1,tmp),Sub(a2,tmp))<0;
}
int gao(PII tmp){
	int t = lower_bound(poly+1,poly+tot-1,tmp)-poly;
	if(t<tot-2){
	if(Cross(Sub(poly[t],poly[t+1]),Sub(tmp,poly[t]))<=0)return 1;//||isonseg(tmp,poly[t],poly[t-1]))return 1;
	else return 0;
	}
	
	int wn = 0;
	REP(i,tot){
		if(isonseg(tmp,ch[i],ch[(i+1)%tot]))return 1;
		ll k = Cross(Sub(ch[(i+1)%tot],ch[i]),Sub(tmp,ch[i]));
		int d1 = ch[i].Y-tmp.Y;
		int d2 = ch[(i+1)%tot].Y-tmp.Y;
		if(k>0&&d1<=0&&d2>0)wn++;
		if(k<0&&d2<=0&&d1>0)wn--;
	}
	if(wn!=0)return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	REP(i,n)cin>>a[i]>>b[i];
	REP(i,m)cin>>c[i]>>d[i];	
//	cout<<"ok"<<endl;
	int tmp1 = 0;
	REP(i,n)tmp1 = max(a[i]+b[i],tmp1);
	int tmp2 = 0;
	REP(i,m)tmp2 = max(c[i]+d[i],tmp2);
	if(tmp1>=tmp2||check(a,c)||check(b,d)){
		cout<<"Max"<<endl;
		return 0;
	}
	int mc = 0,md = 0;
	REP(i,m)mc = max(c[i],mc);
	REP(i,m)md = max(md,d[i]);
	REP(i,m)p[i] = MP(c[i],d[i]);
	p[m++] = MP(0,0);
	p[m++] = MP(mc,0);
	p[m++] = MP(0,md);
	sort(p,p+m);
	tot = 0;
	REP(i,m){
		while(tot>1&&Cross(Sub(ch[tot-1],ch[tot-2]),Sub(p[i],ch[tot-1]))<=0)tot--;
		ch[tot++] = p[i];
	}
	int k = tot;
	for(int i=m-2;i>=0;i--){
		while(tot>k&&Cross(Sub(ch[tot-1],ch[tot-2]),Sub(p[i],ch[tot-1]))<=0)tot--;
		ch[tot++] = p[i];
	}
	if(m>1)tot--;
	REP(i,tot)poly[i] = ch[i];
	reverse(poly+1,poly+tot);
	REP(i,n){
		if(gao(MP(a[i],b[i]))){
			cout<<"Max"<<endl;
			return 0;
		}
	}
	cout<<"Min"<<endl;
	return 0;
}



