class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window = p.size();
        int left = 0;
        vector<int> results;
        std::sort(p.begin(), p.end());
        while(left + window <= s.size())
        {
            if(std::find(p.begin(), p.end(), s[left + window - 1]) == p.end())
            {

                left = left + window;
                continue;
            }

            string subStr = s.substr(left, window);
            sort(subStr.begin(), subStr.end());
            if(p == subStr)
            {
                results.push_back(left);
            }
            left++;
        }        

        return results;
    }
};