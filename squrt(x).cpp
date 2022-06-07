class Solution {
public:
    int mySqrt(int x) 
    {
        long long l=0,h=x/2,ans=0;
        
        while(l<=h)
        {
            long long int m=(h+l)/2;
            if(m*m==x)
                return m;
            else
            if(m*m<x)
                l=m+1;
            else
                h=m-1;
        }
     if(l*l>x)
         return l-1;
     return h;
    }
};
