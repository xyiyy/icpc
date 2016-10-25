#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    char c;
    cin >>c;
    n--;
    long long ans = 0;
    ans += n                                                ;
    if(n % 4 > 1)ans -= 2;
    ans += 12 * (n / 4);
    if(n % 2 == 1)ans += 6;
    if(c > 'c')ans += 'f' + 1 - c;
    else ans += 4 + c - 'a';
    cout << ans << endl;
    return 0;

}

