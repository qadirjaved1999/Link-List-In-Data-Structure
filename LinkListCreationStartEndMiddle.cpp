#include<iostream>
using namespace std;

class Node {
   public:
   int data;
   Node* next;


   Node(int value){  //Default Constructors(Object create karna pa atumatically run hota ha)
    this->data = value;
    this->next = NULL;
   }
};

void insertHead(Node* &head, int d){

    // Create New Node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &tail, int d){

    // Create New Node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition( Node* &tail, Node* &head, int position, int d){
    //Insertion at Start Position.
    if(position == 1){
        insertHead(head, d);
        return;
    }
   Node* temp = head;
   int current = 1;

   while (current < position - 1)
   {
       temp = temp->next;
       current++;
   }

//    Insertion At Last Position
   if(temp -> next == NULL){
       insertTail(tail, d);
       return;
   }

//    creating a node for d
   Node* nodeToInsert = new Node(d);
   nodeToInsert->next = temp->next;
   temp->next = nodeToInsert;
   
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
       cout<< temp->data <<" ";
       temp = temp->next;
    }
    cout<<endl;
}


int main()
{ 

Node* node1 = new Node(10); //Create Object.
cout<<node1-> data<<endl;
cout<<node1-> next<<endl;


//Head pointed to node1
Node* head = node1;
Node* tail = node1;

print(head); //print

// insertHead(head, 12); // calling the function

insertTail(tail, 12); // calling the function

print(head); //print

// insertHead(head, 15); // calling the function

insertTail(tail, 15); // calling the function

print(head); //print

insertAtPosition(tail, head, 4, 44);

// insertAtPosition(head, 3, 33);

// insertAtPosition(head, 1, 33);

print(head); //print

cout<<"Head "<<head->data<<endl;
cout<<"Tail "<<tail->data<<endl;




 return 0;
}