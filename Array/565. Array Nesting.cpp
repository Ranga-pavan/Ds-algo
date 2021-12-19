 range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... }
Return the longest length of a set s[k]

Example 1:

Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
Example 2:

Input: nums = [0,1,2]
Output: 1


865 / 885 test cases passed.
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int res=0,maxres=INT_MIN,curpos,curnum;
        for(int i=0;i<n;i++){
            res=1;
            curpos=nums[i];
            curnum=nums[i];
            while(nums[curpos]!=curnum){    //checking with is the nuumber is in correctposition or not, curpos is nums[i] (range[0,n-1])
                curpos=nums[curpos];
                res++;
            }
            maxres=max(res,maxres);
        }
        return maxres;
    }
};

//all pass
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int res=0,maxres=INT_MIN,curpos,curnum;
        for(int i=0;i<n;i++){
            if(nums[i]<0) continue;
            res=1;
            curpos=nums[i];
            curnum=nums[i];
            nums[i]*=-1;
            while(nums[curpos]>=0 && nums[curpos]!=curnum){
                nums[curpos]*=-1;
                curpos=abs(nums[curpos]);
                res++;
            }
            maxres=max(res,maxres);
        }
        return maxres;
    }
};
