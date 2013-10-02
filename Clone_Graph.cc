/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (node == NULL)
            return NULL;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        
        map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        mp[node] = ret;
        queue<UndirectedGraphNode *> que;
        que.push(node);
        
        UndirectedGraphNode *tmp = NULL, *nxt = NULL;
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            for (int i = 0; i < (tmp->neighbors).size(); i++) {
                nxt = (tmp->neighbors)[i];
                if (mp.find(nxt) == mp.end()) {
                    mp[nxt] = new UndirectedGraphNode(nxt->label);
                    que.push(nxt);
                }
                (mp[tmp]->neighbors).push_back(mp[nxt]);
            }
        }
        return ret;
    }
};
