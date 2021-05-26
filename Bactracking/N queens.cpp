class Solution {
public:
    int cnt=0;
    bool leftside(int n,vector<vector<int>>& board,int i,int j){
        while(j>=0){
            if(board[i][j]==0){
                j-=1;
            }
            else return false;
        }
        return true;
    }
    bool leftupper(int n,vector<vector<int>>& board,int i,int j){
        while(j>=0 && i>=0){
            if(board[i][j]==0){
                j-=1;
                i-=1;
            }
            else return false;
        }
        return true;
    }
    bool leftdown(int n,vector<vector<int>>& board,int i,int j){
        while(j>=0 && i<n){
            if(board[i][j]==0){
                j-=1;
                i+=1;
            }
            else return false;
        }
        return true;
    }
    bool checkpos(int n,vector<vector<int>>& board,int i,int j){
        if(leftside(n,board,i,j) && leftupper(n,board,i,j) && leftdown(n,board,i,j))
            return true;
        return false;
    }
    void checkboard(int n,vector<vector<int>>& board,int col){
        if(col>=n){                 //col==n last col any row is fixed as safe also checks    so res found
            cnt++;
            return ;
        }
        for(int i=0;i<n;i++){                   //checking each row by fixing column in every column
            if(checkpos(n,board,i,col)){        //checking point safe or not       then 1 is put and proceed
                board[i][col]=1;                //making true 
                checkboard(n,board,col+1);      //if res formed by this cnt increase after that
                board[i][col]=0;                //making false
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int> >board(n,vector<int> (n,0)); 
        checkboard(n,board,0);
        return cnt;
    }
};
//leetcode 52
