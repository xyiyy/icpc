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
///*******************************
//最大权匹配
//km
///#################################
//w表示带权图
//pop表示图一侧的点数
//x,y为两侧的点标
//son_y表示结果的匹配方案
const int maxn = 20;
int w[maxn][maxn],x[maxn],y[maxn];
int prev_x[maxn],prev_y[maxn],son_y[maxn],slack[maxn],par[maxn];
int lx,ly,pop;
void adjust(int v){
	son_y[v]=prev_y[v];
	if(prev_x[son_y[v]]!=-2)
		adjust(prev_x[son_y[v]]);
}
bool find(int v){
	for(int i=0;i<pop;i++){
		if(prev_y[i]==-1){
			if(slack[i]>x[v]+y[i]-w[v][i]){
				slack[i]=x[v]+y[i]-w[v][i];
				par[i]=v;
			}
			if(x[v]+y[i]==w[v][i]){
				prev_y[i]=v;
				if(son_y[i]==-1){
					adjust(i);
					return true;
				}
				if(prev_x[son_y[i]]!=-1)continue;
				prev_x[son_y[i]]=i;
				if(find(son_y[i]))return true;
			}
		}
	}
	return false;
}
int km(){
	for(int i=0;i<pop;i++){
		son_y[i]=-1;
		y[i]=0;
	}
	for(int i=0;i<pop;i++){
		x[i]=0;
		for(int j=0;j<pop;j++)
			x[i]=max(x[i],w[i][j]);
	}
	bool flag;
	for(int i=0;i<pop;i++){
		for(int j=0;j<pop;j++){
			prev_x[j]=prev_y[j]=-1;
			slack[j]=INF;
		}
		prev_x[i]=-2;
		if(find(i))continue;
		flag = false;
		while(!flag){
			int m = INF;
			for(int j=0;j<pop;j++)
				if(prev_y[j]==-1)m=min(m,slack[j]);
			for(int j=0;j<pop;j++){
				if(prev_x[j]!=-1)x[j]-=m;
				if(prev_y[j]!=-1)y[j]+=m;
				else slack[j]-=m;
			}
			for(int j=0;j<pop;j++)
				if(prev_y[j]==-1&&!slack[j]){
					prev_y[j]=par[j];
					if(son_y[j]==-1){
						adjust(j);
						flag = true;
						break;
					}
					prev_x[son_y[j]] = j;
					if(find(son_y[j])){
						flag = true;
						break;
					}
				}
		}
	}
	int ans = 0;
	for(int i=0;i<pop;i++)
		ans += w[son_y[i]][i];
	return ans;

}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&w[i][j]);
            }
        }
        pop = n;
        cout<<"Case "<<cas++<<": "<<km()<<endl;
    }
	return 0;
}


