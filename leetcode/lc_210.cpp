class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjList(numCourses);
        vector<int> prereqCount(numCourses, 0);

        for (const auto courseOrder : prerequisites) {
            adjList[courseOrder[1]].push_back(courseOrder[0]);
            prereqCount[courseOrder[0]]++;
        }

        queue<int> clearPrereqs;
        for (int curCourse = 0; curCourse < numCourses; curCourse++) {
            if (prereqCount[curCourse] == 0) {
                clearPrereqs.push(curCourse);
            }
        }

        vector<int> courseOrder{};
        while (!clearPrereqs.empty()) {
            int curCourse = clearPrereqs.front();
            clearPrereqs.pop();
            courseOrder.push_back(curCourse);
            for (int nextCourse : adjList[curCourse]) {
                prereqCount[nextCourse]--;
                if (prereqCount[nextCourse] == 0) {
                    clearPrereqs.push(nextCourse);
                }
            }
        }

        if (numCourses > courseOrder.size()) {
            return {};
        }
        return courseOrder;
    }

};
