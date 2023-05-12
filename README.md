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

## 同std::vector进行**性能对比**(从头部插入数据,测试次数10000次，测试类型为int以及bool)
|     |self::vector|std::vector|
|-|-|-|
|insert(begin)(bool)|0.0142116ms|0.198501ms|
|insert(begin)(int)|0.0141603ms|0.0004827ms|
### 分析：对于self::vector而言，int类型与bool类型的时间基本一样；同std::vector对比，**bool**类型**快**了20倍，**int**类型**慢**了20倍。

### 性能提升策略:在各种方法往往需要将旧数组的数据转移到新数组中，对于基本类型（如int或bool等）的数据转移可以采用数据拷贝**std::memcpy**来取代循环(有重叠部分可以采用**std::memmove**)。

|     |self::vector|std::vector|
|-|-|-|
|insert(begin)(bool)|0.0001323ms|0.200709ms|
|insert(begin)(int)|0.0003312ms|0.0003581ms|

### 分析：self::vector性能得到了提升。对于int类型而言,改进的self.::vector与std::vector性能基本一样。