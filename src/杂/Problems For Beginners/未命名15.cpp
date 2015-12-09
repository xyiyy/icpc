#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) {
            cout << n << "/2=";
            n /= 2;
            cout << n << endl;
        }
        else {
            cout << n << "*3+1=";
            n = 3 * n + 1;
            cout << n << endl;
        }
    }
    return 0;
}
		
		
