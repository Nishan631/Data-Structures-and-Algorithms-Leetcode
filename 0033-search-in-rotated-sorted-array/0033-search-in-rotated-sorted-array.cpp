class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target) return mid;

            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = end - 1;
                }
                else{
                    start = start + 1;
                }
            }
            
            else{
                if(nums[mid] < target && target <= nums[end]){
                    start = start + 1;
                }
                else{
                    end = end - 1;
                }
            }
        }
        return -1; 
    }
};