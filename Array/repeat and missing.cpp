int *findTwoElement(int *arr, int n) {
        static int res[2];
        int index=0;
        for(int i=0;i<n;i++){
            index=abs(arr[i])-1;
            //cout<<arr[index]<<" ";
            if(arr[index]<0) res[0]=abs(arr[i]);
            else arr[index]=-1*arr[index];
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                res[1]=i+1;
                break;
            }
        }
        //cout<<res[0]<<" "<<res[1];
        return res;
    }


Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
