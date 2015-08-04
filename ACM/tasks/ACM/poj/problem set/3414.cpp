//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <queue>
using namespace std;
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int > PII;
int vis[110][110];
PII pa[110][110];
int fa[110][110];
int a,b,c;
PII gao(int x,int y,int i){
    if(i==0)return MP(a,y);
    else if(i==1)return MP(x,b);
    else if(i==2)return MP(0,y);
    else if(i==3)return MP(x,0);
    else if(i==4){
        int need = b - y;
        if( need <= x)return MP(x - need,b);
        else return MP(0,y + x);
    }else{
        int need = a - x;
        if( need <= y)return MP(a, y - need);
        else return MP(x + y, 0);
    }
}
void dfs(int x,int y){
    if(x == 0&& y == 0)return;
    PII p = pa[x][y];
    int tx = p.first;
    int ty = p.second;
    dfs(tx,ty);
    int tmp = fa[x][y];
    if(tmp < 2)cout<< "FILL(" << tmp + 1 << ")" <<endl;
    else if(tmp < 4)cout<< "DROP(" << tmp - 1 << ")" <<endl;
    else if(tmp == 4)cout<< "POUR(1,2)" <<endl;
    else cout<< "POUR(2,1)" <<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b>>c){
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                pa[i][j] = MP(-1,-1);
                fa[i][j] =  -1;
                vis[i][j] = -1;
            }
        }
        queue<PII> q;
        q.push(MP(0,0));
        vis[0][0] = 0;
        int ansx = -1,ansy = -1;
        while(!q.empty()){
            PII p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(x==c||y==c){
                ansx = x;
                ansy = y;
                break;
            }
            for(int i=0;i<6;i++){
                PII tmp = gao(x, y, i);
                int tx = tmp.first;
                int ty = tmp.second;
                if(vis[tx][ty] == -1){
                    vis[tx][ty] = vis[x][y] + 1;
                    pa[tx][ty] =  MP(x,y);
                    fa[tx][ty] = i;
                    q.push(MP(tx,ty));
                }
            }
        }
        if(ansx == -1){
            cout<<"impossible"<<endl;
            continue;
        }
        cout<<vis[ansx][ansy]<<endl;
        dfs(ansx,ansy);

    }
    return 0;
}
