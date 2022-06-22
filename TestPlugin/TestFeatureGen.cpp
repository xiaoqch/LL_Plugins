#include "pch.h"
#include "TestFeatureGen.h"

template <typename T>
struct CustomPtr
{
    T* ptr;
    bool ref;
    CustomPtr(std::unique_ptr<T> uptr)
        : ptr(uptr.release())
        , ref(false){};
    CustomPtr(T* ptr)
        : ptr(ptr)
        , ref(true){};
    ~CustomPtr()
    {
        if (!ref)
            delete ptr;
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    operator bool()
    {
        return ptr != nullptr;
    }

};

void test()
{
    auto a = std::make_unique<std::string>("Test");
    CustomPtr ptr(std::move(a));
    logger.warn("size: {}", *ptr);
}