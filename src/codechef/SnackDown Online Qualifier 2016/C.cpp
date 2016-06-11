#include <bits/stdc++.h>
using namespace std;
string str;
int a[310];
int pre[310];
int bac[310];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        int k ;
        cin >> k;
        int len = str.length();
        memset(a,0,sizeof(a));
        for(int i = 0 ; i < len ; i ++){
            a[str[i]] ++;
        }
        sort(a,a+300);
        pre[0] = a[0];
        for(int i =0 ; i <300; i ++ ){
            pre[i+1] = pre[i] + a[i];
        }
        a[300] = len+1;
        bac[300] = 0;
        for(int i = 300; i > 0; i --){
            bac[i - 1] = bac[i] + a[i-1];
        }
        int ans = len;
        int st = 0;
        while(a[st]==0)st++;
        int minn = a[st];
        int maxx = a[299];
        for(int i = minn; i <= maxx; i++){
            int lx = lower_bound(a+st,a+300,i) - a;
            int rx = upper_bound(a+st,a+300,i+k) - a;
            //cout << i << ":"<< pre[lx] <<" " << bac[rx] - (300 - rx) * (i + k) << endl;
            ans = min(ans, pre[lx]+bac[rx] - (300 - rx) * (i + k));
        }
        cout << ans << endl;
    }
    return 0;
}

