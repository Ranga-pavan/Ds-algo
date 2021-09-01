class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        int pivot=nums[r];
        int i=l;                            //doing ascending order i is starting
        for(int j=l;j<r;j++){
            if(nums[j]<=pivot){             //if any less number is there swap with i which is on left 
               swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);              //when i++ i is at position of right so swap with pivot
        return i;                           //pivot right side are larger numbers only
    }
    int quickselect(vector<int>& nums,int l,int r,int k){
        int p=partition(nums,l,r);
        int n=nums.size();
        if(p==n-k) return nums[p];
        if(p>n-k){
            int left=quickselect(nums,l,p-1,k);//checking for lest and right for recursion for kth largest
            return left;
        }
        else{
            int right=quickselect(nums,p+1,r,k);
            return right;
        }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,0,nums.size()-1,k);
        
    }
};
