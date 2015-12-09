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
char a[110];
int b[110];
int G[110][110];
int G1[110][110];
int main()
{
	ios::sync_with_stdio(false);
	int n,num,maxn=0;
	while(cin>>n)
	{
		CLR(a,'\0');
		CLR(b,0);
		num=0;
		maxn=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i]==a[j])
				{
					G[i][j]=1;
					G[j][i]=1;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(b[i]==b[j])
				{
					G1[i][j]=1;
					G1[j][i]=1;
				}
			}
		}
		for(int c=0;c<2;c++)
		{
			for(int d=0;d<2;d++)
			{
				for(int e=0;e<2;e++)
				{
					for(int f=0;f<2;f++)
					{
						for(int g=0;g<2;g++)
						{
							for(int h=0;h<2;h++)
							{
								for(int i=0;i<2;i++)
								{
									for(int j=0;j<2;j++)
									{
										for(int k=0;k<2;k++)
										{
											for(int l=0;l<2;l++)
											{
												
	}
	return 0;
}

