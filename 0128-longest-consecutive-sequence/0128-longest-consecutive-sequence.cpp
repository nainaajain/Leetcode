class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s;
        for(int i:nums){
            s.insert(i);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int current_element=nums[i]; //3
            int previous_element=current_element-1; //2
            int count=0;
            if(s.find(previous_element)==s.end()){
                
                //means we dont have previous eleemnt we can search for successor
                while(s.find(current_element)!=s.end()){
                    current_element++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;

    }
};