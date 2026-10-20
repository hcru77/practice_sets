class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderLocs {};
        remainderLocs[0] = -1;      // First element in nums cannot be good subarray

        int runningTotal = 0;

        for (int i = 0; i < nums.size(); i++) {
            runningTotal += nums[i];
            int curRemainder = runningTotal % k;
            if (!remainderLocs.contains(curRemainder)) {
                remainderLocs[curRemainder] = i;
            }
            else if (i - remainderLocs[curRemainder] > 1) {
                return true;   
            }
        }
        return false;
    }
};
