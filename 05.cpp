// problem--Longest Palindromic Substring    
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(int i=0;i<s.size();i++){
            t += s[i];
            t += '#';
        }
        int id=0,mx=0,resid=0,resmx=0,rt[t.size()]={0};
        for(int i=1;i<t.size();i++){
            rt[i]=i<mx?min(mx-i,rt[2*id-i]):1;
            while(t[i+rt[i]]==t[i-rt[i]])   rt[i]++;
            if(mx<i+rt[i]){
                mx=i+rt[i];
                id=i;
            }
            if(resmx<=rt[i]){
                resmx=rt[i];
                resid=i;
            }
        }
        return s.substr((resid-resmx)/2,resmx-1);
    }
};
