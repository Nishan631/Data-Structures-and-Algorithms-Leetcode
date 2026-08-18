class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();

        if(digits[n-1]!=9){
            for(int i=0; i<n-1; i++){
                ans.push_back(digits[i]);
            }
            ans.push_back(digits[n-1] + 1);
            return ans;
        }

        int k=0;
        for(int i=n-1; i>0; i--){
            if(digits[i]==9){ 
            }
            else{
                k = i;
                break;
            }
        }
        if(digits[0]==9 && k==0){
            ans.push_back(1);
            for(int i=0; i<n; i++){
                ans.push_back(0);
            }
            return ans;
        }

        for(int i=0; i<n; i++){
            if(i<k){
                ans.push_back(digits[i]);
            }
            else if(i==k){
                ans.push_back(digits[i]+1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};