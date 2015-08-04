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
const int maxn=10;
int n;
ll MOD;
class Matrix{
	public:
		Matrix(int r,int c):row(r),col(c){}
		void Init()
		{
			CLR(matrix,0);
			matrix[0][1]=2;
			for(int i=0;i<row;i++)
			{
				if(i!=3)matrix[i][0]=1;
			}
			matrix[0][2]=matrix[0][4]=1;
			matrix[1][1]=matrix[2][3]=1;
			matrix[3][2]=1;
		}
		void Unit()
		{
			CLR(matrix,0);
			for(int i=0;i<row;i++)
			{
				if(i!=3)matrix[i][0]=1;
			}
			//REP(i,row)matrix[i][0]=1;
		}
		friend Matrix operator *(const Matrix &,const Matrix &);
		ll fast_mod();
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
Matrix Mat(5,1);
ll Matrix::fast_mod()
{
	Matrix temp(5,5);
	temp.Init();
	while(n)
	{
		if(n&1)	Mat=temp*Mat;
		temp=temp*temp;
		n>>=1;
	}
	return Mat.matrix[0][0];
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>MOD&&(n||MOD))
	{
		Mat.Unit();
		n--;
		cout<<Mat.fast_mod()%MOD<<endl;
	}
	return 0;
}


