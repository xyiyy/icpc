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
	int N;
	cin>>N;
	while(N--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int j;
			for(j=1;j<n+1;j++)
			{
				int k=j;
				while(k--)
				{
					cout<<j;
				}
				cout<<endl;
			}
			for(j=n-1;j!=0;j--)
			{
				int k=j;
				while(k--)
				{
					cout<<j;
				}
				cout<<endl;
			}
			if(i<m-1)
			cout<<endl;
		}
		if(N)cout<<endl;
	}
	return 0;
}




