#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {


        if (root != NULL) {
            traverseInOrder(root->left);
            cout << root->key <<" ";
            traverseInOrder(root->right);
        }

}




struct node* newNode(int keyValue)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->key = keyValue;
	temp->left = temp->right = NULL;
	return temp;
}




// Insert a node
struct node *insertNode(struct node *node, int key) {




    if (node==NULL){
            return newNode( key);
    }


    if (key <node->key){
        node->left = insertNode(node->left, key);
    }
    else{
        node->right= insertNode(node->right , key);
    }
    return node;



}


/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{

	if (root == NULL)  //this is the base case
		return root;
	if (key < root->key)  // if the key to be deleted is lesser than the root we have to travel to the root->left
		root->left = deleteNode(root->left, key);
	else if (key > root->key)  // if the key to be deleted is greater  than the root we have to travel to the root->right
		root->right = deleteNode(root->right, key);
	else { //key is not the root->left or root->right , then it is same as the root
		// node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct node* current= root->right;
		while (current && current->left != NULL){  //find the left most loop
            current = current->left;
		}
		struct node* temp= current;



		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
