#include<vector>
#include<iostream>
using namespace std;

class Stack{
   private:
    vector<int> stack;
   public:
    void push(int x){                  //add an element to the stack
        stack.push_back(x);
    }
    void pop(){                     //remove the top most element
        if (stack.empty()){
            cout<<"Stack is already empty!"<<endl;             
        }    
        else stack.pop_back();  
}
    int pop(int x){                  //remove an element at index x
      if(!(x>=0 && x<stack.size())){
        cout<<"Invalid Index. Enter a value between 0 and "<<stack.size()-1<<endl;
        return -1;
      }
      for(int i=x;i<stack.size()-1;i++){
        stack[i]=stack[i+1];
      }
      pop();
    }
    void print(){                    //print the entire stack
     if(stack.size()>0){
        for(int i=0;i<stack.size()-1;i++){
            cout<<stack[i]<<" <- ";
        }
        cout<<stack[stack.size()-1]<<endl;
    }
     else cout<<"Stack is empty!"<<endl;
}
    void top(){                         //return top element
      if(stack.empty())
        cout<<"Stack is empty, no top element!"<<endl;
     else cout<<"Top most element: "<<stack[stack.size()-1]<<endl;
    }
    void bottom(){                      //return bottom element
      if(stack.empty())
        cout<<"Stack is empty, no bottom element!"<<endl;      
     else cout<<"Bottom most element: "<<stack[0]<<endl;
    }
    void clear(){
      for(int i=stack.size()-1; i>-1;i--){
        pop();
      }
    }
};
int main(){
   Stack stack;
   for(int i=1;i<11;i++){
    stack.push(1);
   }
   stack.print(); 
   stack.pop();
   stack.print(); 
   stack.push(10);
   stack.push(11);
   stack.print();
}