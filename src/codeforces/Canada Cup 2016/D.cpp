#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >q;
pair<long long,long long> a[300010];
long long INF = LLONG_MAX;

int main(){
    int n;
    int ans = 0;
    cin >> n;
    long long t,w;
    cin >> t >> w;
    n -- ;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a,a+n);
    int pos = upper_bound(a,a+n,make_pair(t,INF)) - a;
    ans = n - pos + 1;
    for(int i = pos; i < n ; i ++){
        q.push(a[i].second - a[i].first + 1);
    }
    int lastpos = pos;
    int now = ans;
    while(!q.empty()){
        long long delta = q.top();
        q.pop();
        if(t <delta)break;
        t -= delta;
        pos = upper_bound(a,a+lastpos,make_pair(t,INF)) - a;
        now--;
        now += lastpos - pos;
        ans = min(now,ans);
        for(int i = pos;i < lastpos; i ++){
            q.push(a[i].second - a[i].first + 1);
        }
        lastpos = pos;
    }
    cout <<ans <<endl;
    return 0;
}
