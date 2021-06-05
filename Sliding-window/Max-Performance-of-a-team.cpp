class Solution {
public:
    #define ll long long
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll,ll> > v;
        for(ll i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),[](pair<ll,ll> &p1,pair<ll,ll> &p2){             //sort in decreasing order because
           return p1.first>p2.first;              //if efficiency taken as minimum only upper efficiency speeds taken
        });                                       //lower ones have min efficiency
        priority_queue<ll,vector<ll> ,greater<ll> >pq;//min heap for distances size graeter than k remove min distance
        ll i=0,currspeed,curreff,res=0,tot=0;
        pair<int,int> curr;
        while(i<n){
            curr=v[i];
            currspeed=curr.second;
            curreff=curr.first;
            
            if(pq.size()>k-1){                  // hence currspeed is taken below checking for k-1 size
                tot-=pq.top();
                pq.pop();
            }
            pq.push(currspeed);                 //curr speed is taken
            tot+=currspeed;
            res=max(res,tot*curreff);           //speed * curreff
            i++;
        }
        return (int)(res%1000000007);
    }
};
