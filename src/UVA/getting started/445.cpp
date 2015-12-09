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

int main() {
    char a[5000];
    memset(a, '\0', 5000);
    while (cin.getline(a, 5000)) {
        //int len=strlen(a.c_str());
        //int len=strlen(a);
        int num = 0;
        for (int i = 0; a[i] != '\0'; i++) {
            //	cout<<a[i]<<endl;
            if (a[i] >= 48 && a[i] <= 57) {
                num += (a[i] - 48);
            }
            if (a[i] >= 65 && a[i] < 91 || a[i] == 42) {
                while (num--) {
                    cout << a[i];
                }
                num = 0;
            }
            if (a[i] == 98) {
                while (num--) {
                    cout << " ";
                }
                num = 0;
            }
            if (a[i] == 33) {
                cout << endl;
            }

        }
        cout << endl;
        memset(a, '\0', 5000);
    }
    return 0;
}






