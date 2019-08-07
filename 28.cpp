class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> next;
        initnext(needle, next);
        int result = -1;
        const int l = haystack.size();
        int i = 0, j = -1;
        while (i < l) {
            while(j!=-1&&haystack[i]!=needle[j+1]){
                j=next[j];
            }
            if(haystack[i]==needle[j+1]) {
                ++j;
            }
            if(j==needle.size()-1){
                result=i-j;
                break;
            }
            ++i;
        }
        return result;

    }

    void initnext(string &s, vector<int> &next) {
        int len = s.size();
        int j = -1;
        next.push_back(j);
        for (int i = 1; i < len; ++i) {
            while (j != -1 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next.push_back(j);
            printf("j= %d\n",j);
        }
    }
};
/*
1.KMP算法
*/
