#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    void addp(string &s,int p,int &c,int k){
        int n = s[k]-'0';
      //  cout<<n<<endl;
        n+=p+c;

       // cout<<n<<endl;
        if(n>=10)
        {
            c = n/10;
            n = n%10;
        }else
            c = 0;
        s[k] = n+'0';
        
    }
    string multiply(string A, string B) {
        int l1 = A.size(),l2 = B.size();
        string res;
        res.resize(l1+l2,'0');
        bool isneg = A[0] == '-' ^ B[0] == '-';
        int e1,e2;
        e1 = A[0] == '-'?1:0;
        e2 = B[0] == '-'?1:0;
        int n1,n2,p;
        int st=l1+l2-1,k=st,c=0;
        for(int i=l1-1;i>=e1;i--){
            n1 = A[i]-'0';
            k  = st;
            for(int j=l2-1;j>=e2;j--){
                n2 = B[j]-'0';
                p = n1*n2;
                addp(res,p,c,k);
               // cout<<res<<" "<<n1<<" "<<n2<<" "<<p<<" "<<c<<endl;
                k--;
            }
            //cout<<k<<" "<<c<<" "<<endl;
            res[k] = c +'0';
           
            c = 0;

            st--;
        }
        if(c!=0)
        res[k] = c +'0';
        int i=0;
        if(c){
            res[k] = c+'0';
        }
        k--;
        if(isneg)
            res[k] = '-';
        while(res[i] == '0' && i<l1+l2-1)
            i++;
        res = res.substr(i);
        return res;
    }
};

int main(){
    Solution s;
    string c = s.multiply("-9","9");
    cout<<c<<endl;
    return 0;
}