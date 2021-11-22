/*
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.


Input: nums = [-1,0]
Output: [-1,0]
*/




class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalxor=0;
        for(int i=0;i<nums.size();i++) totalxor^=nums[i];
        int rightmost=0;
        cout<<totalxor<<" ";
        while(true){
            if(totalxor&(1<<rightmost)){
                break;
            }
            rightmost++;
        }
        cout<<"rightmost="<<rightmost<<endl;
        int bucket1=0,bucket2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<rightmost)){
                //cout<<nums[i]<<" ";
                bucket1^=nums[i];
            }
            else bucket2^=nums[i];
        }
        return {bucket1,bucket2};
    }
};
