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
    char str[1000010];
    int num[5];
    memset(str, '\0', sizeof(str));
    memset(num, 0, sizeof(num));
    while (cin >> str) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == 'C')num[0]++;
            else if (str[i] == 'T')num[1]++;
            else if (str[i] == 'J')num[2]++;
            else if (str[i] == 'H')num[3]++;
            else if (str[i] == 'S')num[4]++;
        }
        sort(num, num + 5);
        cout << num[3] + num[4] << endl;
        memset(str, '\0', sizeof(str));
        memset(num, 0, sizeof(num));
    }
    return 0;
}

