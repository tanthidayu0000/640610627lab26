#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int idx){
	Node *current1 = root;
	Node *current2 = root;
	Node *temp1, *temp2;

	for(int i=0; i<idx; i++){
		current2 = current2->next;
	}
	temp2 = current2;

	for(int i=0;i<size;i++){
		if(i != idx-1){
			current1=current1->next;
		}
		else{
			temp1=current1->next;
			current1->next=temp2->next;
		}
		if(idx == 0){
			delete root;
			root = current1;
			return;
		}
		else if(i == idx-1){
			delete temp1;
			return;
		}
	}
}
