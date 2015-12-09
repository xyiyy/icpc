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
#define test printf("ok\n")
const int maxn=1010;
int n;
const int MOD=6;
template <typename T>
class Matrix{
	//private:
		
	public:
		T *m;
		int r, c;
		Matrix(int _r, int _c)
		{
			r = max(_r, 1);
			c = max(_c, 1);
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = i%c==i ? 1:0;
		}
		Matrix(T* a, int _r, int _c)
		{
			r = max(_r, 1);
			c = max(_c, 1);
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = a[i];
		}
		Matrix(const Matrix& mat)
		{
			r = mat.r;
			c = mat.c;
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = mat.m[i];
		}
		~Matrix()
		{
			delete[] m;
		}
		T* operator[](int n)
		{
			return m+c*n;
		}
		Matrix& operator+=(const Matrix& mat)
		{
			if(r == mat.r && c == mat.c)
			{
				for(int i = 0; i < r*c; i++)
					m[i] += mat.m[i];
			}
			return *this;
		}
		Matrix& operator-=(const Matrix& mat)
		{
			if(r == mat.r && c == mat.c)
			{
				for(int i = 0; i < r*c; i++)
					m[i] -= mat.m[i];
			}
			return *this;
		}
		Matrix& operator*=(const Matrix& mat)
		{
			if(c == mat.r)
			{
				T* tmp = new T[r*mat.c];
				for(int i = 0; i < r; i++)
				for(int j = 0; j < mat.c; j++)
				{
					tmp[i*mat.c+j] = 0;
					for(int k = 0; k < c; k++)
					{
						tmp[i*mat.c+j] += m[i*c+k] * mat.m[k*mat.c+j];
						tmp[i*mat.c+j]%=6;
					}
				}
				delete[] m;
				m=tmp;
				c=mat.c;
			}
			return *this;
		}
		Matrix& operator*=(T n)
		{
			for(int i = 0; i < c; i++)
			for(int j = 0; j < r; j++)
				m[i][j] *= n;
		}
		Matrix& operator/=(T n)
		{
			for(int i = 0; i < c; i++)
			for(int j = 0; j < r; j++)
				m[i][j] /= n;
		}
		Matrix operator*(T n)
		{
			Matrix t(*this);
			t*=n;
			return t;
		}
		Matrix operator*(const Matrix& mat)
		{
			Matrix t(*this);
			t*=mat;
			return t;
		}
		Matrix operator/(T n)
		{
			Matrix t(*this);
			t/=n;
			return t;
		}
		Matrix operator+(const Matrix& mat)
		{
			Matrix t(*this);
			t+=mat;
			return t;
		}
		Matrix operator-(const Matrix& mat)
		{
			Matrix t(*this);
			t-=mat;
			return t;
		}
		Matrix& operator=(const Matrix& mat)
		{
			delete[] m;
			r = mat.r;
			c = mat.c;
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = mat.m[i];
			return *this;
		}
		Matrix operator^(long long n)
		{
			if(r == c && n > 0)
			{
				int n=r;
				Matrix ans(n,n), tmp(*this);
				while(n)
				{
					if(n&1) ans*=tmp;
					n>>1;
					tmp*=tmp;
				}
				return ans;
			}
			return *this;
		}
		void display()
		{
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
				{
					if(j) cout<<' ';
					cout<<(*this)[i][j];
				}
				cout<<endl;
			}
		}
		friend Matrix Trans(const Matrix &mat)
		{
			Matrix tmp(mat.c, mat.r);
			for(int i = 0; i < mat.r; i++)
			for(int j = 0; j < mat.c; j++)
				tmp.m[i][j] = mat.m[j][i];
			return tmp;
		}
		void swapr(int r1, int r2)
		{
			if(r1<r && r2<r && r1!=r2)
			for(int i = 0; i < c; i++)
				swap((*this)[r1][i], (*this)[r2][i]);
		}
		void addr(int r1, T n, int r2)
		{
			if(r1<r && r2<r)
			for(int i = 0; i < c; i++)
				(*this)[r2][i] += (*this)[r1][i]*n;
		}
		void mulr(int r1, T n)
		{
			if(r1<r)
			for(int i = 0; i < c; i++)
				m[r1][i] *= n;
		}
		friend int gauss(Matrix &func, vector<T>& ans)
		{
			ans.clear();
			if(func.c == func.r+1)
			{
				Matrix mat = func;
				int n=mat.r;
				for(int i = 0; i < n; i++)
				{
					int maxj = i;
					for(int j = i; j < n; j++)
					{
						if(mat[j][i] > mat[maxj][i])
							maxj = j;
					}
					mat.swapr(i, maxj);
					if(fabs(mat[i][i]) < 1e-8) return i;
					for(int j = 0; j < n; j++) if(j!=i)
					{
						mat.addr(i, -mat[j][i]/mat[i][i], j);
					}
				}
				for(int i = 0; i < n; i++)
					ans.push_back(mat[i][n]/mat[i][i]);
				mat.display();
				return n;
			}
			return -1;
		}
};
typedef Matrix<int> MAT;
int main()
{
	int k;
	while(scanf("%d%d",&n,&k)!=EOF&&(n||k))
	{
		MAT Mat1(n,k);
		MAT Mat2(k,n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&Mat1[i][j]);
			}
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&Mat2[i][j]);
			}
		}
		int mm=n*n-1;
		MAT temp(k,k);
		temp=Mat2*Mat1;
		MAT temp2(k,k);
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				temp2[i][j]=(i==j);
			}
		}
		while(mm)
		{
			if(mm&1)temp2=temp*temp2;
			temp=temp*temp;
			mm>>=1;
		}
		Mat1=Mat1*temp2;
		MAT ans(n,n);
		ans=Mat1*Mat2;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				sum+=(ans[i][j]%6);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}


