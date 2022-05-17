class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> former,now;
        while(numRows--){
            if(former.empty()){
                now.push_back(1);
                former = now;
                result.push_back(now);
                now.clear();
                continue;
            }
            now.push_back(1);
            int len = former.size();
            for(int i=1;i<len;++i){
                int key = former[i] + former[i-1];
                now.push_back(key);
            }
            now.push_back(1);
            former = now;
            result.push_back(now);
            now.clear();
        }
        return result;
    }
};
