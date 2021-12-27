Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
catalin number
class Solution {
public:
    int numTrees(int n) {
        int cat[n+1];
        cat[0]=1;
        cat[1]=1;
        if(n==1) return 1;
        cat[2]=2;
        int currnodes=0,currbst=0;
        for(int i=3;i<=n;i++){
            currnodes=i-1;
            currbst=0;
            for(int j=0;j<=currnodes;j++){
                currbst+=(cat[j]*cat[currnodes-j]);
            }
            cat[i]=currbst;
        }
        return cat[n];
    }
};

cat[0]=1 cat[1]=1 cat[2]=2
if n==3 then
currnodes=i-1=3-1=2;  //1 node is root
left        right
cat[0]   *  cat[2]  = 1*2=2
cat[1]   *  cat[1]  = 1*1=1
cat[2]   *  cat[0]  = 2*1=2
  tot = 5 at cat[3]
  
  
