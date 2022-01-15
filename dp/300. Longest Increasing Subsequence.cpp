https://www.interviewbit.com/problems/longest-increasing-subsequence/


Input 1:
    A = [1, 2, 1, 5]

Output 1:
    3
    
Explanation 1:
    The sequence : [1, 2, 5]


int Solution::lis(const vector<int> &A) {
    int n=A.size(),maxlen=1;
    vector<int> lis(n,1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[j]>A[i] && lis[i]>=lis[j]){
                lis[j]=lis[i]+1;
                maxlen=max(lis[j],maxlen);
            }
        }
    }
    return maxlen;
}

class Solution {
public:
    int lowerbound(vector<int> &arr,int num){
    int l=0,h=arr.size()-1,m;
    while(l<h){
        m=l+(h-l)/2;
        if(num<=arr[m]) h=m;
        else l=m+1;
    }
    return l;
}
    int lengthOfLIS(vector<int>& A) {
    vector<int> lis;
    int n=A.size();
    lis.push_back(A[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(A[i]>lis[len-1]){
            lis.push_back(A[i]);
            len++;
        }
        else{
            int index=lowerbound(lis,A[i]);
            lis[index]=A[i];
        }
   
    }
    return len;
    }
};
