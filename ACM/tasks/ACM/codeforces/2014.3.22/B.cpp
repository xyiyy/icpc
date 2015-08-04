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
char li[3010];
int main()
{
	int n,num;
	int fl,fr;
	while(cin>>n)
	{
		fl=-1;fr=-1;
		num=0;
		for(int i=0;i<n;i++)
		{
			cin>>li[i];
		}
		for(int i=0;i<n;i++)
		{
			if(li[i]=='.')continue;
			if(li[i]=='L'&&fr==-1)
			{
				fl=i;
				continue;
			}
			if(li[i]=='R'&&i==0)
			{
				fr=0;
				continue;
			}
			if(li[i]=='R'&&i!=0)
			{
				fr=i;
				num+=fr-fl-1;
				continue;
			}
			if(li[i]=='L')
			{
				fl=i;
			//	cout<<fl<<fr<<endl;
				if((fl-fr)%2==0)num++;
				continue;
			}
		}
		//cout<<num<<endl;
		//cout<<fl<<fr;	
		if(fl>fr&&fl!=-1)num+=n-fl-1;
		//num+=n;
		if(fl==fr)num=n;
		cout<<num<<endl;
			
			
			
			
		
		
	}
	return 0;
}
	




