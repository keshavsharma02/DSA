class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> mat(numRows);
        int i = 0, n = s.length();

        while (i < n) {
            for (int down = 0; down < numRows && i < n; down++) {
                mat[down].push_back(s[i++]);
            }
            for (int up = numRows - 2; up > 0 && i < n; up--) {
                mat[up].push_back(s[i++]);
            }
        }

        string ans = "";
        for (int r = 0; r < numRows; r++) {
            for (char c : mat[r]) {
                ans += c;
            }
        }
        return ans;
    }
};