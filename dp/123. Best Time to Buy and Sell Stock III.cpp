Find the maximum profit you can achieve. You may complete at most two transactions.

/*priced initially =                        1     10
amount available starting =                    100
if buy at 1,10 then amount left will be     99    90
99 is maximum so fb=max(fb,-prices[i]);
first buy -> first sell -> second buy -> second sell */

//fb,fs,sb,ss = current avalable prices after performing respective operations

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb=INT_MIN,sb=INT_MIN;
        int fs=0,ss=0;
        for(int i=0;i<prices.size();i++){
            fb=max(fb,-prices[i]);
            fs=max(fs,fb+prices[i]); //when selling time if we sell current stock then initial available money fb added with
            sb=max(sb,fs-prices[i]);           //curr price that is prices[i] so make sur fs is max because
            ss=max(ss,sb+prices[i]);           
        }                                      //
        return ss;
    }
};
