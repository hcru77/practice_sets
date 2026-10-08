// SEARCH IN ROTATED SORTED ARRAY II
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return true;
            }
            if (nums[l] == nums[m]) {
                // We don't know which part of the rotated array we are in

                // ex. 4, 4, 4, 4, 1, 2, 3
                // ex2. 4, 5, 6, 4, 4, 4, 4

                // move left up by 1 then re-do bin search

                l++;
            }
            else if (nums[m] >= nums[l]) {
                if (target < nums[l] || target > nums[m]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                if (target > nums[r] || target < nums[m]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        return false;
    }
};