class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> elemFreqs{};
        vector<vector<int>> occurrences(N + 1);

        for (int i = 0; i < N; i++) {
            elemFreqs[nums[i]]++;
        }

        for (const auto& [key, value] : elemFreqs) {
            occurrences[value].push_back(key);
        }

        vector<int> topKelements;
        for (int i = N; i >= 0; i--) {
            for (auto num : occurrences[i]) {
                topKelements.push_back(num);
                if (topKelements.size() == k) {
                    return topKelements;
                }
            }
        }

        return topKelements;
    }
};
