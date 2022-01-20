#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    uncomment if you need to use long long for testing instead of int
*/
// #define int long long

class Node{
    public:
    vector<Node *> neigh;
    int val;
    Node(int x){
        val = x;
    }
    void insert(Node *x){
        neigh.push_back(x);
    }
};

int countNodesWithNeighborSumNotMoreThanK(Node* start, unordered_set<Node *>& vis, int K){
    
    // if node already visited, return back
    if(vis.find(start) != vis.end()) return 0;
    
    vis.insert(start);
    
    int sum = 0, ans = 0;
    
    for(int i = 0; i < start->neigh.size(); i++){
        ans += countNodesWithNeighborSumNotMoreThanK(start->neigh[i], vis, K);
        sum += start->neigh[i]->val;
    }

    if(sum <= K) ans += 1;
    
    return ans;
}

int32_t main(){
    // edit the data and check the output for various graphs
    // list of node values
    vector<int> a = {1, 2, 3, 4, 5};
    vector<Node *> v;
    for(int x: a){
        v.push_back(new Node(x));
    }
    // adjacency list for neighbors
    vector<vector<int>> neighbors = {
        {1, 3, 4},
        {0},
        {3, 4},
        {0, 2},
        {0, 2}
    };
    // K value for the problem
    int K = 4;
    for(int i = 0; i < neighbors.size(); i++){
        for(int j: neighbors[i]){
            v[i]->insert(v[j]);
        }
    }
    unordered_set<Node *> vis;
    cout << countNodesWithNeighborSumNotMoreThanK(v[0], vis, K);
}
