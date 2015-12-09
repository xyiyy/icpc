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
vector<int>a;
int b[10];
int main()
{
	ios::sync_with_stdio(false);
    string  s;
    cin>>s;
    //b[0]=1;
    //for(int i=0;i<8;i++){
    //    b[i]=b[i-1]*10;
    //}
    int len=s.length();
    int temp=1;
    while(temp){
        temp=0;
        for(int i=0;i<len;i++){
            temp = temp *10;
            if(s[i]!='0'){
                temp++;
                s[i]--;
            }
        }
        if(temp)
        a.PB(temp);
        else break;

    }
    cout<<(int)a.size()<<endl;;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

	return 0;
}



