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
#define MAX_LENGTH  (10004)
#define TYPE_UNKNOWN (0)
#define TYPE_PASS  (1)
#define TYPE_UNPASS  (2)

typedef struct tagNode {
    char pPass[4];

} NODE, *LPNODE;
//east=0, south=1, west=2, north=3;

class Maze {
private:
    NODE *m_Maze;
    int m_nWidth;
    int m_nHeight;
    int m_nLeft;
    int m_nRight;
    int m_nTop;
    NODE *m_pCur;
    int m_nCx;
    int m_nCy;
    int m_nDir;
public:
    Maze();

    ~Maze();

    void Clean();

    void TurnLeft();

    void TurnRight();

    void Turn180();

    void Move();

    void MoveOnly();

    void Print();
};

Maze::Maze() {
    m_Maze = (NODE *) malloc(MAX_LENGTH * MAX_LENGTH * sizeof(NODE));
    Clean();
}

Maze::~Maze() {
    free(m_Maze);
}

void Maze::Clean() {
    memset(m_Maze, 0, MAX_LENGTH * MAX_LENGTH * sizeof(NODE));

    m_nWidth = MAX_LENGTH;
    m_nHeight = 1;
    m_nLeft = MAX_LENGTH / 2;
    m_nRight = MAX_LENGTH / 2;
    m_nCx = MAX_LENGTH / 2;
    m_nCy = 0;
    m_nDir = 1;
    m_pCur = m_Maze + m_nCx;
}

void Maze::TurnLeft() {
    m_nDir += 3;
    m_nDir &= 0x3;
    m_pCur->pPass[m_nDir] = TYPE_PASS;

}

void Maze::TurnRight() {
    m_nDir += 1;
    m_nDir &= 0x3;
    m_pCur->pPass[m_nDir] = TYPE_PASS;
    m_pCur->pPass[(m_nDir + 3) & 0x3] = TYPE_UNPASS;
    m_pCur->pPass[(m_nDir + 2) & 0x3] = TYPE_UNPASS;
}

void Maze::Turn180() {
    m_nDir += 2;
    m_nDir &= 0x3;
    m_pCur->pPass[(m_nDir + 3) & 0x3] = TYPE_UNPASS;
    m_pCur->pPass[(m_nDir + 2) & 0x3] = TYPE_UNPASS;
    m_pCur->pPass[(m_nDir + 1) & 0x3] = TYPE_UNPASS;
}

void Maze::Move() {
    m_pCur->pPass[m_nDir] = TYPE_PASS;
    switch (m_nDir) {
        case 0:
            m_nCx++;
            m_pCur++;
            if (m_nRight < m_nCx)m_nRight = m_nCx;
            break;
        case 1:
            m_nCy++;
            m_pCur += m_nWidth;
            if (m_nHeight < m_nCy)m_nHeight = m_nCy;
            break;
        case 2:
            m_nCx--;
            m_pCur--;
            if (m_nLeft > m_nCx)m_nLeft = m_nCx;
            break;
        case 3:
            m_nCy--;
            m_pCur -= m_nWidth;
            break;
        default:
            break;
    }
    m_pCur->pPass[(m_nDir + 2) & 0x3] = TYPE_PASS;
}

void Maze::MoveOnly() {
    m_pCur->pPass[m_nDir] = TYPE_PASS;
    switch (m_nDir) {
        case 0:
            m_nCx++;
            m_pCur++;
            break;
        case 1:
            m_nCy++;
            m_pCur += m_nWidth;
            break;
        case 2:
            m_nCx--;
            m_pCur--;
            break;
        case 3:
            m_nCy--;
            m_pCur -= m_nWidth;
            break;
        default:
            break;
    }
    m_pCur->pPass[(m_nDir + 2) & 0x3] = TYPE_PASS;
}

void Maze::Print() {
    int x, y;

    for (y = 1; y <= m_nHeight; y++) {
        NODE *pLine = m_Maze + y * m_nWidth + m_nLeft;
        for (x = m_nLeft; x <= m_nRight; x++, pLine++) {
            int nVal = 0;
            if (pLine->pPass[0] == TYPE_PASS) nVal += 8;
            if (pLine->pPass[1] == TYPE_PASS) nVal += 2;
            if (pLine->pPass[2] == TYPE_PASS) nVal += 4;
            if (pLine->pPass[3] == TYPE_PASS) nVal += 1;
            if (nVal <= 9) nVal += '0';
            else nVal = nVal - 10 + 'a';
            printf("%c", nVal);
        }
        printf("\n");
    }
}

int main() {
    int nRound;
    int i, j;
    FILE *fp;
    char pFir[MAX_LENGTH], pSec[MAX_LENGTH];
    Maze maze;


    scanf("%d", &nRound);

    for (i = 0; i < nRound; i++) {
        maze.Clean();

        scanf("%s%s", pFir, pSec);
        for (j = 0; j < MAX_LENGTH; j++) {
            if (pFir[j + 1] == '/0') break;
            if (pFir[j] == 'W') maze.Move();
            if (pFir[j] == 'L') maze.TurnLeft();
            if (pFir[j] == 'R') {
                if (pFir[j + 1] == 'R') {
                    maze.Turn180();
                    j++;
                }
                else {
                    maze.TurnRight();
                }
            }
        }
        maze.MoveOnly();
        maze.Turn180();
        for (j = 0; j < MAX_LENGTH; j++) {
            if (pSec[j + 1] == '/0') break;
            if (pSec[j] == 'W') maze.Move();
            if (pSec[j] == 'L') maze.TurnLeft();
            if (pSec[j] == 'R') {
                if (pSec[j + 1] == 'R') {
                    maze.Turn180();
                    j++;
                }
                else {
                    maze.TurnRight();
                }
            }
        }
        maze.MoveOnly();
        printf("Case #%d:\n", i + 1);
        maze.Print();
    }
    return 0;
}

