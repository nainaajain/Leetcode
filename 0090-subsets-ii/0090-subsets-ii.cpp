class Solution {
public:
void helper(int ind,vector<int>&ds,vector<vector<int>>&ans,int n,vector<int>& nums){
    if(ind==n){
        ans.push_back(ds);
        return;

    }
    //take 
    ds.push_back(nums[ind]);
    helper(ind+1,ds,ans,n,nums);
    ds.pop_back();
    while(ind+1<nums.size()&& nums[ind]==nums[ind+1])ind++;
    helper(ind+1,ds,ans,n,nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        helper(0,ds,ans,n,nums);
        sort(ans.begin(),ans.end());
        return ans;
    }
};