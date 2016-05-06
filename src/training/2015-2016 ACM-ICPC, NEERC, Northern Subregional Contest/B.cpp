#include <bits/stdc++.h>
using namespace std;
void init(){
    freopen("black.in","r",stdin);
    freopen("black.out","w",stdout);
}
bool a[210][410];
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    int r = 210,w = 402;
    init();
    while(cin >> n >> m){
        for(int i = 0 ; i < r; i ++ ){
            for(int j = 0; j < w/2; j ++){
                a[i][j] = 1;
            }
            for(int j = w / 2; j < w; j ++){
                a[i][j] = 0;
            }
        }
        n--,m--;
        for(int i = 1; i < r; i += 2){
            if(!n)break;
            for(int j = 1; j < w / 2; j += 2){
                a[i][j] = 0;
                n--;
                if(!n)break;
            }
            //if(!n)break;
        }
        for(int i = 1; i < r; i += 2){
            if(!m)break;
            for(int j = w / 2 + 1; j < w; j += 2){
                a[i][j] = 1;
                m--;
                if(!m)break;
            }
            //if(!m)break;
        }
        cout << r << " " << w << endl;
        for(int i = 0; i < r ; i++){
            for(int j = 0 ; j < w; j ++){
                if(a[i][j])cout << ".";
                else cout << "@";
            }
            cout << endl;
        }

    }


    return 0;
}
