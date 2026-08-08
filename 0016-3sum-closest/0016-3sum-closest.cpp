class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (abs(target - currSum) < abs(target - sum)) {
                    sum = currSum;
                }
                if (currSum == target) {
                    return target;
                }
                else if (currSum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return sum;
    }
};