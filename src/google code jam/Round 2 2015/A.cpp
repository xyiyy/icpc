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
char a[110][110];
int b[110][110];
int r,c;
bool in(int x,int y){
    if(x>=0&&x<r&&y>=0&&y<c)return 1;
    else return 0;
}
int dirx[4]={0,-1,1,0};
int diry[4]={-1,0,0,1};
int main()
{
	ios::sync_with_stdio(false);
    freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	int cas=1;
	while(t--){

        cin>>r>>c;
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
                if(a[i][j]=='.')b[i][j]=0;
                if(a[i][j]=='<')b[i][j]=1;
                if(a[i][j]=='^')b[i][j]=2;
                if(a[i][j]=='v')b[i][j]=3;
                if(a[i][j]=='>')b[i][j]=4;

            }
        }
        /*for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;

        }*/
        bool imp=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                   // cout<<"asfa"<<endl;
                if(b[i][j]==0)continue;
                int num=0;
                bool flag=0;
                for(int k=1;k<=4;k++){
                    if(k==b[i][j]){
                        int tx=i+dirx[k-1];
                        int ty=j+diry[k-1];
                        while(in(tx,ty)){
                            if(b[tx][ty])break;
                            tx=tx+dirx[k-1];
                            ty=ty+diry[k-1];
                        }
                        if(!in(tx,ty))num++;
                        else flag=1;
                    }else{
                        int tx=i+dirx[k-1];
                        int ty=j+diry[k-1];
                        while(in(tx,ty)){
                            if(b[tx][ty])break;
                            tx=tx+dirx[k-1];
                            ty=ty+diry[k-1];
                        }
                        if(!in(tx,ty))num++;
                    }
                }
                if(flag)continue;
                if(num<4)ans++;
                else imp=1;
                //if(c==4)ans++;
            }
        }
        cout<<"Case #"<<cas++<<": ";
        if(imp)cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
	}
	return 0;
}


