class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int maxarea=min(heights[i],heights[j])*(j-i);
        while(i<j) {
            
            if (heights[i]<heights[j]) {
                i++;
                maxarea=max(maxarea,min(heights[i],heights[j])*(j-i));
            } else {
                j--;
                maxarea=max(maxarea,min(heights[i],heights[j])*(j-i));
            }
        }
        return maxarea;
    }
};
