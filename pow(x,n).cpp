class Solution {
public:
    double help(double x, int n) {
        
        if(n==0) return 1;
        double t=help(x,n/2);
        if(n%2==0)  
            return t*t;

        return x*t*t;
    }
    
    double myPow(double x, int n)
    {
        double ans=help(x,abs(n)/2);
        if(n<0) return (n%2!=0)?(1/(ans*ans*x)):(1/(ans*ans));
        return (n%2!=0)?ans*ans*x:ans*ans;
    }
};
