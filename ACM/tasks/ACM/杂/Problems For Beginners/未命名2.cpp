#include<iostream>
using namespace std;
int main ()
{
	char a[50];
	cin.getline(a,100);
	char b[100];
	int n=0;
	for(int i=0;a[i]!='\0';i++)
	{
		n++;
		b[i]=a[i];
	}
	for(int i=0;a[i]!='\0';i++)
	{
		b[2*n-i-1]=a[i];
	}
	b[2*n]='\0';
	cout<<b;
	return 0;
}
	
	
	
	
