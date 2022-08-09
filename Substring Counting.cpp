#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

#define MAXS 5100

using namespace std;

// dp[i][j] contains length of LCS of s[0..i-1] and t[0..j-1]

int dp[MAXS][MAXS];
int ans = 0;

void LCSS(string s, string t){
    memset(dp, 0, sizeof(dp));
    int lenS = s.size(), lenT = t.size();
    for(int i = 1; i <= lenS; i++){
        for(int j = 1; j <= lenT; j++){

            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] == lenT){ // I have a string t inside string s
                    ans ++;
                    string piv = s.substr(i, lenS - i);
                    LCSS(piv, t);
                    return;
                }

            }else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    int q; cin >> q;
    while(q--){
        ans = 0;
        cin >> t;
        LCSS(s, t);
        cout << ans << endl;
    }

    return 0;
}