// A C++ program to implement Cartesian Tree sort 
// Note that in this program we will build a min-heap 
// Cartesian Tree and not max-heap. 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// Creating a shortcut for int, Node* pair type 
typedef pair<int, Node*> iNPair; 

// This function sorts by pushing and popping the 
// Cartesian Tree nodes in a pre-order like fashion 
void pQBasedTraversal(Node* root) 
{ 
	// We will use a priority queue to sort the 
	// partially-sorted data efficiently. 
	// Unlike Heap, Cartesian tree makes use of 
	// the fact that the data is partially sorted 
	priority_queue <iNPair, vector<iNPair>, greater<iNPair>> pQueue; 
	pQueue.push (make_pair (root->data,root)); 

	// Resembles a pre-order traverse as first data 
	// is printed then the left and then right child. 
	while (! pQueue.empty()) 
	{ 
		iNPair popped_pair = pQueue.top(); 
		printf("%d ",popped_pair.first); 

		pQueue.pop(); 

		if (popped_pair.second->left != NULL) 
			pQueue.push (make_pair(popped_pair.second->left->data, 
								popped_pair.second->left)); 

		if (popped_pair.second->right != NULL) 
			pQueue.push (make_pair(popped_pair.second->right->data, 
									popped_pair.second->right)); 
	} 

	return; 
} 


Node *buildCartesianTreeUtil(int root, int arr[], 
		int parent[], int leftchild[], int rightchild[]) 
{ 
	if (root == -1) 
		return NULL; 

	Node *temp = new Node; 

	temp->data = arr[root]; 
	temp->left = buildCartesianTreeUtil(leftchild[root], 
				arr, parent, leftchild, rightchild); 

	temp->right = buildCartesianTreeUtil(rightchild[root], 
				arr, parent, leftchild, rightchild); 

	return temp ; 
} 

// A function to create the Cartesian Tree in O(N) time 
Node *buildCartesianTree(int arr[], int n) 
{ 
	// Arrays to hold the index of parent, left-child, 
	// right-child of each number in the input array 
	int parent[n],leftchild[n],rightchild[n]; 

	// Initialize all array values as -1 
	memset(parent, -1, sizeof(parent)); 
	memset(leftchild, -1, sizeof(leftchild)); 
	memset(rightchild, -1, sizeof(rightchild)); 

	// 'root' and 'last' stores the index of the root and the 
	// last processed of the Cartesian Tree. 
	// Initially we take root of the Cartesian Tree as the 
	// first element of the input array. This can change 
	// according to the algorithm 
	int root = 0, last; 

	// Starting from the second element of the input array 
	// to the last on scan across the elements, adding them 
	// one at a time. 
	for (int i=1; i<=n-1; i++) 
	{ 
		last = i-1; 
		rightchild[i] = -1; 

		// Scan upward from the node's parent up to 
		// the root of the tree until a node is found 
		// whose value is smaller than the current one 
		// This is the same as Step 2 mentioned in the 
		// algorithm 
		while (arr[last] >= arr[i] && last != root) 
			last = parent[last]; 

		// arr[i] is the smallest element yet; make it 
		// new root 
		if (arr[last] >= arr[i]) 
		{ 
			parent[root] = i; 
			leftchild[i] = root; 
			root = i; 
		} 

		// Just insert it 
		else if (rightchild[last] == -1) 
		{ 
			rightchild[last] = i; 
			parent[i] = last; 
			leftchild[i] = -1; 
		} 

		// Reconfigure links 
		else
		{ 
			parent[rightchild[last]] = i; 
			leftchild[i] = rightchild[last]; 
			rightchild[last]= i; 
			parent[i] = last; 
		} 

	} 

	// Since the root of the Cartesian Tree has no 
	// parent, so we assign it -1 
	parent[root] = -1; 

	return (buildCartesianTreeUtil (root, arr, parent, 
									leftchild, rightchild)); 
} 

// Sorts an input array 
int printSortedArr(int arr[], int n) 
{ 
	// Build a cartesian tree 
	Node *root = buildCartesianTree(arr, n); 

	printf("The sorted array is-\n"); 

	// Do pr-order traversal and insert 
	// in priority queue 
	pQBasedTraversal(root); 
} 

/* Driver program to test above functions */
int main() 
{ 
	/* Given input array- {5,10,40,30,28}, 
		it's corresponding unique Cartesian Tree 
		is- 

		5 
		\ 
		10 
			\ 
			28 
			/ 
		30 
		/ 
		40 
	*/

	int arr[] = {5, 10, 40, 30, 28}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	printSortedArr(arr, n); 

	return(0); 
} 
