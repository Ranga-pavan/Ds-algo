void reverse(vector<int> &arr,int i,int j){
	while(i<j){
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
}

void nextGreaterPermutation(vector<int> &arr) {
    int n=arr.size()-1,flag=0,greaternum;
	for(int i=n;i>=1;i--){
		if(arr[i]>arr[i-1]){
			flag=1;
			int temp=arr[i-1];
			for(int k=i;k<=n;k++){
				if(arr[k]>temp){
					greaternum=k;
				}
				else break;
			}
			swap(arr[i-1],arr[greaternum]);
			reverse(arr,i,n);
			break;
		}
	}
	if(flag==0){
		reverse(arr,0,n);
	}
	
}
