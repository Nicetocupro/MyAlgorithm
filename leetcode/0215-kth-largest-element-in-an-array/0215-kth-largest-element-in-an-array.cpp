class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return nums[left];

        int random = left + rand() % (right - left + 1);
        swap(nums[random], nums[left]);
        int pivot = nums[left];

        // 三路划分
        // [left, lt)  < pivot
        // [lt, gt]   == pivot  ← 这整段都不用再递归
        // (gt, right] > pivot
        int lt = left, i = left + 1, gt = right;

        while (i <= gt) {
            if (nums[i] < pivot)
                swap(nums[lt++], nums[i++]);
            else if (nums[i] > pivot)
                swap(nums[i], nums[gt--]);
            else
                i++;
        }

        // 判断 k 落在哪一段
        if (k < lt)
            return quickSelect(nums, left, lt - 1, k);
        else if (k > gt)
            return quickSelect(nums, gt + 1, right, k);
        else
            return nums[k];  // k 落在 == pivot 段，直接返回
    }
};