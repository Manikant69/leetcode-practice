class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int n = edges.size();

        // //because the vertices are from 1 to n 
        // vector<int> path(n+2, 0);

        // for(int i=0; i<n; i++)
        // {
        //     path[edges[i][0]]++;
        //     path[edges[i][1]]++;
        // }

        // for(int i=0; i<path.size(); i++)
        // {
        //     if(path[i] == edges.size()){
        //         return i;
        //     }
        // } 

        // return -1; 


       /* In a star graph, there will be only two columns always as the center is connected to other edges
example- [[1,2],[5,1],[1,3],[1,4]] in this example 1->2,1->5,1->3,1->4
So you have to just check for [0][0]==[0][1] || [0][0]==[1][1] so if [0][0] occurs twice then it is your answer and if this is not your answer then next element will definitely is your answer because there are only two columns and center element must occur in all rows so  */

        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
            return edges[0][0];
        }
        else{
            return edges[0][1];
        }
    }
};
