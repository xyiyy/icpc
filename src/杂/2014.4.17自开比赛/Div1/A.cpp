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
//	ios::sync_with_stdio(false);
    int n;

    int maxx = 0;
    while (scanf("%d", &n) == 1) {
        map<int, int> a;
        maxx = 0;
        for (int i = 0; i < n; i++) {
            int b;
            scanf("%d", &b);
            a[b]++;
            if (a[b] > maxx)maxx = a[b];
        }
        cout << maxx << endl;

    }

    return 0;
}

