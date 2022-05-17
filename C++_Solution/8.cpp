class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        char a[1000]="";
        int i=0,m=0,res=0;
        while(str[i]==' '){
            i++;
        };
        if(str[i]=='+'||str[i]=='-'){
            a[m++]=str[i++];
        }
        if(str[i]<'0'||str[i]>'9'){
            res=0;
        }else{    
            while(str[i]>='0'&&str[i]<='9'){
                a[m++]=str[i++];
            }
            a[m]='\0';
            long long num;
            sscanf(a,"%lld",&num);
            if(num>INT_MAX){
                res=INT_MAX;
            }else if(num<INT_MIN){
                res=INT_MIN;
            }else{
                res=(int)num;
            }
        }
        return res;
    }
};

/*
1.强制类型转换会导致高位丢失，所以不能用于long long向int类型的转换
2.limits.h头文件中定义了int的最大值INT_MAX和最小值INT_MIN
*/
