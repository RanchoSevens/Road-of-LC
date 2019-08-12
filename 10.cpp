#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
/*
1.动态规划，dp[i][j]表示s的前i位和p的前j位是否匹配
2.当p[j-1]=='*'时，p[j-2]要么重复0次，要么重复至少1次（dp[i-1][j]即可)
3.当p[j-1]!='*'时，只需判断i-1位的p和j-1位的s即可
4.动态规划由下而上，也可以用递归，由上至下，但是复杂度极高
*/

class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

int main() {
    Solution S;
    string a = "aa", b = "a";
    a = "bbabacccbcbbcaaab";
    b = "a*b*a*a*c*aa*c*bc*";
    int res = S.isMatch(a, b);
    printf("res=%d\n", res);
    return 0;

}
