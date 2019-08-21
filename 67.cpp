class Solution {
public:
    string addBinary(string a, string b) {
        a = '0' + a;    b = '0' + b;
        int len = max(a.size(),b.size());
        while(a.size()<len){
            a = '0' + a;
        }
        while(b.size()<len){
            b = '0' + b;
        }
        string res(len,'0'),result;
        int inp=0;
        for(int i=len-1;i>-1;--i){
            int ai = a[i] - '0';
            int bi = b[i] - '0';
            int ans = ai + bi + inp;
            inp = ans/2;
            res[i] = '0' + ans%2;
        }
        bool flag=false;
        for(int i=0;i<len;++i){
            if(flag)    result +=res[i];
            else if(res[i]!='0'){
                flag=true;
                result += res[i];
            }
        }
        if(flag==false) result = '0';
        return result;
    }
};
