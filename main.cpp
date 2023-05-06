#include<iostream>
#include<string>
#include<vector>
#include<sys/time.h>
#include "Vector.h"

// using namespace std;

using namespace selfstl;

int main(){


    struct timeval tv1;
    gettimeofday(&tv1, NULL);
    int start_sec1 = tv1.tv_sec;
    int start_usec1 = tv1.tv_usec;
    const int max1 = 10000;
    Vector<bool> v1;
    for (int i = 0; i < max1; i++)
    {
        v1.insert(v1.begin(), true);
    }
    gettimeofday(&tv1, NULL);
    int end_sec1 = tv1.tv_sec;
    int end_usec1 = tv1.tv_usec;
    double time_diff1 = (end_sec1 - start_sec1) * 1000000 + (end_usec1 - start_usec1);
    std::cout << time_diff1 / 1000 / max1 << "ms" << std::endl;


    struct timeval tv2;
    gettimeofday(&tv2, NULL);
    int start_sec2 = tv2.tv_sec;
    int start_usec2 = tv2.tv_usec;
    const int max2 = 10000;
    std::vector<bool> v2;
    for (int i = 0; i < max2; i++)
    {
        v2.insert(v2.begin(), true);
    }
    gettimeofday(&tv2, NULL);
    int end_sec2 = tv2.tv_sec;
    int end_usec2 = tv2.tv_usec;
    double time_diff2 = (end_sec2 - start_sec2) * 1000000 + (end_usec2 - start_usec2);
    std::cout << time_diff2 / 1000 / max2 << "ms" << std::endl;










    // //creat
    // Vector<int> v;
    // //push_back
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.show();

    // //end
    // Vector<int>::Iterator it = v.end();
    // std::cout<<"v.end():"<<*it<<std::endl;

    // //begin
    // Vector<int>::Iterator it = v.begin();
    // std::cout<<"v.begin():"<<*it<<std::endl;

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