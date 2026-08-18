class Solution {
public:
    bool isAllStars(string &p, int j) {
        for(int k=1; k<=j; k++) {
            if(p[k-1] != '*')
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m+1, false);
        vector<bool> curr(m+1, false);

        // base cases
        prev[0] = true;

        for(int j=1; j<=m; j++) {
            prev[j] = isAllStars(p, j);         
        }
        // Iterative DP (Space optimization)
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {

                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];
                }

                else if (p[j-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                }

                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};