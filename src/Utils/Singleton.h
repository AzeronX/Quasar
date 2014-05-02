#include <common.h>

template<class T>
class Singleton
{
protected:
    Singleton()
    {
        instance = NULL;
    }
    ~Singleton()
    {
        if(instance != NULL)
            delete instance;
    }

public:

    static T *getInstance()
    {
        if(instance == NULL)
            instance = new T;
        return instance;
    }

    static void destroy()
    {
        if(instance != NULL)
        {
            delete instance;
            instance = NULL;
        }
    }

private:
    static T *instance;
};

template <typename T>
T *Singleton<T>::instance = NULL;
