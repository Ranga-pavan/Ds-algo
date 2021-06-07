class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=1 && nums[i]<=n && nums[i]!=i+1){
                while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){      //nums[i]-1 should equal tonums[i]
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
