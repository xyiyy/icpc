#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
pair<int,pair<int,int> >p[110];
int main(){
    ios::sync_with_stdio(0);
    int i= 0;
    char c;
    while(cin>>p[i].second.first>>c>>p[i].second.second>>c>>p[i].first)i++;
    sort(p,p+i);
    for(int j=0;j<i;j++){
        cout<<setw(2)<<setfill('0')<<p[j].second.first<<c<<setw(2)<<setfill('0')<<p[j].second.second<<c<<setw(4)<<setfill('0')<<p[j].first<<endl;
    }


    return 0;
}
