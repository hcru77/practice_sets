class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        int minn = nums[0];
        while (l < r) {
            int mid = (l + r) / 2;

            minn = min(minn, nums[mid]);
            if (nums[l] > nums[r]) {
                if (nums[mid] >= nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                r = mid - 1;
            }
        }
        return min(minn, nums[l]);
    }
};
