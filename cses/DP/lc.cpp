#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define deb(x) cerr << #x << ": " << x << '\n'
#define rep(i,n) for(int i = 0; i<n; ++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int minCost;  

    TrieNode() : minCost(INT_MAX) {}
};

struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word, int cost) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->minCost = min(node->minCost, cost);
    }
    TrieNode* getRoot() {
        return root;
    }
    
};
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        Trie trie;
        for (int i = 0; i < words.size(); ++i) {
            trie.insert(words[i], costs[i]);
        }

        TrieNode* root = trie.getRoot();

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue;
            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                if (node->children.find(target[j]) == node->children.end()) {
                    break;
                }
                node = node->children[target[j]];
                if (node->minCost != INT_MAX) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + node->minCost);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
/*
   "abcdef"
i:  0 
j:  0
dp: INF 1 2 INF 7    
"abcdef"
["abdef","abc","d","def","ef"]
[100,1,1,10,5]


*/

void solve(){

  

}


int main(){
  ios();
  int T = 1;
  //cin >> T;
  while (T--){
    solve();
  }
    return 0;
}