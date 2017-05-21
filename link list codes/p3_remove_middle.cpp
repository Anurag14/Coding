// this program is about removing the middle element from the link list
#include <bits/stdc++.h>
using namespace std;
struct node {
   int data;
   node* next;
};
void remove_middle_element(node* &head){
     node* slow=head;
     node* slow_prev=head;
     node* fast=(head)?head->next:NULL;
     while(fast){
     	slow_prev=slow;
     	slow=slow->next;
     	fast=fast->next;
     	if(fast)
     		fast=fast->next;
     }
     if(slow){
     	slow_prev->next=slow->next;
     	if(head==slow)
     		head=NULL;
     	delete(slow);
     }
     return;
}
void print_list(node* head){
while(head){
    cout<<head->data<<"-->";
    head=head->next;
}
cout<<"NULL"<<endl;
}
void insert_at_head(node* &head){
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
int main(){
	node* head=NULL;
	char ch;
	cout<<"Do you want to enter data[y/n]?";
	cin>>ch;
    while(ch=='y'){
    	insert_at_head(head);
    	cout<<"Do you want to enter data[y/n]?";
	    cin>>ch;
    }
    print_list(head);
    remove_middle_element(head);
    print_list(head);
	return 0;
}
