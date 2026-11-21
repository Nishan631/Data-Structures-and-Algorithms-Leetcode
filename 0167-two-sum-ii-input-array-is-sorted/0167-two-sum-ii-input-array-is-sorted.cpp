class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 1, j = n;

        while(i < j) {
            if(numbers[i-1] + numbers[j-1] == target) {
                return {i,j};
            }
            else if(numbers[i-1] + numbers[j-1] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return {-1,-1};
    }
};