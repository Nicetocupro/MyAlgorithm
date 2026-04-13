class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int len = nums.size();
        int start = 0;
        int res = 0;
        int k = 0;
        if(len == 1)
        {
            return 0;
        }
        while(start < len)
        {
            k = start + nums[start];
            cout << start << " " << start + nums[start] << endl;
            if(k >= len - 1)
            {
                return res + 1;
            }
            int maxPos = 0;
            for(int i = start + 1; i <= k ;i++)
            {
                cout << endl;
                cout << i << " " << i + nums[i] << endl;
                if(i + nums[i] > maxPos)
                {
                    maxPos = i + nums[i];
                    start = i;
                }
            }
            res++;
        }
        return res;
    }
};