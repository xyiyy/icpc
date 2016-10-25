#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >vec;
priority_queue<pair<int,int> > q;
bool vis[100010];
int main(){
    int n;
    cin >> n;
    long long ret = 0;
    for(int i = 0 ; i < n ; i ++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a <= d && b <= c)continue;
        ret -= b, ret -= d;
        if(a + b <= c + d){
            if(a > d)ret += a + b;
            else ret += c + d;
        }else{
            vec.push_back(make_pair(a+b,c+d));
        }
    }
    for(int i = 0 ; i < vec.size(); i ++){
        q.push(make_pair(vec[i].first,i));
    }
    while(!q.empty()){
        ret += q.top().first;
        int x = q.top().second;
        q.pop();
        if(!vis[x]){
            vis[x] = true;
            q.push(make_pair(vec[x].second,x));
        }
        x = q.top().second;
        q.pop();
        if(!vis[x]){
            vis[x] = true;
            q.push(make_pair(vec[x].second,x));
        }
    }
    cout << ret << endl;
    return 0;
}
