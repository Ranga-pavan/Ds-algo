class Solution {
public:
    vector<string> res;
    void dfs(string digits,string ans,unordered_map<char,string> &map,int index,int &n){
        //cout<<"l---"<<ans<<" "<<index<<" ";
        if(index==n){
            //cout<<"l-l-"<<ans<<" ++"<<endl;
            res.push_back(ans);
            return ;
        }
        else{
            string str=map[digits[0]];
            //cout<<str<<" "<<index<<" ";
            string k=digits.substr(1);            //in k take string as from 1st index 
            //cout<<"k="<<k<<" ";
            for(int i=0;i<str.size();i++){
                ans+=str.substr(i,1);             //and 1 character of that index each time
                dfs(k,ans,map,index+1,n);
                ans=ans.substr(0,ans.size()-1);             //add and remove
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}};
        int n=digits.size();
        if(n==0) return {};
        dfs(digits,"",map,0,n);
        return res;
    }
};
