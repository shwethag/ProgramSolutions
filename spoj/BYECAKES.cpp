#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int available[4],needed[4];
	int cur, pos,reqFac = 0;

	while(true){
		for(int i=0;i<4;i++)
			cin>>available[i];
		for(int i=0;i<4;i++)
			cin>>needed[i];

		if(available[0] == -1 && needed[0] == -1)
			break;

		reqFac = (int)ceil((float)available[0]/(float)needed[0]);
		pos = 0;

		for(int i=1;i<4;i++){
			if((cur = (int)ceil((float)available[i]/(float)needed[i]))>reqFac)
			{
				reqFac = cur;
			}
		}

		
		for(int i=0;i<4;i++){
			needed[i] = (needed[i] * reqFac) - available[i];
		}

		cout<<needed[0]<<" "<<needed[1]<<" "<<needed[2]<<" "<<needed[3]<<endl;


	}
	
	return 0;
}