https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1/#

Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Example 1:

Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
Example 2:

Input: 
n = 5
arr[] = {1, 45, 47, 50, 5}
Output: 50
Explanation: Maximum element is 50.maximum element in an array which is first increasing and then decreasing


class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int l=0,h=n-1;
	    int m;
	    while(l<=h){
	        m=l+(h-l)/2;
	        if((m==0 || arr[m-1]<arr[m]) && (m==n-1 || arr[m]>arr[m+1])){
	            return arr[m];
	        }
	        else if(arr[m-1]>arr[m]){
	            h=m-1;
	        }
	        else l=m+1;
	    }
	    return -1;
	}
};
