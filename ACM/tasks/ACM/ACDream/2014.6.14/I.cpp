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
const double delta=1e-6;
double xx[1010],yy[1010];
const int num = 3;
double matrix[num][num + 1];   //系数矩阵，从0开始
double ans[num];               //结果数组
void exchange_col(int p1,int p2,int n)  //交换p1行和p2行的所有数据
{ double t; int i;

     for(i = 0 ; i <= n ; i++)
          t = matrix[p1][i],matrix[p1][i] = matrix[p2][i],matrix[p2][i] = t;}
bool gauss(int n)   //求解系数矩阵为n的线性方程组
{ int i,j,k;int p;double r;
     for(i = 0 ; i < n - 1 ; i++) { p = i;
          for(j = i + 1 ; j < n ; j++) {   //寻找i列最大值位置
               if(matrix[j][i] > matrix[p][i])p = j;}
          if(matrix[p][i] == 0) return false;
          if(p != i)     exchange_col(i,p,n);
          for(j = i + 1 ; j < n ; j++) {       //剩余列进行消元
               r = matrix[j][i] / matrix[i][i];
               for(k = i ; k <= n ; k++)matrix[j][k] -= r * matrix[i][k];} }
     for(i = n - 1 ; i >= 0 ; i--) {   //获得结果
          ans[i] = matrix[i][n];
          for(j=n-1;j>i;j--)ans[i]-=matrix[i][j]*ans[j];ans[i]/=matrix[i][i];}
     return true;}
int main()
{
	ios::sync_with_stdio(false);
	double x,y;
	cin>>x>>y;
	int n;
	cin>>n;
	int key=1;
	int mm=0,nn=0;
	for(int i=0;i<n;i++)
	{
		cin>>xx[i]>>yy[i];
		if(xx[i]==x&&yy[i]==y)
		{
			i--;n--;
		}
		if(xx[i]<x)
		{
			mm++;
		}else if(xx[i]>x)
		{
			nn++;
		}
	}
	if(n>1)
	for(int i=1;i<n;i++)
	{
		if(xx[i]!=xx[0]||yy[i]!=yy[0])
		{
			swap(xx[1],xx[i]);
			swap(yy[1],yy[i]);
			break;
		}
	}
		
	if(n<=1&&xx[0]!=x)
	{
		cout<<"Yes"<<endl;
	}
	else if(mm*nn!=0)
	{
		cout<<"No"<<endl;
	}
	else{
		matrix[0][0]=x*x;
		matrix[0][1]=x;
		matrix[0][2]=1.0;
		matrix[0][3]=y;
		for(int i=0;i<2;i++)
		{
			matrix[i+1][0]=xx[i]*xx[i];
			matrix[i+1][1]=xx[i];
			matrix[i+1][2]=1.0;
			matrix[i+1][3]=yy[i];
		}
		if(gauss(3))
		{
			bool flag=false;
			if(ans[0]>-delta)flag=1;
			for(int i=0;i<n;i++)
			{
				if(fabs(yy[i]-xx[i]*xx[i]*ans[0]-xx[i]*ans[1]-ans[2])>delta)flag=1;
			}
			if(flag)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	
	return 0;
}


