class Solution {
public:
    // time/space: O(n)/O(1)
    bool isIsomorphic(string s, string t) {
        // map `s` to `i` and `t` to `j`
        unordered_map<char, int> m,p;
        for (auto& c : s) {
            if (m.count(c) != 0) continue;
            m[c] = m.size();
        }
        for (auto& c : t) {
            if (p.count(c) != 0) continue;
            p[c] = p.size();
        }

        // compare `s` and `t` after mapping
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] != p[t[i]]) return false;
        }
        return true;
    }
};