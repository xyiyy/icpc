#include<iostream>  
#include<stdio.h>  
using namespace std;  
int a[1000005];  
void phi_table(int n , int * phi)//筛选法求欧拉函数  
{  
 for(int i=2 ; i<= n; i++) phi[i] = 0;  
 phi[1]= 1;  
 for(int i =2; i<=n ;i ++)  
  if(!phi[i])  
  for(int j = i ; j<=n; j+=i)  
  {  
   if(!phi[j]) phi[j] = j;  
   phi[j] = phi[j] /i*(i-1);  
  }  
}  
int main()  
{  
 int n;  
 phi_table(1000001,a);  
 while(scanf("%d",&n)==1)  
 {
 	int cas=1;
 	for(int i=0;i<n;i++)
 	{
 		if(a[a[i]]<=a[a[n]]&&(a[i]&1))
 		{
 			if(cas++)printf(" ");
		 	printf("%d",i) ;
		}	
	}
	printf("\n");	
    // printf("%d/n",a[a[n]]);  
 }  
}  
