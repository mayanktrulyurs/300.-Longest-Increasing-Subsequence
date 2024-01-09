// class Solution {

    // top down approach using memoization

// public:

//     int findLIS (int curr_idx, int prev_idx, int n, vector<int>& nums, vector<vector<int>>& dp){
//         if (curr_idx>=n){
//             return 0;
//         }

//         if (dp[curr_idx][prev_idx+1]!=-1){
//             return dp[curr_idx][prev_idx+1];
//         }

//         int Take=0;

//         if (prev_idx==-1 || nums[curr_idx]>nums[prev_idx]){
//             Take=1+findLIS(curr_idx+1, curr_idx, n, nums, dp);
//         }
//         int not_Take=0+findLIS(curr_idx+1, prev_idx, n, nums, dp);

//         return dp[curr_idx][prev_idx+1]=max(Take, not_Take);
//     }
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n=nums.size();

//         vector<vector<int>>dp (n, vector<int>(n+1, -1));
//         return findLIS(0,-1,n,nums,dp);
//     }
// };
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // tabulation, bottom up approach
        
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0)); // n+1 since, for curr_idx=n-1, we do dp[curr_idx+1], which will require idx n, so we declare it to be n+1 for the current index as well.

        for (int curr_idx=n-1;curr_idx>=0;curr_idx--){
            for (int prev_idx=curr_idx-1;prev_idx>=-1;prev_idx--){

                int Take=0;
                if (prev_idx==-1 || nums[curr_idx]>nums[prev_idx]){
                    Take=1+dp[curr_idx+1][curr_idx+1];
                }
                int not_Take=0+dp[curr_idx+1][prev_idx+1];

                dp[curr_idx][prev_idx+1]=max(Take,not_Take);
            }
        }
        return dp[0][-1+1];
    }
};
