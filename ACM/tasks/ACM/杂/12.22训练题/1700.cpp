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
	int n,num=0;
	while(cin>>n)
	{
		if(n==0)
		return 0;
		if(num!=0)
		cout<<"\n\n";
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Qsort(a,n);
		for(int h=0;h<n-5;h++)
		{
			for(int i=h+1;i<n-4;i++)
			{
				for(int j=i+1;j<n-3;j++)
				{
					for(int k=j+1;k<n-2;k++)
					{
						for(int l=k+1;l<n-1;l++)
						{
							for(int m=l+1;m<n;m++)
							{
								cout<<a[h]<<" "<<a[i]<<" "
									<<a[j]<<" "<<a[k]<<" "
									<<a[l]<<" "<<a[m];
									if(h!=n-6||i!=n-5||j!=n-4||k!=n-3||l!=n-2||m!=n-1)
									cout<<endl;
							}
						}
					}
				}
			}
		}
		num++;
	}
	return 0;
}
		
