//1297. Maximum Number of Occurrences of a Substring

Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 ocurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
Example 3:

Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
Output: 3
Example 4:

Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
Output: 0  
  
  
class Solution {
public:
    int maxFreq(string s, int maxletters, int minsize, int maxsize) {
        int n=s.size(),uniquecnt=0;
        vector<int> letter(26,0);
        map<string,int> rescnt;
        int ans=0,j=0;
        for(int i=0;i<n;i++){
            if(letter[s[i]-'a']==0) uniquecnt++;
            letter[s[i]-'a']++;
            int flag=0;
            while(i-j+1>minsize){                               
                if(letter[s[j]-'a']==1) uniquecnt--;
                letter[s[j]-'a']--;
                j++;
            }
            if(i-j+1==minsize && uniquecnt<=maxletters)     //checking only for minsize 
                ans=max(ans,++rescnt[s.substr(j,i-j+1)]);
        }
        return ans;
    }
};

//Which esentially means that since the substring of size greater than minSize starisfies the constraint of distinct letters <= maxLetters there will be a substring of this selected substring of size minSize that'll satisfy the same constraint and the frequency of this substring will be atleast as much as the parent substring.
//We also know that number of shorter substrings are more than the longer ones , thus we only need to check for substrings of minSize satisfying the condition.
