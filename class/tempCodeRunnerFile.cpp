#include<iostream>
using namespace std;
class Test2
{
int y;
}; 
class Test
{
int x;
Test2 t2;
public:
operator Test2 () {return t2;}
operator int (){return x;}
};
void fun ( int x) {cout << "fun(int) called";}
void fun ( Test2 t ){cout << "fun(Test 2) called";}
int main()
{
Test t;
fun(t);
return 0;
}