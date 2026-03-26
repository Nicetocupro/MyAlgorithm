class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> map;
        int needCount = 0;

        for (int i = 0; i < t.size(); i++) {
            map[t[i]]++;
            needCount++;
        }

        int minWindow = s.size();
        int minLeft = 0;
        bool found = false;
        int left = 0, right = 0;

        while (right < s.size()) {
            if (map[s[right]] > 0) {
                needCount--;
            }

            map[s[right]]--;

            while (needCount == 0) {
                if (minWindow > right - left) {
                    minLeft = left;
                    minWindow = right - left;
                    found = true;
                }

                map[s[left]]++;

                if (map[s[left]] > 0) {
                    needCount++;
                }
                left++;
            }
            right++;
        }

        if (!found) {
            return "";
        }

        return s.substr(minLeft, minWindow + 1);
    }
};