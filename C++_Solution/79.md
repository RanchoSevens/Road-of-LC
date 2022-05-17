class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        bool result = false;
        if (word.empty()||word.empty()) return result;
        int leni = board.size(), lenj = board[0].size();
        vector<int> flag(leni * lenj, 1);
        for (int i = 0; i < leni; ++i) {
            for (int j = 0; j < lenj; ++j) {
                if (board[i][j] == word[0]) {
//                    cout << "board[" << i << "][" << j << "]=" << board[i][j] << endl << "word[iw]=" << word[0] << endl;
                    flag[i * lenj + j] = 0;
                    dfs(board, flag, word, result, i, j, 1, leni, lenj);
                    if (result) return result;
                    flag[i * lenj + j] = 1;
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>> &board, vector<int> &flag, string &word, bool &result, int x, int y, int iw, int leni,
             int lenj) {
        if (iw == word.size()) {
            result = true;
            // cout<<"yes"<<endl;
            return;
        }
        int direction[4][2] = {{0,-1},
                               {0,1},
                               {-1,0},
                               {1,0}};
        for (int t = 0; t < 4; ++t) {
            int i=direction[t][0];
            int j=direction[t][1];
            int posx = x + i, posy = y + j;
            if (posx < 0 || posx >= leni || posy < 0 || posy >= lenj) continue;

            if (board[posx][posy] == word[iw] && flag[posx * lenj + posy]) {
                // cout << "board[" << posx << "][" << posy << "] ==" << " word[iw] = " << word[iw]<< endl;
                flag[posx * lenj + posy] = 0;
                dfs(board, flag, word, result, posx, posy, iw + 1, leni, lenj);
                if(result) return;
                flag[posx * lenj + posy] = 1;
            }
        }
        return;
    }
};
