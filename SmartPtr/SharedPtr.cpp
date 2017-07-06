//定制删除器版本的shared_ptr
#include<string>
class Fclose
{
public:
    void operator()(void *ptr)
    {
        fclose((FILE *)ptr);
        cout<<"fclose"<<endl;
    }
};
struct Free
{
    void operator()(void *ptr)
    {
        free(ptr);
        cout<<"free"<<endl;
    }
};
class DefaultDel
{
public:
    void operator()(void *ptr)
    {
        delete ptr;
        cout<<"delete"<<endl;
    }
};
template<class T,class D=DefaultDel>   //默认的定制删除器是DefaultDel
class SharedPtr
{
public:
    SharedPtr(T *ptr=0,D del=DefaultDel())
        :_ptr(ptr)
        ,_pcount(new int(1))
        ,_del(del)
    {}
    ~SharedPtr()
    {
        if(--GetCount() == 0)   //当只有最后一个指针维护这块空间的时候才能删除它
        {
            Destroy();
        }
    }
    SharedPtr(const SharedPtr<T,D>& sp)   //sp2(sp1)
    {
        _ptr=sp._ptr;
        _pcount=sp._pcount;
        //使得this指针指向该空间，而且引用计数加1
        ++GetCount();
    }
    SharedPtr<T,D>& operator=(const SharedPtr<T,D>& sp)  //sp3=sp2
    {
        if(this != &sp)    //不能自己给自己赋值
        {
            //this指针的引用计数-1.如果是最后一个指向该空间的只能指针则销毁该空间
            if(--GetCount() == 0)
            {
                Destroy();
            }
            //重新给this指针赋予新的智能指针
            _ptr=sp._ptr;
            _pcount=sp._pcount;
            ++GetCount();
        }
        return *this;
    }
    T& operator*()
    {
        return *_ptr;
    }
    T *operator->()
    {
        return _ptr;
    }
private:
    void Destroy()
    {
        _del(_ptr);  //_del指定不同的删除函数
        _ptr=0;
        delete _pcount;
        _pcount=0;
    }
    int& GetCount()   //获取引用计数的值
    {
        return *_pcount;
    }
protected:
    T *_ptr;
    int *_pcount;
    D _del;
};

void TestSharedPtrDel()
{
    SharedPtr<int> sp1(new int(10));
    cout<<*sp1<<endl;
    SharedPtr<FILE,Fclose> sp2(fopen("test.txt","w"),Fclose());  
    SharedPtr<string,Free> sp3((string *)malloc(sizeof(string)),Free());  
}