class Solution {
public:
    int calculate(string p) {
        stack<int>st;
        int i=0,k=0,curnum=0,l=0;
        string s="";
        for(int j=0;j<p.size();j++){
            if(p[j]!=' '){
                s+=p[j];
            }
        }
        while(s[l]>='0' && s[l]<='9' && l<s.size()){        //number may contain more than one dight
                curnum=curnum*10+(s[l]-'0');
                l++;
            }
        st.push(curnum);
        i=l;
        while(i<s.size()){
            l=i+1;
            curnum=0;
            while(s[l]>='0' && s[l]<='9' && l<s.size()){
                curnum=curnum*10+(s[l]-'0');
                l++;
            }
            
            if(s[i]=='-' || s[i]=='+'){
                if(s[i]=='-') k=-1*(curnum);
                else k=curnum;
                st.push(k);
            }
            else if(s[i]=='/' || s[i]=='*'){
                if(s[i]=='/'){
                    k=st.top()/(curnum);
                }
                else if(!st.empty()) k=st.top()*(curnum);
                st.pop();
                st.push(k);
            }
            i=l;
        }
        int res=0;
        while(!st.empty()){                       //without stack we can use adding each num to res from start
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
