class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelCount{0}, curVowelCount{0}, l{0};
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        for (int r = 0; r < s.size(); r++) {
            if (vowels.contains(s[r])) {
                curVowelCount++;
            }
            if (r - l == k) {
                if (vowels.contains(s[l])) {
                    curVowelCount--;   
                }
                l++;
            }
            maxVowelCount = max(maxVowelCount, curVowelCount);
        }

        return maxVowelCount;
    }
};
