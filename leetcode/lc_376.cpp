class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> differences {};

        for (int i = 1; i < nums.size(); i++) {
            int curDiff = nums[i] - nums[i - 1];
            if (curDiff != 0) {
                differences.push_back(curDiff);
            }
        }

        if (differences.empty()) {
            return 1;
        }
        int subsequenceLen = 2;
        
        for (int i = 1; i < differences.size(); i++) {
            int curDiff = differences[i];
            int lastDiff = differences[i - 1];
            if ((curDiff > 0 && lastDiff < 0) || 
                (curDiff < 0 && lastDiff > 0)) {
                subsequenceLen++;
            }
        }
        return subsequenceLen;
    }
};
