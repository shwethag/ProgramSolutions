#include <iostream>
#include <climits>

using namespace std;

/*
Count the number of prime numbers less than a non-negative number, n
*/
class Solution {
  
public:
      int countPrimes(int n) {
      	int *num = new int[n+1];
       for(int i=0;i<n;i++)
       	num[i] = 0;
       num[0]=num[1]=1;
       for(int i=2;i*i<n;i++){
       		if(num[i] != 0)
       			continue;
       		for(int j=2;j*i<=n;j++){
       			num[i*j] = 1;
       		}
       }
       int count=0;
       for(int i=2;i<n;i++){
       		if(num[i]==0)
       			count++;
       }
       delete []num;
       return count;
    }
};

int main(){
	int n =2;
	Solution s;
	int pcount = s.countPrimes(n);
	cout<<pcount<<endl;
	return 0;
}