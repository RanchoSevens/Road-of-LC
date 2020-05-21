class Solution {
public:
    void swap(vector<vector<int>>& matrix,int i1,int j1,int i2,int j2){
        int temp = matrix[i1][j1];
        matrix[i1][j1]=matrix[i2][j2];
        matrix[i2][j2]=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int num = matrix[0].size();
        int n=num;
        num/=2;
        for(int i=0;i<num;++i){
            for(int j=i;j<n-i-1;++j){
                swap(matrix,i,j,j,n-1-i);
                swap(matrix,n-1-j,i,i,j);
                swap(matrix,n-1-i,n-1-j,n-1-j,i);   
            }
        }
    }
};
