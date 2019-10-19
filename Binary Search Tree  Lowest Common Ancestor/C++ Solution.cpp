#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        vector<Node*> pathToV1 = getPath(root, v1);
        vector<Node*> pathToV2 = getPath(root, v2);

        if(pathToV1.size() > pathToV2.size()){
            return findAncestor(pathToV1, pathToV2);
        }else{
            return findAncestor(pathToV2, pathToV1);
        }
    }

    Node* findAncestor(vector<Node*> longList, vector<Node*> shortList){
        for(int i = 0; i < shortList.size(); i++){
            if(shortList[i] != longList[i]){
                return shortList[i-1];
            }
        }
        return shortList[shortList.size() - 1];
    }

    vector<Node*> getPath(Node *n, int val){
        vector<Node*> list;
        list.push_back(n);

        while(n->data != val){
            if(n->data > val){
                n = n->left;
            }else{
                n = n->right;
            }
            list.push_back(n);
        }
        return list;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
