class Solution {
public:
    string minWindow(string str, string arr) {
        if(str.size() < arr.size()) return "";          //pattern is greater return empty
          unordered_map<char,int> map1;         //pat for number of characters stored
          unordered_map<char,int> map;
          for(auto i:arr){
              map1[i]+=1;
          }  
          int cnt=0,l=0,h,ressize=INT_MAX,start,end;
          for(int i=0;i<str.size();i++){            
            map[str[i]]+=1;
            if(map1[str[i]] && map[str[i]]<=map1[str[i]]){              //increase count only it is less than pattern
              cnt+=1;                                                   //so adding will ncrease count
            }
              //cout<<i<<" "<<"cnt="<<cnt<<" ";
            while(cnt==arr.size()){
              h=i;
              //cout<<"str="<<str.substr(l,h-l+1)<<" ";
              if(h-l+1<=ressize){
                ressize=h-l+1;
                start=l;
                end=h;
              }
              //cout<<str[l]<<" "<<l<<" ";
              map[str[l]]-=1;                       //removing low character
              if(map1[str[l]] && map[str[l]]<map1[str[l]]){     //checking each time if it is less than
                  cnt-=1;                                       //only < not '<=' because after removing also if it is equal
              }                                           //no need to decrease the cnt hence all character present in window
              l++;
              //cout<<"str[l]="<<str[l]<<" "<<str.substr(l,h-l+1)<<" "<<"cnt="<<cnt<<" ";
            }
          }
          if(ressize==INT_MAX) return "";               //still int max return empty
          return str.substr(start,end-start+1);
    }
};
