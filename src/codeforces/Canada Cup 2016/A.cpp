#include <bits/stdc++.h>
using namespace std;

string str;
int main(){
    int lx = 0 ,rx = 0;
    int n;
    cin >> n;
    cin >>str;
    int len = str.length();
    int now = 0;
    for(int i = 0 ; i < len ; i ++){
        if(str[i] == '<')now++;
        else break;
    }
    for(int i = len - 1; i >=0 ; i --){
        if(str[i] == '>')now++;
        else break;
    }
    cout << now <<endl;
    return 0;
}
