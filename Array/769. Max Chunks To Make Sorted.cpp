class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),prefixmax=INT_MIN,res=0;
        for(int i=0;i<n;i++){
            prefixmax=max(arr[i],prefixmax);    //when index = prefixmax notes
            if(i==prefixmax) res++;
         }
        return res;
    }
};

index  0 1 2 3 4 5
arr    1 2 0 4 3 5  //input
prefix 1 2 2 4 4 5
max

op 3 
  https://leetcode.com/problems/max-chunks-to-make-sorted/
