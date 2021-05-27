class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int l=0,r=0,maxlen=0;
        set<char> set;
        while(r<s.size()){
            auto it=set.find(s[r]);
            if(it==set.end()){   //inserting upto no
                set.insert(s[r]);//repeating character comes
                if(set.size()>maxlen) maxlen=set.size();
                r++;
            }
            else{
                set.erase(s[l]);//clearing upto repeated
                l+=1;           //character deletes 
            }
        }
        return maxlen;
    }
};
