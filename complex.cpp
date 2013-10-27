/*
object oriented languages
Lecture 16 - 21: operator overloading
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
		if(imaginary>0)
		cout<<real<<"+"<<imaginary<<'i'<<endl;
		else
			cout<<real<<imaginary<<'i'<<endl;	
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
	//STREAM INSERIOTN OPERATOR OVERLOADING
	friend ostream & operator << (ostream &os,const complex &c){
		os<<'('<<c.real<<','<<c.imaginary<<')'<<endl;;
		return os;	 
		
	}
	//STREAM EXTRACTION OPERATOR
	friend istream & operator >>(istream &in,complex &c){
		in>>c.real;
		in>>c.imaginary;
		return in;
		
	}
	//OVERLOADING EQUALITY OPERATOR
	bool operator ==(const complex &c){
		
		if((real==c.real)&&(imaginary==c.imaginary))
		{
			return true;
		}
		else
		 {
			return false;	
			
		}
	}
	//UNARY MINUS OPERATOR OVERLOADING 
	complex operator - (){
		
		complex temp ;
		temp.real=-real;
		temp.imaginary=-imaginary;
		return temp;
	}
	
	//preincrement returns reference
	complex & operator ++(){
		
		real=real+1;
		return *this;
	}
	
	//POST INCREMENT REQUIRE AN EXTRA DUMMY PARAMERTER , return type is complex not reference
	complex operator ++(int){
		complex t=*this;
		real+=1;
		return t;
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
	complex c5(1,3);
	cin>>c5;
	cout<<c5;
	if(c1==c2){
		cout<<"complex are equal"<<endl;
	}
	else{
		cout<<"complex are not equal"<<endl;
	}
	c1=-c1;
	c1.printComplex();
	++c2;
	c2.printComplex();
	++++c2;
	c2.printComplex();
	
	return 0;
}