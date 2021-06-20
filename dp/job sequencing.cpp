class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<int> jobs[n];
        for(int i=0;i<n;i++)
        {
            jobs[i]={endTime[i],startTime[i],profit[i]};
        }
        sort(jobs,jobs+n);
        int end[n],start[n],money[n];
        int i=0;
        for(auto j:jobs){
            end[i]=jobs[i][0];
            start[i]=jobs[i][1];
            money[i]=jobs[i][2];
            i++;
        }
        vector<int> gain(n,0);          // dp array stores max profit from 0 to i
        gain[0]=money[0];
        int maxele=0;
        for(int i=1;i<n;i++){
            //gain[i]=max(money[i],gain[i-1]);
            int temp=0;
            for(int j=i-1;j>=0;j--){
                if(start[i]>=end[j]){   //find first non-overlapping interval before i 
                    temp=gain[j];       // last max profit calculated from 0 .. i-1 is end[j]        
                    break;
                }
            }
            gain[i]=max(gain[i-1],temp+money[i]);   //if end[j](temp) + money[i] not greater than
        }                                          //previous profit val gain[i-1] we store it as gain[i-1]
        for(auto i:gain){                           //or else store new val (temp+money[i]) as profit from
            cout<<i<<" ";                           //0 to i-1
            
        }
        return gain[n-1];
    }
};
