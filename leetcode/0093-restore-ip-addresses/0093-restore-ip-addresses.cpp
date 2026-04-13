class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        int len = s.size();
        vector<string> ans;
        // 插入字符的位置在 1 - len - 1，随机选三个

        for (int pos1 = 1; pos1 < len - 2; pos1++)
        {
            for (int pos2 = pos1 + 2; pos2 < len + 1; pos2++)
            {
                for (int pos3 = pos2 + 2; pos3 < len + 2; pos3++)
                {
                    string str = s;
                    str.insert(pos1, 1, '.');
                    str.insert(pos2, 1, '.');
                    str.insert(pos3, 1, '.');
                    if (check(str))
                    {
                        ans.push_back(str);
                    }
                }
            }
        }
        return ans;
    }

    bool check(string str)
    {
        //cout << "check " << str << endl;
        vector<string> parts;
        size_t pos = 0;
        string token;
        string delimiter = ".";
        while ((pos = str.find(delimiter)) != string::npos)
        {
            token = str.substr(0, pos); // 提取从0到pos位置的子字符串
            parts.push_back(token);
            str.erase(0, pos + delimiter.length()); // 删除已处理的部分
        }
        parts.push_back(str); // 添加最后一部分

        for (unsigned int i = 0; i < parts.size(); i++)
        {
            try
            {
                if(parts[i][0] - '0' == 0 && parts[i].size() > 1)
                {
                    return false;
                }

                int part = stoi(parts[i]);

                if (part > 255 || part < 0)
                {
                    return false;
                }
            }
            catch (const std::invalid_argument &e)
            {
                return false;
            }
            catch (const std::out_of_range &e)
            {
                return false;
            }
            catch (const std::exception &e)
            {
                return false;
            }
        }
        return true;
    }
};