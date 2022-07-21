#define Max 1000003
void findFact(vector<long long>&fact)
{
    fact[0]=1;
    for(int i=1;i<fact.size();i++)
    {
        fact[i]=(fact[i-1]*i);
        fact[i]%=Max;
    }
}

void findFreq(vector<long long> &Dfact, vector<int> &freq, string &A)
{
    freq[A[A.size()-1]-'A']++;
    Dfact[A.size()-1]=1;
    
    for(int i=A.size()-2;i>=0;i--)
    {
        freq[A[i]-'A']++;
        Dfact[i]=(Dfact[i+1])*(freq[A[i]-'A']);
        Dfact[i]%=Max;
    }    
}

long long power(long long a,int b,int mod)
{
    if(b==0) return 1;
    long long t=power(a,b/2,mod);
    if(b%2==0)
        return (t%mod * t%mod)%mod;
    else
        return (a%mod * t%mod * t%mod)%mod;
}

int Solution::findRank(string A) {
    vector<long long>fact(A.size(),1),Dfact(A.size(),1);
    vector<int>freq(60,0);
    findFact(fact);
    findFreq(Dfact,freq,A);
    long long ans=0;
    for(int n=0;n<A.size();n++)
    {
        char ch=A[n];
        int count=0;
        for(int i=0;i != ch-'A';i++)
        {
            count+=freq[i];            
        }
        freq[A[n]-'A']--;
        ans=(ans%Max + (((count%Max * fact[A.size()-1-n]%Max)%Max)*power(Dfact[n],Max-2,Max)%Max)%Max)%Max;

        /*
            farmet theorem:
            (a/b)%mod = (a%mod *power(b,mod-2)%mod)%mod) 
        */
    }
    return (ans+1)%Max;
}
