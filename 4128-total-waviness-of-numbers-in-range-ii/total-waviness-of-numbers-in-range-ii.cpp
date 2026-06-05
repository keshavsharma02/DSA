long long dp[17][2][17][12][12][2];

long long fun(int i,string &s,int t,int cnt,int p,int q,int st){
    if(i>=s.size()) return cnt;

    long long l=0;

    if(t==1){
        l=s[i]-'0';
    }else{
        l=9;
    }

    long long m=0;

    if(dp[i][t][cnt][p+1][q+1][st]!=-1) return dp[i][t][cnt][p+1][q+1][st];

    for(int j=0;j<=l;j++){
        long long nc=cnt;

        if(st==0 && j==0){
          m+=fun(i+1,s,(t&(j==l)),nc,p,q,0); 
        }

        else if( (st==0 && j!=0) || st==1){

        if(p!=-1 && q!=-1){
           if( (q>j && q>p) || (q<j && q<p) ){
              nc++;
           }
           m+=fun(i+1,s,(t&(j==l)),nc,q,j,1); 
        }
        else{
           m+=fun(i+1,s,(t&(j==l)),nc,q,j,1);
        }

        }
    }

    return dp[i][t][cnt][p+1][q+1][st]=m;
}

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        string s1=to_string(num1-1);
        string s2=to_string(num2);

        memset(dp,-1,sizeof(dp));
        long long l=fun(0,s1,1,0,-1,-1,0);
        memset(dp,-1,sizeof(dp));
        long long r=fun(0,s2,1,0,-1,-1,0);


        return r-l;
    }
};