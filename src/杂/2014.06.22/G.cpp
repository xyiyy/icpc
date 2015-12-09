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
const int M = 10010; // M : size 
bool mark[M]; // true : prime number
void sieve_prime() {
    memset(mark, true, sizeof(mark));
    mark[0] = mark[1] = false;
    for (int i = 2; i <= sqrt(M); i++) {
        if (mark[i]) {
            for (int j = i * i; j < M; j += i)
                mark[j] = false;
        }
    }
}

int a[M];

int main() {
    ios::sync_with_stdio(false);
    int n, size = 0;
    int first = 1, last = size;
    int times = 0;
    sieve_prime();
    for (int i = 2; i < M; i++) {
        if (mark[i])a[++size] = i;
    }

    while (cin >> n) {
        first = 1;
        last = size;
        while (a[last] > n)last--;
        times = 0;
        while (first <= last) {
            int p = a[last];
            while (p * a[first] <= n) {
                p *= a[first];
                first++;
            }
            last--;
            times++;
        }
        cout << times << endl;
    }

    return 0;
}

