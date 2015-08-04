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
typedef pair<int,pair<int ,int > > PII;
typedef vector<PII> VII;
typedef vector<int> VI;
PII edge[10010];
int pa[110];
int ra[110];
void init(int n){
    for(int i=0;i<=n;i++){
        pa[i]=i;
        ra[i]=0;
    }
}
int find(int x){
    if(x!=pa[x])pa[x]=find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x= find(x);
    y = find(y);
    if(x==y)return 0;
    if(ra[x]<ra[y]){
        pa[x]=y;
    }else{
        pa[y]=x;
        if(ra[x]==ra[y])ra[x]++;
    }
    return 1;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas =1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tmp;
        int num =0;
        int tot =0;
        init(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>tmp;
                tot += tmp;
                if(tmp)edge[num++]=MP(tmp,MP(i,j));
            }
        }
        sort(edge,edge+num);
        int used = 0;
        int sum  = 0;
        for(int i=0;i<num;i++){
            PII p = edge[i];
            int x = p.second.first;
            int y = p.second.second;
            int d = p.first;
            if(unite(x,y)){
                used++;
                sum+=d;
            }
            if(used==n-1)break;
        }
        cout<<"Case "<<cas++<<": ";
        if(used==n-1){
            cout<<tot-sum<<endl;
        }else cout<<-1<<endl;

    }
    return 0;
}
