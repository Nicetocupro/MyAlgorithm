class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int MaxLength = 0; 
        for(int i = 0; i < s.size(); i++)
        {
            int sum = 1;
            for(int n = 1; n < s.size() - i; n++)
            {
                string subStr = s.substr(i, n);
                if(subStr.find(s[i + n]) == std::string::npos)
                {
                    sum++;
                }
                else 
                {
                    break;
                }
            }
            if(sum > MaxLength)
            {
                MaxLength = sum;
            }
        }

        return MaxLength;
    }
};