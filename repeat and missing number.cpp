vector<int> Solution::repeatedNumber(const vector<int> &A)
{
int n = A.size();
long int ss = 0;
long int s = long(n*long(n+1))/2;
long int S = long(n*long(n+1)*long(2*n+1))/6;
long int SS = 0;

for(int i = 0;i<n;i++)
{
ss += A[i];
SS += long(A[i])*long(A[i]);
}

long int x = ss - s;
long int y = SS - S;
long int z = y/x;

long int a = long(x+z)/2;
long int b = z - a;

return {a,b};
}
