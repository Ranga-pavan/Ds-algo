class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*'){
                dp[0][i]=true;
                }
            else{
                break;
            }
        }
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*') dp[i][j]=dp[i][j-1] || dp[i-1][j];          // consider both cases of '*'
                else if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];     //equal or ? both letters will removed checked opposite
                else dp[i][j]=false;
                
            }   
        }
        /*cout<<endl;
        cout<<"  ";
        for(int i=0;i<=m;i++){
            if(i>=1) cout<<s[i-1]<<" ";
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        return dp[m][n];
    }
};
