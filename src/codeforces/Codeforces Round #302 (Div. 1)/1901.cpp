#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace  std;
typedef pair<int,pair<int,int> > PII;
#define MP(A,B,C) make_pair(A,make_pair(B,C))

char a[10][10];
map<int,int>ms[20];
int n,m;
bool in(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='O')return 1;
    return 0;
}
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<16;i++)ms[i].clear();
        cin>>n>>m;
        int now =0;
        int tot = 1<<(n*m);
        tot--;
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'||a[i][j]=='X'){
                    now |=1<<(i*m+j);
                    if(a[i][j]=='S'){
                        sx = i;
                        sy = j;
                        a[i][j]='O';
                    }
                }
            }
        }
        queue<PII> q;
        q.push(MP(0,sx*m+sy,now));
        int ans = 10010;
        ms[0][now]=1;
        while(ans==10010){
            PII p = q.front();
            q.pop();
            int x = p.second.first/m;
            int y = p.second.first%m;
            now = p.second.second;
            int num = p.first;
            for(map<int,int>::iterator it = ms[num].begin();it!=ms[num].end();it++){
                if((now|(it->first))==tot)
                {
                    ans = num;
                }
            }
            for(int i=0;i<4;i++){
                int tx = x + dirx[i];
                int ty = y + diry[i];
                if(in(tx,ty)){
                    ms[num+1][now|(1<<(tx*m+ty))]=1;
                    q.push(MP(num+1,tx*m+ty,now|(1<<(tx*m+ty))));
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

