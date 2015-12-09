#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int a[100], b[100];
int c[200];

int main() {
    int N, k = 1;
    cin >> N;
    while (N--) {
        int n, m, num = 0;
        cin >> n;
        memset(a, 0, 100);
        memset(b, 0, 100);
        memset(c, 0, 200);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[i] = a[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            c[i + n] = b[i];
        }
        sort(c, c + n + m);
        /*for(int i=0;i<n+m;i++)
        {
            if(c[i]!=0)cout<<" "<<c[i];
        }*/
        for (int i = 0; i < n + m; i++) {
            i = 0;
            while (c[i] == 0 || (c[i + 1] - c[i] > 1 && i < n + m - 1)) {
                i++;
            }

            if (c[i + 1] - c[i] == 0) {
                c[i] = c[i] - 2;
                c[i + 1] = c[i + 1] + 1;
            }
            if (c[i + 1] - c[i] == 1) {
                c[i] = 0;
                c[i + 1] = c[i + 1] + 1;
            }
            sort(c, c + n + m);
            for (int i = 0; i < n + m; i++) {
                if (c[i] != 0)cout << " " << c[i];
            }
            cout << endl;
        }
        for (int i = 0; i < n + m; i++) {
            if (c[i] != 0)num++;
        }
        cout << "Case " << k++ << ":" << endl;
        cout << num;
        for (int i = 0; i < n + m; i++) {
            if (c[i] != 0)cout << " " << c[i];
        }
        cout << endl;
    }
    return 0;
}
					
			
		







