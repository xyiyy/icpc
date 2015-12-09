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

int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main() {
    long long a, b, n = 0, m = 0;
    int k = 0;
    while (cin >> a >> b) {
        if (k)cout << endl;
        cout << "Case " << ++k << ":" << endl;
        if (a == 0 && b == 0) {
            cout << "no GCD" << endl;
            cout << "no LCM" << endl;
            continue;
        }
        else if (a == 0 || b == 0) {
            cout << "GCD(" << a << "," << b << ") = " << abs(a + b) << endl;
            cout << "no LCM" << endl;
            continue;
        }
        int gcd = abs(__gcd(a, b));
        int lcm = abs(a / gcd * b);
        cout << "GCD(" << a << "," << b << ") = " << gcd << endl;
        cout << "LCM(" << a << "," << b << ") = " << lcm << endl;
    }
    return 0;
}
