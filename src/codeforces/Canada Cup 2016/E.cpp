#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long dp[200010];

int pos,now;
int get(int x){
    if(x == pos)return now;
    else if(x < pos)return a[x];
    else return a[x-1];
}
long long sum(int x){
    if(x >= pos)return now + dp[x-1];
    else return dp[x];
}
int main(){
    int c,n;
    cin >> c >>n;
    for(int i = 1 ; i <= n; i ++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i ++){
        dp[i] = dp[i - 1] + a[i];
    }
    bool ok = false;
    int ans ;
    for(int i = 1; i <= c ; i ++){
        now = i;
        int cur = c;
        pos = lower_bound(a + 1,a+n+1,now) - a;
        while(1){
            if(cur < get(1))break;
            int l = 1, r = n + 1, sr = 1,sl = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(get(mid)<=cur)l = mid + 1,sr = mid;
                else r = mid - 1;
            }
            l = 0, r = sr;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(sum(sr) - sum(mid) <= cur)r = mid - 1,sl = mid;
                else l = mid + 1;
            }
            cur -= sum(sr) - sum(sl);
            if(!sl)break;
        }
        if(cur) ok = true;
        if(ok){
            ans = i;
            break;
        }
    }
    if(!ok)cout << "Greed is good" << endl;
    else cout <<ans <<endl;

    return 0;
}

