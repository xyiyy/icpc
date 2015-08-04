#include<iostream>
using namespace std;


void Qsort(int *a,int size)
{
	int pivot=a[size-1],temp;
	int left=0,right=size-1;
	if(size<1)return ;
	do
	{
		while(left<right && a[left]<=pivot)left++;
		while(left<right && a[right]>=pivot)right--;
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}while(left<right);
	a[size-1]=a[left];
	a[left]=pivot;
	Qsort(a,left);
	Qsort(a+left+1,size-left-1);
}


int main()
{
	int a[1000],x,y,z;
	int i=0;
	for(int j=0;j<1000;j++)
	{
		a[j]=0;
	}
	char f;
	while(cin>>x>>f>>y>>f>>z)
	{
		a[i]=x+100*y+10000*z;
		i++;
	}
	int b[i];
	for(int j=0;j<i;j++)
	{
		b[j]=a[j];
	}
	Qsort(b,i);
	for(int j=0;j<i;j++)
	{
		int x=b[j]%100;
		b[j]=b[j]/100;
		int y=b[j]%100;
		b[j]=b[j]/100;
		z=b[j];
		
		printf("%02d/%02d/%04d",x,y,z);
		if(j<i-1)
		{
			cout<<endl;
		}
	}
	return 0;
}
	
