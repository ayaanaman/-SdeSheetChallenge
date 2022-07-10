int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n=A.size()/3;
    if(n<1)
        return A[0];
    int num1=-1,num2=-1,cnt1=0,cnt2=0;
    
    for(auto &x:A)
    {
        if(num1==x)
            cnt1++;
        else
        if(num2==x)
            cnt2++;
        else
        if(cnt1==0)
        {
            num1=x;
            cnt1=1;
        }
        else
        if(cnt2==0)
        {
            num2=x;
            cnt2=1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1=0,cnt2=0;
    for(auto &x:A)
    {
        if(num1==x)
            cnt1++;
        else
        if(num2==x)
            cnt2++;
    }
    
    if(cnt1>n)
        return num1;
    else if(cnt2>n)
        return num2;
    return -1;
}
