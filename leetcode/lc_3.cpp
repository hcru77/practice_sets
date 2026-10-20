class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> letterCount;
        int leftInd = 0;
        int longestLength = 0;

        for (int rightInd = 0; rightInd < s.size(); rightInd++) {
            char curLetter = s[rightInd];
            letterCount[curLetter]++;
            if (letterCount[curLetter] > 1) {
                while (letterCount[curLetter] > 1) {
                    letterCount[s[leftInd]]--;
                    leftInd++;
                }
            }
            longestLength = max(longestLength, rightInd - leftInd + 1);
        }
        return longestLength;
    }
};
