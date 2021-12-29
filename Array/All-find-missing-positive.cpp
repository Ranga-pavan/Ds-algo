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


442. Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>duplicates;
        //for(int k=0;k<8;k++) cout<<k<<" ";
        //cout<<endl;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            else duplicates.push_back(abs(nums[i]));
        }
        return duplicates;
    }
};

287. Find the Duplicate Number

Given an array of integers nums containing // n + 1 // integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
    
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])]<0) return abs(nums[i]);
            nums[abs(nums[i])]*=-1;
        }
        return n;
    }
};
