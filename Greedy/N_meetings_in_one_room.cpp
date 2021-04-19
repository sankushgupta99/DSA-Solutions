class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool sortbysec(pair<int,int> p1, pair<int,int> p2){
        return p1.second < p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meet;
        for(int i = 0; i < n; i++){
            meet.push_back(make_pair(start[i], end[i]));
        }
        sort(meet.begin(), meet.end(), sortbysec);
        int max_meets = 1;
        int end_time = meet[0].second;
        for(int i = 1; i < n; i++){
            if(meet[i].first > end_time){
                max_meets++;
                end_time = meet[i].second;
            }
        }
        return max_meets;
    }
};