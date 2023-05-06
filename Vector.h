#pragma once
#include <iostream>
namespace selfstl
{
    template <typename T>
    class Vector{
    public:
        Vector();   //构造函数
        ~Vector();  //析构函数
        void show();    //展示VECTOR内部情况

        void push_back(const T& val);   //插入


    private:
        //vector还是数组，三个属性：数组首地址，数组大小，数组容量
        T* m_data;  //数组首地址
        int m_size; //数组大小
        int m_capacity; //数组容量
    };

template <typename T>
Vector<T>::Vector() : m_data(nullptr),m_size(0),m_capacity(0){

}

template<typename T>
void Vector<T>::show(){
    for(int i=0;i<m_size;i++){
        std::cout<<m_data[i]<<","<<std::endl;
    }
    std::cout<<"m_size :"<<m_size<<std::endl;
    std::cout<<"m_capacity :"<<m_capacity<<std::endl;
    return ;
}

template <typename T>
Vector<T>::~Vector(){
    //析构函数，将数组清空
    if(m_data!=nullptr){
        delete [] m_data;
        m_data = nullptr;
    }
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
void Vector<T>::push_back(const T& val){
    //数组容量足够时直接插入
    if(m_size < m_capacity){
        m_data[m_size] = val;
        m_size += 1;
        return ;
    }
    //数组容量不足时要进行扩容
    if(m_capacity == 0){
        m_capacity = 1;
    }else{
        m_capacity *= 2;    //简单的直接扩大两倍
    }
    //数组扩容之后要将旧数组的内容拷贝到新数组中，同时删除旧数组以及完成插入操作
    T* data = new T[m_capacity];
    for(int i=0;i<m_size;i++){
        data[i] = m_data[i];
    }
    //删除旧数组
    if(m_data!=nullptr){
        delete [] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_data[m_size] = val;
    m_size += 1;
    return ;
}


    
} // namespace selfstl
