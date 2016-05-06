#include <bits/stdc++.h>
using namespace std;

int a[110][110];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int r,c;
bool in(int x,int y){
    if(x >= 0 && y >= 0 && x < r && y < c)return 1;
    return 0;
}
void input(){
    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);
}
int main(){
    ios::sync_with_stdio(0);
    input();
    while(cin >> r >> c){
        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c ; j++){
                cin >> a[i][j];
            }
        }
        int ans = 0;
        int tx,ty;
        for(int i =0 ; i < r ; i++){
            for(int j = 0; j < c ; j++){
                for(int k = 0; k < 4 ;k ++){
                    int px = i + dx[k], py = j + dy[k];
                    bool flag = 1;
                    while(in(px,py)){
                        if(a[px][py] >= a[i][j]){
                            flag = 0;
                            break;
                        }
                        px = px + dx[k];
                        py = py + dy[k];
                    }
                    ans += flag;

                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

