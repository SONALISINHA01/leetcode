struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head=tail=nullptr;
        size=0;
    }
    int get(int index) {
        if(size==0 ||index>=size)return -1;
        Node* temp=head;
        while(index--){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(size==0){
            head=tail=newnode;
        }else{
            newnode->next = head;
            head= newnode;
        }
        size++;
        return;
    }
    
    void addAtTail(int val) {
        Node* newnode = new  Node(val);
        if(head==nullptr){
            head=tail = newnode;
            size++;
            return;
        }
        Node* temp =head;
        while(temp->next!=nullptr){
            temp =temp->next;
        }
        temp->next= newnode;
        tail =newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        index--;
        Node* temp= head;
        while(index--){
            temp=temp->next;
        }
        Node* hello = temp->next;
        Node* newnode = new Node(val);
        temp->next=newnode;
        newnode->next = hello;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        if(index==0){
            head=head->next;
            size--;
            return;
        }
        index--;
        Node* temp= head;
        while(index--){
            temp=temp->next;
        }
        temp->next= temp->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */