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


int main() {
    ios::sync_with_stdio(false);
    freopen("fuck.out", "w", stdout);

    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            for (int k = j; k <= 1500; k++) {
                if (i * i == j * j + k * k)
                    cout << i << ',';
            }
        }
    }


    return 0;
}

