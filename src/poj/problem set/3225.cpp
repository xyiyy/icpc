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
const int maxn=(1<<16);
//char a[maxn][11];
//int lx[maxn],rx[maxn];
//int seg[maxn*3*3];
//int X[maxn*2];
//int id1[maxn*2];
//int id[maxn][2];
int num[maxn*3+(1<<18)];
//int index;
int state;//0为赋0，1为赋1，2为取反 
//bool cmp(int x,int y)
//{
//	return X[x]<X[y];
//}
void init()
{
	num[1]=0;
}
void update(int l,int r,int t=1,int L=0,int R=(1<<18)-1)
{
	if(r<L||l>R)return ;
	l=max(l,L);
	r=min(r,R);
	if(l==L&&r==R)
	{
		if(state==0)num[t]=0;
		else if(state==1)num[t]=1;
		else if(state==2)num[t]^=1;
		return ;
	}
	if(num[t]>=0)num[(t)<<1]=num[((t)<<1)|1]=num[t];
	else if(num[t]==-1)
	{
		num[(t)<<1]^=1;
		num[((t)<<1)|1]^=1;
	}
	num[t]=-2;
	int mid=(L+R)/2;
	update(l,r,(t)<<1,L,mid);
	update(l,r,((t)<<1)|1,mid+1,R);
}
int check(int x)
{
	x+=(1<<18);
	int r;
	while(x)
	{
		if(num[x]>=0)r=num[x];
		else if(num[x]==-1)r^=1;
		x>>=1;
	}
	return r;
}
void query()
{
	
	int cas=0,l=-1;
	for(int i=0;i<maxn*3;i++)
	{
		if(i!=(1<<18)&&check(i))
		{
			if(l==-1)l=i;
		}
		else {
			if(l!=-1)
			{
				if(cas)printf(" ");
				cas++;
				if(l%3==2)printf("(");
				else printf("[");
				printf("%d,%d",l/3,(i-1)/3);
				if((i-1)%3==0)printf(")");
				else printf("]");
				l=-1;
			}
		}
	}
	if(!cas)printf("empty set");
	printf("\n");
}

int main()
{
//	ios::sync_with_stdio(false);
	//int i=0,j;
	init();
	char c,cl,cr;
	int l,r;
	//while(cin>>c>>cl>>l>>cr>>r>>cr)
	while(scanf("%c %c%d,%d%c\n",&c,&cl,&l,&r,&cr)==5)
	{
		if(cl=='(')l=l*3+2;
		else l=l*3+1;
		if(cr==')')r=r*3;
		else r=3*r+1;
		//cout<<"ok1"<<endl;
		if(c=='U')
		{
			state=1;
			update(l,r);
		}
		else if(c=='I')
		{
			state=0;
			update(0,l-1);
			update(r+1,(1<<18)-1);
		}
		else if(c=='D')
		{
			state=0;
			update(l,r);
		}
		else if(c=='C')
		{
			state=0;
			update(0,l-1);
			update(r+1,(1<<18)-1);
			state=2;
			update(l,r);
		}
		else if(c=='S')
		{
			state=2;
			update(l,r);
		}
	//	cout<<"ok2"<<endl;
	}
	query();		
		
	/*
	while(scanf("%c %c%d,%d%c\n",&a[i][0],&a[i][1],&lx[i],&rx[i],&a[i][2])==5)
	{
		//cin>>a[i][1]>>lx[i]>>a[i][2]>>rx[i]>>a[i][2];
		i++;
	}
	for(j=0;j<i;j++)
	{
		id1[j]=j;
		if(a[j/2][1]=='(')X[j]=lx[j/2]*3+2;
		else if(a[j/2][1]=='[')X[j]=lx[j/2]*3+1;
		j++;
		id1[j]=j;
		if(a[j/2][2]==')')	X[j]=rx[j/2]*3+0;
		else if(a[j/2][2]==']')X[j]=rx[j/2]*3+1;
	}
	sort(id1,id1+j,cmp);
	index=1;
	int kk=0;
	id[id1[0]/2][kk]=index;
	for(int k=0;k<j;k++)
	{
		kk=id1[k]%2;
		if(X[id1[k]]==X[id1[k-1]])
		{
			id[id1[k]/2][kk]=index;
		}
		else 
		{
			index++;
			id[id1[k]/2][kk]=index;
		}
	}
	index++;
	for(int k=0;k<i;k++)
	{
		if(a[k][0]=='U')
		{
			state=1;
			update(id[k][0],id[k][1]);
		}
		else if(a[k][0]=='I')
		{
			state=0;
			update(0,id[k][0]-1);
			update(id[k][1]+1,index);
		}
		else if(a[k][0]=='D')
		{
			state=0;
			update(id[k][0],id[k][1]);
		}
		else if(a[k][0]=='C')
		{
			state=0;
			update(0,id[k][0]-1);
			update(id[k][1]+1,index);
			state=2;
			update(id[k][0],id[k][1]);
		}
		else if(a[k][0]=='S')
		{
			state=2;
			update(id[k][0],id[k][1]);
		}
	}
	for(int i=0;i<index;i++)
	{
		cout<<num[i]<<endl;
	}
//	query(0,index);
	/*if(ansl%3==0)cout<<"(";
	else if(ansl%3==1)cout<<"[";
	cout<<ansl/3;
	if(ansr%3==1)cout<<"]";
	else if(ansr%3==2)cout<<")";
	cout<<ansr/3<<endl;	*/
	return 0;
}


