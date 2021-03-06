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
const int maxn = 10;
int m, n;

class Matrix {
public:
    Matrix(int r, int c) : row(r), col(c) { }

    void Init() {
        CLR(matrix, 0);
        matrix[0][0] = matrix[0][1] = matrix[1][0] = 1;
    }

    void Unit() {
        CLR(matrix, 0);
        REP(i, row)matrix[i][i] = 1;
    }

    int Result() const {
        return matrix[0][1] % m;
    }

    friend Matrix operator*(const Matrix &, const Matrix &);

    ll fast_mod();

private:
    ll matrix[maxn][maxn];
    int row, col;
};

Matrix operator*(const Matrix &M1, const Matrix &M2) {
    Matrix M(M1.row, M2.col);
    REP(i, M1.row)
        REP(j, M2.col) {
            M.matrix[i][j] = 0;
            REP(k, M1.col) {
                M.matrix[i][j] = (M.matrix[i][j] + M1.matrix[i][k] * M2.matrix[k][j]) % m;
            }
        }
    return M;
}

Matrix Mat(2, 2);

ll Matrix::fast_mod() {
    Matrix temp(2, 2);
    temp.Init();
    while (n) {
        if (n & 1) {
            Mat = temp * Mat;
            n--;
        }
        else {
            temp = temp * temp;
            n >>= 1;
        }
    }
    return Mat.matrix[0][1];
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        n = 2 * n;
        Mat.Unit();
        cout << Mat.fast_mod() << endl;
    }
    return 0;
}


