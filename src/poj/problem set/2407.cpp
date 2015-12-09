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

int eular()//欧拉函数，用于求1到n-1与n互质的组数
{
    int ret = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret *= i - 1;
            n /= i;
            while (n % i == 0) {
                n /= i;
                ret *= i;
            }
        }
    }
    if (n > 1)
        ret *= n - 1;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n && n) {
        cout << eular() << endl;
    }
    return 0;
}

