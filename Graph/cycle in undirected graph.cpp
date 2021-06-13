#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int find(vector<int> &parent,int num){
    for(int i=1;i<5;i++){
        cout<<" n= "<<parent[i];
    }
    cout<<endl;
    while(parent[num]!=-1){
        //cout<<"{}"<<num<<" "<<parent[num]<<endl;
        num=parent[num];                                    //in a cycle last one and first one checking last gives as last because parent[x]=x if it is -1 and first traverse  
    }                                                       //upto last make both node parent equal cycle forms
    return  num;
}
bool solve(int A, vector<vector<int> > &edge) {
     vector<int>parent(A+1,-1);
    for(int i=0;i<edge.size();i++){
        int x=find(parent,edge[i][0]);
        int y=find(parent,edge[i][1]);
        cout<<edge[i][0]<<" "<<edge[i][1]<<"went"<<endl;
        cout<<x<<" "<<y<<"parent"<<endl;
        cout<<"{}"<<endl;
        if(x==y)
            return 1;
        parent[x]=y;                          //both parents equal
    }
    return 0;
}
int main() {
    vector<vector<int> >edge{{1,2},{1,4},{2,3},{3,4}};
    bool x=solve(4,edge);
    cout<<"x="<<x;
}
