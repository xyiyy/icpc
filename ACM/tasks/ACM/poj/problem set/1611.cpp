#include <iostream>
using namespace std;
#define MAXN 30010

int pa[MAXN]; // parent
int ra[MAXN]; // rank

void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m&&(n||m)){
        init(n);
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            int u,v;
            cin>>u;
            for(int j=1;j<k;j++){
                cin>>v;
                unite(u,v);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(same(0,i))ans++;
        }
        cout<<ans<<endl;
    }
}
