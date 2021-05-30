#include <iostream>
using namespace std;
int hasbitset(int n,int k){
    int temp;
    temp=n & 1<<k;             //left shift one k bits to find kth bit set
    return temp==1;
}
int main() {
    int a[6]={1,3,1,2,2,6};
    int k=0,temp,all=0;
    for(int i=0;i<6;i++){
        all^=a[i];
    }
    int ans[2]={0,0};
    while(hasbitset(all,k)==0)
        k++;
    for(int i=0;i<6;i++){                           
        ans[hasbitset(a[i],k)]^=a[i];              //kth bit set goto 0 index remaining 1 index
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<k;
}
