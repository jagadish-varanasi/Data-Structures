#include<iostream>
using namespace std;

template <class T>
class Rectangle{
    private:
      T len;
      T bre;
    public:
        Rectangle(T l,T b);
       T area();
};
template <class T>
Rectangle<T>::Rectangle(T l,T b){
    this->len=l;
    this->bre=b;
}
template <class T>
 T Rectangle<T> ::area(){
     return len*bre;
 }

int main(){
    Rectangle<int> r(10,20);
    cout<<r.area()<<endl;

    Rectangle<float> r1(10.1,20.2);
    cout<<r1.area()<<endl;
}