#pragma once
#include <cassert>

template <class T>
class Singleton
{
public:
    typedef Singleton<T> Base;

    Singleton()
    {
        assert(nullptr == msInstance);
        msInstance = static_cast<T*>(this);
    }

    virtual ~Singleton()
    {
        assert(nullptr != msInstance);
        msInstance = nullptr;
    }

    static T& getInstance()
    {
        assert(nullptr != getInstancePtr());
        return (*getInstancePtr());
    }

    static T* getInstancePtr()
    {
        return msInstance;
    }

private:
    static T* msInstance;
};

template<class T>
T * Singleton<T>::msInstance = nullptr;
