class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int res = 0;
        int i = 0, j = n-1;
        
        while(i<j) {
            int area = min(height[i], height[j]) * (j-i);
            res = max(res, area);
            if(height[i] > height[j]) {
                --j;
            } else{
                ++i;
            }
        }
        return res;
    }
};