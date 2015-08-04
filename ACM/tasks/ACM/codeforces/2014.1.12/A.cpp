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

int num[1010];//vis[1010];

int main()
{
	int n;
	while(cin>>n)
	{
	//	int sum=0;
		memset(num,0,1010);
		//memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		//	sum+=num[i];
		}
		int fir=0,sec=0;
		int left=0,right=n-1;
		for(;;)
		{
			if(num[right]>num[left])
			{
				fir+=num[right];
				right--;
				if(left>right)break;
				if(num[right]>num[left])
				{
					sec+=num[right];
					right--;
					if(left>right)break;
				}
				else
				{
					sec+=num[left];
					left++;
					if(left>right)break;
				}
			}
			else
			{
				fir+=num[left];
				left++;
				if(left>right)break;
				if(num[right]>num[left])
				{
					sec+=num[right];
					right--;
					if(left>right)break;
				}
				else
				{
					sec+=num[left];
					left++;
					if(left>right)break;
				}
			}
		//	cout<<fir<<" "<<sec<<endl;
		}
		cout<<fir<<" "<<sec<<endl;
	}
	return 0;
}
		
		
	
	
	
	
	
	
	
	
	
	
