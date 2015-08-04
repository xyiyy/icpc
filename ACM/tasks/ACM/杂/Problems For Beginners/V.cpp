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

int fun(int *a,int m)
{
	int x=a[1]-a[0];
	for(int i=2;i<m;i++)
	{
		if(a[i]-a[i-1]!=x)
		{
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}
		

int main()
{
	int n,m;
	cin>>n;
	for(int j=0;j<n;j++)
	{
		if(j!=0)
		{
			cout<<endl;
		}
		cin>>m;
		int a[m];
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		Qsort(a,m);
		if(m==1||m==2)
		{
			cout<<"yes";
		}
		else
		{
			fun(a,m);
		}
	}
	return 0;
}
			
