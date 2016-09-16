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
	//构建大根堆
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

	//后序遍历大根堆
	void visit(){
		_visit(_root);	
	}
	//调整大根堆
	void change(int elem){
		if(_root == NULL)
			return;
		if(elem > _root->elem){
			return;
		}
		_root->elem = elem;
		adjust(_root);
	}
	//堆排序接口
	void heap_sort(vector<int>& vect){
		init(vect);
		sort_visit(&_root);
	}
	//显示排序后的数组
	void display(){
		vector<int>::iterator iter;
		for(iter=sort.begin();iter!=sort.end();iter++){
			cout<<"elem:"<<*iter<<endl;
		}
		return;
	}
	
	int deepth(){
		return _deepth(_root);
	}
private:
	Node* _root;
	vector<int> sort;
	//构建大根堆
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
	//排序遍历
	void sort_visit(Node** root){
		if(*root==NULL){
			return;
		}
		sort_visit(&((*root)->leftchild));
		sort_visit(&((*root)->rightchild));
		process(root);
	}
	//处理节点，将其值与根节点值交换，并释放该节点
	void process(Node** n){
		sort.push_back(_root->elem); 
		_root->elem = (*n)->elem;
		delete *n;
		*n = NULL;
		adjust(_root);
		return;
	}
	//调整大根堆
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

	int max(int a,int b){
		return a>b? a:b;
	}
	//递归的方式求大根堆的深度
	int _deepth(Node* root){
		if(!root){
			return 0;
		}
		return max(_deepth(root->leftchild)+1,_deepth(root->rightchild)+1);
	}
	
	void _visit(Node* root){
		if(root==NULL){
			return;
		}
		_visit(root->leftchild);
		_visit(root->rightchild);
		cout<<"value:"<<root->elem<<endl;
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
