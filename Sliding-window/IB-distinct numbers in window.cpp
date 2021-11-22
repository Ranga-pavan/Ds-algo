/*
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1] - 2 distinct numbers
 [2, 1, 3] - 3
 [1, 3, 4] - 3
 [3, 4, 3] - 2
 So, we return an array [2, 3, 3, 2].
 */


vector<int> Solution::dNums(vector<int> &A, int k) {
    unordered_map<int,int> map;
    int dist=0,n=A.size();
    vector<int> res;
    for(int i=0;i<k;i++){
        if(!map[A[i]]){
            map[A[i]]+=1;
            dist+=1;
        }
        else map[A[i]]+=1;
    }
    res.push_back(dist);
    for(int i=k;i<n;i++){
        map[A[i-k]]-=1;
        if(!map[A[i-k]]) dist-=1;
        if(!map[A[i]]){
            map[A[i]]+=1;
            dist+=1;
        }
        else{
            map[A[i]]+=1;
        }
        res.push_back(dist);
    }
    return res;
}
