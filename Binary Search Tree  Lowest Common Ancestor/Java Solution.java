import java.util.*;
import java.io.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {

	/*
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/
	public static Node lca(Node root, int v1, int v2) {
      	// Write your code here.
        List<Node> pathToV1 = pathToNode(root, v1);
        List<Node> pathToV2 = pathToNode(root, v2);

        if(pathToV1.size() > pathToV2.size()){
            return findCommonAncestor(pathToV1, pathToV2);
        }else{
            return findCommonAncestor(pathToV2, pathToV1);
        }
    }

    public static Node findCommonAncestor(List<Node> longList, List<Node> shortList){
            for(int i = 0; i < shortList.size(); i++){
                if(shortList.get(i) != longList.get(i)){
                    return longList.get(i-1);
                }
            }
            return shortList.get(shortList.size() - 1);
    }

    public static List<Node> pathToNode(Node n, int val){
        List<Node> list = new ArrayList<Node>();
        list.add(n);
        while(n.data != val){
            if(n.data > val){
                n = n.left;
            } else{
                n = n.right;
            }
            list.add(n);
        }
        return list;
    }

	public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
        int v1 = scan.nextInt();
      	int v2 = scan.nextInt();
        scan.close();
        Node ans = lca(root,v1,v2);
        System.out.println(ans.data);
    }	
}