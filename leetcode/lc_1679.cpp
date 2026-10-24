class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int numsLength = static_cast<int>(nums.size());
        int l = 0, r = numsLength - 1;

        int operationCount{0};
        while (l < r) {
            int curSum = nums[l] + nums[r];
            if (curSum == k) {
                operationCount++;
                l++;
                r--;
            }
            else if (curSum > k) {
                r--;
            }
            else {
                l++;
            }
        }
        return operationCount;
    }
};
