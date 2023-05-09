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
- Iterator find(const T& value);//自定义函数，返回第一个指定值的迭代器,不存在则返回end()

## 同std::vector进行**性能对比**(测试次数50000次，测试类型为int以及bool)
|     |self::vector|std::vector|
|-|-|-|
|push_back(int)|0.01923333ms|0.019233333ms|
|push_back(bool)|0.01923333ms|0.019233333ms|

### 性能提升策略: