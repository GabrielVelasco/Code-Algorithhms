#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

#define min(a, b) (((a) < (b)) ? (a) : (b))

#define MAXS 1e6

using namespace std;

// dp[i][j] contains length of LCS of s[0..i-1] and t[0..j-1]

class Solution {
private:
	bool isPrefix(vector<string>& strs, int mid, string piv){
		for(int i = 1; i < strs.size(); i++){ // for each i I have a string
			// for any str in strs that doesn't have a prefix equals
			// piv, than piv is not a possible prefix
			if(strs[i].compare(0, mid, piv) != 0)
				return false;	
		}

		return true;
	}

public:   
    
    string longestCommonPrefix(vector<string>& strs) {
        // find str with minimum length
        string ans = "";
        if(strs.empty())	return ans;
        int minLen = MAXS;
        for(int i = 0; i < strs.size(); i++){
        	minLen = min(minLen, strs[i].size());
        }

		int L = 1, R = minLen, mid;
		while(L <= R){
			mid = L + ((R-L)/2);
			string piv = strs[0].substr(0, mid);
			// Finds if strs[0] substr [0 ... mid] is a prefix of the others str in strs
			if(isPrefix(strs, mid, piv)){
				// increase mid, increasing str piv[0 .... mid]
				ans = piv;
				L = mid + 1;
			}else{
				// decrease mid, decreasing str piv[0 .. mid]
				R = mid - 1;
			}
		}

		return ans;  
    }
    
};

int main(){
	Solution objSolution;
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("floght");
	string a = objSolution.longestCommonPrefix(strs);
	cout << a << endl;

    return 0;
}