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
//vector<int>vec[1010];
double a[1010];
int V;
const int MAX_V=1010;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
int fuc[MAX_V];
void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	fuc[k]++;
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}

int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++)
	{
		if(!used[v])dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}
int numm[1010];
double cao[1010];
bool Map[110][110];
vector<int>gg[110];
int fff[1010];
int depth[1010];
void dfs3(int x,int d){
    depth[x]=max(depth[x],d);
    for(int i=0;i<gg[x].size();i++){
        dfs3(gg[x][i],d+1);
    }
}
int dfs2(int x){
    int ret=numm[x];
    used[x]=1;
    for(int i=0;i<gg[x].size();i++){
            int v=gg[x][i];
        if(depth[v]==depth[x]+1)
        ret+=dfs2(gg[x][i]);
    }
    //cout<<x<<" "<<ret<<endl;
    fff[x]=ret;
    return fff[x];
}

double dfs1(int x,double p){
   // cout<<x<<endl;
   used[x]=1;
   double tp=p*(1-cao[x]);

    double ret=fff[x]*p*cao[x];
    for(int i=0;i<gg[x].size();i++){
            ret+=dfs1(gg[x][i],tp);
    }
    return ret;
}
class TheTips{
public:
    double solve(vector<string>str,vector<int>p){
        //for(int i=0;i<1010;i++)vec[i].clear();
        for(int i=0;i<str.size();i++){
            string s=str[i];
            int len = s.length();
            for(int j=0;j<len;j++){
                if(i==j)continue;
                if(s[j]=='Y'){
                    //vec[i].PB(j);
                    add_edge(i,j);
                }
            }
        }
       // cout<<"ok"<<endl;
        int n = p.size(); V=n;
        for(int i=0;i<n;i++)a[i]=p[i]/100.0;
        int k = scc();
        for(int i=0;i<1010;i++)cao[i]=1.0;
        for(int i=0;i<n;i++){
            cao[cmp[i]]*=1-a[i];
        }
        for(int i=0;i<str.size();i++){
            numm[cmp[i]]++;
            string s=str[i];
            int len = s.length();
            for(int j=0;j<len;j++){
                if(cmp[i]==cmp[j])continue;
                if(s[j]=='Y'){
                    Map[cmp[i]][cmp[j]]=1;
                    gg[cmp[i]].PB(cmp[j]);
                    //vec[i].PB(j);
                    //add_edge(i,j);
                }
            }
        }
        CLR(used,0);
        for(int i=0;i<k;i++){
            if(used[i])continue;
            dfs3(i,0);
        }
        //cout<<numm[0]<<endl;;
        CLR(used,0);
        for(int i=0;i<k;i++){
            if(used[i])continue;
            dfs2(i);
        }
       // cout<<"ok"<<endl;
       // cout<<numm[0]<<endl;
       CLR(used,0);
        for(int i=0;i<n;i++)cao[i]=1-cao[i];
        double ret=0;
        for(int i=0;i<k;i++){
            if(used[i])continue;
            used[i]=1;
            ret+=dfs1(i,1);
        }
         return ret;
    }
};
int main()
{
	ios::sync_with_stdio(false);
	TheTips t;
	vector<string> t1;
	t1.PB("YYY");
	t1.PB("NYY");
	t1.PB("NNY");
	vector<int>t2;
	t2.PB(100);
	t2.PB(0);
	t2.PB(0);
	cout<<t.solve(t1,t2)<<endl;;
	return 0;
}



