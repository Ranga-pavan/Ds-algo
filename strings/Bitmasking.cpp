//1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> map; //<parity,index>
        vector<char> vowels{'a','e','i','o','u'};
        int index,ans=0,parity=0;               //in parity 1 is even 0 isodd
        map[0]=-1;     //hence initially even cnt in "leetcodeisgreat" subract with 4-(-1)=5 at leetc(index 4)  <parity,index>
        for(int i=0;i<s.size();i++){
            auto it=find(vowels.begin(),vowels.end(),s[i]);
            if(it!=vowels.end()){
                index=it-vowels.begin();
                parity^=1<<index;                   //1 becomes 0 means odd become even and vice versa
            }
            if(map.count(parity)){
                 ans=max(ans,i-map[parity]);            //if it present odd-odd=even,even - even = even
            }
            else{
                map[parity]=i;
            }
        }
        return ans;
    }
};
//bit masking

1542. Find Longest Awesome Substring

class Solution {
public:
    int longestAwesome(string s) {
        int parity=0,ans=1,index,tempparity;
        unordered_map<int,int> map;
        map[0]=-1;
        for(int i=0;i<s.size();i++){
            index=s[i]-'0';
            parity^=1<<index;
            if(map.count(parity)) ans=max(ans,i-map[parity]);           //even-even=even palindrome can form
            else map[parity]=i;
            tempparity=parity;
            for(int j=0;j<=9;j++){
                tempparity=parity;
                tempparity^=1<<j;
                if(map.count(tempparity)) ans=max(ans,i-map[tempparity]);     //change 1 bit palindrome with
                //else map[tempparity]=i;                                     //odd digits
            }
            
        }
        return ans;
    }
};



1915. Number of Wonderful Substrings

class Solution {
public:
    long long wonderfulSubstrings(string s) {
        int parity=0;
        long long ans=0;
        unordered_map<int,vector<int> > map;
        map[0]={1};             //initially with 1 size
        for(int i=0;i<s.size();i++){
            parity^=1<<(s[i]-'a');
            if(map.count(parity)) ans+=map[parity].size();          //all indexes can form even cnt substrings
            map[parity].push_back(i);
            for(int j=0;j<=9;j++){
                if(map.count(parity^(1<<j))) ans+=map[parity^(1<<j)].size();    //checking odd cnt
            }
        }
        return ans;
    }
};
