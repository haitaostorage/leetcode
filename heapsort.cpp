/*
	heap sort and get top k maxsize number

*/
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	Node(int arg):elem(arg),parent(NULL),leftchild(NULL),rightchild(NULL){}
	int elem;
	Node* parent;
	Node* leftchild;
	Node* rightchild;
};


class Heap{
public:
	Heap():_root(NULL){}

	void init(vector<int>& vect){
		if(vect.empty()){
			return;
		}
		vector<int>::iterator iter = vect.begin();
		for(iter=vect.begin();iter!=vect.end();iter++){
			Node* node = new Node(*iter);
			build(&(_root),node);
		}
	}

	Node* get_root() const{
		return _root;
	}

	void visit(Node* root){
		if(root==NULL){
			return;
		}
		visit(root->leftchild);
		visit(root->rightchild);
		cout<<"value:"<<root->elem<<endl;
	}
	
	void change(int elem){
		if(_root == NULL)
			return;
		if(elem > _root->elem){
			return;
		}
		_root->elem = elem;
		adjust(_root);
	}
	
	void sort_visit(Node** root){
		if(*root==NULL){
			return;
		}
		sort_visit(&((*root)->leftchild));
		sort_visit(&((*root)->rightchild));
		process(root);
	}

	void heap_sort(vector<int>& vect){
		init(vect);
		sort_visit(&_root);
	}

	void display(){
		vector<int>::iterator iter;
		for(iter=sort.begin();iter!=sort.end();iter++){
			cout<<"elem:"<<*iter<<endl;
		}
		return;
	}

private:
	Node* _root;
	vector<int> sort;
	void build(Node** root,Node* n){
		if(*root==NULL){
			*root = n;
			n->parent = (Node*)((void*)root-24);
			return;
		}
		if(n->elem > (*root)->elem){
			n->parent = (*root)->parent;
			(*root)->parent = n;
			n->leftchild = *root;
			*root = n;
			return;
		}
		build(&((*root)->rightchild),n);
		//build(&((*root)->rightchild),n);
	}

	void process(Node** n){
		sort.push_back(_root->elem); 
		_root->elem = (*n)->elem;
		delete *n;
		*n = NULL;
		adjust(_root);
		return;
	}
	
	void adjust(Node* root){
		int temp;
		if(root == NULL){
			return;
		}
		if(!root->leftchild && !root->rightchild){
			return;
		}
		if(!root->leftchild  && root->rightchild->elem < root->elem){
			return;
		}
		if(!root->rightchild  && root->leftchild->elem < root->elem){
			return;
		}
		if(!root->leftchild  && root->rightchild->elem > root->elem){
			temp = root->elem;
			root->elem = root->rightchild->elem;
			root->rightchild->elem = temp;
			adjust(root->rightchild);
			return;
		}
		if(!root->rightchild  && root->leftchild->elem > root->elem){
			temp = root->elem;
			root->elem = root->leftchild->elem;
			root->leftchild->elem = temp;
			adjust(root->leftchild);
			return;
		}

		if(root->leftchild && root->leftchild->elem < root->elem &&
			root->rightchild && root->rightchild->elem < root->elem){
			return;
		}
		if(root->leftchild && root->rightchild && root->rightchild->elem < root->leftchild->elem
			&& root->elem < root->leftchild->elem){
			temp = root->elem;
			root->elem = root->leftchild->elem;
			root->leftchild->elem = temp;
			adjust(root->leftchild);
			return;
		}
		if(root->leftchild && root->rightchild && root->rightchild->elem > root->leftchild->elem
			&& root->elem < root->rightchild->elem){
			temp = root->elem;
			root->elem = root->rightchild->elem;
			root->rightchild->elem = temp;
			adjust(root->rightchild);
			return;
		}
	}
};

int main()
{
	Heap heap;
	vector<int> vect;
	int i = 0;
	int a;
	while(i<5){
		cin>>a;
		vect.push_back(a);
		i++;
	}
	heap.heap_sort(vect);
	heap.display();
	return 0;
}
