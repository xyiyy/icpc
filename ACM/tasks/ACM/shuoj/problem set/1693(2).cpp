#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    cin.ignore();
    string a;
    //getchar();
    while(t--){
        getline(cin,a,'\n');
        int len = a.length();
        if(a[0]>='0'&&a[0]<='9'){
            while(len--){
                int num = 0;
                if(a[len]=='1'){
                    num = 100;
                    len --;
                    num += (a[len]-'0')*10;
                    len --;
                    num += a[len]-'0';
                }else{
                    num = (a[len] - '0')*10;
                    len --;
                    num += a[len] - '0';
                }
                cout << (char)num;
            }
        }else{
            while(len--){
                int tmp = a[len];
                while(tmp){
                    cout << tmp%10;
                    tmp/=10;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

