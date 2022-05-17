class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        int len=0;
        string temp;
        while(in>>temp){
            len=temp.size();
        }
        return len;
    }
};
