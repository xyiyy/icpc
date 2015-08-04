#include <iostream>  
#include <cstdio>  
using namespace std;  
int main(){  
    int nCase;  
    cin>>nCase;  
    while(nCase--)
	{  
    	int DNA[11];  
    	int l=0;  
    	while(l<10)
		{  
    		scanf("%d",&DNA[l]);  
      	  l++;  
    	} 
		int dish[43];  
  		int t_dish[43];  
   		for(int i=0;i<=41;i++)
		{  
    		dish[i]=(i==20?1:0);  
			t_dish[i]=dish[i];  
   		}  
    	l=0;  
    	while(l++<50)
		{  
    		for(int i=1;i<=40;i++)
			{  
        		t_dish[i]=dish[i];  
            	switch(dish[i])
				{  
            		case 0:printf(" ");break; 
					case 1:printf(".");break;  
            	    case 2:printf("x");break;  
            	    case 3:printf("W");break;  
            	}  
        	}  
        	cout<<endl;  
        	for(int i=1;i<=40;i++)
			{  
        		dish[i]=DNA[t_dish[i-1]+t_dish[i]+t_dish[i+1]];       
        	}  
    	}  
    	if(nCase!=0)cout<<endl;  
    }        
    return 0;  
}  

