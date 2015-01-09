#include <boost/thread.hpp>
#include <iostream>
using namespace std;
using namespace boost;
template<class T>
class basic_atom
{
private:
    T n;
    typedef mutex mutex_t;
    mutex_t mu;
public:
    basic_atom (T x = T()):n(x){}
    T operator++()
    {
        mutex_t::scoped_lock lock(mu);
        return ++n;
    }
    operator T()
    {
        return n;
    }
};

typedef basic_atom<int> atom_int;

mutex io_mu;
void printing(atom_int& x, const string& str)
{
    for(int i=0; i<5; ++i)
    {
        mutex::scoped_lock lock(io_mu);
        cout << str << ++x << endl;
    }
}
int main()
{
    cout << "test thread" << endl;
    cout << "thread max num:" << thread::hardware_concurrency() << endl;
    atom_int x;
    thread t1(printing, ref(x), "boost");
    thread t2(printing, ref(x), "hello");
    thread t3(bind(printing, ref(x), "thread"));
    t1.detach();
    t2.join();
    t3.join();
    return 0;
}

