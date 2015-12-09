//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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

int main() {
    ios::sync_with_stdio(0);
    int t;
    scanf("%d", &t);
    while (t--) {
        int b0, b1, b2, w0, w1, w2;
        scanf("%d%d%d%d%d%d", &w0, &w1, &w2, &b0, &b1, &b2);
        if (w1 % 2 == 1 || b1 % 2 == 1) {
            printf("-1\n");
            continue;
        } else if ((b2 <= 2 && b2 >= 1 && b1 == 0) || (w2 <= 2 && w2 >= 1 && w1 == 0)) {
            printf("-1\n");
            continue;
        } else if ((b2 == 0 && b1 == 2) || (w2 == 0 && w1 == 2)) {
            printf("-1\n");
            continue;
        } else {
            int m = w1 / 2 + w2 + b1 / 2 + b2;
            int n = w1 + w2 + w0;
            printf("%d\n", m);
            //if(!)
            if (w2) {
                printf("1 2 1\n");
                for (int i = 2; i <= w2; i++) {
                    printf("%d %d 1\n", i, i + 1);
                }

                //if(w2>1){
                printf("%d %d 1\n", w2 + 1, w2 + 2);
                //}
                for (int i = w2 + 3; i <= w2 + w1; i += 2) {
                    printf("%d %d 1\n", i, i + 1);
                }
            } else {
                for (int i = 1; i <= w1; i += 2) {
                    printf("%d %d 1\n", i, i + 1);
                }
            }
            if (b2) {
                int i, j;
                printf("1 3 0\n");
                for (i = 2, j = 3; i <= b2; i++, j += 2) {
                    if (j > n)j = 2;
                    if (j + 2 > n) {
                        printf("%d 2 0\n", j);
                        j = 0;
                        continue;
                    }
                    printf("%d %d 0\n", j, j + 2);
                }
                // printf("2 %d 0\n",j);
                //printf("%d\n",j);
                int f = j;
                if (f == 2) {
                    if (n & 1)f = n;
                    else f = n - 1;
                }
                j += 2;
                if (j > n)j = 2;
                printf("%d %d 0\n", f, j);
                //j+=2;
                for (int i = 3; i <= b1; j += 4, i += 2) {
                    if (j > n)j = 1;
                    if (j + 2 > n) {
                        printf("%d 2 0\n", j);
                        j = 0;
                        continue;
                    }
                    printf("%d %d 0\n", j, j + 2);
                }
            } else {
                for (int i = 1, j = 2; i <= b1; i += 2, j += 4) {
                    if (j > n)j = 1;
                    if (j + 2 > n) {
                        printf("%d 2 0\n", j, 1);
                        j = 0;
                        continue;
                    }
                    printf("%d %d 0\n", j, j + 2);
                }
            }
            /*for(int i=1;i<w2;i++){
                printf("%d %d 0\n",i,i+1);
            }
            for(int i=w2+1;i<=w1+w2;i+=2){
                printf("%d %d 0\n",i,i+1);
            }*/
            /*if(w2==1){
                printf("1 2 0\n");
                printf("1 3 0\n");
                for(int i=4;i<=w1+1;i+=2){
                    printf("%d %d 0\n",i,i+1);
                }
            }else if(w2==2){
                printf("1 2 0\n");
                printf("1 3 0\n");
                printf("2 4 0\n");
                for(int i=5;i<=w1+2;i+=2){
                    printf("%d %d 0\n",i,i+1);
                }
            }else{
                if(w2){
                    printf("1 %d 0\n",w2);
                    for(int i=1;i<w2;i++){
                        printf("%d %d 0\n",i,i+1);
                    }
                }
                for(int i=w2+1;i<=w2+w1;i+=2){
                    printf("%d %d 0\n",i,i+1);
                }
            }
            if(b2==1){
                printf("1 2 1\n");
                printf("1 3 1\n");
                for(int i=4;i<=b1+1;i+=2){
                    printf("%d %d 1\n",i,i+1);
                }
            }else if(b2==2){
                printf("1 2 1\n");
                printf("1 3 1\n");
                printf("2 4 1\n");
                for(int i=5;i<=b1+2;i+=2){
                    printf("%d %d 1\n",i,i+1);
                }
            }else{
                if(b2){
                    printf("1 %d 1\n",b2);
                    for(int i=1;i<b2;i++){
                        printf("%d %d 1\n",i,i+1);
                    }
                }
                for(int i=b2+1;i<=b2+b1;i+=2){
                    printf("%d %d 1\n",i,i+1);
                }
            }*/



        }
    }
    return 0;
}
