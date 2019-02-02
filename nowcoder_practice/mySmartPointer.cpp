// 自己实现的智能指针
// 2018-10-2
#include <iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
    SmartPtr(T *p);
    ~SmartPtr();
    SmartPtr(const SmartPtr<T> &orig);                // 浅拷贝
    SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // 浅拷贝
    T* operator->();
    T& operator*();

private:
    T *ptr;
    // 将 use_count 声明成指针是为了方便对其的递增或递减操作
    int *use_count; // 实际的shared_ptr中，该指针指向一个control block，里面存放的是引用计数值
};

template<typename T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p)
{
    try {
        use_count = new int(1);
    }
    catch (bad_alloc) {
        delete ptr;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Allocate memory for use_count fails." << endl;
        exit(1);
    }

    cout << "Constructor is called!" << endl;
}

// 析构
template<class T>
SmartPtr<T>::~SmartPtr()
{
    // 只在最后一个指向对象的shared_ptr销毁时，才释放对象的内存
    if (--(*use_count) == 0)
    {
        delete ptr; // 销毁ptr指向的内存
        delete use_count;

        ptr = nullptr;
        use_count = nullptr;

        cout << "Destructor is called!" << endl;
    }
}

// 拷贝构造
template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig)
{
    if (this != &orig) { // 相同的元素没必要进行拷贝初始化
        ptr = orig.ptr;
        use_count = orig.use_count;
        ++(*use_count);
        cout << "Copy constructor is called!" << endl;
    }

}

// 重载等号函数不同于复制构造函数，即等号左边的对象可能已经指向某块内存。
// 这样，我们就得先判断左边对象指向的内存已经被引用的次数。如果次数为1，
// 表明我们可以释放这块内存；反之则不释放，由其他对象来释放。
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
    // 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使rhs的使用计数加1，
    // 从而防止自身赋值”而导致的提早释放内存
    ++(*rhs.use_count);

    // 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象
    if (--(*use_count) == 0)
    {
        delete ptr;
        delete use_count;
        cout << "Left side object is deleted!" << endl;
    }

    // 当前指针指向新的内存
    ptr = rhs.ptr;
    use_count = rhs.use_count;
    
    cout << "Assignment operator overloaded is called!" << endl;
    return *this;
}

template<typename T>
T& SmartPtr<T>::operator*() {
    return *ptr;
}

template<typename T>
T* SmartPtr<T>::operator->() {
    return ptr;
}
