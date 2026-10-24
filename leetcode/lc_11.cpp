class Solution {
public:
    int maxArea(vector<int>& height) { 
        int heightsLength = static_cast<int>(height.size());
        int maxWater = 0;

        int l = 0, r = heightsLength - 1;

        while (l < r) {
            int curArea = (r - l) * min(height[r], height[l]);
            maxWater = max(maxWater, curArea);
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxWater;
    }
};
