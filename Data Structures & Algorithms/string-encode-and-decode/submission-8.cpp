class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded_str;
        for (string& s : strs) {
            int len = s.length();
            encoded_str.append(to_string(len));
            encoded_str.append("/");
            encoded_str.append(s);
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int len = 0;
        int i = 0;
        while (i < s.length()) {
            size_t hash_pos = s.find('/', i);
            int len = stoi(s.substr(i, hash_pos - i));
            decoded_strs.push_back(s.substr(hash_pos + 1, len));
            i = hash_pos + len + 1;
        }
        return decoded_strs;
    }
};
