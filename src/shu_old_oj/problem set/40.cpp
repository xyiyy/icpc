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
int y, m, d, days;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapyear() {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int main() {
    ios::sync_with_stdio(false);
    int sum = 0;
    int j;
    while (cin >> y >> m >> d >> days) {
        if (leapyear())day[2] = 29;
        sum = 0;
        for (int i = 1; i < m; i++) {
            sum += day[i];
        }
        sum += d;
        cout << sum << " ";
        j = 1;
        while (day[j] < days) {
            days -= day[j];
            j++;
        }
        cout << j << " " << days << endl;
        day[2] = 28;
    }


    return 0;
}


