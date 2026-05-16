class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fq;
        vector<int> res;
        int n = nums.size();

        for (int& i : nums) fq[i]++;

        vector<vector<int>> buckets(n + 1);
        for (auto& i : fq) buckets[i.second].push_back(i.first);

        for (int i = n; i >= 1; --i) {
            if (res.size() == k) break;
            for (auto& num : buckets[i]) res.push_back(num);
        }
        return res;
    }
};
