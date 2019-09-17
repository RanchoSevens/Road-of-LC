class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        int j = num.size();
        if (i == j-1) {
            cout<<"输出 ";
            print(i,num);
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            print(i,num);
            recursion(num, i+1, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        recursion(nums, 0, res);
        return res;
    }
    void print(int i,vector<int>& num){
        int len = num.size();
        cout<<"i = "<<i<<"###";
        for(int i=0;i<len;++i){
            cout<<num[i];
            if(i!=len-1) cout<<" ";
        }
        cout<<endl;
    }
};
