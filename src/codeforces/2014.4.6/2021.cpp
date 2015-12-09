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
int a[6] = {100, 50, 10, 5, 2, 1};
int p[110];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            int j = 0;
            while (j < 6) {
                if (p[i] >= a[j]) {
                    p[i] -= a[j];
                    num++;
                }
                else {
                    j++;
                }
            }
        }
        cout << num << endl;
    }
    //if()
    //	for(int j=0;j<)

    //for)
    return 0;
}

