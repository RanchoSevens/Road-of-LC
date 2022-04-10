class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        for(int i=0;i<9;++i){
            result = result && rowvalid(board,i) && columnvalid(board,i);
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                result = result && subboxvalid(board,i,j);
            }
        }
        return result;
    }
    
    bool rowvalid(vector<vector<char>>& board,int i){
        vector<int> count(10,0);
        for(int j=0;j<9;++j){
            char c = board[i][j];
            if(isdigit(c)){
                int num = board[i][j] - '0';
                count[num]++;
                if(count[num]>1) return false;
            }
        }
        return true;
    }
    
    bool columnvalid(vector<vector<char>>& board,int j){
        vector<int> count(10,0);
        for(int i=0;i<9;++i){
            char c = board[i][j];
            if(isdigit(c)){
                int num = board[i][j] - '0';
                count[num]++;
                if(count[num]>1) return false;
            }
        }
        return true;
    }
    
    bool subboxvalid(vector<vector<char>>& board,int m,int n){
        vector<int> count(10,0);
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                char c = board[m+i][n+j];
                if(isdigit(c)){
                    int num = board[m+i][n+j] - '0';
                    count[num]++;
                    if(count[num]>1) return false;
                }
            }
        }
        return true;
    }
};
