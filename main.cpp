#include<iostream>
#include "Vector.h"

using namespace selfstl;

int main(){
    //creat
    Vector<int> v;
    //push_back
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.show();

    

    // //=
    // Vector<int> v2;
    // v2 = v;
    // v2.show();

    // //data
    // int *p = v.data();
    // *p = 10;
    // v.show();

    // //swap
    // Vector<int> v2;
    // v2.push_back(4);
    // v2.push_back(5);
    // v2.show();
    // v2.swap(v);
    // v2.show();

    // //front
    // std::cout<<"v.front() :"<<v.front()<<std::endl;

    // //back
    // std::cout<<"v.back() :"<<v.back()<<std::endl;

    // //pop_back
    // v.pop_back();
    // v.show();

    // //size
    // std::cout<<"m_size :"<<v.size()<<std::endl;

    // //capacity
    // std::cout<<"m_capacity :"<<v.capacity()<<std::endl;

    // //reverse
    // v.reserve(16);
    // v.show();

    // //resize
    // v.resize(32);
    // v.show();

    // //at
    // std::cout<<"v[2] :"<<v.at(2)<<std::endl;

    // //[]
    // std::cout<<"v[2] :"<<v[2]<<std::endl;

    // //empty
    // std::cout<<"v is empty :"<<v.empty()<<std::endl;

    // //clear
    // v.clear();
    // v.show();

    std::cout<<"main cout test"<<std::endl;
    return 0;
}