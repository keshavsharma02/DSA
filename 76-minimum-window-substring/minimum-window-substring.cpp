class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        unordered_map<char, int> map;
        for (char c : t) map[c]++;
        
        int i = 0, j = 0, start = 0, minLen = INT_MAX;
        int count = map.size();
        
        while (j < s.length()) {
            if (map.count(s[j])) {
                map[s[j]]--;
                if (map[s[j]] == 0) count--;
            }
            
            while (count == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                if (map.count(s[i])) {
                    map[s[i]]++;
                    if (map[s[i]] > 0) count++;
                }
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};