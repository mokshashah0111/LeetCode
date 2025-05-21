class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q_R;
        queue<int>q_D;
        
        for(int i=0;i<senate.size();i++){
            if(senate[i] == 'D')q_D.emplace(i);
            else q_R.emplace(i);
        }

        while(!q_D.empty() && !q_R.empty()){
            int r = q_R.front();
            q_R.pop();
            int d= q_D.front();
            q_D.pop();

            if(r<d)q_R.emplace(r+senate.size());
            else q_D.emplace(d+senate.size());
        }

        return q_R.empty() ? "Dire" : "Radiant";
    }
};