
/*
    Minimum Height Trees

    https://leetcode.com/problems/minimum-height-trees/

    For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

    Format
    The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
    You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

    Example 1:

    Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

            0
            |
            1
           / \
          2   3
    return [1]

    Example 2:

    Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

         0  1  2
          \ | /
            3
            |
            4
            |
            5
    return [3, 4]

    Show Hint

    (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
    (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (edges.empty()) { return {0}; }
        vector<unordered_set<int>> neighbours(n);

        for (auto p : edges) {
            neighbours.at(p.first).insert(p.second);
            neighbours.at(p.second).insert(p.first);
        }

        vector<int> curr_vec, prev_vec;
        for (int index = 0; index < neighbours.size(); index++) {
            if (neighbours.at(index).size() == 1) { prev_vec.push_back(index); }
        }

        while (true) {
            for(auto prev_index : prev_vec) {
                for (auto to_remove_index : neighbours.at(prev_index)) {
                    neighbours.at(to_remove_index).erase(prev_index);
                    if (neighbours.at(to_remove_index).size() == 1) {
                        curr_vec.push_back(to_remove_index);
                    }
                }
            }

            if (curr_vec.empty()) { break; }
            prev_vec = curr_vec;
            curr_vec.clear();
        }
        return prev_vec;
    }
};


