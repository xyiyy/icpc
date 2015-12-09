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
inline bool equal(const char ch, const char symbol) {  
       return (ch == symbol || ch == 'T');  
}  
  
bool check(const char board[10][10], const char symbol) {  
       for (int i = 0; i < 4; ++i) {  
               int cntrow = 0, cntcol = 0;  
               for (int j = 0; j < 4; ++j) {  
                       if (equal(board[i][j], symbol))  
                               ++cntrow;  
                       if (equal(board[j][i], symbol))  
                               ++cntcol;  
               }  
               if (cntrow == 4 || cntcol == 4)  
                       return true;  
       }  
       int cntdiag1 = 0, cntdiag2 = 0;  
       for (int i = 0, j = 0, k = 3; i < 4; ++i, ++j, --k) {  
               if (equal(board[i][j], symbol))  
                       ++cntdiag1;  
               if (equal(board[i][k], symbol))  
                       ++cntdiag2;  
       }  
       if (cntdiag1 == 4 || cntdiag2 == 4)  
               return true;  
       return false;  
}  
  
int main() {   
       int T;  
       scanf("%d", &T);  
       for (int casenum = 1; casenum <= T; ++casenum) {  
               
               char board[10][10];  
               for (int i = 0; i < 4; ++i)  
                       scanf("%s", board[i]); 
				printf("Case #%d: ", casenum);  	    
               if (check(board, 'X')) {  
                       printf("X won\n");  
               } else if (check(board, 'O')) {  
                       printf("O won\n");  
               } else {  
                       bool filled = true;  
                       for (int i = 0; i < 4 && filled; ++i)  
                               for (int j = 0; j < 4 && filled; ++j)  
                                       if (board[i][j] == '.')  
                                               filled = false;  
                       if (filled)  
                               printf("Draw\n");  
                       else  
                               printf("Game has not completed\n");  
               }  
       }
       return 0;  
}  
