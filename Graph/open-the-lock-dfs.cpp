class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        unordered_map<string,bool>visited;
        for(int i=0;i<deadends.size();i++){
            visited[deadends[i]]=true;                        //deadends are visited
        }
        if(visited["0000"]) return -1;
        visited["0000"]=true;
        q.push("0000");
        int size,level=0;                                   //level start with 0
        string str,temp0,temp1;
        while(!q.empty()){
            size=q.size();
            for(int l=0;l<size;l++){
                str=q.front();
                q.pop();
                //cout<<str<<" ";
                if(target==str){
                    return level;
                }
                for(int i=0;i<4;i++){
                    temp0=str;
                    temp1=str;
                    if(temp0[i]=='9') temp0[i]='0';
                    else temp0[i]+=1;
                    if(visited[temp0]==false){
                        visited[temp0]=true;
                        q.push(temp0);
                    }
                    if(temp1[i]=='0') temp1[i]='9';
                    else temp1[i]-=1;
                    if(visited[temp1]==false){
                        visited[temp1]=true;
                        q.push(temp1);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
