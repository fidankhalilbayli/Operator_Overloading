//Fidan Khalilbayli
//150150905
//hw#3

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;


template <class Type>//class template
class GenericArray{
public:
	Type *elements;
	Type total;
	int size;//shows the size of the array
	GenericArray(int s){//// A generic dynamic array for any type(built-in and user defined)
		size=s;
		elements= new Type[size];
	}
	
	Type sum(){//sum function takes the sum of the elements in the arrays and return the value 
		Type b;
		for(int i=0;i<size;i++){
				if(elements[i]<0) throw "The amount of money cannot be below zero!";
			b=b+elements[i];
			//if a negative value is entered an error message is thrown
		
		}	
		return b;		
	}
	
	Type incrementer(){//incrementer function
			if(total>100)//add 5 to the total if it is more than 100
				total+=5;		
			else if(total<100)//subttract 5 from the total if it is less than 100
				total-=5;
			else if(total==100)
			return total;
			return total;//return the new value after addition/subtraction
			
	}

	~GenericArray(){// destructor to give dynamically allocated space back
		delete[] elements;
	}
};

//user defined class
class Money{
	public:
	int lira;
	double kurus;
	Money():lira(0),kurus(0){}//when default Money constructor is called it assigns 0 to both lira and kurus values
	Money(int a,double b):lira(a),kurus(b){//when Money constructor with arguments is called it assigns the given values to lira and kurus
		//if the total amount entered is less than 0 an error message is returned
		//the reason for having 2 exceptions in the code is because the user can create a negative valued Money but not use it as an array member
		if(lira<0||(lira==0&&kurus<0)) throw "The amount of money cannot be below zero!";
	}	
	
	Money operator+(Money &z){//returns the sum of money values
		int lira1;
		double kurus1;
		lira1=lira+ z.lira;
		kurus1=kurus+z.kurus;
		return Money(lira1,kurus1); 
	}
	bool operator>(int a ){//returns true if the sum of Money array is greater than the input value
		double compare=static_cast<double>(a);
		double final;
		final=static_cast<double>(lira)+kurus/100;//combining lira and kurus to double for better comparison purposes
		if(final>compare){
		cout<<	"Your total amount for money object array "<<lira<<" lira: "<<kurus<<" kurus "<<endl;
			return true;
		}
		else return false;
	}
	
	
	bool operator<(int a){//returns true if the sum of Money array is less than the input value
		double compare2=static_cast<double>(a);
		double final2;
		final2=static_cast<double>(lira)+kurus/100;
		if(final2<compare2){
			cout<<	"Your total amount for money object array "<<lira<<" lira: "<<kurus<<" kurus "<<endl;
			return true;
		}
		else return false;
	}
	
	Money operator+=(int q){//adds the input value to the sum of the Money array
		int lira2;
		double kurus2;
		lira2=lira+q;//lira is incremented
		kurus2=kurus;//kurus has not changed
		cout<<"You have won "<<q<<" tl bonus, your new amount is "<<lira2<<" lira: "<<kurus2<<" kurus "<<endl;
		return Money(lira2,kurus2);
	}
	

	
	bool operator==(int a ){//returns true if the sum of Money array is greater than the input value
		double compare3=static_cast<double>(a);
		double final3;
		final3=static_cast<double>(lira)+kurus/100;//combining lira and kurus to double for better comparison purposes
		if(final3==compare3){
		cout<<	"Your total amount for money object array "<<lira<<" lira: "<<kurus<<" kurus "<<endl;
			return true;
		}
		else return false;
	}
		
	Money operator-=(int q){//subracts the input value form the sum of the Money array
		int lira3;
		double kurus3;
		lira3=lira-q;
		kurus3=kurus;
		cout<<"You have won "<<q<<" tl bonus, your new amount is "<<lira3<<" lira: "<<kurus3<<" kurus "<<endl;
		return Money(lira3,kurus3);
	}

};

int main(){
	GenericArray<int>m1(5);// creates an empty 5-element-integer array
	GenericArray<double>m2(5);// creates an empty 5-element-double array
	GenericArray<Money>m3(5);// creates an empty 5-element-Money array
	try{//the reason for just covering the below line in try-catch block is because I do not want the program to terminate because of a 
	//minus value which will not be used in the summation but if wanted the try-catch block can cover all the lines between 120-125
		Money d(-1,89);
	}
	catch ( const char * result1) {
		cout <<result1<<endl;
	}
	
	Money a(10,5);
	Money b(10,5);
	Money c(43,7);
	Money k(50,6);
	Money m(10,20);
	Money bonus(5,0);	
	
	
	m1.elements[0]=1;
	m1.elements[1]=2;
	m1.elements[2]=5;
	m1.elements[3]=9;
	m1.elements[4]=90;

	m2.elements[0]=12.5;
	m2.elements[1]=11.6;
	m2.elements[2]=13.9;
	m2.elements[3]=23.7;
	m2.elements[4]=130.7;
	
	m3.elements[0]=a;
	m3.elements[1]=b;
	m3.elements[2]=c;
	m3.elements[3]=k;
	m3.elements[4]=m;

//if any of the money/int/double values is negative an error message will be thrown
//try-catch blocks
//the reason for having 3 try-catch blocks is because I want to produce multiple error messages if the number of negative values is more than 1
	try{
		m1.total=m1.sum();
	}
	catch ( const char * result ) {
		cout <<result<<endl;
	}	
	try{
	m2.total=m2.sum();
	}
	catch ( const char * result ) {
		cout <<result<<endl;
	}
	try{
	m3.total=m3.sum();
	}
	catch ( const char * result ) {
		cout <<result<<endl;
	}
	
m3.incrementer();//calling incrementing function of the Money array
if(sizeof(int)==sizeof(m1.elements[0])){//this part is used for printing :"The total of integer array is "

cout<<endl<<"The total of integer array is "<<m1.total<<endl;//calling total function and  printing its value for integer array
cout<<"You have won 5 tl bonus new amount is "<<m1.incrementer()<<endl<<endl;//incrementing the total
}
if(sizeof(double)==sizeof(m2.elements[0])){////this part is used for printing :"The total of double array is "
cout<<"The total of double array is "<<m2.total<<endl;//calling total function and  printing its value for integer array
cout<<"You have won 5 tl bonus new amount is "<<m2.incrementer()<<endl;//incrementing the total
}
	return 0;
}
