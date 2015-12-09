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
const int size = 1000001;
int H_number[size + 1];

void init() {
    int mul;
    CLR(H_number, 0);
    for (int i = 5; i <= size; i += 4) {
        for (int j = 5; j <= size; j += 4) {
            mul = i * j;
            if (mul > size)break;
            if (H_number[i] == 0 && H_number[j] == 0) {
                H_number[mul] = 1;
            }
            else {
                H_number[mul] = -1;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= size; i++) {
        if (H_number[i] == 1) {
            count++;
        }
        H_number[i] = count;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int n;
    while (cin >> n && n) {
        cout << n << " " << H_number[n] << endl;
    }
    return 0;
}


