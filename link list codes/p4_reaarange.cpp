//this problem is about rearrangement of a link list such that for a given node x we can move all the elements smaller than the
// appear before all the elements greater than or equal to the node x
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* next;
};
void insert_on_head(node* &head,node* ptr){
     ptr->next=NULL;
     if(!head){
        head=ptr;
        return;
     }
     ptr->next=head;
     head=ptr;
}
void print_list(node* head){
while(head){
    cout<<head->data<<"-->";
    head=head->next;
}
cout<<"NULL"<<endl;
}
void insert_front(node* &head){
  node* ptr=new node;
  ptr->next=NULL;
  cout<<"fill in the data";
  cin>>ptr->data;
  if(!head){
      head=ptr;
      return;
  }
  ptr->next=head;
  head=ptr;
  return;
}
void rearrange(node* &head,node* &head1,node* &head2,int x){
     node* ptr=head;
     while(head){
         head=head->next;
        if(ptr->data<x)
            insert_on_head(head1,ptr);
        else insert_on_head(head2,ptr);
        ptr=head;
     }
     print_list(head1);
     print_list(head2);
     node * it=head1;
     while(it->next)
        it=it->next;
     it->next=head2;
     head=head1;
     return;
}
int main(){
    node* head=NULL;node* head1=NULL;node* head2=NULL;
	char ch;
	cout<<"Do you want to enter data[y/n]?";
	cin>>ch;
    while(ch=='y'){
    	insert_front(head);
    	cout<<"Do you want to enter data[y/n]?";
	    cin>>ch;
    }
    print_list(head);
    int x;
    cout<<"enter the number for pivot:";
    cin>>x;
    rearrange(head,head1,head2,x);
    print_list(head);
	return 0;
}
