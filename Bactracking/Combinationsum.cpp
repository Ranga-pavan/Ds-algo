class Solution {
public:
    vector<vector<int> >res;
    void solve(vector<int>& arr,int j,int target,vector<int> ans){
        if(target<0) return ;
        if(target==0){
            res.push_back(ans);
            return ;
        }
        for(int i=j;i<arr.size();i++){
        ans.push_back(arr[i]);
        solve(arr,i,target-arr[i],ans);
        ans.pop_back();
        
    }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        solve(candidates,0,target,ans);
        return res;
    }
};
