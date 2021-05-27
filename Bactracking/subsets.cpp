class Solution {
public:
    void solve(vector<int>& nums,int i,int n,vector<int> ans,vector<vector<int>> &set){
       /* cout<<"[";
        for(auto k:set){
            cout<<"[";
            for(auto l:k){
                cout<<l<<",";
            }
            cout<<"]";
        }
        cout<<"] [";
        for(auto k:ans){
            cout<<k<<",";
        }
        cout<<"]"<<endl;*/
        if(i>n-1){
            set.push_back(ans);
            return ;
        }
        
        ans.push_back(nums[i]);
        solve(nums,i+1,n,ans,set);
        ans.pop_back();
        solve(nums,i+1,n,ans,set);      //   { //for [1] push 2 and [1,2] pop 2 sending [1] } 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >set;
        vector<int> ans;
        solve(nums,0,nums.size(),ans,set);
        return set;
    }
};
