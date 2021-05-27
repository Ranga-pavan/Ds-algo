class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        int flag=0;
        long pow=n;
        if(n==0) return 1;
        if(pow<0){
            pow=pow*(-1);
            flag=1;
        }
        if(n==1 && flag==0)
            return x;
        else if(pow%2==0){
            double k=myPow(x,pow/2);
            res=k*k;
        }
        else{
            double k=myPow(x,pow/2);
            res=k*k*x;
        }
        if(flag==0) return res;
        return (double)1/(double)res;
    }
};
//leetcode
