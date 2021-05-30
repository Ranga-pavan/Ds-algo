class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=-1,r=-1,resl=0,resr=0,minval=INT_MAX,maxval=INT_MIN;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    minval=min(minval,nums[i+1]);
                }
            }
            for(int i=nums.size()-1;i>=1;i--){
                if(nums[i]<nums[i-1]){
                    maxval=max(maxval,nums[i-1]);                                     //find peak elements
                }
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]>minval){
                    l=i;
                    break;
                }
            }
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]<maxval){
                    r=i;
                    break;
                }
            }
            if(l==-1) return 0;
        cout<<l<<" "<<r;
            return r-l+1;
        
    }
};
