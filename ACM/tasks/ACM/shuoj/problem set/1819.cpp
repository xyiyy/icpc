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
int n,m,k=1,id;  
char a[40];  
//int num[10010];  
char ans[10010];  
int main()  
{  
    ios::sync_with_stdio(false);  
    for(int i=0;i<36;i++)  
    {  
        if(i<10)a[i]='0'+i;  
        else a[i]='A'+i-10;  
    }  
    stack<int > s;  
    while(cin>>n>>m)  
    {  
        CLR(ans,'\0');  
        id=0;  
        while(n)  
        {  
            s.push(n%m);  
            n/=m;  
        }  
        while(!s.empty())  
        {  
            ans[id++]=a[s.top()];  
            s.pop();  
        }  
        cout<<"Case "<<k++<<": "<<ans<<endl;  
    }  
          
    return 0;  
}  
