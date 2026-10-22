class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> threeSums;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < N; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int target = -nums[i];
            std::cout << target << std::endl;
            int j = i + 1, k = N - 1;

            while (j < k) {
                int curSum = nums[j] + nums[k];
                if (curSum == target) {
                    threeSums.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
                else if (curSum > target) {
                    k--;
                }
                else {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }

            }
        }
        return threeSums;
    }
};
