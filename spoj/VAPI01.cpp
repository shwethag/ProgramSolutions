#include <iostream>
#include <ctype.h>
#define MAX 10001

int hash[30];
char door[MAX];
char key[MAX];

using namespace std;

int main(){
	int testcases,n;
	char reqKey;
	int keyRequired = 0;
	cin>>testcases;
	while(testcases--){
		cin>>n;
		keyRequired = 0;
		for(int i=0;i<n-1;i++){
			cin>>key[i]>>door[i];
		}
		for(int i=0;i<30;i++){
			hash[i] = 0;
		}

		for(int i=0;i<n-1;i++){
			reqKey = tolower(door[i]);
			if(key[i] != reqKey){
				hash[key[i]-'a']++;
				if(hash[reqKey-'a'] == 0)
					keyRequired++;
				else
					hash[reqKey-'a']--;
			}

		}

		cout<<keyRequired<<endl;
	}

	return 0;
}