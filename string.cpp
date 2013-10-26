/*
Lecture 17: operator overloading string 
*/
#include <iostream>
class String{
	int size;
	char *bufferPtr;
public:
	String(){
		size=0;
		bufferPtr=NULL;
		
	}
	
	String(const char *ptr)
	{
		if(ptr!=NULL)
		{
			size=strlen(ptr);
			bufferPtr=new char[size+1];
			strcpy(bufferPtr,ptr);
		}
		 else
		{
			bufferPtr=NULL;
			size=0;
			
		}
		
	} 
	
	
	String(const String & rhs) //copy constructor
	{
		size=rhs.size;
		if(rhs.size!=0)
		{
			bufferPtr=new char[size+1];
			strcpy(bufferPtr,rhs.bufferPtr);
		}	
		
		else 
			bufferPtr=NULL;
		
	}
	void printString(){
		std::cout<<bufferPtr<<std::endl;
	}	
	
	String& operator= (const String & rhs) // return type is void to a=b=c problem
	{
		
		//checking for condition str1=str1;self assignment
		if(this!=&rhs){
		size=rhs.size;
		delete []bufferPtr;
		if(rhs.size!=0) 
		{
			bufferPtr=new char[rhs.size+1];
			strcpy(bufferPtr,rhs.bufferPtr);	
			
		} 	
		else 
		{
			bufferPtr=NULL;
		}
		}
		return *this;	// ? why not return rhs
	}
};




int main (){
	String str1("Hell9");
	String str2("world");
	String str3("Nadeem");	
	str1=str2;
	(str1=str2)=str3;
	str1.printString();
	str2.printString();
	str3.printString();
	
	return 0;
}
