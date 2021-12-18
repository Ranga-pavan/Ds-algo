class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int minnum=INT_MAX,maxnum=INT_MIN;
        int n=nums.size();
        if(n<2) return 0;
        int maxres=INT_MIN,prev=INT_MIN;
        for(int i=0;i<n;i++){
            minnum=min(minnum,nums[i]);
            maxnum=max(maxnum,nums[i]);
        }
        int gap;
        if(minnum==maxnum) return 0;
        gap=(maxnum-minnum)/(n-1);
        if((maxnum-minnum)%(n-1)!=0){
           gap++;
       }
        vector<int>maxarr(n,INT_MIN);
        vector<int>minarr(n,INT_MAX);
        int index;
        for(int i=0;i<n;i++){
            index=(nums[i]-minnum)/gap;
            maxarr[index]=max(maxarr[index],nums[i]);
            minarr[index]=min(minarr[index],nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if(minarr[i]==INT_MAX ) continue;   //bucket have no values
            if(prev==INT_MIN) prev=maxarr[i];   
            else{
                maxres=max(maxres,minarr[i]-prev);  //currbucketmin - prevbucketmax gives maxgap
                prev=maxarr[i];
            }
        }
        return maxres;
        
    }
};


Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
