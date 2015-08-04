#include<iostream>  
#include<cstring>  
using namespace std;  
int main()  
{  
    char word[1000],check[1000];  
    int round,i,j,flag[26],los,get,sum;  
    while(cin>>round&&round!=-1)  
    {  
        cout<<"Round "<<round<<endl;  
        cin>>word;  
        cin>>check;  
        memset(flag,0,sizeof(flag));  
        los=get=sum=0;  
        for(i=0;word[i]!='\0';i++)  
        {  
            if(flag[word[i]-'a']==0)  
            {  
                flag[word[i]-'a']=1;  
                sum++;  
            }  
        }  
        for(i=0;check[i]!='\0';i++)  
        {  
            if(flag[check[i]-'a']==0)  
            {  
                flag[check[i]-'a']=-1;  
                los++;  
            }  
            else  
            {  
                if(flag[check[i]-'a']==1)  
                {  
                    flag[check[i]-'a']=2;  
                    get++;  
                }  
            }  
            if(los==7||get==sum)  
                break;  
        }  
        if(los==7)  
            cout<<"You lose."<<endl;  
        else  
        {  
            if(get==sum)  
                cout<<"You win."<<endl;  
            else  
                cout<<"You chickened out."<<endl;  
        }  
    }  
    return 0;  
}
