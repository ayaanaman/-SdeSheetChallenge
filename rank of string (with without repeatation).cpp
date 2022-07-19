#define Max 1000003
using namespace std;
void findFact(vector<long long>& fact)
{
    fact[0]=1;
    for(int i=1;i<fact.size();i++)
    {
        fact[i]=((fact[i-1]%Max)*i)%Max;
    }
}

void findFreq(vector<int>& freq, vector<long long>& Dfact, string &A)
{
    freq[A[A.size()-1]-'A']++;
    Dfact[A.size()-1]=1;
    for(int i=A.size()-2;i>=0;i--)
    {    
        freq[A[i]-'A']++;
        Dfact[i]=(Dfact[i+1]%Max)*freq[A[i]-'A'];
        Dfact[i]%=Max;
    }
}

int findRank(string A) {
    vector<long long>fact(A.size()),Dfact(A.size());
    findFact(fact);
    vector<int>freq(58,0);
    findFreq(freq,Dfact,A);
    long ans=0;
    
    for(int n=0;n<A.size();n++)
    {
        char ch=A[n]; 
        int count=0;
        for(int i=0;i != ch-'A';i++)
        {
            if(freq[i]) 
                count+=freq[i];
        }
        
        //cout<<count<<"-"<<Dfact[n]<<" ";
        
        freq[ch-'A']--;
        ans=(ans%Max)+(fact[A.size()-1-n]/Dfact[n]*count)%Max;
        
    }
    return (ans+1)%Max;
}
int main() {
    string A;
    int t=0;
    cin>>t;
    while(t--){
        cin>>A;
        cout<<findRank(A)<<endl;
    }
    return 0;
}
