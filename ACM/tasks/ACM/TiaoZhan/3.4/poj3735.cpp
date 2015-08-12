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

const int maxn=110;
int n;
//const ll MOD=10007;
class Matrix{
	public:
		Matrix(int r,int c):row(r),col(c){}
		void Init()
		{
			CLR(matrix,0);
			matrix[0][0]=1;
		}
		void Unit()
		{
			CLR(matrix,0);
			REP(i,row)matrix[i][i]=1;
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
	CLR(M.matrix,0);
	REP(i,M1.row)
		REP(k,M1.col)
		{
			if(M1.matrix[i][k])
			{
				REP(j,M2.col)
				{
					M.matrix[i][j]+=M1.matrix[i][k]*M2.matrix[k][j];//%MOD;
				}
			}
		}	
	return M;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF&&(n||m||k))
	{
		Matrix temp(n+1,n+1);
		Matrix Mat(n+1,1);
		Mat.Init();
		char a[10];
		int x,y;
		temp.Unit();
		for(int i=0;i<k;i++)
		{
			scanf("%s",a);
			if(a[0]=='g')
			{
				scanf("%d",&x);
				temp.matrix[x][0]++;
			}
			else if(a[0]=='e')
			{
				scanf("%d",&x);
				for(int j=0;j<=n;j++)
				{
					temp.matrix[x][j]=0;
				}
			}
			else
			{
				scanf("%d%d",&x,&y);
				for(int j=0;j<=n;j++)
				{
					swap(temp.matrix[x][j],temp.matrix[y][j]);
				}
			}
		}
		//temp.Init();
		while(m)
		{
			if(m&1)Mat=temp*Mat;
			temp=temp*temp;
			m>>=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(i>1)printf(" ");
			printf("%lld",Mat.matrix[i][0]);
		}
		printf("\n");
	}
	return 0;
}


