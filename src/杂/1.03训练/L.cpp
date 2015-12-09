#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<iterator>
using namespace std ;

struct dic
{
	string word;
	string sorted;
}a[111],b[10000];
string ddd[10000];


int main()
{
//	string ddd[1000];
	int i,j,count;
	int num=0;
	for(i=0;cin>>a[i].word&&a[i].word!="XXXXXX";i++)
	{
		a[i].sorted=a[i].word;
		sort(a[i].sorted.begin(),a[i].sorted.end());
	}
	for(j=0;cin>>b[j].sorted&&b[j].sorted!="XXXXXX";j++)
	{
		sort(b[j].sorted.begin(),b[j].sorted.end());
	}
	for(int ii=0;ii<j;ii++)
	{
		count=0;
		num=0;
		for(int jj=0;jj<i;jj++)
		{
			if(b[ii].sorted==a[jj].sorted)
			{
				//cout<<a[jj].word<<endl;
				count++;
				ddd[num++]=a[jj].word;
			
			}
		}
		if(count>1)
		{
			sort(ddd,ddd+num);
		
			for(int kk=0;kk<num;kk++)
			{
				cout<<ddd[kk]<<endl;
			}
		}
		else
		{
			if(count==1)cout<<ddd[0]<<endl;
			if(count==0)
			{
				cout<<"NOT A VALID WORD"<<endl;
			}
		}
		
		cout<<"******";
		cout<<endl;
	}
	return 0;
}


	
	
	
	
	
	
