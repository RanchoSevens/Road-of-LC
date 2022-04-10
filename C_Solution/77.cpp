class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> visited(n+1,0);
        vector<vector<int>> result;
        for(int i=1;i<=n;i++){
            vector<int> temp;
            visited[i] = 1;
            temp.push_back(i);
            dfs(result,temp,visited,i,k,n);
            temp.pop_back();
            visited[i] = 0;
        }
        return result;
    }
    void dfs(vector<vector<int>>& result,vector<int>& temp,vector<int>& visited,int start,int num,int n){
        if(temp.size()==num){
            result.push_back(temp);
            for(int i=0;i<temp.size();++i){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
            return;
        }else{
            for(int i=start;i<=n;i++){
                if(!visited[i]){
                    visited[i]=1;
                    temp.push_back(i);
                    dfs(result,temp,visited,i,num,n);
                    temp.pop_back();
                    visited[i]=0;
                }
            }
        }
    }
};
