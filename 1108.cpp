class Solution {
public:
    string defangIPaddr(string address) {
        int num[4];
        char ss[100]={};
        for(int i=0;i<address.size();++i){
            ss[i]=address[i];
        }
        sscanf(ss,"%d.%d.%d.%d",&num[0],&num[1],&num[2],&num[3]);
        string res = to_string(num[0]);
        for(int i=0;i<3;i++){
            res += ("[.]"+to_string(num[i+1]));
        }
        return res;
    }
};
