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
//char aa[3010];
char b[6010];
int num1,num2,num3,num4;
long long num;
int dpw[6010][2010];
int dpb[6010][2010];
int numw[6010],numb[6010];


int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
	//	memset(a,'\0',sizeof(a));
	//	memset(b,'\0',sizeof(b));
		memset(dpw,0,sizeof(dpw));
		memset(dpb,0,sizeof(dpb));
		memset(numw,0,sizeof(numw));
		memset(numb,0,sizeof(numb));
		num1=0;num2=0;
		cin>>n;
	//	cout<<n;
		
		cin.ignore();
		//cout<<"ok"<<endl;
		for(int i=0;i<6010;i++)
		{
			dpw[i][0]=1;
			dpb[i][0]=1;
		}
		for(int i=0;i<2*n;i++)
		{
			 cin>>b[i];
			 //cout<<b[i]<<" ";
			 if(b[i]=='W'){num1++;numb[i]=numb[i-1];if(i==0)numw[i]=1;else numw[i]=numw[i-1]+1;}
			 if(b[i]=='B'){num2++;numw[i]=numw[i-1];if(i==0)numb[i]=1;else numb[i]=numb[i-1]+1;}
		}
		//cout<<endl;
		if(b[0]=='B'||num1!=num2)num=0;
		else 
		{
			dpw[0][1]=1;
			for(int i=0;i<2*n;i++)
			{
					int nn;
				if(b[i]=='W')
				{
					if(i==0)
					{
						continue;
					}
					else
					{
						for(int j=1;j<=i+1&&j<=numw[i]&&j<=n/2;j++)
						{
							dpw[i][j]=(dpw[i-1][j]+dpw[i-1][j-1])%1000000007;
							dpb[i][j]=dpb[i-1][j];
						}
					}
				}
				if(b[i]=='B')
				{
					for(int j=1;j<=i+1&&j<=numb[i]&&j<=n/2;j++)
					{
						dpw[i][j]=dpw[i-1][j];
						nn=numw[i]-j;
						if(nn<j)
						{
							dpb[i][j]=dpb[i-1][j];
						}
						else 
						{
							dpb[i][j]=(dpb[i-1][j]+dpb[i-1][j-1])%1000000007;
						}
					}
							
				}
					
				
			}
			num=(dpw[2*n-1][n/2]*dpb[2*n-1][n/2])%1000000007;
		}
		cout<<num<<endl;
	}
				
					
						
							
		
	return 0;
}

