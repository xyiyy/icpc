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


#define lson t<<1,l,m
#define rson t<<1|1,m+1,r
int num;
int a[37]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,  
           55440,83160,110880,166320,221760,277200,332640,498960,500001};  
int b[37]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};  

char c[500005][11];
int d[500005];
struct node 
{
	int l,r,sum;
}bit[500005*4];
void build(int t,int l,int r)
{
	bit[t].l=l;
	bit[t].r=r;
	bit[t].sum=r-l+1;
	if(l==r)return ;
	int m=(l+r)/2;
	build(lson);
	build(rson);
}
int query(int s,int t)
{
	bit[t].sum--;
	if(bit[t].l==bit[t].r)
	{
		return bit[t].l;
	}
	if(s<=bit[t<<1].sum)
		return query(s,t<<1);
	return query(s-bit[t<<1].sum,t<<1|1);
}
int main()
{
//	ios::sync_with_stdio(false);
	int n,s;
	//while(cin>>n>>s)
	while(scanf("%d %d",&n,&s)==2)
	{
		int i=0,maxx=0;
		num=0;
		while(a[i]<=n)i++;
		num=a[i-1];
		build(1,1,n);
		maxx=b[i-1];
		for(i=1;i<=n;i++)
		{
			scanf("%s %d",&c[i],&d[i]);
			//cin>>c[i]>>d[i];
		}
		int id;
	//	cout<<num<<" "<<n<<endl;
		for(i=0;i<num;i++)
		{
			n--;
			id=query(s,1);
			//cout<<id<<endl; 
			if(n==0)break;
			if(d[id]>0)
				s=(s-1+d[id]-1)%n+1;
			else 
				s=((s-1+d[id])%n+n)%n+1;
		}
		printf("%s %d\n",c[id],maxx);
		//cout<<c[id]<<" "<<maxx<<endl;
	}
	return 0;
}


