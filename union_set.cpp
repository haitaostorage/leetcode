#include <iostream>
#include <map>
using namespace std;

class Node{
public:
	Node(int a,int b,int c):elem(a),parent(b),rank(c){}
	int elem;
	int parent;
	int rank;
};
class Union_set{
public:
	Union_set(){}
	
	Node* findset(int elem){
		Node* node = _ElemSet[elem];
		if(node->elem != node->parent){
			node = findset(node->parent);
		}
		return node;
	}

	int Union(int a,int b){
		map<int,Node*>::iterator iter = _ElemSet.end();
		Node* node;
		if(_ElemSet.find(a)==iter){
			node = new Node(a,a,1);
			_ElemSet[a] = node;
		}
		if(_ElemSet.find(b)==iter){
			node = new Node(b,b,1);
			_ElemSet[b] = node;
		}
		Node* node1 = findset(a);
		Node* node2 = findset(b);
		if(node1->rank <= node2->rank){
			node1->parent = node2->elem;
			node2->rank++;
		}
		else{
			node2->parent = node1->elem;
			node1->rank++;
		}
	}
	int SetCount(){
		map<Node*,int> count;
		map<int,Node*>::iterator iter;
		Node* parent;
		for(iter=_ElemSet.begin();iter!=_ElemSet.end();iter++){
			parent = findset(iter->second->elem);
			count[parent] = 1;
		}
		return count.size();
	}
	~Union_set(){
		map<int,Node*>::iterator iter;
		for(iter=_ElemSet.begin();iter!=_ElemSet.end();iter++){
			delete iter->second;
		}
		_ElemSet.clear();
	}
private:
	map<int,Node*> _ElemSet;
};

int main()
{
	int a,b;
	Union_set uset;
	while(cin>>a>>b){
		if(a==0){
			break;
		}
		uset.Union(a,b);
	}
	cout<<"Count of unionset is "<<uset.SetCount()<<endl;
	return 0;




}

