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
#define BIGNUM 500000
int sto[110][110];

int main()
{
	int n=1;
	//cout<<BIGNUM<<endl;
	while(cin>>n&&n!=0)
	{
		int num,c;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				sto[i][j]=BIGNUM;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>num;
			for(int j=0;j<num;j++)
			{
				cin>>c;
				cin>>sto[i][c];
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(sto[i][k]<BIGNUM&&sto[k][j]<BIGNUM&&((sto[i][k]+sto[k][j])<sto[i][j]))
					{
						sto[i][j]=sto[i][k]+sto[k][j];
					}
				}
			}
		}
		int r=0,minn=BIGNUM;
		for(int i=1;i<=n;i++)
		{
			int m=0;
			for(int j=1;j<=n;j++)
			{
				if(j!=i&&m<sto[i][j])//continue;
				//m=max(m,sto[i][j]);
				m=sto[i][j];
			}
			if(m<minn)
			{
				minn=m;
				r=i;
			}
		}
		//if(minn<BIGNUM)
		cout<<r<<" "<<minn<<endl;
		//else
		//{
		//	cout<<"disjoint"<<endl;
		//}
	}
	return 0;
}
			






