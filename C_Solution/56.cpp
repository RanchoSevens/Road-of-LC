class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len<=1) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        int left=intervals[0][0],right=intervals[0][1];
        for(int i=1;i<len;++i){
            int ileft=intervals[i][0],iright=intervals[i][1];
            if(ileft>=left&&ileft<=right){
                right=iright>right?iright:right;
            }else{
                vector<int> temp;
                temp.push_back(left);   temp.push_back(right);
                result.push_back(temp);
                left=ileft; right=iright;
            }
        }
        vector<int> temp;
        temp.push_back(left);   temp.push_back(right);
        result.push_back(temp);
        return result;
    }
    static bool cmp(const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
};
