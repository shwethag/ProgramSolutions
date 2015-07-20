#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        map<string,int> wordmap1,wordmap2;
        vector<int> indices;
        if(s.length() == 0 || words.size() == 0){
        	return indices;
        }
       	int vlen = words.size();
       	for(int i=0;i<vlen;i++){
       		wordmap1[words[i]]++;
       	}

       	int wlen = words[0].length();
       	int slen = s.length();

       	int i=0,left = -1;
       	string sub;
       	int cnt = 0;
       	string str;
       	int j=0, tlen = slen - wlen*vlen; 
       	while(j<wlen){
       		i = j;
       		cnt = 0;
       		left = j;
       		wordmap2.clear();
	       	while(i<slen){
	       		sub = s.substr(i,wlen);
	       		if(wordmap1[sub]){
	       			wordmap2[sub]++;
	       			if(wordmap2[sub] <= wordmap1[sub])
	       				cnt++;
	       			else{
	       				while(wordmap2[sub] > wordmap1[sub]){
	       					str = s.substr(left,wlen);
	       					wordmap2[str]--;
	       					if(wordmap2[str]<wordmap1[str])
	       						cnt--;
	       					left+=wlen;
	       				}
	       			}
	       			
	       		}else{
	       			cnt = 0;
	       			wordmap2.clear();
	       			left = i+wlen;

	       		}

	       		i+=wlen;
	       		//cout<<sub<<" "<<cnt<<endl;
	       		if(cnt == vlen){
	       			indices.push_back(left);
	       			cnt = 0;
	       			wordmap2.clear();
	       			left += wlen;
	       			i = left;
	       		}
	       	}
	       	j++;
       	}
       	return indices;

    }
};

int main(){
	string src = "wordgoodgoodgoodbestword";// ["","","","good"];
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");

	Solution s;
	vector<int> subind = s.findSubstring(src,words);
	for(int i=0;i<subind.size();i++){
		cout<<subind[i]<<" - ";
	}
	cout<<endl;

	return 0;
}