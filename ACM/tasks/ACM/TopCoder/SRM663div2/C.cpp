//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
pair<int,int>b[50010]; 
int a[110][110];
int vis[110];
int n;
int b8[20010][21];
int c4[20];
ll pan[20];
ll pan8[20];
ll gao[20];
int c0[10];
int c1[10];
void bfs(int *c){
	sort(c,c+4);
	int win1,win2;
	int win;
	do{
		
		if(a[c[0]][c[1]])win1 = c[0];
		else win1 = c[1];
		if(a[c[2]][c[3]])win2 = c[2];
		else win2 = c[3];
		if(a[win1][win2])win = win1;
		else win = win2;
		pan[win]++;
	}while(next_permutation(c,c+4));
}
void dfs(int r,int x,int num,int f){
	int st = 8*f + 8;
	if(num==4){
		num = 0;
		for(int i=8*f;i<st;i++){
			if(!vis[i])c1[num++] = i;  
		}
		//CLR(gao,0);
		CLR(pan,0);
		bfs(c0);
		bfs(c1);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				ll tmp = pan[c0[i]]*pan[c0[j]];
				if(a[c0[i]][c1[j]])pan8[c0[i]]+=tmp;
				else pan8[c1[j]]+=tmp;
			}
		}
	}
	for(int i = x;i<st;i++){
		dfs(r,x+1,num,f);
		vis[x] = 1;
		c0[num] = b8[r][i];
		dfs(r,x+1,num+1,f);
		vis[x] = 0;
	}
}
		
	int p[110];
	int pp[110];
class CheeseRolling{
	public:
		vector<long long> waysToWin(vector <string> wins){
			n = wins[0].size();
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(wins[i][j]=='Y')a[i][j]=1;
					else a[i][j] = 0;
				}
			}
			if(n!=16){
				for(int i=0;i<n;i++){
					p[i] = i;
				}
				do{
					int len = n;
					for(int i=0;i<n;i++){
						pp[i] = p[i];
					}
					while(len!=1){
						for(int i=0,j=0;i<len;i+=2,j++){
							if(a[pp[i]][pp[i+1]])pp[j]=pp[i];
							else pp[j] = p[i+1];
						}
						len/=2;
					}
					gao[pp[0]]++;
				}while(next_permutation(p,p+n));
				vector<ll>ans;
				for(int i=0;i<n;i++)ans.PB(gao[i]);
				return ans;
			}
			int tot = 1<<n;
			int num1,num2;
			int t =0;
			for(int i=0;i<tot;i++){
				if(__builtin_popcount(i)==n/2){
					num1 = i;
					num2 = ((tot-1)^num1);
					if(num1>num2)swap(num1,num2);
					b[t++] = MP(num1,num2);
				}
			}
			sort(b,b+t);
			t = unique(b,b+t)-b;
			for(int i=0;i<t;i++){
				int x = b[i].first;
				int num = 0;
				for(int j=0;j<n;j++){
					if(x&(1<<j)){
						b8[i][num++] = j;
					}
				}
				x = b[i].second;
				for(int j=0;j<n;j++){
					if(x&(1<<j)){
						b8[i][num++] = j;
					}
				}
			}
			for(int i=0;i<t;i++){
				CLR(pan8,0);
				dfs(i,0,0,0);
				dfs(i,8,0,1);
				for(int j=0;j<8;j++){
					for(int k=8;k<16;k++){
						ll tmp = pan8[b8[i][j]]*pan8[b8[i][k]];
						if(a[b8[i][j]][b8[i][k]])gao[b8[i][j]]=gao[b8[i][j]] + tmp;
						else gao[b8[i][k]]=gao[b8[i][k]] + tmp;
					}
				}
			}
			vector<ll>ans;
			for(int i=0;i<16;i++)ans.PB(gao[i]);
			return ans;
		}
			
};
int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



