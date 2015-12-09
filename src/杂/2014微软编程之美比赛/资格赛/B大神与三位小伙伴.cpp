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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
int n;
#define fuc 1000000007

int main() {
    ios::sync_with_stdio(false);
    int t;
    int k = 1;
    cin >> t;
    long long sum;
    while (t--) {
        sum = 0;
        cin >> n;
        for (int i = 1; i < n + 1; i++) {
            sum = (sum + ((n + 1 - i) * (n + 1 - i) * (n + 1 - i))) % fuc;//1000000007
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (j == i)continue;
                for (int k = 1; k < n + 1; k++) {
                    if (k == i || k == j)continue;
                    sum = (sum + ((n + 1 - i) * (n + 1 - j) * (n + 1 - k))) % fuc;
                }
            }
        }
        cout << "Case " << k++ << ": ";
        cout << sum << endl;
    }

    return 0;
}

