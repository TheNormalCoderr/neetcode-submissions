class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_val = -1;
        for (int i = n - 1; i >= 0; --i) {
            int curr = arr[i];
            arr[i] = max_val;
            max_val = max(max_val, curr);
        }
        return arr;
    }
};