// C++ program to implement Tree Sort
#include<bits/stdc++.h>

using namespace std;

long long comparation = 0; 
long long swaps = 0; 
long long iteration = 0;

struct Node
{
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Stores inorder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
	if (root != NULL)
	{
		comparation++;
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* A utility function to insert a new
Node with given key in BST */
Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) {
		comparation;
		return newNode(key);
	} 

	/* Otherwise, recur down the tree */
	if (key < node->key){
		node->left = insert(node->left, key);
		comparation++;
		swaps++;
	}
	else if (key > node->key){
		comparation++;
		node->right = insert(node->right, key);
		swaps++;

	}

	/* return the (unchanged) Node pointer */
	return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
	struct Node *root = NULL;

	// Construct the BST
	root = insert(root, arr[0]);
	for (int i=1; i<n; i++){
		root = insert(root, arr[i]);
		swaps++;
	}

	// Store inorder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(root, arr, i);
}

int main () {

    int n; 
    int a[1000006];

    cin >> n; 

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    treeSort( a, n);

	cout << comparation << ";" << swaps << ";";
	
}
