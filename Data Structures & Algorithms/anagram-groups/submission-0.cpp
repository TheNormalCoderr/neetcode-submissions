class Solution {
   public:
    string generateKey(const string s) {
        vector<int> fq(26);
        for (char c : s) fq[c - 'a']++;

        ostringstream oss;
        for (int i = 0; i < fq.size(); ++i) {
            if (i != 0) oss << "#";
            oss << fq[i];
        }
        return oss.str();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        int n = strs.size();

        for (string& str : strs) {
            string key = generateKey(str);

            if (map.find(key) != map.end()) {
                map[key].push_back(str);
                continue;
            }
            map[key] = {str};
        }
        for (auto& i : map) {
            res.push_back(i.second);
        }
        return res;
    }
};
