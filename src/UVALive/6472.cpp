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
/*
const int maxn=10;
int x,y,n;
const ll MOD=10007;
class Matrix{
	public:
		Matrix(int r,int c):row(r),col(c){}
		void Unit()
		{
			CLR(matrix,0);
		//	x=x%MOD;
		//	y=y%MOD;
			matrix[0][0]=matrix[1][0]=matrix[2][0]=matrix[2][2]=matrix[1][1]=1;
			matrix[2][1]=2;
		//	matrix[1][1]=(x*x)%MOD;
		//	matrix[1][2]=(y*y)%MOD;
		//	matrix[1][3]=(2*x*y)%MOD;
		//	matrix[3][1]=x%MOD;
		//	matrix[3][3]=y%MOD;
		}
		void Init()
		{
			CLR(matrix,0);
			REP(i,3)matrix[i][i]=1;
		}
		friend Matrix operator *(const Matrix &,const Matrix &);
		ll fast_mod();
		void show()
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<matrix[i][j]<<"  ";
				}
				cout<<endl;
			}
		}
	private:
		ll matrix [maxn][maxn];
		int row,col;
};
Matrix operator*(const Matrix&M1,const Matrix &M2)
{
	Matrix M(M1.row,M2.col);
	REP(i,M1.row)
		REP(j,M2.col)
		{
			M.matrix[i][j]=0;
			REP(k,M1.col)
			{
				M.matrix[i][j]=(M.matrix[i][j]+M1.matrix[i][k]*M2.matrix[k][j])%MOD;
			}
		}
	return M;
}
Matrix Mat(3,3);
ll Matrix::fast_mod()
{
	Matrix temp(3,3);
	temp.Unit();
	while(n)
	{
		if(n&1)
		{
			Mat=temp*Mat;
			n--;
		}
		else 
		{
			temp=temp*temp;
			n>>=1;
		}	
	}
	
	return Mat.matrix[0][0];
}*/


ll dp[100010][50];
int p,r,c;
ll C(int m, int n)
{
	if(n>=50)n=m-n;
	if(m<100010&&n<50&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<100010&&n<50)dp[m][n]=ret;
	return ret;
}
ll fast_mod(int n)
{
	ll temp=p;
	ll ans=1;
	while(n)
	{
		if(n&1)ans=ans*temp;
		temp=temp*temp;
		n>>=1;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int t,cas;
	ll ans;
	cin>>t;
	while(t--)
	{
		cin>>cas>>p>>r>>c;
		ans=(C(r,c)*fast_mod(r-c));
		cout<<cas<<" "<<ans<<endl;
		//Mat.Init();
		//Mat.fast_mod();
		//Mat.show();
	}
	return 0;
}


