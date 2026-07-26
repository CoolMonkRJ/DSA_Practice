class Solution {
    private :
      bool isCycle(int src ,vector<int> &vis , vector<int> adj[], vector<int>&PathV) {
        vis[src]=1;
        PathV[src]=1;

        for( auto it : adj[src]) {
            if(!vis[it]) {
                if(isCycle(it,vis,adj,PathV))
                return true;
            }
            else if(PathV[it]) {
                return true;
            }
        }
        PathV[src] =0;

        return false;
      }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>adj[numCourses];

        //build the graph 

        for(auto it : prerequisites)
        {
            int u= it[1];
            int v = it[0];

            adj[u].push_back(v);
        }

        vector<int> vis(numCourses,0);
        vector<int> PathV(numCourses,0);

        for(int i=0;i<numCourses;i++) {

            if(!vis[i]) {
                if(isCycle(i,vis,adj,PathV))
                return false;
            }

        }

        return true;
    }
};


// becuase the graphs can be disconnected 
// we have visted a node via some other parents 
