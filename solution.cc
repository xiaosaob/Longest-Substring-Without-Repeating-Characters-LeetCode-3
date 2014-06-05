// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        vector<int> table(256, 0);
        int start = 0, end = 0;
        while(end < s.size()) {
            while(end < s.size()) {
                if(++table[s[end++]] > 1) break;
                maxLen = max(maxLen, end-start);
            }
            if(end == s.size()) return maxLen;
            while(start < end) {
                if(--table[s[start++]] == 1) break;
            }
        }
        return maxLen;
    }
};
