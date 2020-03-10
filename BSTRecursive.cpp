#include<iostream>
using namespace std;
void printLevel(struct Node* node,int level) ;


struct Node{
	int data;
	Node* left;
	Node* right;


};

Node* createNode (int data){
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* insertRec(Node* root, int data){
	if (root == NULL)
		root = createNode(data);
	else if (data < root->data)
		root->left = insertRec(root->left, data);
	else
		root->right = insertRec(root->right, data);
	return root;
}

Node* findMinRec(Node* root){

	if (root==NULL)
	{
		
		return root;

	}

	if(root->left != NULL)
		root = findMinRec(root->left);

		
	return root;

}

Node* findMaxRec (Node* root){

	if (root==NULL)
	
		return NULL;
	

	if (root->right !=NULL)
		
		root = findMaxRec(root->right);

	return root;

}


Node* findPrevRec(Node* root, int passedInData) {
	
	if (root ==NULL)
		return NULL;
	else{
		if (passedInData < root->data)
			root=findPrevRec(root->left, passedInData);
		else if (passedInData > root->data)
			root=findPrevRec(root->right, passedInData);

		else
			root=findMaxRec(root->left);
	}

	return root;
}



Node* findNextRec(Node* root, int passedInData) {
	
	if (root ==NULL)
		return NULL;
	else{
		if (passedInData < root->data)
			root=findNextRec(root->left, passedInData);
		else if (passedInData > root->data)
			root=findNextRec(root->right, passedInData);

		else
			root=findMinRec(root->right);
	}

	return root;
}

Node* deleteRec (Node* root, int data){

	if (root==NULL){
		return root;
	}
	else if (data < root->data){
		root->left = deleteRec(root->left, data);
	}
	else if (data > root->data){
		root->right =deleteRec(root->right, data);
	}
	else{
		if (root->left ==NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if (root->left ==NULL){
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right ==NULL){
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			Node* temp = findMinRec (root->right);
			root->data = temp->data;
			root->right = deleteRec(root->right, temp->data);
		}
	}
	return root;
}


int height(Node* node){
	if(node==NULL){
		return 0;
	}
	else{
		int lDepth=height(node->left);
		int rDepth=height(node->right);
		if(lDepth > rDepth){
			return (lDepth+1);
		}
		else{
			return (rDepth+1);
		}
	}
}

void printLevelOrder(struct Node* node) { 

	int h=height(node);
	 
	for(int i=0;i<=h;i++){
		printLevel( node ,i);
	}

}  

void printLevel(struct Node* node,int level) { 

    if (node == NULL) 
        return; 
	if(level==1){
		cout<<node->data<<endl;

	}   
	else if (level>1){
		printLevel(node->left,level-1); 
	  	
	    printLevel(node->right,level-1); 
	}
    
}


int main(int argc, char const *argv[])
{
	Node* root = NULL;

	root = insertRec(root, 15);
	root = insertRec(root, 12);
	root = insertRec(root, 20);
	root = insertRec(root, 14);
	root = insertRec(root, 123);
	root = insertRec(root, 39);
	root = insertRec(root, 28);
	root = insertRec(root, 5);
	root = insertRec(root, 1);
	root = insertRec(root, 0);
	root = insertRec(root, 4);

	//cout << findMinRec(root) ->data <<endl;
	//cout << findMaxRec(root,15) ->data <<endl;

	deleteRec(root, 15);
	
	printLevelOrder(root);
	//cout << height (root);

	//cout << findNextRec(root, 12)->data <<endl;
	//cout << findPrevRec(root, 20)->data <<endl;



	
	return 0;
}
