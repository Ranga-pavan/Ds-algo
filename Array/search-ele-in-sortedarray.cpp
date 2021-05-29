class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid,low=0,high=nums.size()-1;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){
                if(target<nums[mid] && target>=nums[low])
                    high=mid-1;
                else
                   low=mid+1;
            }
            else{
                if(nums[mid]<target && nums[high]>=target)
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};
