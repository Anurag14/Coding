#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
using namespace std;
template <typename T> class LinkedList;
template <typename T>
class Node {
    T data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(const T & el) : data(el), next(0) {}
    Node(const T & el, Node * ad): data(el), next(ad) {}
    T getData() const {
        return data;
    }
    template <typename V>
        friend class LinkedList;
    template<typename V>
       friend ostream & operator<<(ostream &, const LinkedList<V> &);
};

// This is a linked list class which has head and tail pointers. Implement all the below functions.
// Make sure that head and tail are always pointing to correct node after each operation.
// This is not double linked list. You only have one pointer in each node to store address of next element.
template <typename T>
class LinkedList {
    Node<T> * head;
    Node<T> * tail;
    // Prinvate function which empties the list.
    void clear() {
    while(head){
     Node<T>*temp=head;
    delete head;
    head=temp;
    } tail=NULL;
    }
    // Private function which empties the list and then creates the copy of the LinkedList passed as argument
    void copyAs(const LinkedList & L) {
        clear();
        Node<T> * it=L.head;
        Node <T> * temp=head;
        while(it){
            temp->data=it->data;
            temp=temp->next;
        }
    }
    static Node<T>* & reverselinkedlist(Node<T> * head){
       if(head==tail)
        return tail;
       Node<T> * temp=head;
       head=head->next;
       head=reverselinkedlist(head);
       Node<T>* ptr=head;
       while(ptr!=NULL){
        ptr=ptr->next;
       }
       ptr=temp;
       ptr->next=NULL;
       tail=temp;
       return head;
    }
    void deletetheaddress(Node<T>* ptr){
      if(ptr==head){
        head=head->next;
      delete(ptr);
       return;
    }
    Node<T> *temp=head;
    while(temp->next!=ptr){
        temp=temp->next;
    }
    temp->next=ptr->next;
    delete(ptr);
    }
    Node<T> * settotailprev(Node<T> * tail){
    Node<T> * tailprev=head;
      while(tailprev->next!=tail){
        tailprev=tailprev->next;
        return tailprev;
    }
    public:
    LinkedList() : head(0) {}
    ~LinkedList() {
        clear();
    }
    LinkedList(const LinkedList & L) : head(0) {
        copyAs(L);
    }
    LinkedList & operator=(const LinkedList & L) {
        copyAs(L);
        return *this;
    }
    // Inserts element at the end.
    void append(const T & el) {
        Node<T> * temp=new Node<T>;
        temp->data=el;
        temp->next=0;
        tail->next=temp;
        tail=temp;
    }
    // Inserts element at the beginning
    void prepend(const T & el) {
      Node<T> * temp=new Node<T>;
      temp->data=el;
      temp->next=head;
      head=temp;
    }

    // Delete one element from the beginning
    void deleteFromHead() {
        Node<T> * temp;
        temp=head;
        head=head->next;
        delete(temp);
    }

    // Delete one element from the end
    void deleteFromTail() {
      Node<T> *temp;
      temp=head;
      while(temp->next!=tail){
        temp=temp->next;
      }
      delete(tail);
      tail=temp;
      }

    // Insert at Kth Position
    void insertATKthPosition(int K, const T & el) {
    Node<T> *ptr1=head;
    Node<T> *ptr2=head->next;
    K--;
    while(K){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=ptr2->next;
    ptr2->next=0;
    delete(ptr2);
    }

    // Delete from Kth Position
    void deleteAtKthPosition(int K, const T & el) {
     Node<T> * temp=head;
     Node<T> * temp1=head->next;
     K--;
     while(K){
        temp=temp->next;
        temp1=temp1->next;
     }
     temp->next=temp1->next;
     delete(temp1);

    }

    // Return address of el in the list. If not present return NULL
    Node<T> * findElement(const T & el) const {
        Node<T>  * ptr=head;
        while(ptr!=NULL){
            if(ptr->data==el){
                return ptr;
            }
        ptr=ptr->next;
        }

    }
    // Function which returns length of the linked list
    int length() const {
        int len=0;
        Node<T> * ptr=head;
        while(ptr!=NULL){
            len++;
            ptr=ptr->next;
        }
     return len;
     }
    // function which returns address of Kth Node - returns NULL if K is out of Bound
    Node<T> * findKthElement() const {
        if(K>length)
            return NULL;
        Node<T> * temp=head;
        while(K--){
            temp=temp->next;
        }
        return temp;
    }
    // Swap ith and Jth Node of the linked list - Swap Nodes not the data. Do nothing if I or J are out of bounds
    void swap(int i, int j) {
    Node<T> *ptr=head,ptr1=head->next,ptr2=head,ptr3=head->next;
    if(i>length()||j>length())
        return;
    i--;j--;
    for(int k=0;k<j;i++){
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    for(int k=0;k<j;k++){
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
     ptr->next=ptr1->next;
     ptr2->next=ptr3->next;
     ptr3->next=ptr->next;
     ptr1->next=ptr2->next;
     ptr->next=ptr3;
     ptr2->next=ptr1;
    }
    // Reverses the linked list. You need to actually reverse the list not print in reverse order.
    void reverse() {
        reverselinklist(head);
    }
    // Sort the linked list using selection sort. You need to change next pointers in the data without using any array.
    void selectionsort() {

    }

    // Returns address of the mid node of the linked list
    Node<T> * findMidPoint() const {
        Node<T> * ptr=head,ptr1=head;
        while(ptr!=tail){
            ptr=ptr->next;
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
    return ptr1;
    }

    // Returns true if elements in the linked list make it palindrome for e.g: 1->13->4->5->4->13->1
    bool checkIfPalindrome() const {
        LinkedList L1 = L;
        L1.reverse();
        Node<T> * ptr1=L.head;
        Node<T> *ptr=head;
        while(ptr){
            if(ptr->data!=ptr1->data)
                return false;
        }
        return true;
    }

    // Rearrange the nodes such that all even elements are after odd elements. Again you need change next pointers not the data
    void arrangeEvenElementsAfterOddElements() {
        Node<T> * ptr=head->next;
        Node<T> * ptrprev=head;
        while(ptr){
            if((ptr->data)%2!=0){
               ptrprev->next=ptr->next;
               ptr->next=0;
               ptr->next=head;
               head=ptr;
            }
        }
    }

    // Rotate Linked List By K. You need to clockwise rotate the linked list by K. E.g. 1->2->3->4->5->6null and if K was 2 linked list should become 5->6->1->2->3->4->null
    void rotateClockWise(int K) {
      Node<T>* tailprev=settotailprev(tail);
      Node<T>*temp;
      while(K){
        temp=tail;
        tail=tailprev;
        tailprev=settotailprev(tail);
        temp->next=head;
        head=temp;
      }
    }

    // K reverse the linked list i.e. you reverse first K elements then reverse next K elements and join the linked list and so on.
    // For e.g. 3->4->5->2->6->1->9->10->NULL, and For K = 3 should become 5->4->3->1->6->2->10->9->NULL
    void kReverse(int K) {

    }

    // Remove Duplicates From the sortedList.
    // This function assumes the linked list is sorted and deletes duplicated nodes from the linked list.
    void removeDuplicatesFromSorted() {
        Node<T> * temp1=head;
        Node<T> * temp2=head->next;
        while(temp2->next){
            if(temp1->data==temp2->data){
                deletetheaddress(temp2);
            }
        }
    }
  //Return a linked list which is sorted
  LinkedList & merge(LinkedList & L){
   LinkedList newlist;
   while(head!=NULL&&L.head!=NULL){
    Node *temp;
    if(head->data<L.head-<data){
        temp=head;
        head=head->next;
    }
    else {
        temp=L.head;
        L.head=L.head->next;
    }
    temp->next=NULL;
    if(newlist.head==NULL){
        newlist.tail=newlist.head=temp;
    }
    else{
        newlist.tail->next=temp;
        newlist.tail=temp;
    }
   }
  }
  //for a linked list a1->a2->b1->b2
  //to a1->b1->a2->b2
  LinkedList& convertantobn(LinkedLIst&L){
   LinkedList newlist;
   Node *mid=L.findMidPoint();
   head=L.head;
   Node * head1=mid->next;
   mid->next=NULL;
   L.tail=mid;
   Node * ptr=head;
   for(int i=0;head1!=NULL;i++){
    if(i%2==0){
        ptr=L.head;
        L.head=L.head->next;
        ptr->next=NULL;
    }
    else{
        ptr=head1;
        head1=head1->next;
        ptr->next=NULL;
    }
   }
    }
    void insretionsort(){
    if(head==NULL||head->next==NULL)
        return;
    head=insertionsorthelper(head);
    }
  static Node<T>*insertionsorthelper(node<T>*head){

  }
    template<typename V>
       friend ostream & operator<<(ostream &, const LinkedList<V> &);
};

template <typename V>
ostream & operator<<(ostream & obj, const LinkedList<T> & L) {
    const Node<T> * it = L.head;
    while (it != NULL) {
        obj << it->data << "-->";
        it = it->next;
    }
    obj << "NULL";
    return obj;
}
#endif
