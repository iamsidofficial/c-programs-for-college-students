#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

string tree2str(Node* root) {
        string ans = to_string(root->data);
        if(root == NULL) return ans;
        
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
            
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
            
		}
        cout<<ans<<endl;
		return ans;
        
    }


void levelOrder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }else if(!q.empty())
            q.push(NULL);
        
    }
    
}

int sumAtKthLevel(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum =0;
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            {
                if(level == k){
                    sum+= node->data;
                }
            }
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }else if(!q.empty()){
            q.push(NULL);
            level++;
        }
        
    }
    return sum;
}

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;

}

int sumOfAllNode(Node* root){
    if(root== NULL){
        return 0;
    }
    return sumOfAllNode(root->left) + sumOfAllNode(root->right) + root->data;
}

int calHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int lheight = calHeight(root->left);
    int rheight = calHeight(root->right);
    return max(lheight,rheight) + 1;
}
// Diamter is the number of nodes in the longest path between any 2 leaves
int calDiameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lheight =  calHeight(root->left);
    int rheight = calHeight(root->right);
    int currDiameter = lheight + rheight + 1;
    int ldiameter = calDiameter(root->left);
    int rdiameter = calDiameter(root->right);
    return max(currDiameter, max(ldiameter,rdiameter));
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);
    root->left->left->right=new Node(10);
    //preOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout<<endl;
    // levelOrder_traversal(root);
    // cout<<endl;
    // cout<<"The sum of nodes at 2st Level is "<< sumAtKthLevel(root, 2);
    tree2str(root);
    // cout<<countNodes(root)<< "\t"<< sumOfAllNode(root)<<"\t";
    // cout<<calHeight(root)<< " "<<calDiameter(root);

    return 0;
}