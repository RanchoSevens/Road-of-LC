class Solution {
public:
    string intToRoman(int num) {
        const int level=13;
        int l[level]={};
        string R[level]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int D[level]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<level;i++){
            l[i]=num/D[i];
            num=num%D[i];
        }
        string res;
        for(int i=0;i<level;i++){
            if(l[i]){
                for(int j=0;j<l[i];j++){
                    res+=R[i];
                }
            }
        }
        return res;
    }
};

/*
1.用数组逐单位取余
2.char与string转换时容易出错，只用string或者只用char
3.string不要用+=
*/
