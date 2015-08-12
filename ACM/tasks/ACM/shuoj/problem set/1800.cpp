#include <iostream>  
using namespace std;  
int n=0;  
int main()  
{  
    ios::sync_with_stdio(false); 
	int t;
	cin>>t; 
    while(t--)  
    {  
    	cin>>n;
        if(n<=100&&n>=90)  
        {  
            cout<<"A"<<endl;  
        }  
        else if(n<90&&n>=80)  
        {  
            cout<<"B"<<endl;  
        }  
        else if(n<80&&n>=70)  
        {  
            cout<<"C"<<endl;  
        }  
        else if(n<70&&n>=60)  
        {  
            cout<<"D"<<endl;  
        }  
        else if(n<60)  
        {  
            cout<<"E"<<endl;  
        }  
    }  
    return 0;  
}  
