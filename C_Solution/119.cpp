class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> former,now;
        rowIndex ++;
        while(rowIndex--){
            if(former.empty()){
                now.push_back(1);
                former = now;
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
            now.clear();
        }
        return former;
    }
};
