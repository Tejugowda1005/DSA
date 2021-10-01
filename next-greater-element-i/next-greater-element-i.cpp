class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        int n = nums1.size(), m = nums2.size();
        for(int i = 0; i < n; ++i){
            int j = m-1;
            int grt = -1;
            for(;nums2[j] != nums1[i]; --j) {
                if(nums2[j] > nums1[i]) {
                    grt = nums2[j];
                }
            }
            m1[nums1[i]] = grt;
        }
        
        vector<int> res;
        
        for(int i = 0; i <n; ++i) {
            res.push_back(m1[nums1[i]]);
        }
        return res;
    }
};