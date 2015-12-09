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

char a[110][110];
//char b[110][110];

int main()
{
	int count=0;
	int len;
	int maxn=0;
	while(cin.getline(a[count],110))
	{
		len=strlen(a[count]);
		if(len>maxn)maxn=len;
		count++;
	}
	int n=count;
	//int maxn=0;
	/*for(int i=0;i<=n;i++)
	{
		count--;
		
		for(int j=0;j<len;j++)
		{
			b[j][count]=a[i][j];
		}
		
	}*/
	for(int i=0;i<maxn;i++)
	{
		for(int j=count-1;j>=0l;j--)
		{
			if(i<strlen(a[j]))
			{
				cout<<a[j][i];
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
		//cout<<b[i]<<endl;
	}
	return 0;
}
		





