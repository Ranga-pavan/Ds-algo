class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        vector<int> res;
        int n=a.size();
        for(int i=0;i<n;i++){
            //cout<<a[dq.front()]<<" ";
            while(!dq.empty() && i-k>=dq.front()) dq.pop_front();    //if it is outside window simply popfront
            while(!dq.empty() && a[i]>=a[dq.back()]){          //checking from back to find max inside subarray
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) res.push_back(a[dq.front()]);                //add start from kth index
        }
        return res;
    }
};
//leetcode
