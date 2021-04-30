class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int N) {
        vector<int> v1;
        int xor1 = 0;
        for(int i = Q.size()-1; i >= 0; i--){
            int q_type = Q[i][0];
            int x = Q[i][1];
            if(q_type == 0){
                v1.push_back(x ^ xor1);
            }
            else{
                xor1 = xor1 ^ x;
            }
        }
        v1.push_back(xor1);
        sort(v1.begin(), v1.end());
        return v1;
    }
};

//OR

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int N) {
        vector<int> v1;
        v1.push_back(0);
        vector<pair<int,int> > vpi;
        for(int i = 0; i < Q.size(); i++){
            int q_type = Q[i][0];
            int x = Q[i][1];
            if(q_type == 0){
                v1.push_back(x);
            }
            else{
                int len = vpi.size();
                if(len > 0 && vpi[len-1].first == v1.size()-1){
                    vpi[len-1].second = vpi[len-1].second ^ x;
                }
                else
                vpi.push_back(make_pair(v1.size()-1, x));
            }
        }
        int xor1 = 0;
        int j = vpi.size()-1;
        for(int i = v1.size()-1; i >= 0; i--){
            if(j >= 0 && vpi[j].first == i){
                xor1 = xor1 ^ vpi[j].second;
                j--;
            }
            v1[i] = v1[i] ^ xor1;
        }
        sort(v1.begin(), v1.end());
        return v1;
    }
};