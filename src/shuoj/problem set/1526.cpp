#include<iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[2 * n], min = 1000000000;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = n; i < 2 * n; i++)a[i] = a[i - n];
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = i; j < i + n; j++) {
                for (int k = j + 1; k < i + n; k++) {
                    if (a[j] > a[k])temp++;
                }
            }
            if (temp < min)min = temp;

        }
        printf("%d\n", min);
    }
    return 0;
}
					
		
		
		
		
