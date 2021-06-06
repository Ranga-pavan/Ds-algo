class Solution {
public:
    //with path compresion parent array changes
    int findpar(int u,int parent[]){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findpar(parent[u],parent);
    }
    void unions(int u,int v,int parent[],vector<int>& nums){
        int x=findpar(u,parent);
        int y=findpar(v,parent);
        parent[x]=parent[y];
        
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int parent[n];
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            parent[i]=i;            //parent contains indexes
            map[nums[i]]=i;
        }
        for(auto it:map){               //duplicate numbers will come so only one considers 2nd case 0 2times
            int i=it.second;               //map[0]=8th index
            if(map.count(nums[i]+1)){
                unions(i,map[nums[i]+1],parent,nums);
                
            }
        }
        /*for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }*/
        cout<<endl;
        map.clear();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            int k=findpar(i,parent);
            map[k]++;
            //cout<<"nums[i]="<<nums[i]<<" k="<<k<<" ";
            //cout<<endl;
            if(map[k]>max) max=map[k];
        }
        /*for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }*/
        return max;
    }
};




class Solution {
public:
    //without path compresion parent array not changes
    int findpar(int u,int parent[]){
        if(u==parent[u]){
            return u;
        }
        return findpar(parent[u],parent);
    }
    void unions(int u,int v,int parent[],vector<int>& nums){
        int x=findpar(u,parent);
        int y=findpar(v,parent);
        parent[x]=parent[y];
        
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int parent[n];
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            parent[i]=i;            //parent contains indexes
            map[nums[i]]=i;
        }
        for(auto it:map){               //duplicate numbers will come so only one considers 2nd case 0 2times
            int i=it.second;               //map[0]=8th index
            if(map.count(nums[i]+1)){
                unions(i,map[nums[i]+1],parent,nums);
                
            }
        }
        /*for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }*/
        cout<<endl;
        map.clear();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            int k=findpar(i,parent);
            map[k]++;
            //cout<<"nums[i]="<<nums[i]<<" k="<<k<<" ";
            //cout<<endl;
            if(map[k]>max) max=map[k];
        }
        /*for(int i=0;i<n;i++){
            cout<<parent[i]<<" ";
        }*/
        return max;
    }
};
