#include<iostream>
#include<iomanip>
#include<cmath> 

using namespace std;

int main() {
    int N, M;
    double p, q;
    while (cin >> N >> M >> p >> q) {
        if (N == 0) printf("0.00\n");
        else {
            if (M == 0) printf("1.00\n");
            else {
                if (p == 0 || q == 1) {
                    printf("0.00\n");
                }
                else {
                    double k = q * (1 - p) / (p * (1 - q));
                    double a = 0.0, b = 0.0;
                    for (int i = 0; i < N; i++) {
                        a += pow(k, i);
                    }
                    for (int i = 0; i < N + M; i++) {
                        b += pow(k, i);
                    }
                    double l = 0.0;
                    l = a / b;
                    cout << fixed << setprecision(2) << l << endl;
                }
            }
        }
    }
    return 0;
}


		 
