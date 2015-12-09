#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

string ans[19] = {
    "-1", "-1", "-1", "-1",
    "1 * 2\n5 + 3\n6 + 4", //4
    "-1", //5
    "1 + 2\n7 + 3\n8 + 4\n9 + 5\n10 - 6", //6
    "1 + 2\n8 + 3\n9 / 4\n5 / 6\n11 + 7\n12 * 10", //7
    "1 + 2\n9 + 3\n4 - 5\n11 * 6\n12 * 7\n13 * 8\n14 + 10", //8
    "1 + 2\n10 + 3\n4 / 5\n6 / 7\n8 / 9\n11 - 12\n15 - 13\n16 - 14", //9
    "1 + 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 + 12\n16 + 13\n17 + 14\n18 + 15", //10
    "1 / 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 + 12\n13 + 14\n17 * 18\n19 * 15\n20 * 16", //11
    "1 + 2\n13 + 3\n14 + 4\n15 + 5\n16 + 6\n17 + 7\n18 - 8\n19 - 9\n20 - 10\n21 - 11\n22 - 12", //12
    "2 / 3\n4 / 5\n6 / 7\n8 / 9\n10 / 11\n12 / 13\n1 - 14\n15 + 16\n20 * 21\n22 * 17\n23 * 18\n24 * 19", //13
    "1 + 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 / 12\n13 / 14\n15 - 16\n22 - 17\n23 - 18\n24 - 19\n25 - 20\n26 + 21", //14
    "2 / 3\n4 / 5\n6 / 7\n8 / 9\n10 / 11\n12 / 13\n14 / 15\n1 - 16\n23 - 17\n24 - 18\n19 + 20\n25 * 26\n27 * 21\n28 * 22", //15
    "1 + 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 / 12\n13 / 14\n15 / 16\n18 + 19\n20 + 21\n22 + 23\n25 * 26\n28 * 27\n29 * 24\n17 - 30", //16
    "2 / 3\n4 / 5\n6 / 7\n8 / 9\n10 / 11\n12 / 13\n14 / 15\n16 / 17\n18 + 19\n20 + 21\n22 + 23\n26 * 27\n29 * 28\n30 - 24\n31 * 25\n32 + 1", //17
    "1 + 2\n3 / 4\n5 / 6\n7 / 8\n9 / 10\n11 / 12\n13 / 14\n15 / 16\n17 / 18\n20 + 21\n22 + 23\n24 + 25\n30 + 26\n31 * 28\n32 * 29\n33 * 27\n19 - 34", //18
};

int main()
{
    //freopen("1009.out","w",stdout);
    int n;
    //for(int n = 5; n <= 100; n++) if(n!=5)
    while(~scanf("%d", &n))
    {
        //printf("%d\n", n);
        if(n <= 18) printf("%s\n", ans[n].c_str());
        else if(n % 2 == 0) {
            REP(i,n/2)
                printf("%d / %d\n", i*2+1, i*2+2);
            int cur = n + n / 2;
            printf("%d + %d\n", n + 1, n + 2); // cur + 1.
            printf("%d + %d\n", n + 3, n + 4); // cur + 2.
            printf("%d * %d\n", cur + 1, cur + 2); // cur + 3
            printf("%d + %d\n", n + 5, n + 6); // cur + 4.
            printf("%d + %d\n", cur + 4, n + 7); // cur + 5.
            printf("%d + %d\n", n + 8, n + 9); // cur + 6.
            printf("%d * %d\n", cur + 5, cur + 6); // cur + 7
            printf("%d * %d\n", cur + 3, cur + 7); // cur + 8
            REP2(i,cur+8,n*2-2) {
                printf("%d * %d\n", i, n + 10 + i-(cur+8));
            }
        }else if(n <= 45) {
            REP(i,n/2) {
                printf("%d / %d\n", i*2+2, i*2+3);
            }
            int l = n+1, r = n + n/2;
            int res = n;
            int pos = 1;
            int cur = r + 1;
            while(l <= r) {
                if(res < 24) {
                    printf("%d + %d\n", pos, l++);
                    res++;
                }else if(res > 24) {
                    printf("%d - %d\n", pos, l++);    
                    res--;
                }else{
                    printf("%d * %d\n", pos, l++);    
                }
                pos = cur++;
            }
        }else{
            REP(i,n/2) {
                printf("%d / %d\n", i*2+2, i*2+3);
            }
            int l = n+1, r = n + n/2;
            int res = n;
            int pos = 1;
            int cur = r + 1;
            while(res != 1) {
                if(res % 2 == 0) {
                    printf("%d + %d\n", l, l+1); l+=2;
                    printf("%d / %d\n", pos, cur++);
                    res /= 2;
                }else{
                    printf("%d - %d\n", pos, l++);    
                    res--;
                }
                pos = cur++;
            }
            
            // l ~ pos
            
            cur = pos;
            printf("%d + %d\n", l, l+1); // cur + 1.
            printf("%d + %d\n", l+2, l+3); // cur + 2.
            printf("%d * %d\n", cur + 1, cur + 2); // cur + 3
            printf("%d + %d\n", l+4, l+5); // cur + 4.
            printf("%d + %d\n", cur + 4, l+6); // cur + 5.
            printf("%d + %d\n", l+7, l+8); // cur + 6.
            printf("%d * %d\n", cur + 5, cur + 6); // cur + 7
            printf("%d * %d\n", cur + 3, cur + 7); // cur + 8
            REP2(i,cur+8,n*2-2) {
                printf("%d * %d\n", i, i == n*2-2?pos : l+9 + i-(cur+8));
            }
        }
    }
    return 0;
}
