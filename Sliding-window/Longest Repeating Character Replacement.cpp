class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxnum=0,res=0;
        unordered_map<int,int> count;
        for(int i=0;i<s.size();i++){
            count[s[i]]+=1;             
            maxnum=max(maxnum,count[s[i]]);
            if(res<k+maxnum)            //res < k(can replace) maxnum=charcter having more times in window
                res+=1;                 //k characters can replace with maxnum characters for repeating char
            else{
                count[s[i-res]]-=1;         //res holds answer lower one deleted if res more
            }
        }
        return res;
    }
};
