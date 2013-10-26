/*
object oriented languages
Lecture 16 + 17 : operator overloading
by : Mohd Nadeem Khan
*/

#include <iostream>
using namespace std;
class complex{
 private: 
	int real;
	int imaginary;
 public:
	void printComplex()
	{
		cout<<real<<"+"<<imaginary<<"i"<<endl;	
	}
	void set(int x,int y)
	{
		real=x;
		imaginary =y;
		
	}
	complex(int x,int y)
	{
		real=x;
		imaginary=y;
	}
	complex()
	{
		
	}
	complex operator + (const complex &rhs)
	{
		complex t ;
		t.real= real+rhs.real;
		t.imaginary=imaginary+rhs.imaginary;
		return t;
	}
	
	complex operator + (const double & rhs)
	{
		complex t;
		t.real=real+rhs;
		t.imaginary=imaginary;
		return t;
	}
	
	friend complex operator +(const complex &lhs, const double &rhs)
	{
		complex t;
		t.real=lhs.real+rhs;
		t.imaginary=lhs.imaginary;
		return t;	
		
	}	 
	
	friend complex operator +(const double &rhs, const complex &lhs) //require for 12+c1
	{
		complex t;
		t.real=rhs+lhs.real;
		t.imaginary=lhs.imaginary;
		return t;			
	}
/*	void operator << (ostream &os){
		os<<'('<<real<<','<<imaginary<<')';
	
	}

*/	
	friend ostream & operator << (ostream &os,const complex &c){
		os<<'('<<c.real<<','<<c.imaginary<<')'<<endl;;
		return os;	 
		
	}
		
};

int main()
{
	complex c1(2,3);
	c1.printComplex();
	complex c2;
	c2.set(12,13);
	c2.printComplex();
	complex c3= c1+c2+c1;
	c3.printComplex();
	complex c4=12+c3;
	c4.printComplex();
	cout<<c1<<c2;
	return 0;
}