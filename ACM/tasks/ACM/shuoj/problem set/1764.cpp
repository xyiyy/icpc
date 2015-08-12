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
//#include <strstream>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define IT iterator
#define CLR(A,X) memset(A,X,sizeof(A))
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char a[100010];
char b[10010];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int n=0;
    int len;
    int cas=1;
    while(T--)
    {
        CLR(a,0);
        CLR(b,0);
        n=0;
        cin>>a;
        len=strlen(a);
        for(int i=0;i<len;i++)
        {
            if(a[i]=='_')
            {
                n++;
                continue;
            }
            if(n&&a[i-1]=='_')b[i-n]=a[i]-('a'-'A');
            else b[i-n]=a[i];
        }
        cout<<"Case "<<cas++<<":"<<endl;
        cout<<b<<endl;
    }
     
     
    return 0;
}
