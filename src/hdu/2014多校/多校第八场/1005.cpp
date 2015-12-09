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
const int MAXN = 300;
//有equ个方程，var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int equ,var;
int a[MAXN][MAXN]; //增广矩阵
int x[MAXN]; //解集
int free_x[MAXN];//用来存储自由变元（多解枚举自由变元可以使用）
int free_num;//自由变元的个数

//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss()
{
    int max_r,col,k;
    free_num = 0;
    for(k = 0, col = 0 ; k < equ*2 && col < var ; k++, col++)
    {
        max_r = k;
        for(int i = k+1;i < equ*2;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;//这个是自由变元
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1;i < equ;i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col;j < var+1;j++)
                    a[i][j] ^= a[k][j];
            }
        }
    }
    for(int i = k;i < equ;i++)
        if(a[i][col] != 0)
            return -1;//无解
    if(k < var) return var-k;//自由变元个数
    //唯一解，回代
    for(int i = var-1; i >= 0;i--)
    {
        x[i] = a[i][var];
        for(int j = i+1;j < var;j++)
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}
int n,m;
void init()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    equ = n*m;
    var = n*m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            int t = i*n+j;
            a[t][t] = 1;
            if(i > 0)a[(i-1)*m+j][t] = 1;
            if(i < n-1)a[(i+1)*m+j][t] = 1;
            if(j > 0)a[i*m+j-1][t] = 1;
            if(j < m-1)a[i*m+j+1][t] = 1;
            a[t+equ][t] = 0;
            if(i > 0)a[(i-1)*m+j+equ][t] = 1;
            if(i < n-1)a[(i+1)*m+j+equ][t] = 1;
            if(j > 0)a[i*m+j-1+equ][t] = 1;
            if(j < m-1)a[i*m+j+1+equ][t] = 1;
            
        }
}
void solve()
{
    int t = Gauss();
    if(t == -1)
    {
        printf("inf\n");
        return;
    }
    else if(t == 0)
    {
        int ans = 0;
        for(int i = 0;i < n*n;i++)
            ans += x[i];
        printf("%d\n",ans);
        return;
    }
    else
    {
        //枚举自由变元
        int ans = 0x3f3f3f3f;
        int tot = (1<<t);
        for(int i = 0;i < tot;i++)
        {
            int cnt = 0;
            for(int j = 0;j < t;j++)
            {
                if(i&(1<<j))
                {
                    x[free_x[j]] = 1;
                    cnt++;
                }
                else x[free_x[j]] = 0;
            }
            for(int j = var-t-1;j >= 0;j--)
            {
                int idx;
                for(idx = j;idx < var;idx++)
                    if(a[j][idx])
                        break;
                x[idx] = a[j][var];
                for(int l = idx+1;l < var;l++)
                    if(a[j][l])
                        x[idx] ^= x[l];
                cnt += x[idx];
            }
            ans = min(ans,cnt);
        }
        printf("%d\n",ans);
    }
}

int main()
{
	ios::sync_with_stdio(false);

	while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&a[i*m+j][m*n]);
				a[i*m+j+m*n][m*n]=a[i*m+j][m*n];
			}
		}
		solve();
	}
		
			
			
	
	return 0;
}


