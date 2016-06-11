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
int x[100010],y[100010],z[100010],d[100010];
vector<PII> L,R;
map<int,int>ml,mr;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    //cin >> t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        //cin >> n;
        int l = 0 ;
        R.clear();
        L.clear();
        ml.clear();
        mr.clear();
        rep(i,n){
            //cin >> x[i] >> y[i] >> z[i] >> d[i];
            scanf("%d%d%d%d",&x[i],&y[i],&z[i],&d[i]);
            if(y[i] - x[i] > 2 * z[i])continue;
            if(d[i] == 1){
                R.push_back(mp(y[i] - z[i],-1));
                R.pb(mp(x[i] + z[i] , 0));
                R.pb(mp(x[i] + z[i]+1 , 1));
            }else{
                L.pb(mp(y[i] - z[i], -1));
                L.pb(mp(x[i] + z[i], 0));
                L.pb(mp(x[i] + z[i]+1, 1));
            }
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        int sz = R.size();
        int ans = 0 ;
        int nowx  = -10000000;
        int num = 0;
        for(int i = 0 ; i < sz ; i ++ ){
            nowx = -R[i].first;
            num -= R[i].second;
            //cout << num << endl;
            //mr[nowx] = mr[nowx]
            if(mr.count(nowx)){
                mr[nowx] = max(mr[nowx],num);
            }else mr[nowx] = num;
            ans = max(ans,num);
        }
        sz = L.size();
        num = 0 ;
        for(int i = 0 ; i < sz; i ++){
            nowx = -L[i].first;
            num -= L[i].second;
            //cout << num << endl;
            if(ml.count(nowx)){
                ml[nowx] = max(ml[nowx],num);
            }else ml[nowx] = num;
            ans = max(ans,num);
        }
        int maxl = 0;
       // cout << ml[-3] << endl;
       // cout << ans << endl;
        map<int,int>::iterator  itl,itr;
        for(itl = ml.begin(),itr = mr.begin();itl!=ml.end() && itr != mr.end();){
                //cout << itr -> first << " " << itl -> first <<endl;
            if(itr->first < itl->first){
                itr++;
            }else if(itr -> first >= itl -> first){
                maxl = max(itl->second,maxl);
                //cout << maxl << endl;
                ans = max(ans , itr->second + maxl);
                itl++;
            }
        }
        //cout << (itr == mr.end())<<endl;
        //cout << maxl << endl;
        while(itr != mr.end()){
            ans = max(ans,itr->second + maxl);
            itr ++;
        }
        cout << "Case #"<< cas++ << ":" <<endl;;
        cout << ans <<endl;




    }
    return 0;
}
