#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <functional>
#include <ios>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        int minn=1e9;
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            minn=min(minn,(n+a-1)/a*b);
        }
        cout<<minn<<endl;
    }

    return 0;
}
