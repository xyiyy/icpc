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
#define N 200010
struct human {
    char sex;
    int dna, alive, mother;
} hun[N];

int find_mother(int id) {
    if (hun[id].mother == -id) {
        return id;
    }
    else {
        return hun[id].mother = find_mother(hun[id].mother);
    }
}

void query(int size) {
    int flag = 1, flag1 = 1, num = 0, num1 = 0, mark, mark1;
    for (int i = 1; i <= size; i++) {
        if (hun[i].alive) {
            if (hun[find_mother(i)].dna > 0) {
                if (flag) {
                    flag = 0;
                    mark = i;
                    num++;
                }
                else if (hun[find_mother(i)].dna != hun[find_mother(mark)].dna) {
                    cout << "NO" << endl;
                    return;
                }
            }
            else {
                if (flag1) {
                    flag1 = 0;
                    mark1 = i;
                    num1++;
                }
                else if (hun[find_mother(i)].dna != hun[find_mother(mark1)].dna) {
                    num1++;
                }
            }
        }
    }
    if (num1 > 1 || (num && num1))cout << "POSSIBLY" << endl;
    else cout << "YES" << endl;
    return;
}


int main() {
    ios::sync_with_stdio(false);
    int n, m, bm, bf;
    int size;
    char a;
    int k, Dna, id;
    while (cin >> n) {
        size = n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            hun[i].sex = a;
            hun[i].dna = -i;
            hun[i].alive = 1;
            hun[i].mother = -i;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> bf;
            if (bf > 0) {
                cin >> bm;
                hun[++size].mother = bm;
                cin >> a;
                hun[size].sex = a;
                hun[size].dna = hun[bm].dna;
                hun[size].alive = 1;
            }
            else {
                hun[-bf].alive = 0;
            }
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> id >> Dna;
            hun[find_mother(id)].dna = Dna;
        }
        query(size);
    }


    return 0;
}

