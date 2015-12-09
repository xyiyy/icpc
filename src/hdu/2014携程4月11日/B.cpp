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

bool f[801][801];  
int len[40];  
int cir;            
double p;          
  
int main() {  
   
    int n;  
    while(cin >> n&&n) {  
        cir = 0;  
        for(int i = 0;i < n; i++) {  
            cin >> len[i];  
            cir += len[i];  
        }  
        p = cir / 2.0;  
        memset(f, false, sizeof(f));  
        f[0][0] = true;  
        for(int i = 0; i < n; i++) {  
            for(int j = p - 1; j >= 0; j--) {  
                for(int k = j; k >= 0; k--) {  
                    if(len[i] <= j)  
                        f[j][k] |= f[j - len[i]][k];  
                    if(len[i] <= k)  
                        f[j][k] |= f[j][k - len[i]];  
                }  
            }  
        }  
        double ans = -1;  
        for(int i = 1; i < p - 1; i++) {  
            for(int j = 1; j < p - 1; j++) {  
                if(f[i][j]) {  
                    int tmp = cir - i - j;  
                    double area = p * (p - tmp) * (p - i) * (p - j);  
                    ans = max(ans, area);  
                }  
            }  
        }  
        if(ans > 0) cout << int(sqrt(ans) * 100) << endl;  
        else cout << -1 << endl;  
    }  
    return 0;  
}  
