/*SIMPLE CALCULATOR*/

#include<iostream>
using namespace std;
class Calculator{
	public:
		void add(int num1,int num2,int sum) {
			sum=num1+num2;
			cout<<"Sum is: "<<sum;
		}
		void sub(int num1,int num2,int sub) {
			sub=num1-num2;
			cout<<"Difference is: "<<sub;
		}
		void mul(int num1,int num2,int mul) {
			mul=num1*num2;
			cout<<"Product is: "<<mul;
		}
		void div(int num1,int num2,int div) {
			div=num1/num2;
			cout<<"Division is: "<<div;
		}
};
int main() {
	Calculator x;
	int num1,num2,result=0;
	char op,c;
	do{
	cout<<"Enter first number: ";
	cin>>num1;
	cout<<"Enter second number: ";
	cin>>num2;
	cout<<"Enter operation: ";
	cin>>op;
	switch(op){
		case '+':
			cout<<"For addition: "<<endl;
	        x.add(num1,num2,result);
	        break;
	    case '-':
	    	cout<<"\nFor subtraction: "<<endl;
        	x.sub(num1,num2,result);
        	break;
        case '*':
        	cout<<"\nFor multiplication: "<<endl;
	        x.mul(num1,num2,result);
	        break;
	    case '/':
	    	cout<<"\nFor division: "<<endl;
	        x.div(num1,num2,result);
	        break;
	}
	cout<<"\nDo you want to continue? (y/n) ";
	cin>>c;} while(c=='y' || c=='Y');	
	return 0;
}
