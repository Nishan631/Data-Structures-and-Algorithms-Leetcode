class Solution {
public:
    int firstPosition(vector<int>& nums, int target){
        int s=0, e=nums.size()-1, mid;
        int ans=-1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }

    int lastPosition(vector<int>& nums, int target){
        int s=0, e=nums.size()-1, mid;
        int ans=-1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPosition(nums,target);
        if(first == -1) return {-1,-1};
        int last = lastPosition(nums,target);
        return {first,last};
    }
};