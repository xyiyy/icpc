#include <bits/stdc++.h>
using namespace std;
void init(){
    freopen("alex.in","r",stdin);
    freopen("alex.out","w",stdout);
}
int main(){
    ios::sync_with_stdio(0);
    init();
    double h,w;
    while(cin >> h >> w){
        if(h > w)swap(h,w);
        double ans = min(w / 3.0, h);
        ans = max(h / 2, ans);
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
