class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        return Msum(nums , 0 , nums.size() - 1)[2];
    }

    vector<int> Msum(vector<int>& nums, int l , int r)
    {
        int m = (l + r) / 2;
        if(l == r)
        {
            return { nums[l], nums[l], nums[l], nums[l] };
        }
        else
        {
            vector<int> larray , rarray , marray(4);
            larray = Msum(nums , l , m);
            rarray = Msum(nums , m + 1 , r);
            marray[0] = max(larray[0], larray[3] + rarray[0]); // Lsum
            marray[1] = max(rarray[1], rarray[3] + larray[1]); // rsum
            marray[2] = max(max(larray[2], rarray[2]), larray[1] + rarray[0]); // msum
            marray[3] = larray[3] + rarray[3]; // isum
            return marray;
        }
    }
};
