class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int N = temps.size();
        vector<int> nextWarmerDay(N, 0);

        vector<pair<int, int>> tempStack;
        for (int tempInd = 0; tempInd < N; tempInd++) {
            int curTemp = temps[tempInd];
            while (!tempStack.empty() && curTemp > tempStack.back().first) {
                int lastTemp = tempStack.back().first;
                int lastTempInd = tempStack.back().second;
                nextWarmerDay[lastTempInd] = tempInd - lastTempInd;
                tempStack.pop_back();
            }
            tempStack.push_back({curTemp, tempInd});
        }
        return nextWarmerDay;

    }
};
