//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
deque<int>q[1010];
deque<int>s1;
deque<int>s2;
deque<int>s;
int a[1010];
int b[1110];
PII c[1010];
bool vis[1010];
PII cal(int x){
    //while(!s.empty())s.pop_front();
    int sz = q[x].size();
    int ret = 0;
    int now = 0;
    while(!q[x].empty()){
        ret = max(q[x].front() - now,ret);
        //cout << q[x].front() - now << " ";
        s.push_back(q[x].front());
        q[x].pop_front();
        now++;
    }
   // cout << endl;
    while(!s.empty()){
        q[x].push_back(s.front());
        s.pop_front();
    }
   // cout << ret << endl;
    return mp(ret,sz);
}
void change(int x,int xx,int y,int yy){
    int now = 0;
    while(now < xx){
        s1.push_back(q[x].front());
        q[x].pop_front();
        now++;
    }
    now = 0;
    while(now < yy){
        s2.push_back(q[y].front());
        q[y].pop_front();
        now++;
    }
    while(!s1.empty()){
        q[y].push_front(s1.back());
        s1.pop_back();
    }
    while(!s2.empty()){
        q[x].push_front(s2.back());
        s2.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0 ;i < n;i++){
        cin >> a[i];
        for(int j = 0 ; j < a[i];j++){
            cin >> b[j];
            q[i].push_back(b[j]);
        }
    }
    int q;
    cin >> q;
    int x,xx,y,yy;
    priority_queue<PII,vector<PII>,greater<PII> >pq;
    while(q--){
        cin >> x >> xx >> y >> yy;
        x--;y--;
        vis[x] = vis[y] = 0;
        change(x,xx,y,yy);
        for(int i = 0 ; i < n ; i ++){
            if(!vis[i]){
                vis[i] = 1;
                c[i] = cal(i);
                pq.push(c[i]);
            }else pq.push(c[i]);
        }
        //for(int i = 0 ;i <n ;i++)pq.push(cal(i));
        int ans = 0;
        int now = 0;
        while(!pq.empty()){
            int px = pq.top().first;
            //cout << px << endl;
            if(px > now){
                ans += px - now;
                now = px;
            }
            now += pq.top().second;
            pq.pop();
        }
        cout << ans << endl;

    }

    return 0;
}

