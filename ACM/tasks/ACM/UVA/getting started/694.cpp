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

int main()
{
	long long n,m;
	int k=1;
	while(cin>>n>>m&&(n!=-1||
	m!=-1))
	{
		int count=0;
		long long num=n;
		while(num!=1&&num<=m)
		{
			if(num%2==0)
			{
				num/=2;
				count++;
			}
			else if(num%2==1)
			{
				num=3*num+1;
				count++;
			}
			if(num==1)
			count++;
		}
		cout<<"Case "<<k++<<": A = "<<n<<", limit = "<<m<<", number of terms = "<<count<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
