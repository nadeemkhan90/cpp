/*
Lecture 17: operator overloading string 
MOHD NADEEM KHAN
*/


#include <iostream>
#include <assert.h>
using namespace std;
class String{
	int size;
	char *bufferPtr;
public:
	//CONSTRUCTOR
	String(){
		size=0;
		bufferPtr=NULL;
		
	}
	
	//OVERLOADED CONSTRUCTOR 
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
	
	//COPY CONSTRUCTOR 
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
	
	//
	void printString(){
		std::cout<<bufferPtr<<std::endl;
	}	
	
	//ASSIGNMENT OPERATOR OVERLOADING 
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
	
	//SETTER FUNCTION 
	void setString(const char *p){
		if(p!=NULL){
            size=strlen(p);
            bufferPtr=new char[size+1];
            strcpy(bufferPtr,p);
        }
        else{
            bufferPtr=NULL;
            size=0;
        }
		
	}	
	
	//changing any charactr in given string
	void setChar(char c,int pos){
		if(bufferPtr!=NULL){
			if((pos>0) && (pos<=size))
				bufferPtr[pos-1]=c;
		}
		
	}
	
	//SUBSCRIPT OPERATOR OVERLOADING
	char & operator [](int pos ){
		assert(pos>0 && pos<=size);
		return bufferPtr[pos-1];
		
	}
	
	//function operator overloading
	char & operator ()(int pos ){
		assert(pos>0  && pos<=size);
		return bufferPtr[pos-1];
		
	}
	
	//GETTING SUBSTRING OF A STRING 
	String operator ()(int index, int sublength){
//		assert(index>0 && index< size && sublength<=size);
		char *ptr=new char[sublength+1];
		for (int i=0;i<sublength;i++)
			ptr[i]=bufferPtr[i+index-1];
		ptr[sublength]='\0';
		String str(ptr);
		delete []ptr;
		return str;
	}
	
};




int main (){
	String str1("Hell9");
	String str2("world");
	String str3("Hello World");	
	str1=str2;
	(str1=str2)=str3;
	str1.printString();
	str2.printString();
	str3.printString();
	String s4;
	s4.setString("ping");
	s4.printString();
	s4.setChar('o',2);
	s4.printString();
	s4[2]='n';
	s4.printString();
	s4(2)='k';		//function operator
	//cout<<s4[1];
	char i= s4(2);
	cout<<i<<endl;
	s4.printString();
	String str5(str3(1,5));
	str5.printString();
	return 0;
}
