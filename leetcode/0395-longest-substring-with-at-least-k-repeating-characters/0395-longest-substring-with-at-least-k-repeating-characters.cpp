class Solution {
public:
    int longestSubstring(string s , int k)
    {
        if(s.size() < k)
        {
            return 0;
        }
        else
        {
            map<char, int> char_to_num;
            for(int i = 0 ; i < s.size() ; i++)
            {
                auto it = char_to_num.find(s[i]);
        
                // 如果键存在，则增加计数
                if (it != char_to_num.end()) 
                {
                    it->second++;
                } 
                // 如果键不存在，则插入一个新的键值对，并将计数初始化为1
                else 
                {
                    char_to_num[s[i]] = 1;
                }
            }

            auto it = char_to_num.begin();
            bool t = true;
            for(; it != char_to_num.end(); ++it) 
            {
                cout << it->first << " " << it->second << endl;
                if(it->second < k)
                {
                    return max(longestSubstring(s.substr(0 , s.find_first_of(it->first)) , k) ,longestSubstring(s.substr(s.find_first_of(it->first) + 1) , k));
                }
            }
            return s.size();
        }
    }
};