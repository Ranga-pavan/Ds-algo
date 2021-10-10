int calculateMedianOfMatrix(vector<vector<int> > &m) {
    int l = INT_MAX, h = INT_MIN,r=m.size(),c=m[0].size();
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < l)
            l = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > h)
            h = m[i][c-1];
    }
	int desired=(r*c+1)/2,mid,cnt;
	while(l<h){
		mid=l+(h-l)/2;
		cnt=0;
		for(int i=0;i<r;i++){
			cnt+=(upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin());
		}
		if(cnt<desired){
			l=mid+1;
		}
		else h=mid;
	}
	return l;
}

1 2 3
3 3 4
1 1 2
Median: 2
 1 1 1 2 |2| 3 3 3 4  r,c always odd
