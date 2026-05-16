class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int product = 1;
        for(int i : nums){
            if(i != 0)
                product *= i;
            else
                zeros++;
        }
        if(zeros > 1)
            return(vector<int>(n, 0));
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            if(zeros > 0){
                if(nums[i] == 0)
                    ans[i] = product;
                else
                    ans[i] = 0;
            }
            else
                ans[i] = product / nums[i];
        }
        return ans;
    }
};
