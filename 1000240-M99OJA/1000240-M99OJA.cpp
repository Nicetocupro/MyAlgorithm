class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s)
    {
        vector<string> init;
        for (unsigned int i = 0; i < s.size(); i++)
        {
            string str(1, s[i]);
            init.push_back(str);
        }
        solve(init , 0);
        return ans;
    }

    void solve(vector<string> init , int pos)
    {
        int len = init.size();
        if (len == 0)
        {
            return;
        }
        else if (len == 1)
        {
            if (isPalindrome(init[0]))
            {
                ans.push_back(init);
            }
            return;
        }
        else
        {
            bool check = true;
            for (int i = 0; i < len; i++)
            {
                if (!isPalindrome(init[i]))
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
               ans.push_back(init);
            }
            for (int i = pos; i < len - 1; i++)
            {
                vector<string> temp(init);
                temp[i] += temp[i + 1];
                temp.erase(temp.begin() + i + 1);
                solve(temp , i);
            }
            return;
        }
    }

    bool isPalindrome(const string &s)
    {
        int left = 0;               // 左指针
        int right = s.length() - 1; // 右指针

        while (left < right)
        {
            // 跳过非字母和非数字字符
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;

            // 比较左右字符，忽略大小写
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false; // 如果不匹配，则不是回文
            }
            left++;  // 移动左指针
            right--; // 移动右指针
        }
        return true; // 所有字符都匹配，则是回文
    }
};