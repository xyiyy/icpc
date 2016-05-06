#include <bits/stdc++.h>
using namespace std;
void input(){
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
}
int main(){
    ios::sync_with_stdio(0);
    //input();
    string str;
    while(cin >> str){
        string ans = "";
        int len = str.length();
        bool flag = 0;
        for(int i = 0; i < len; i ++){
            if(str[i] == '-'){
                flag = 1;
                cout << str[i] << str[i + 1];
                i++;
            }else if(str[i] == '+'){
                flag = 0;
                cout << str[i] ;
            }else{

                if(flag){
                    cout << "+";
                    ans = "";
                    while(i < len && isdigit(str[i])){
                        ans = ans + str[i];
                        i++;
                    }
                    i--;
                    int j = 0;
                    int tlen = ans.length();
                    while(j < tlen - 1){
                        if(ans[j]!='0')break;
                        j++;

                    }
                    for(;j<tlen;j++){
                        cout << ans[j];
                    }
                }
                else cout << str[i];
            }
        }
        cout <<endl;
    }
    return 0;
}

