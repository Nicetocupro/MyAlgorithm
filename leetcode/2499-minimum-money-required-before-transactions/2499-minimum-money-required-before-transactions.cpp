class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) 
    {
        long long lose = 0;
        long long s = 0;
        for(int i = 0 ; i < transactions.size() ; i++)
        {
            lose += max(transactions[i][0] - transactions[i][1] , 0);
            s = max(s , (long long)min(transactions[i][0] , transactions[i][1]));
        }
        return lose + s;
    }
};