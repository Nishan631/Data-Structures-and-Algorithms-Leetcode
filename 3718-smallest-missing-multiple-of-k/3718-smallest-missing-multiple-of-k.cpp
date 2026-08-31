class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> vis;

        for(int x : nums) {
            vis.insert(x);
        }

        if(vis.find(k) == vis.end()) {
            return k;
        }

        int ans = k;
        do {
            ans += k; 
        }
        while(vis.find(ans) != vis.end());

        return ans;
    }
};