#include<bits/stdc++.h>
using namespace std;
char ans[2][110];
int main(){
    string str;
    cin >> str;
    int n = str.length();
    bool ok = false;
    int x, y;
    for(int i = 0 ; i < n ; i ++){
        for(int j = i + 2; j < n ; j ++ ){
            if(str[j] == str[i]){
                x = i,y = j;
                ok = true;
            }
            if(ok)break;
        }
        if(ok)break;
    }

    if(ok){
        int len = y - x;
        int gao = x + len/2;
        int now = gao;
        for(int i = 12;i >= 0; i --){
            if(now == x)now--;
            if(now < 0)break;
            ans[1][i] = str[now--];
        }
       // cout << now << endl;
        int i = 0 ;
        while(now >= 0){
            ans[0][i++] = str[now--];
        }
        //cout << ans[0] << endl;
        now = gao+1;
        for( i = 12; i >= 0; i --){
            if(now > 26)break;
            ans[0][i] = str[now++];
        }
         i = 0;
        while(now < 27){
            ans[1][i++] = str[now++];
        }
        cout << ans[0] << endl << ans[1] << endl;
    }else {
        cout << "Impossible" << endl;
    }

    return 0;
}

/*
ABCDEFGHIJKLMNOPQRSTUVWXYZW
*/
