https://www.interviewbit.com/problems/flip/
output shoud be range of [L,R] where flip of 0 to 1 and vice versa gives max no of 1's
  Example Input
Input 1:

A = "010"
Input 2:

A = "111"


Example Output
Output 1:

[1, 1]  -> 1 indexing gives "110" so two ones
Output 2:

[]

Example Explanation
Explanation 1:

A = "010"


Pair of [L, R] | Final string
____________|__________
[1 1]          | "110"
[1 2]          | "100"
[1 3]          | "101"
[2 2]          | "000"
[2 3]          | "001"



We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

Explanation 2:

No operation can give us more than three 1s in final string. So, we return empty array [].


vector<int> Solution::flip(string A) {
    int count=0,n=A.size(),maxcount=0,last=0,l=0,r=0;
    for(int i=0;i<n;i++){
        if(A[i]=='0'){
            count+=1;
        }
    }
    if(count==0) return {};
    count=0;
    for(int i=0;i<n;i++){
        if(A[i]=='0'){
            count+=1;               //count always store count(0) - count(1)
        }
        else count-=1;
        if(count>maxcount){         //like kadanes algo finding start and end index
            maxcount=count;
            l=last;                 //start index for given range
            r=i;                    // r is the curr index 
        }
        if(count<0){
            count=0;                //any time count becomes < 0 leave upto this 
            last=i+1;               //start next index no change in l,r if end index is not there hence l,r already stored for answer
        }
    }
    return {l+1,r+1};
}
