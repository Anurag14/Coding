//the program is to find an algorithm to find the k th element from the last element in the link list.
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* next;
};
int print_kth_from_last(node* head,int k){
   if(!head)return 0;
   int ans=print_kth_from_last(head->next,k)+1;
   if(ans==k){cout<<head->data;}
   return ans;
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
cout<<"Do you want to insert into link list [y/n]?";
cin>>ch;
while(ch=='y'){
    insert_at_head(head);
    cout<<"Do you want to insert into link list [y/n]?";
    cin>>ch;
}
print_list(head);
int k;
cout<<"enter k:";
cin>>k;
print_kth_from_last(head,k);
}
