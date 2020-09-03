class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

/*
1.vector<vector<int>> subs = {{}}; 
    size(subs) = 1;
    size(subs[0]) = 0;
2.以[1,2,3]为例
            sub[0].size() = 0 
            subs.size() = 1	n = 1
            ###&&&
            ------------------------------
            subs.size() = 2	n = 2
            ###&&&
            ###1 &&&
            ------------------------------
            subs.size() = 4	n = 4
            ###&&&
            ###1 &&&
            ###2 &&&
            ###1 2 &&&
            ------------------------------
            subs.size() = 8
            ###&&&
            ###1 &&&
            ###2 &&&
            ###1 2 &&&
            ###3 &&&
            ###1 3 &&&
            ###2 3 &&&
            ###1 2 3 &&&
            ------------------------------
*/
