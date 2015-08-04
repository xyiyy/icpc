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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int a[10010]; 
int main()  
{  
    int n;  
    while(cin>>n)  
    {  
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)  
            cin>>a[i];  
  
        sort(a+1,a+n+1);  
  
        cout<<a[n/2+1]<<endl;  
   
    }  
    return 0;  
}  

