#include <iostream>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    string str;
    while(cin>>str){
        int len = str.length();
        len--;
        ll now = 1;
        ll ans = 0;
        while(len>=0){
            if(str[len]=='u')ans += -now;
            else if(str[len]=='1')ans+=now;
            now <<= 1;
            len --;
        }
        cout << ans << endl;
    }

    return 0;
}


