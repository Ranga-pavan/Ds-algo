class Solution {
public:
    void reverse_arr(vector<int> &nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse_arr(nums,0,n-k-1);  //step 1 reverse 1st part
        reverse_arr(nums,n-k,n-1);  //step 2 reverse 2nd part
        reverse_arr(nums,0,n-1);    //step 3 reverse total similar to reverse words in a string
        
        
        for(int i=0;i!=nums.size();i++){
            cout<<nums[i]<<" ";
        }
    }
};


First, brilliant idea! If the author doesn't mind, here is a good way to explain it:
Think about shifting array [1,2,3,4,5] by k=2:

1,2,3,4,5 -> 4,5,1,2,3
  
 step 1,step 2 : 3,2,1  ,  5,4
 step 3 : totreverse 4,5,1,2,3

If you observe, what we did is: swap left & right sub arrays, where right sub has len=k

(1,2,3),(4,5) -> (4,5),(1,2,3)
