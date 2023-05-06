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
        void pop_back();//移除尾部元素
        int size() const;//数组大小
        int capacity() const;//数组容量
        void reserve (int n);//数组容量是否大于n,否则扩容
        void resize(int size); //指定数组大小为size
        T& at(int idx);//返回idx处元素的引用
        T& operator [](int idx);//重载[]
        bool empty() const;//数组是否为空
        void clear();//清空数组
        T& front() const;//返回数组头的引用
        T& back() const;//返回数组尾部的引用
        void swap(Vector<T>& other);//交换两个容器
        T* data();//直接返回数组首地址（头指针）
        Vector<T>& operator = (const Vector<T>& other);//重载=


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

template <typename T>
void Vector<T>::pop_back(){
    if(m_size > 0){
        m_size -= 1;
    }
    return ;
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
void Vector<T>::reserve(int n)
{
    while(m_capacity < n){
        if(m_capacity == 0){
            m_capacity = 1;
        }else{
            m_capacity *= 2;
        }
    }
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
    return ;
}

template <typename T>
void Vector<T>::resize(int size)
{
    if(m_size >= size){
        m_size = size;
        return ;
    }
    if(m_capacity >= size){
        for(int i=m_size;i<size;i++){
            m_data[i] = T();
        }
        m_size = size;
        return ;
    }
    while(m_capacity < size){
        if(m_capacity == 0){
            m_capacity = 1;
        }else{
            m_capacity *= 2;
        }
    }
    T* data = new T[m_capacity];
    for(int i=0;i<m_size;i++){
        data[i] = m_data[i];
    }
    for(int i=m_size;i<size;i++){
        data[i] = T();
    }
    //删除旧数组
    if(m_data!=nullptr){
        delete [] m_data;
        m_data = nullptr;
    }
    m_data = data;
    m_size = size;
    return ;

}

template <typename T>
T &Vector<T>::at(int idx)
{
    if(idx < 0 || idx > m_size){
        throw std::logic_error("out of range!");
    }
    return m_data[idx];
}

template <typename T>
T &Vector<T>::operator[](int idx)
{
    return at(idx);
}

template <typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
    return ;
}

template <typename T>
T &Vector<T>::front() const
{
    if(m_size < 0){
        throw std::logic_error("vector is empty!");
    }
    return m_data[0];
}

template <typename T>
T &Vector<T>::back() const
{
    if(m_size < 0){
        throw std::logic_error("vector is empty!");
    }
    return m_data[m_size-1];
}

template <typename T>
void Vector<T>::swap(Vector<T> &other)
{
    T* data = other.m_data;
    int size = other.m_size;
    int capacity = other.m_capacity;

    other.m_data = m_data;
    other.m_size = m_size;
    other.m_capacity = m_capacity;

    m_data = data;
    m_size = size;
    m_capacity = capacity;

    return ;
}

template <typename T>
T *Vector<T>::data()
{
    return m_data;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if(m_capacity < other.m_size){
        if(m_data!=nullptr){
            delete [] m_data;
            m_data = nullptr;
            m_size = 0;
            m_capacity = 0;
        }
        while(m_capacity < other.m_size){
            if(m_capacity == 0){
                m_capacity = 1;
            }else{
                m_capacity *= 2;
            }
        }
    }
    m_data = new T[m_capacity];
    for(int i=0;i<other.m_size;i++){
        m_data[i] = other.m_data[i];
    }
    m_size = other.m_size;
    return *this;
}

} // namespace selfstl
