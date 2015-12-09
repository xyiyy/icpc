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

char str[110];
int a[110];
int b[110];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        memset(str, '\0', sizeof(str));
        cin >> str;
        int flag = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == '0')a[i] = 1;
        }
        for (int i = 0; i < len; i++) {
            if (str[len - 1 - i] == '1')b[i] = 1;
        }
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "False" << endl;
        }
        else {
            cout << "True" << endl;
        }
    }


    return 0;
}

