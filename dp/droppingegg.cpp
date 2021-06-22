class Solution
{
    public:
    int solve(int e,int n,int **dp){            //1-find i,j
        
        if(n==0 || n==1) return n;                        //2- have to write base case
        if(e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        int res =INT_MAX,low,high;
           for(int k=1;k<=n;k++){
               //int temp=max(solve(e,n-k,dp),solve(e-1,k-1,dp))+1;
               if(dp[e][n-k]==-1) low=solve(e,n-k,dp);                //3-  k sequence loop
               else low=dp[e][n-k];
               if(dp[e-1][k-1]==-1) high=solve(e-1,k-1,dp);
               else high=dp[e-1][k-1];
               int temp=max(low,high)+1;                           
               if(res>temp) res=temp;                //4-  find ans from tempans
           }
           return dp[e][n]=res;
    }
    int eggDrop(int e, int n) 
    {
        int **dp=new int*[e+1];
        for(int i=0;i<=e;i++){
            dp[i]=new int[n+1];
        }
        for(int i=0;i<=e;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        /*for(int i=0;i<e;i++){ 
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[1][i]=i;
        }
        for(int i=1;i<=e;i++){
            dp[i][1]=1;
        }*/
        //if(n==0 || n==1) return dp[e][n]=n;  
        //if(e==1) return dp[e][n]=n;
        int res=solve(e,n,dp);
        return res;
    }
};
