class Solution1 {
public:
    string countAndSay(int n) {
        vector<string> nums(31);
        nums[1] = "1";

        for (int i = 2; i < n + 1; ++i) {
            nums[i-1] = nums[i-1] + '*';//使操作统一
            int len = nums[i - 1].size();
            int count=1;

            for (int j = 0; j < len-1; ++j) {
                if(nums[i-1][j]==nums[i-1][j+1]){
                    count++;
                }else{
                    nums[i]+=(to_string(count)+nums[i-1][j]);
                    count=1;
                }
            }
        }
        return nums[n];
    }
};

class Solution2 {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1) + '*';
        const int len = str.size();
        string s="";
        int count=1;
        for(int i=0;i<len-1;++i){
            if(str[i]==str[i+1]) count++;
            else{
                s = s + (to_string(count) + str[i]);
                count=1;
            }
        }
        return s;
    }
};

