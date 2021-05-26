class Solution {
public:
    vector<string> res;
    void helper(string ans,int &n,int openb,int closeb){
        if(closeb==n && openb==n){
            res.push_back(ans);
            return ;
        }
        else{
            if(openb<n){
                helper(ans+'(',n,openb+1,closeb);
            }
            if(openb>closeb){
                helper(ans+')',n,openb,closeb+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans="";
        helper(ans,n,0,0);
        return res;
    }
};
//leetcode
