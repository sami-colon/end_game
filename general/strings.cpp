#include<bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict, string pattern){
	vector<string> temp_dict = dict;
    for(int i=0; i<pattern.size(); i++){
    	char curr = pattern[i];
    	for(int j=i; j<pattern.size(); j++){
    		if(curr == pattern[j] && pattern[j]-'a'>=0 && pattern[j]-'a'<=25)
    			pattern[j] = (i+1) + '0';
    	}
    }
    for(int m=0; m<dict.size(); m++){
        for(int i=0; i<dict[m].size(); i++){
    		char curr = dict[m][i];
    		for(int j=i; j<dict[m].size(); j++){
    			if(curr == dict[m][j] && dict[m][j]-'a'>=0 && dict[m][j]-'a'<=25)
    				dict[m][j] = (i+1) + '0';
    		}
    	}
    }
    vector<string> ans;
    for(int i=0; i<dict.size(); i++){
        if(dict[i] == pattern)
           ans.push_back(temp_dict[i]);
    }
    return ans;
}

int main(){
	std::vector<string> dict = {"abb", "abc","xyz", "xyy"};
	std::vector<string> v = findMatchedWords(dict, "foo");
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
}