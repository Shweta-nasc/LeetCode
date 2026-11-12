class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int loser=matches[i][1];
            mp[loser]++;
        }
        vector<int>neverlos;
        vector<int>onelos;
        for(int i=0;i<n;i++){
            int winner=matches[i][0];
            int loser=matches[i][1];

            if(mp.find(winner)==mp.end()){
                neverlos.push_back(winner);
                mp[winner]=2;

            }
            if(mp[loser]==1){
                onelos.push_back(loser);
            }
        }

        sort(onelos.begin(),onelos.end());
        sort(neverlos.begin(),neverlos.end());



        return {neverlos,onelos};

    }
};