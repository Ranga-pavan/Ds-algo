class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),a,b,x,y,ans=1;
        vector<int>dx={1,0,-1,0,1,-1,1,-1};
        vector<int>dy={0,1,0,-1,-1,1,1,-1};
        if(grid[0][0]==1 || grid[n-1][n-1]==1 || n==0)
            return -1;
        queue<pair<int,int> >q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;j++){
            pair<int,int> curr=q.front();
            q.pop();
            a=curr.first;
            b=curr.second;
            if(a==n-1 && b==n-1) return ans;
            for(int i=0;i<8;i++){
                x=a+dx[i];
                y=b+dy[i];
                
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0){
                    grid[x][y]=1;
                    q.push({x,y});
                }
            }
            }
            ans++;
        }
        return -1;
    }
};
//leetcode 1091
