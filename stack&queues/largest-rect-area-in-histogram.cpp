class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> st;
        int i = 0;
        int maxarea=0,tp,area;
            while(i<n){
                if(st.empty() || h[st.top()]<=h[i]){                  //if coming val(6) is more than top add to stack hence rectangle formed
                    st.push(i);                                       //h[st.top()](2) not <= 1
                    i++;                                              // in 1 5 6 2
                }
                else{                                                 //(2 came)else pop(6,5) val upto which  rectangle forms  6*(3-1(5)-1) first next 5*(3-0(1)-1) 
                    tp=st.top();
                    st.pop();
                    area = h[tp]*(st.empty()? i:i-st.top()-1);
                    if(maxarea<area)
                    {
                        maxarea = area;
                    }
                }
            }
        while(!st.empty()){
            tp=st.top();
            st.pop();
            
            area = h[tp]*(st.empty()? i:i-st.top()-1);          //if stack is empty it is the minimum it is equal to length and no s.top() also 
            if(maxarea<area){                                   //i is next smaller element st.top() is first element of that rectangle
                maxarea = area;
            }
        }
        return maxarea;
    }
};
