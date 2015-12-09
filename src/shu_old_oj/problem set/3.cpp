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
int prime[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
bool vis[31];
int a[3][3];
bool p[61];
int sum;
int n;
void fun()
{
	for(int i7=0;i7<17;i7++)
	{
		if(prime[i7]<=a[1][1])continue;
		a[2][1]=prime[i7]-a[1][1];
		if(!p[a[2][1]+a[2][0]])	continue;
		if(a[2][1]>n)break;
		if(vis[a[2][1]])continue;
		vis[a[2][1]]=1;
		for(int i8=0;i8<17;i8++)
		{
			if(prime[i8]<=a[1][2])continue;
			a[2][2]=prime[i8]-a[1][2];
			if(a[2][2]>n)break;
			if(vis[a[2][2]])continue;
			if(!p[a[2][2]+a[2][1]])continue;											
			sum++;
		//	for(int j=0;j<3;j++)
		//	{
		//		for(int k=0;k<3;k++)
		//		{
		///			cout<<a[j][k]<<" ";
		//		}
		//		cout<<endl;
		//	}
		}
		vis[a[2][1]]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int cas=1;
	CLR(p,0);
	for(int i=0;i<17;i++)
	{
		p[prime[i]]=1;
	}
	while(cin>>n)
	{
		CLR(vis,0);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			a[0][0]=i;
			vis[i]=1;
			for(int i1=0;i1<17;i1++)
			{
				if(prime[i1]<=i)continue;
				a[0][1]=prime[i1]-a[0][0];
				if(vis[a[0][1]])continue;
				if(a[0][1]>n)break;
				vis[a[0][1]]=1;
				for(int i2=0;i2<17;i2++)
				{
					if(prime[i2]<=i)continue;
					a[1][0]=prime[i2]-a[0][0];
					if(vis[a[1][0]])continue;
					if(a[1][0]>n)break;
					vis[a[1][0]]=1;
					for(int i3=0;i3<17;i3++)
					{
						if(prime[i3]<=a[0][1])continue;	
						a[0][2]=prime[i3]-a[0][1];
						if(a[0][2]>n)break;
						if(vis[a[0][2]])continue;
						vis[a[0][2]]=1;
						for(int i4=0;i4<17;i4++)
						{
							if(prime[i4]<=a[0][1])continue;
							a[1][1]=prime[i4]-a[0][1];
							if(!p[a[1][1]+a[1][0]])continue;
							if(a[1][1]>n)break;
							if(vis[a[1][1]])continue;
							vis[a[1][1]]=1;
							for(int i5=0;i5<17;i5++)
							{
								if(prime[i5]<=a[1][0])continue;
								a[2][0]=prime[i5]-a[1][0];
								if(a[2][0]>n)break;
								if(vis[a[2][0]])continue;
								vis[a[2][0]]=1;
								for(int i6=0;i6<17;i6++)
								{
									if(prime[i6]<=a[0][2])continue;
									a[1][2]=prime[i6]-a[0][2];
									if(!p[a[1][2]+a[1][1]])continue;
									if(a[1][2]>n)break;
									if(vis[a[1][2]])continue;
									vis[a[1][2]]=1;
									fun();
									vis[a[1][2]]=0;
								}
								vis[a[2][0]]=0;
							}
							vis[a[1][1]]=0;
						}
						
						vis[a[0][2]]=0;
					}
					vis[a[1][0]]=0;
				}
				vis[a[0][1]]=0;
			}
			vis[a[0][0]]=0;
		}
	//	if(cas!=1)cout<<endl;
		cout<<"Case "<<cas++<<":"<<endl;
		cout<<sum<<endl;
		cout<<endl;
	}
	return 0;
}


