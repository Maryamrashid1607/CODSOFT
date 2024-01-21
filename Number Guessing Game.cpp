#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	cout<<"\t\t\t\t\t\t NUMBER GUESSING GAME "<<endl;
    cout<<"Enter any key to start: ";
    char c;
    cin>>c;
    system("cls");
    char ch;
    do{
    srand((unsigned int) time(0));
    int num=rand()%100+1;
    int input=0;
    int attempt=1;
    do{
    	cout<<"Enter your guess number "<<attempt<<" (b/w 1-100): ";
    	cin>>input;
    	if(input<num){
    		cout<<"Guess higher!"<<endl;
    		attempt++;
		}
		else if(input>num){
			cout<<"Guess lower!"<<endl;
			attempt++;
		}
		else if(input==num){
			cout<<"CONGRATULATIONS!"<<endl;
			cout<<"You guessed it right!"<<endl;
		}
		else{
		    cout<<"Invalid input! \n Enter a valid number";
	    }  
	}while(input!=num);
	cout<<"Do you want to play again? (y/n): ";
	cin>>ch;
	system("cls");
	}while(ch=='y' || ch=='Y');
    return 0;
}
