class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        st.push(0);
        for(int i=1;i<nums.size();i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                res[st.top()]=nums[i];
                st.pop();
                //st.push(i);
            }
            st.push(i);
        }
        int i=0,top,flag=1;
        while(!st.empty()){
            top=st.top();
            st.pop();
            i=0;
            flag=1;
            while(i<top){
                if(nums[top]<nums[i]){
                    res[top]=nums[i];
                    flag=0;
                    break;
                }
                i++;
            }
            if(flag==1) res[top]=-1;
        }
        return res;
    }
};
////////////////////////////////optimized
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> st;
        int n=nums.size();
        for(int i=0;i<2*nums.size();i++){                                   /for 'iouae' is come frm rotated 'aeiou' consider 'iouae-iouae' two times and find it 
            while(!st.empty() && nums[i%n]>nums[st.top()]){
                res[st.top()]=nums[i%n];
                st.pop();
                //st.push(i);
            }
            if(i<n) st.push(i%n);
        }
        
        return res;
    }
};
