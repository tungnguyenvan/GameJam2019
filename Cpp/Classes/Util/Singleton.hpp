//
//  Singleton.hpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 10/22/19.
//

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <class T>
class Singleton
{
public:
	static T* getInstance()
    {
        if (!hasInstance())
        {
            s_instance = new T();
        }

        return s_instance;
    }

	static bool hasInstance()
    {
	    return s_instance != 0;
    }

	static void freeInstance()
    {
	    delete s_instance;
        s_instance = 0;
    }

protected:
	Singleton() {}
	virtual ~Singleton()
    {
        s_instance = 0;
    }

private:
	static T* s_instance;
};

template <class T>
T* Singleton<T>::s_instance = 0;

#endif // __SINGLETON_H__