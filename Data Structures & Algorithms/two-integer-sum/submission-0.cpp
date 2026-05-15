class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int cmp = target - nums[i];
            if (mp.find(cmp) != mp.end()){
                if(i < mp[cmp]){
                    res.push_back(i);
                    res.push_back(mp[cmp]);
                }else{
                    res.push_back(mp[cmp]);
                    res.push_back(i);
                }
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
