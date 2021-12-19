class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=1 && nums[i]<=n && nums[i]!=i+1){
                while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){      //nums[i]-1 should equal tonums[i]  which means -- 
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

--nums[i]-1 should equal tonums[i]
index     0 1 2 3 4
nums[i]   1 2 3 4 5

    
//not all testcases passed
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int correctpos,n=nums.size();
        for(int i=0;i<nums.size();i++){
            correctpos=nums[i]-1;               //overflow occurs at INT_MIN 
            while(1<=nums[i] && nums[i]<=n && nums[i]!=nums[correctpos]){      //whenever not equal to nums[correctpos] where it actually be will swap 
                swap(nums[i],nums[correctpos]);
                correctpos=nums[i]-1;
            }
        }
        for(int i=0;i<n;i++){
            if( nums[i]!=i+1) return i+1;                   //correctpos is at index+1
        }
        return n+1;
    }
};
