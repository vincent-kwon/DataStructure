#include <iostream>
using namespace std;

template < typename T >
class TemplateSingleton
{
protected:
    TemplateSingleton()
    {
             
    }
    virtual ~TemplateSingleton()
    {
 
    }
 
public:
    static T * GetInstance()
    {
        if (m_pInstance == NULL)
            m_pInstance = new T;
        return m_pInstance;
    };
 
    static void DestroyInstance()
    {
        if (m_pInstance)
        {
            delete m_pInstance;
            m_pInstance = NULL;
        }
    };
 
private:
    static T * m_pInstance;
};
 
template <typename T> 
T * TemplateSingleton<T>::m_pInstance = 0;
 
class CObject : public TemplateSingleton<CObject>
{
private:
    CObject() {};
    ~CObject() {};
public:
    void print() { cout << "hello" << endl; };
    friend class TemplateSingleton<CObject>;
};

int main() {
  CObject* s = TemplateSingleton<CObject>::GetInstance();
  //CObject s2;

  s->print();
}
