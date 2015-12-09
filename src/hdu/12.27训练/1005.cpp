#include<iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int a[5][300];
    while (T--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 300; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 300; i++) {
            for (int j = 0; j < 300; j++) {
                for (int k = 0; k < 300; k++) {
                    for (int l = 0; l < 300; l++) {
                        for (int m = 0; m < 300; m++)
