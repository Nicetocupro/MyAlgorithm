class Solution {
public:
    string shortestPalindrome(string s)
    {
        int len = s.length();
        if(len == 0)
        {
            return "";
        }
        string rev_s = string(s.rbegin(), s.rend());
        string new_str = s + "#" + rev_s;
        vector<int> pi = prefixFunction(new_str);
        int max_prefix = pi.back();

        string remaining = s.substr(max_prefix);  // s中未匹配的部分

        remaining = string(remaining.rbegin() , remaining.rend());

        return remaining + s;  // 构造最短回

    }
    vector<int> prefixFunction(const string& s) 
    {
        vector<int> pi(s.size() , 0);
        for(unsigned int i = 1 ; i < s.size() ; i++)
        {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }
            if(s[i] == s[j])
            {
                j++;
            }
            pi[i] = j;
        }

        return pi;
    }
};
