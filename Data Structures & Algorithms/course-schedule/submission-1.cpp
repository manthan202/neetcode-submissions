class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // FIX 1: Map course to a VECTOR of prerequisites
        unordered_map<int, vector<int>> prereq; 
        unordered_set<int> completed; 

        for(int i = 0; i < prerequisites.size(); i++){
            // FIX 2: Correctly add prerequisite to the list
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; i++){
            unordered_set<int> current;
            
            // FIX 3: Replace while(true) with a recursive check to handle branches
            if(!checkCourse(i, prereq, current, completed)) {
                return false;
            }
        }

        return true;
    }

private:
    bool checkCourse(int course, unordered_map<int, vector<int>>& prereq, unordered_set<int>& current, unordered_set<int>& completed) {
        
        // If we already know this course is safe, no need to check again
        if (completed.find(course) != completed.end()) return true;
        
        // If we see this course in our current path, we found a cycle!
        if (current.find(course) != current.end()) return false; 

        // Mark as currently visiting
        current.insert(course);

        // Loop through ALL prerequisites for this course and check them
        for (int p : prereq[course]) {
            if (!checkCourse(p, prereq, current, completed)) {
                return false;
            }
        }

        // We finished checking all branches for this course. 
        // Remove from current path and mark as fully completed.
        current.erase(course); 
        completed.insert(course); 
        
        return true;
    }
};