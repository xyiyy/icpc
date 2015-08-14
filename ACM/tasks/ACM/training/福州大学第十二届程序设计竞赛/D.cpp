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
	char s[1100];
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",s);
	    ll fir=0;
	    int i;
	    for(i=0;s[i]!='.';i++){
            fir*=10;
            fir+=s[i]-'0';
	    }
	    while(s[i]=='.')i++;
	    ll fz=0;
	    ll fm=1;
	    int len=strlen(s);
	    for(;i<len;i++){
            fz*=10;
            fm*=10;
            fz+=s[i]-'0';
	    }
	    if(fir){
            fz+=fir*fm;
	    }
	    cout<<fz/__gcd(fz,fm)<<"/"<<fm/__gcd(fz,fm)<<endl;

	}
	return 0;
}
