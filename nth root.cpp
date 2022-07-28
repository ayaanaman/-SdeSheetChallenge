bool isCheck(double num,double m,int n){
    for(int i=0;i<n;i++)
        m=m/num;
    
    if(m<=1.00)
        return true;
    return false;
}
double findNthRootOfM(int n, int m) {
	double l=0,h=m;
    
    for(int i=0;i<100;i++){
        double mid=(l+h)/2.0;
        if(isCheck(mid,m,n)){
            h=mid;
        }
        else{
            l=mid;
        }
    }
    return (l+h)/2.0;
}
