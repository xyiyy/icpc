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
const int maxn=100;
int n,kk,m;
ll MOD;
class Matrix{
	public:
		Matrix(int r,int c):row(r),col(c){}
		void Init()
		{
			CLR(matrix,0);
			//x=x%MOD;
			//y=y%MOD;
			REP(i,n)
			{
				matrix[n+i][i]=matrix[n+i][n+i]=1;
			}
		}
		void Unit()
		{
			CLR(matrix,0);
			REP(i,n)matrix[i][i]=1;
			//REP(i,row)matrix[i][0]=1;
		}
		friend Matrix operator *(const Matrix &,const Matrix &);
		ll fast_mod();
	//private:
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
Matrix Mat(4,4);
ll Matrix::fast_mod()
{
	Matrix temp(4,4);
	temp.Init();
	while(n)
	{
		if(n&1)Mat=temp*Mat;
		temp=temp*temp;
		n>>=1;	
	}
	return Mat.matrix[0][0];
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>kk>>MOD)
	{
		Matrix M(2*n,n);
		M.Unit();
		Matrix temp(2*n,2*n);
		temp.Init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>temp.matrix[i][j];
			}
		}
	//	temp.Init();
		kk++;
		while(kk)
		{
			if(kk&1)M=temp*M;
			temp=temp*temp;
			kk>>=1;	
			//cout<<"ok"<<endl;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j)cout<<" ";
				int x=M.matrix[n+i][j];
				if(i==j)x=(x-1+MOD)%MOD;
				cout<<x%MOD;
			}
			cout<<endl;
		}
	}
	return 0;
}


