//the follwing the problem of removing the duplicates from the unsorted link list
//we will be using two methods first one will use the hash table to solve the problem in amortized O(n) time
// the second method uses a current and a runner where runner deletes all the nodes which are having same data as
//the current. This approach has time complexity of O(N*N)
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* next;
};
void remove_duplicates_method1(node* &head){
    map<int,bool> buffer;
    node* ptr=head;node* ptr_prev=head;
    while(ptr){
        if(buffer.find(ptr->data)==buffer.end()){
            buffer[ptr->data]=true;
            if(ptr!=head)
                ptr_prev=ptr_prev->next;
            ptr=ptr->next;
        }
        else{
           //remove the current pointer node;
           ptr_prev->next=ptr->next;
           delete(ptr);
           ptr=ptr_prev->next;
        }
    }
}
void remove_duplicates_method2(node* &head){
 node* current_ptr=head;
 while(current_ptr){
    node* runner_prev=current_ptr;node* runner=current_ptr->next;
    while(runner){
        if(current_ptr->data==runner->data){
            //remove duplicate pointer node
            runner_prev->next=runner->next;
            delete(runner);
            runner=runner_prev->next;
        }
        else{
            runner=runner->next;
            runner_prev=runner_prev->next;
        }
    }
    current_ptr=current_ptr->next;
 }
}
void create_linklist(node* &head,node* &tail){
    char insert_more;
    cout<<"do you want to insert?(Y/N):";
    cin>>insert_more;
    while(insert_more=='Y'||insert_more=='y'){
    if(head==NULL){
        head=new node;
        tail=head;
        tail->next=NULL;
        cin>>head->data;
    }
    else{
        node* ptr=new node;
        ptr->next=NULL;
        tail->next=ptr;
        tail=ptr;
        cin>>ptr->data;
    }
    cout<<"do you want to insert?(Y/N):";
    cin>>insert_more;
    }
}
void print(node *head){
  while(head){
    cout<<head->data<<"-->";
    head=head->next;
  } cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;node* tail=NULL;
    create_linklist(head,tail);
    print(head);
    remove_duplicates_method1(head);
    //remove_duplicates_method2(head);
    print(head);
}
