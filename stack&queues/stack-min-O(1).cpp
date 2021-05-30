stack<long long int>s;
    
        long long int min = 0;
    
    void push(int val) {
        
        if(s.size()==0)
        {
            s.push(val);
            
            min = val;
        }
        
        else if(val>=min)
        {
            s.push(val);
        }
        
        else
        {
            long long int p = 2*(long long)val-min;                         //2*2-7=-3
            s.push(p);
            
            min = val;
        }
    }
    
    void pop() {
        if(s.size()==0) return;
        
        else
        {
            if(s.top()>=min)
            {
                s.pop();
            }
            
            else
            {
                int ov = min;
                
                min = 2*min-s.top();                          //2*2-(-3)=7
                
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.size()==0) return -1;
        
        else
        {
            if(s.top()>=min)
            {
                return s.top();
            }
            
            else
            {
                return min;
            }
        }
    }
    
    int getMin() {
        return min;
    }
/*Here we have 4 functions to complete --> Top , pop , getmin , push
We will take a variable min that will store the current minimum element in the stack.
As we need to maintain the other functions of the stack and as well as the minimum function we have to make an indicator that will tell that the after pushing the current element the minimum value has changed.

For Push: If the val>=min , then simply push the element into the stack , if the val<min , then we need to prepare an indicator as discussed above and we will thus push val+val-min into the stack.Since val<min , therefore val-min will be negative and therefore the value of val+val-min < val.
For Top: if the data at the top is greater than min return the value itself , else return min as min contains the original value of the indicator.
For pop: During Pop we need to take care that if the topmost element is greater than min then simply pop , else we need to pop the element that is equal to min then we will first decrypt the value of the indicator by doing min = 2.min-data.top() and then pop the element , so we are thus ready with the next min.
For getmin: simply return the value of min.
Ex: push --> 8 , 47 , 17 , 7 , 2 and then getmin , pop.

push 8: Stack --> 8 and min = 8
push 47: Stack --> 8 , 47 and min = 8
push 17: Stack --> 8 ,47 , 17 and min = 8
push 7: Stack --> 8 , 47 , 17 , 7+(7-8) and min = 7
push 2: Stack --> 8 , 47 , 17 , 6 , 2+(2-7) and min = 2
Getmin : min ==> min = 2
pop: As stack top is not greater than min then :
s.top() = -3
pop the stack top and update min to min = 2.min-s.top ==> 2.2+3 = 7 which will be the new min*/


//https://leetcode.com/problems/min-stack/discuss/1231813/Min-Stack-in-O(1)-space-and-O(1)-time-complexity-With-step-be-step-explanation
