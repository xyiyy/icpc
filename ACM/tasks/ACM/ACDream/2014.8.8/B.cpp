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
  
int main() {  
       int T;  
       scanf( "%d", &T);  
       for (int casenum = 1; casenum <= T; ++casenum) {  
                 
               int a[100][100];  
               int n, m;  
               scanf("%d%d", &n, &m);  
               int rowmax[100] = {0}, colmax[100] = {0};  
               for (int i = 0; i < n; ++i) {  
                       for (int j = 0; j < m; ++j) {  
                               scanf("%d", &a[i][j]);  
                               rowmax[i] = std::max(rowmax[i], a[i][j]);  
                               colmax[j] = std::max(colmax[j], a[i][j]);  
                       }  
               }  
               bool ans = true;  
               for (int i = 0; i < n && ans; ++i)  
                       for (int j = 0; j < m && ans; ++j)  
                               if (a[i][j] < rowmax[i] && a[i][j] < colmax[j])  
                                       ans = false;  
               printf("Case #%d: ", casenum);              
               if (ans)  
                       printf("YES\n");  
               else  
                       printf("NO\n");  
       }  
       return 0;  
}  


