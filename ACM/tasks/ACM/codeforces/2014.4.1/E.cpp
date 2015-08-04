#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
double check(int a, int b){
	double aa=a/2.0;
	return aa*b/sqrt(double(aa*aa+b*b));
}
int main(){
	int a, b;
	double x;
	scanf("%lf",&x);
	//printf("%.4lf", gao(10, 3));
	for(int i=1; i<=10; i++)
		for(int j=1; j<=10; j++)
			if(check(i,j)+1e-4>x && check(i,j)-1e-4<x){printf("%d %d\n", i, j);return 0;}
}

