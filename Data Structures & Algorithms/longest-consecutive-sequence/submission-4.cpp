class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> startList;
        for(int i = 0; i < nums.size(); ++i){
            if(s.find(nums[i] - 1) == s.end()) startList.push_back(nums[i]);
        }
        int count = 1;

        for(int i = 0; i < startList.size(); ++i){
            int currStart = startList[i];
            int newCount = 1;
            int j = 1;
            while(s.find(currStart + j) != s.end()){
                j++;
                count = max(count, ++newCount);
            }
        }
        return count;
    }
};
