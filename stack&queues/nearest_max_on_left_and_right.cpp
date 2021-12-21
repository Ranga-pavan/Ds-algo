MAXSPPROD interviewbit

int Solution::maxSpecialProduct(vector<int> &arr) {
    stack<int> s;
    vector<int> left;
    int n=arr.size();
    if(n==1 || n==2) return 0;
    stack<int> stack0;
    stack <int> stack1;
    stack0.push(0);                     //index
    
    for(int i=1;i<arr.size()-1;i++){
        while(!stack0.empty() && arr[stack0.top()]<=arr[i]){
            stack0.pop();
        }
        if(stack0.empty()) left.push_back(0);         //here leaving 1st and last index making top alwayes greater if empty then 0 else stacktop index one nearest left max
        else left.push_back(stack0.top());
        stack0.push(i);
    }
    
    long long maxnum=-1,num;
    stack1.push(n-1);
    for(int i=n-2;i>=1;i--){
        while(!stack1.empty() && arr[stack1.top()]<=arr[i]){
            stack1.pop();
        }
        if(stack1.empty()) num=0;
        else{
            num=(left[i-1]*stack1.top()*1LL);
            
        }
        if(num>maxnum){
                maxnum=num;
        }
        stack1.push(i);
    }
    
    return maxnum%1000000007;
}
