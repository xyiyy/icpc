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
int a[10][3];
int b[10][3];
int ans[10][3];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	int x1,y1,x2,y2;
	int maxn;
	while(cin>>n>>m)
	{
		maxn=0;
		//maxx=max(n,m);
		//minn=min(n,m);
		/*	cout<<n<<" "<<m<<endl;
			cout<<0<<" "<<0<<endl;
		if(n&&m)
		{
			if((n-1)*(n-1)+m*m>=(m-1)*(m-1)+n*n&&n>1&&(n-2)*(n-2)+m*m>=(n-1)*(n-1)+(m-1)*(m-1))
			{
				cout<<n-1<<" "<<m<<endl;
				cout<<1<<" "<<0<<endl;
			}
			else if((n-1)*(n-1)+m*m>=(m-1)*(m-1)+n*n&&n==1)
			{
				cout<<n-1<<" "<<m<<endl;
				cout<<1<<" "<<0<<endl;
			}
			else if((n-1)*(n-1)+m*m>=(m-1)*(m-1)+n*n&&(n-1)*(n-1)+(m-1)*(m-1)>=(n-2)*(n-2)+(m)*(m))
			{
				cout<<n-1<<" "<<m<<endl;
				cout<<0<<" "<<1<<endl;
			}
			else if((m-1)*(m-1)+n*n>=(n-1)*(n-1)+m*m&&m==1)
			{
				cout<<n<<" "<<m-1<<endl;
				cout<<0<<" "<<1<<endl;
			}
			else if((m-1)*(m-1)+n*n>=(n-1)*(n-1)+m*m&&m>1&&(m-2)*(m-2)+n*n>=(m-1)*(m-1)+(n-1)*(n-1))
			{
				cout<<n<<" "<<m-1<<endl;
				cout<<0<<" "<<1<<endl;
			}
			else if((m-1)*(m-1)+n*n>=(n-1)*(n-1)+m*m&&(m-1)*(m-1)+(n-1)*(n-1)>=(m-2)*(m-2)+n*n)
			{
				cout<<n<<" "<<m-1<<endl;
				cout<<1<<" "<<0<<endl;
			}
		
		}
		else if(n==0)
		{
			cout<<0<<" "<<m-1<<endl;
			cout<<0<<" "<<1<<endl;
		}
		else 
		{
			cout<<n-1<<" "<<0<<endl;
			cout<<1<<" "<<0<<endl;
		}*/
		if(n==0)
		{
			a[0][0]=0;
			a[0][1]=0;
			a[1][0]=0;
			a[1][1]=1;
			//a[2][0]=1;
			//a[2][1]=0;
			b[0][0]=n;
			b[0][1]=m;
		//	b[1][0]=n-1;
		//	b[1][1]=m;
			b[1][0]=n;
			b[1][1]=m-1;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					for(int k=0;k<2;k++)
					{
						for(int l=0;l<2;l++)
						{
							if(i==k)continue;
							if(j==l)continue;
							if((a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1])>maxn)
							{
								ans[0][0]=a[i][0];
								ans[0][1]=a[i][1];
								ans[1][0]=b[j][0];
								ans[1][1]=b[j][1];
								ans[2][0]=a[k][0];
								ans[2][1]=a[k][1];
								ans[3][0]=b[l][0];
								ans[3][1]=b[l][1];
								maxn=(a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1]);
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
			}
		}
		else if(m==0)
		{
			a[0][0]=0;
			a[0][1]=0;
			//a[1][0]=0;
			//a[1][1]=1;
			a[1][0]=1;
			a[1][1]=0;
			b[0][0]=n;
			b[0][1]=m;
			b[1][0]=n-1;
			b[1][1]=m;
		//	b[2][0]=n;
		//	b[2][1]=m-1;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					for(int k=0;k<2;k++)
					{
						for(int l=0;l<2;l++)
						{
							if(i==k)continue;
							if(j==l)continue;
							if((a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1])>maxn)
							{
								ans[0][0]=a[i][0];
								ans[0][1]=a[i][1];
								ans[1][0]=b[j][0];
								ans[1][1]=b[j][1];
								ans[2][0]=a[k][0];
								ans[2][1]=a[k][1];
								ans[3][0]=b[l][0];
								ans[3][1]=b[l][1];
								maxn=(a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1]);
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
			}
		}
		else if(m==1&&n==1)
		{
			cout<<1<<" "<<1<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<1<<" "<<0<<endl;
			cout<<0<<" "<<1<<endl;
		}
		else if(m==1)
		{
			cout<<n<<" "<<m<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<1<<endl;
		}
		else if(n==1)
		{
			cout<<n<<" "<<m<<endl;
			cout<<0<<" "<<0<<endl;
			
			cout<<0<<" "<<m<<endl;
			cout<<1<<" "<<0<<endl;
		}
		else
		{
			a[0][0]=0;
			a[0][1]=0;
			a[1][0]=0;
			a[1][1]=1;
			a[2][0]=1;
			a[2][1]=0;
			b[0][0]=n;
			b[0][1]=m;
			b[1][0]=n-1;
			b[1][1]=m;
			b[2][0]=n;
			b[2][1]=m-1;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int k=0;k<3;k++)
					{
						for(int l=0;l<3;l++)
						{
							if(i==k)continue;
							if(j==l)continue;
							if((a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1])>maxn)
							{
								ans[0][0]=a[i][0];
								ans[0][1]=a[i][1];
								ans[1][0]=b[j][0];
								ans[1][1]=b[j][1];
								ans[2][0]=a[k][0];
								ans[2][1]=a[k][1];
								ans[3][0]=b[l][0];
								ans[3][1]=b[l][1];
								maxn=(a[i][0]-b[j][0])*(a[i][0]-b[j][0])+(a[i][1]-b[j][1])*(a[i][1]-b[j][1])+(b[j][0]-a[k][0])*(b[j][0]-a[k][0])+(b[j][1]-a[k][1])*(b[j][1]-a[k][1])+(a[k][0]-b[l][0])*(a[k][0]-b[l][0])+(a[k][1]-b[l][1])*(a[k][1]-b[l][1]);
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
			}
		}
	}
	return 0;
}


