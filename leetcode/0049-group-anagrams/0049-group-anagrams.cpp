class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> maps;
        vector<string> keys;
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            maps[key].push_back(strs[i]);
            if(std::find(keys.begin(), keys.end(), key) == keys.end())
            {
                keys.push_back(key);
            }
        }

        vector<vector<string>> result;
        for(int i = 0; i < keys.size(); i++)
        {
            result.push_back(maps[keys[i]]);
        }

        return result;
    }
};