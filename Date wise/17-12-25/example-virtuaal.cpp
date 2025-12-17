#include <iostream>
using namespace std;

class shape{
  public: 
  virtual void draw(){
    cout<<"Drawing Shape"<<endl;
  }
};
class Line: public shape{
  public: 
  void draw(){
    cout<<"Drawing Line"<<endl;
  }
};
class Triangle: public shape{
  public: 
  void draw(){
    cout<<"Drawing Triangle"<<endl;
  }
};
class Rectangle: public shape{
  public: 
  void draw(){
    cout<<"Drawing Rectangle"<<endl;
  }
};
class Circle: public shape{
  public: 
  void draw(){
    cout<<"Drawing Circle"<<endl;
  }
};

void drawing (shape* s){
  cout<<"Drawing ";
  s->draw();
  /**
  few more logics
  */
}


int main() 
{
    shape* s;
    
    Line l;
    
    s = &l;
    drawing(s);
    
    Triangle t;
    
    s = &t;
    drawing(s);
    
    
    
    return 0;
}












