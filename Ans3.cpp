//  In your implementation of question 2, add the following functions in your Doubly Linked-list class.									      10
// print() : Prints the linked-list starting from head. Expected Complexity O(n).
// merge(LinkedList a) : This function takes as input a LinkedList and merges the “LinkedList a” at the back of the current linked-list. Expected Complexity O(1).
// 	Your implementation for problem 2 and 3 should look like this. You may write any extra functions that you need.
	
// class Node{
// 	int value;
// 	Node* nxt;
// 	Node* prv;
// };

// class LinkedList{
// 	Node* head;
// 	Node* tail;
// 	LinkedList()
// 	{
// 		//Write your code
// 	}
// 	void insertHead(int value)
// 	{
// 		//Write your code
// 	}
// 	void insertTail(int value)
// 	{
// 		//Write your code
// 	}
// 	void insertMid(int value)
// 	{
// 		//Write your code
// 	}
// 	void print()
// 	{
// 		//Write your code
// 	}
// 	void Merge(LinkedList a)
// 	{
// 		//Merge a at the back of this linked-list
// 		//Write your code
// 	}
// };
// int main()
// {
// 	LinkedList a;
// 	LinkedList b;

// 	a.insertHead(1);
// 	a.insertTail(5);
// 	a.insertMid(3);
// 	a.insertHead(0);
// 	a.insertTail(10);
// 	a.print(); // prints  0 1 3 5 10
	
// 	b.insertHead(10);
// 	b.insertTail(50);
// 	b.insertMid(30);
// 	b.insertHead(9);
// 	b.insertTail(100);
// 	b.print(); // prints  9 10 30 50 100
	
// 	a.Merge(b);
// 	a.print(); // prints  0 1 3 5 10 9 10 30 50 100
// 	b.print(); // prints  9 10 30 50 100
// }




// ----------------------- Solution -------------------------
 #include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int value;
	Node* nxt;
	Node* prv;
};

class LinkedList{
	public:
	Node* head;
	Node* tail;
    int sz;
	LinkedList()
	{
		head = NULL;
        tail = NULL;
        sz = 0;
	}
    Node* CreateNewNode (int data){
        Node* newnode = new Node;
        newnode->value = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
	void insertHead(int value)
	{
		        Node* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        sz++;
	}
	void insertTail(int value)
	{
        Node* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
	}
	void insertMid(int value)
	{
		Node* node = CreateNewNode(value);
		Node* temp = head;
        if(sz==0)
        {
            head = node;
            tail = node;
            sz++;
            return;
        }
		int mid = sz/2;
		for (int i=0;i<mid;i++){
			temp = temp->nxt;
		}

		if (sz % 2 == 0) {
            node->prv = temp->prv;
            node->nxt = temp;
            temp->prv->nxt = node;
            temp->prv = node;
        } else {
            node->nxt = temp->nxt;
            node->prv = temp;
            temp->nxt->prv = node;
            temp->nxt = node;
        }
	}
	void print()
	{
		Node* a=head;
		while(a!=NULL){
			cout<<a->value<<" ";
			a = a->nxt;
		}
		cout<<"\n";
	}
	void Merge(LinkedList a)
	{
		if(a.head==NULL){
			return;
		}
		if(head == NULL){
			head = a.head;
		}
		else{
			tail->nxt=a.head;
			a.head->prv=tail;
		}
		tail = a.tail;
		sz+=a.sz;
	}
};
int main()
{
	LinkedList a;
	LinkedList b;

	a.insertHead(1);
	a.insertTail(5);
	a.insertMid(3);
	a.insertHead(0);
	a.insertTail(10);
	a.print(); // prints  0 1 3 5 10

	b.insertHead(10);
	b.insertTail(50);
	b.insertMid(30);
	b.insertHead(9);
	b.insertTail(100);
	b.print(); // prints  9 10 30 50 100

	a.Merge(b);
	a.print(); // prints  0 1 3 5 10 9 10 30 50 100
	b.print(); // prints  9 10 30 50 100
}


