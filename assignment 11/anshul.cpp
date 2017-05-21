#include <iostream>
using namespace std;

int stackk[100], item, top;

void push(int n)
{
    if(top==99)
        cout << "overflow\n";
    else{
        top++;
        cout << top;
        stackk[top] = n;
    }
}

void pop()
{
    if(top==-1)
        cout << "underflow\n";
    else{
        item = stackk[top];
        top-=1;
    }
}

int main()
{
    top = 0;
    while(1){
        cout << "\nchoose your query..\n";
        cout << "1. push\n2.pop\n";
        int k; cin >> k;
        if(k==1){
            int n;
            cout << "Enter the item : ";
            cin >> n;
                    push(n);
        }
        if(k==2){pop();
                    cout << "the poped item is : " << item << "\n";
        }

        if(top == 0)
            cout << "The stack is Empty.\n";

        else{
            int i;
            cout << "The stack contains : " ;
            for(i=1; i<=top; i++)
                cout << stackk[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
