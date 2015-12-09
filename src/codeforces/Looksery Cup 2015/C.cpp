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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int main()
{
	ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a,b=0,c=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a&1)b++;
        else c++;
    }
    int need_to_move = n-k;
    if(need_to_move&1){//qujishuci
        if(k%2==0&&need_to_move/2>=c||need_to_move/2>=b)cout<<"Daenerys"<<endl;//houshou
        else cout<<"Stannis"<<endl;
    }else{
        if(need_to_move/2>=c&&k%2==1)cout<<"Stannis"<<endl;//xianshou
        else cout<<"Daenerys"<<endl;
    }


	return 0;
}


