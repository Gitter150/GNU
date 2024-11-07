#include<vector>
#include<iostream>

class Stack{
   private:
    std::vector<int> stack;
   public:
    void push(int x){                   //add an element to the stack
        stack.push_back(x);
    }
    void pop(){                         //remove the top most element
        if (stack.empty()){
            std::cout<<"Stack is already empty!"<<std::endl;             
        }    
        else stack.pop_back();  
}
    int pop(int x){                     //remove an element at index x
      if(!(x>=0 && x<stack.size())){
        std::cout<<"Invalid Index. Enter a value between 0 and "<<stack.size()-1<<std::endl;
        return -1;
      }
      for(int i=x;i<stack.size()-1;i++){
        stack[i]=stack[i+1];
      }
      pop();
    }
    void print(){                       //print the entire stack
     if(stack.size()>0){
        for(int i=0;i<stack.size()-1;i++){
            std::cout<<stack[i]<<" <- ";
        }
        std::cout<<stack[stack.size()-1]<<std::endl;
    }
     else std::cout<<"Stack is empty!"<<std::endl;
}
    void top(){                         //return top element
      if(stack.empty())
        std::cout<<"Stack is empty, no top element!"<<std::endl;
     else std::cout<<"Top most element: "<<stack[stack.size()-1]<<std::endl;
    }
    void bottom(){                      //return bottom element
      if(stack.empty())
        std::cout<<"Stack is empty, no bottom element!"<<std::endl;      
     else std::cout<<"Bottom most element: "<<stack[0]<<std::endl;
    }
    void clear(){                       //empties the stack
      for(int i=stack.size()-1; i>-1;i--){
        pop();
      }
    }
};
int main(){
   Stack stack;
   for(int i=1;i<11;i++){
    stack.push(i);
   }
   stack.print();
   stack.clear();
   stack.print();
}
