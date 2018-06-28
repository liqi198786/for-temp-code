

#include <iostream> 
#include <functional>
#include <vector>
using namespace std;
using namespace std::placeholders;

#define CALL(index,param)  {Reg::call(index,param);}    
 
typedef std::function<void(int,int)> Fun;
 
class B{
	public:
        void call(int a,Fun f)
        {
            f(a,2);
        }
};
 
class Test{
public:
	void callback(int a,int b)
	{
        cout<<a<<"+"<<b<<"="<<a+b<<endl;
	}
 
	void bind()
	{
        Fun fun=std::bind(&Test::callback,this,_1,_2);
		B b;
		b.call(1,fun);
	}
 
};

class Reg{
public:
Reg(){};

void reg(Fun fun)
{
fv.pushback(fun);
}

static void call(int i,int param)
{
fv[i](param);
}
private:
static vector<Fun> fv;
};
vector<Fun> Reg::fv;

int main()
{
    //Test test;
	//test.bind();
	//return 0;
	Reg reg0;
	Test test;
	function<void(int,int)> fun0 = bind(&Test::callback,&test,1,_1);
	CALL(0,3);
}
