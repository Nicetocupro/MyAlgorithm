class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) 
    {
        vector<int> ans;
        
        for (int j = 0; j < cnt; j++)
        {
            int minx = stock[0];
            unsigned int i = 0 , k = 0;
            for (;i < stock.size(); i++)
            {
                if(minx > stock[i])
                {
                    minx = stock[i];
                    k = i;
                }
            }
            ans.push_back(minx);
            stock.erase(stock.begin() + k);
        }
        return ans;
    }
};