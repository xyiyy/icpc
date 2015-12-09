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
int matrix1[2][2],matrix[2][2]={1,1,0,0};
int matrix2[2][2],matrix3[2][2];
int a,b,n;
void fun()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			matrix2[i][j]=matrix[i][j];
			matrix3[i][j]=matrix1[i][j];
		}
	}
	if(n%2==1)
	{
		n--;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				matrix[i][j]=0;
				for(int k=0;k<2;k++)
				{
					matrix[i][j]+=matrix2[i][k]*matrix3[k][j];
				}
				matrix[i][j]%=7;
			}
		}
	}
	else {
		n/=2;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				matrix1[i][j]=0;
				for(int k=0;k<2;k++)
				{
					matrix1[i][j]+=matrix3[i][k]*matrix3[k][j];
				}
				matrix1[i][j]%=7;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	while(cin>>a>>b>>n&&(a||b||n))
	{
		a%=7;b%=7;
		matrix[0][0]=matrix[0][1]=1;
		matrix[1][0]=matrix[1][1]=0;
		matrix1[0][0]=a;
		matrix1[0][1]=1;
		matrix1[1][0]=b;
		matrix1[1][1]=0;
		n-=2;
		while(n)
		{
			fun();
		}
		cout<<matrix[0][0]%7<<endl;
	}
		
		
	return 0;
}

