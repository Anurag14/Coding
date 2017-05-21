#include<iostream>
using namespace std;
//template<typename T>
class mystack{
 int arr[100];
 int  top= -1;
 public:
     void push(const int& el){
     if(top==99){
        cout<<"stack is full!";
        return;
        }
        top++;
        arr[top]=el;
        return;
     }
     void pop(){
     if(top==-1){
        cout<<"stack is empty";
        return;
     }
      top--;
      return;
     }
     int val_top(){
     if(top==-1){
        cout<<"stack is empty";
        return -13;
     }
     return arr[top];
     }
};
int main(){
 mystack S;
 for(int i=0;i<10;i++)
  S.push(i);
 for(int i=0;i<10;i++){
    cout<<S.val_top()<<endl;
    S.pop();
 }
}
