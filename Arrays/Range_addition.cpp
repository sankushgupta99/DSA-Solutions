class Solution {
public:

    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        int arr[length]={0};
        for(int i = 0; i < updates.size(); i++){
            arr[updates[i][0]] += updates[i][2];
            if(updates[i][1] < length - 1)
            arr[updates[i][1] + 1] -= updates[i][2];
        }
        int sum = 0;
        vector<int> res;
        for(int i = 0; i < length; i++){
            sum += arr[i];
            res.push_back(sum);
        }
        return res;
    }
};