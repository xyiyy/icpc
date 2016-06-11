#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        a[0] = 0;
        cin >> n;
        for(int i = 1; i <= n; i ++)cin >> a[i];
        for(int i =0 ; i < n ; i ++ )a[i] = a[i+1] - a[i];
        for(int i = 0; i < n ; i ++ )cin >> b[i];
        int ans = 0;
        for(int i = 0; i < n ; i ++ )if(a[i] >= b[i])ans++;
        cout << ans << endl;
    }
    return 0;
}
