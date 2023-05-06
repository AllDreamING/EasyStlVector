#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <typeinfo>
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

        class Iterator{ //内部类，本质上就是一个指针
        public:
            Iterator() : m_pointer(nullptr){};
            Iterator(T* pointer) : m_pointer(pointer){};
            ~Iterator(){}; 
            //重载一些运算符
            bool operator == (const Iterator& other){
                return m_pointer == other.m_pointer;
            };
            bool operator != (const Iterator& other){
                return m_pointer != other.m_pointer;
            };
            Iterator operator = (const Iterator& other){
                m_pointer = other.m_pointer;
                return *this;
            };
            Iterator& operator ++ () {
				m_pointer += 1;
				return *this;
			};
            Iterator operator ++ (int) {
				Iterator it = *this;
				++(*this);
				return it;
			};
            Iterator operator + (int i) {
				Iterator it = *this;
				it.m_pointer += i;
				return it;
			};
            Iterator& operator += (int i) {
				m_pointer += i;
				return *this;
			};
            Iterator operator - (int i) {
				Iterator it = *this;
				it.m_pointer -= i;
				return it;
			};
			Iterator& operator -= (int i) {
				m_pointer -= i;
				return *this;
			};
			int operator - (const Iterator& other) const {
				return m_pointer - other.m_pointer;
			};
            T& operator* () {
				return *m_pointer;
			};
			T* operator -> () {
				return m_pointer;
			};

        private:
            T* m_pointer;
        };

        Iterator begin();//返回数组头的迭代器
        Iterator end();//返回数组尾端的迭代器
        Iterator find(const T& value);//自定义函数，返回指定值的迭代器
        Iterator insert(const Iterator it, const T& value);//在指定位置插值
		Iterator insert(const Iterator it, int n, const T& value);//在指定位置插入n个值

    private:
        bool is_base_type();

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
    if (is_base_type())
    {
        std::memcpy(data, m_data, m_size * sizeof(T));
    }else{
        for(int i=0;i<m_size;i++){
            data[i] = m_data[i];
        }
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

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    Vector<T>::Iterator it(m_data);
    return it;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    Vector<T>::Iterator it(m_data+m_size);
    return it;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::find(const T &value)
{
    for (Vector<T>::Iterator it = begin(); it != end(); it++) {
			if (*it == value) {
				return it;
			}
		}
		return end();
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::insert(const Iterator it, const T &value)
{
        return insert(it,1,value);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::insert(const Iterator it, int n, const T &value)
{
        int size = it - begin();//要插入的位置
        if(m_size+n <= m_capacity){//不需要扩容
            for(int i=m_size;i>size;i--){//先将后面的向后移
                m_data[i+n-1] = m_data[i-1]; 
            }
            for(int i=size;i<n;i++){//再插入
                m_data[i] = value;
            }
            m_size = m_size + n;
            return Vector::Iterator(m_data+size);
        }
        while (m_size + n > m_capacity) {
			if (m_capacity == 0) {
				m_capacity = 1;
			}
			else {
				m_capacity *= 2;
			}
		}
		T* data = new T[m_capacity];
		for (int i = 0; i < size; i++) {
			data[i] = m_data[i];
		}
		for (int i = 0; i < n; i++) {
			data[size + i] = value;
		}
		for (int i = size; i < m_size; i++) {
			data[i] = m_data[i];
		}
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
		}
		m_data = data;
		m_size += n;
		return Vector<T>::Iterator(m_data + size);
}

template <typename T>
bool Vector<T>::is_base_type()
{
    if (std::is_pointer<T>::value)
    {
        return true;
    }
    return (typeid(T) == typeid(bool)) ||
           (typeid(T) == typeid(char)) ||
           (typeid(T) == typeid(unsigned char)) ||
           (typeid(T) == typeid(short)) ||
           (typeid(T) == typeid(unsigned short)) ||
           (typeid(T) == typeid(int)) ||
           (typeid(T) == typeid(unsigned int)) ||
           (typeid(T) == typeid(long)) ||
           (typeid(T) == typeid(unsigned long)) ||
           (typeid(T) == typeid(float)) ||
           (typeid(T) == typeid(double));
}

} // namespace selfstl
