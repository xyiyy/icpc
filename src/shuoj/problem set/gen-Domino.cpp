#include <bits/stdc++.h>
#include <cassert>
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("domino.in2","w",stdout);
    srand(time(NULL));
    int t = 3;
    while(t--) {
        int N = rand()%100;
        vector<int> p;
        REP(i,N) {
            p.push_back(rand()%1000+1);
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        N=p.size();
        cout<<N<<endl;
        REP(i,N) {
            cout<<p[i]<<' '<<(rand()%3+1)<<endl;
        }
    }
    return 0;
}
