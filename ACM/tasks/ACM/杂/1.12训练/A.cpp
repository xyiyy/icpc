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
map<int,vector<int> > a;  
int main()  
{  
	int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
		a.clear();  
		for(int i=0;i<n;i++)  
		{  
			int num;  
			scanf("%d",&num);  
			if(!a.count(num))  
			a[num]=vector<int>();  
			a[num].push_back(i+1);  
		}  
		for(int i=0;i<m;i++)  
		{  
        	int p,q;  
        	scanf("%d%d",&p,&q);  
        	if(!a.count(q)||a[q].size()<p)  
        	printf("0\n");  
        	else  
        	printf("%d\n",a[q][p-1]);   
		}  
  	}  
    return 0;  
}  














