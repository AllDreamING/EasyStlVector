# Easy Vector
## 自己写的vector,实现了vector中一些常用函数，并添加了一些函数.

### 实现的函数如下:
- void push_back(const T& val);
- void pop_back();
- int size() const;
- int capacity() const;
- void reserve (int n);
- void resize(int size); 
- T& at(int idx);
- T& operator [](int idx);
- bool empty() const;
- void clear();
- T& front() const;
- T& back() const;
- void swap(Vector<T>& other);
- T* data();
- Vector<T>& operator = (const Vector<T>& 
- Iterator begin();
- Iterator end();
- Iterator insert(const Iterator it, const T& value);
- Iterator insert(const Iterator it, int n, const T& value);
- Iterator ==,++,--等运算符的重载
### 自定义函数如下:
- Iterator find(const T& value);//自定义函数，返回指定值的迭代器

## 同std::vector进行**性能对比**
### 
### 性能提升策略: