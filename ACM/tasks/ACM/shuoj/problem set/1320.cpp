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
int Scan() {
	int res=0, ch;
	while(ch=getchar(), ch<'0'||ch>'9');
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a) {
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int d[1000010];
int s[1000010];
ll a[1000010];


int main()
{
	ios::sync_with_stdio(false);
    int n,l;
    n = Scan();
    l = Scan();
    int tot = 0;
    for(int i=0;i<n;i++){
        d[i]=Scan();
        s[i]=Scan();
        tot += d[i];
    }
    d[0] = l-tot;
    for(int i=0;i<n;i++){
        d[i+n]=d[i];
        s[i+n]=s[n];
    }
    tot=0;
    d[2+n]=d[n];
    a[0] = s[0] - d[1];
    for(int i=;i<2*n;i++){
        a[i] = s[i] - d[i+1] + a[i-1];
    }
    tot = 1;
    while(tot<n)tot<<=1;


	return 0;
}


