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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int N = 100010;
char a[N];

int main() {
    ios::sync_with_stdio(false);
    int k = 1, num = 0;
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin.getline(a, N, '\n');

        //strlwr(a);  
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] >= 'a' && a[i] <= 'z' || (a[i] >= 'A' && a[i] <= 'Z')) {
                num++;
                while (a[i] != ' ' && i < strlen(a)) {
                    i++;
                }
            }
        }
        cout << "Case " << k++ << ": " << num << endl;
        num = 0;
        memset(a, '\0', sizeof(a));
    }
    return 0;
}  
