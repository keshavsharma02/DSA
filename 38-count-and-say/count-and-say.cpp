class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        while (--n) {
            string t;
            t.reserve(s.size() * 2);   // prevent reallocations

            for (int i = 0; i < s.size(); ) {
                char c = s[i];
                int cnt = 0;

                // count same chars
                while (i < s.size() && s[i] == c) {
                    ++cnt;
                    ++i;
                }

                // manually append count (faster than to_string)
                if (cnt >= 10) t.push_back('0' + cnt / 10);
                t.push_back('0' + cnt % 10);
                t.push_back(c);
            }

            s.swap(t);   // faster than assignment
        }

        return s;
    }
};
