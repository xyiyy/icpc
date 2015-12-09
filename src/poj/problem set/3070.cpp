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
int matrix[2][2],matrix1[2];
int ans[2],temp[2][2];
int  n;
const int MOD=10000;
void fast_mod()
{
	if(n>2)
	{
		n-=2;
		matrix[0][0]=matrix[0][1]=matrix[1][0]=1;
		matrix[1][1]=0;
		ans[0]=ans[1]=1;
		
		while(n)
		{
			if(n&1)
			{
				matrix1[0]=ans[0];
				matrix1[1]=ans[1];
				ans[0]=ans[1]=0;
				REP(i,2)
					REP(j,2)
						ans[i]=(ans[i]+matrix[i][j]*matrix1[j])%MOD;
				n--;		
			}
			REP(i,2)
				REP(j,2)
				{
					temp[i][j]=matrix[i][j];
					matrix[i][j]=0;
				}
			
			REP(i,2)
				REP(j,2)
					REP(k,2)
					{
						matrix[i][j]=(matrix[i][j]+temp[i][k]*temp[k][j])%MOD;
					}
			n>>=1;
		}
	}
	else if(n==1||n==2)
	{
		ans[0]=1;
	}
	else ans[0]=0;
}
						 
		
		
	
		
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n&&n>=0)
	{
		fast_mod();
		cout<<ans[0]<<endl;
	}
		
	return 0;
}


