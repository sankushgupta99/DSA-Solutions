/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    int find(int x, int par[]){
        if(par[x] == x)
        return x;

        int temp = find(par[x], par);
        par[x] = temp;
        return temp;
    }

    void unionSet(int x, int y, int par[], int rank[]){
        int lox = find(x, par);
        int loy = find(y, par);

        if(rank[lox] > rank[loy]){
            par[loy] = lox;
        }
        else if(rank[loy] > rank[lox]){
            par[lox] = loy;
        }
        else{
            par[lox] = loy;
            rank[loy]++;
        }
    }

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        int par[n*m], rank[n*m];
        memset(par, -1, sizeof(par));
        for(int i = 0; i < n*m; i++){
            rank[i] = 1;
        }

        vector<int> res;
        int islands = 0;

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto i : operators){
            int x = i.x;
            int y = i.y;
            int pos = (x * m) + y;

            if(par[pos] != -1){
                res.push_back(islands);
                continue;
            }
            par[pos] = pos;
            islands++;

            for(int k = 0; k < 4; k++){
                int x1 = x + dir[k][0];
                int y1 = y + dir[k][1];
                int pos1 = (x1 *m) + y1;

                if(x1 < 0 || y1 < 0 || x1 == n || y1 == m || par[pos1] == -1)
                continue;

                if(find(pos, par) != find(pos1, par)){
                    islands--;
                    unionSet(pos, pos1, par, rank);
                }
            }
            res.push_back(islands);
        }
        return res;
    }
};