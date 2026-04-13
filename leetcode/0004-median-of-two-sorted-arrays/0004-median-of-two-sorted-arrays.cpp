class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int k = nums1.size() + nums2.size();
        if(k % 2 == 0)
        {
            return (findtheNums(nums1 , nums2 , k / 2) + findtheNums(nums1 , nums2 , k / 2 + 1)) / 2.0;
        }
        else
        {
            return findtheNums(nums1 , nums2 , k / 2 + 1 );
        }
    }

    //解法二通过分别折半
    double findtheNums(vector<int>& nums1,vector<int>& nums2 ,int k)
    {
        int m = nums1.size(), n = nums2.size();

        cout << m << " " << n << " " << k << endl;

        if(m == 0)
        {
            return nums2[k - 1];
        }

        if(n == 0)
        {
            return nums1[k - 1];
        }
        
        cout << nums1[m / 2] << " " << nums2[n / 2] << endl;

        if(nums1[m / 2] <= nums2[n / 2])
        {
            if(k <= m / 2 + n / 2 + 1)
            {

                vector<int> temp(nums2.begin() , nums2.begin() + n / 2);
                return findtheNums(nums1 ,temp ,k);
            }
            else
            {
                //cout << 3 << endl;
                vector<int> temp(nums1.begin() + m / 2 + 1 , nums1.end());
                return findtheNums(temp ,nums2 ,k - m / 2 - 1);
            }
        }
       else
       {
            if(k <= m / 2 + n / 2 + 1)
            {
                vector<int> temp(nums1.begin() , nums1.begin() + m / 2);
                return findtheNums(temp ,nums2 ,k);
            }
            else
            {
                vector<int> temp(nums2.begin() + n / 2 + 1 , nums2.end());
                return findtheNums(nums1 ,temp ,k - n / 2 - 1);
            }
       }
    }
};