class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int c = 0 ; 
        unordered_set<int> visited, found;
        queue<int> q;
        for(auto & vec : initialBoxes){
            found.insert(vec);
            if(status[vec]==1){
                q.push(vec);
                visited.insert(vec);
                c+=candies[vec];

            }
        }
        while(!q.empty()){
            int box= q.front();
            q.pop();
            for(int& vec  : containedBoxes[box]){
                found.insert(vec);
                if(status[vec]==1 && !visited.count(vec)){
                q.push(vec);
                visited.insert(vec);
                c+=candies[vec];

                }
            }
            for(int &vec : keys[box]){
                status[vec]=1;
                if(found.count(vec) && !visited.count(vec)){
                q.push(vec);
                visited.insert(vec);
                c+=candies[vec];
                }
            }
        }
        // for(auto &vec : initialBoxes){
        //     c += dfs(vec, candies, keys, containedBoxes, visited, found,status);
        // }
        return c;

    }
//     int dfs(int box, vector<int> & candies, vector<vector<int>> &keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& found, vector<int>& status){
//         if(visited.count(box))
//         return 0; 

//         if(status[box]==0){
//             found.insert(box);
//             return 0;
//         }
//         visited.insert(box);
//         int cc = candies[box];
//         for(auto &vec : containedBoxes[box]){
//             cc+=dfs(vec,candies, keys, containedBoxes, visited, found,status);
//         }
//         for(auto &vec : keys[box]){
//             status[vec]=1;
//             if(found.count(vec)){
//                 cc +=dfs(vec,candies, keys, containedBoxes, visited, found,status);
//             }
//         }
//         return cc;
//     }
 };