https://www.interviewbit.com/problems/combination-sum/
in leetcode inputs are only distinct

Given candidate set 2,3,6,7 and target 7,

A solution set is:

[2, 2, 3]
[7]

void backtrack(int curr,int target,vector<int> temp,vector<vector<int>> &res,vector<int> &A){
    if(target<0 || curr==A.size()) return ;
    if(target==0){
        res.push_back(temp);
        return ;
    }
        temp.push_back(A[curr]);
        backtrack(curr,target-A[curr],temp,res,A);          //one element can choose unlimited no of times
        temp.pop_back();
        backtrack(curr+1,target,temp,res,A);
}
 
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector<int>>res;
    vector<int> temp;
    vector<int> arr;
    arr.push_back(A[0]);
    for(int i=1;i<A.size();i++){        //for unique combinations duplicate should not there
         if(A[i]!=A[i-1]){
            arr.push_back(A[i]);
        }
    }
    backtrack(0,B,temp,res,arr);
    return res;
}

Before 1 element can choose infinite times after one can choose only one time 
for loop ensures   take or not take current element

https://www.interviewbit.com/problems/combination-sum-ii/
lt-40
  

void backtrack(int start,int target,vector<int> temp,vector<vector<int>> &res,vector<int> &A){
    if(target<0 ) return ;
    if(target==0){
        res.push_back(temp);
        return ;
    }
    for(int i=start;i<A.size();i++){
        if(i>start && A[i]==A[i-1]) continue;     //if it's not there unique combinations will not produce duplicate will produce ->1
        if(target<A[i]) break;        //check this hence sorted
        temp.push_back(A[i]);
        backtrack(i+1,target-A[i],temp,res,A);    //if duplicate there i+1 ensures for one can choose only one time
        temp.pop_back();
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> ans;
    vector<vector<int>> res;
    sort(A.begin(),A.end());
    backtrack(0,B,ans,res,A);
    return res;
}

->1  
Wrong Answer  Runtime: 3 ms
Your input
[1,1,1,1,1]
4
Output
        [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]
indices [[0,1,2,3],[0,1,2,4],[0,1,3,4],[0,2,3,4],[1,2,3,4]]
Expected
[[1,1,1,1]]

