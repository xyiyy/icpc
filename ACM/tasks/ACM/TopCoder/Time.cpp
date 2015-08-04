#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
class Time{
public:
	string  whatTime(int n){
	int h,m,s;
	h=n/3600;
	m=(n%3600)/60;
	s=n%60;
	char buf[110];
	sprintf(buf,"%d:%d:%d",h,m,s);
 string ss(buf);
 return ss;
	}
	};


// Powered by FileEdit
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by CodeProcessor
