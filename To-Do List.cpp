#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
struct list{
	int serial;
	string task;
};

void home();
void header();
void IndexInitial();
void add();
void view();
void Mark();
void del();
int index;

int main(){
	IndexInitial();
	home();
	return 0;
}

void home(){
	header();
	cout<<"1. Add task."<<endl;
	cout<<"2. View task."<<endl;
	cout<<"3. Mark tasks."<<endl;
	cout<<"4. Remove task."<<endl;
	int num;
	cout<<"Enter your option: ";
	cin>>num;
	switch(num){
		case 1:
			system("cls");
			add();
			break;
		case 2:
			system("cls");
			view();
			break;
		case 3:
			system("cls");
			Mark();
			break;
		case 4:
			system("cls");
			del();
			break;
		default:
		    cout<<"Invalid input!";
		    break;
	}
}

void header(){
	cout<<"*****************************"<<endl;
	cout<<"\tTO DO LIST"<<endl;
	cout<<"*****************************"<<endl;
}

void IndexInitial(){
	ifstream fin;
	fin.open("tasks.txt");
	list t;
	while(!fin.eof()){
		fin>>t.serial;
		fin.ignore();
		getline(fin, t.task);
		if(t.serial>index){
			index=t.serial;
		}
	}
	fin.close();
}

void add(){
	header();
	list t1;
	cout<<"Enter new task: ";
	cin.get();
	getline(cin, t1.task);
	char save;
	cout<<"Do you want to save this task? (y/n): ";
	cin>>save;
	if(save=='y' || save=='Y'){
		index++;
		ofstream fout;
		fout.open("tasks.txt", ios::app);
		fout<<"\n"<<index;
		fout<<"\n"<<t1.task;
		fout.close();
		char newtask;
		cout<<"Do you want to add another task? (y/n): ";
		cin>>newtask;
		if(newtask=='y' || newtask=='Y'){
			system("cls");
			add();
		}
		else{
			cout<<"Task added successfully!"<<endl;
			system("cls");
			home();
		}
		system("cls");
	}	
}

void view(){
	header();
	list t1;
	ifstream fin;
	fin.open("tasks.txt");
	cout<<"Tasks: "<<endl;
	while(!fin.eof()){
		fin>>t1.serial;
		fin.ignore();
		getline(fin, t1.task);
		if(t1.task != ""){
			cout<<t1.serial<<". "<<t1.task<<endl;
		}
		else{
			cout<<"No tasks!"<<endl;
		}
	}
	fin.close();
	char e;
	cout<<"Do you wish to exit? (y/n): ";
	cin>>e;
	if(e=='y' || e=='Y'){
	    system("cls");
    	home();
    }
    else{
    	system("cls");
    	view();
	}
}

void Mark(){
	header();
	int a;
	cout<<"Enter the index of task you want to mark: ";
	cin>>a;
	list t1;
	ofstream temp;
	temp.open("temp.txt");
	ifstream fin;
	fin.open("tasks.txt");
	int i=1;
	while(!fin.eof()){
		fin>>t1.serial;
		fin.ignore();
		getline(fin, t1.task);
		if(t1.serial==a){
			temp<<"\n"<<i;
			temp<<"\n"<<t1.task<<"(\xfb)";
			i++;
			}
		else{
			temp<<"\n"<<i;
			temp<<"\n"<<t1.task;
			i++;
		}
	}
	fin.close();
	temp.close();
	remove("tasks.txt");
	rename("temp.txt", "tasks.txt");
	cout<<"Task has been marked!"<<endl;
	char mark;
	cout<<"Do you wish to mark more tasks? (y/n):";
	cin>>mark;
	if(mark=='Y' || mark=='y'){
		Mark();
	}
	else
		system("cls");
		home();
}

void del(){
	header();
	int b;
	cout<<"Enter the index of task you want to delete: ";
	cin>>b;
	char sure;
	cout<<"Sure you want to delete this task? (y/n): ";
	cin>>sure;
	if(sure=='y' || sure=='Y'){
		list t1;
		ofstream temp;
		temp.open("temp.txt");
		ifstream fin;
		fin.open("tasks.txt");
		int i=1;
		while(!fin.eof()){
			fin>>t1.serial;
			fin.ignore();
			getline(fin, t1.task);
			if(t1.serial!=b){
				temp<<"\n"<<i;
				temp<<"\n"<<t1.task;
				i++;
				index--;
			}
		}
		fin.close();
		temp.close();
		remove("tasks.txt");
		rename("temp.txt", "tasks.txt");
		cout<<"Task has been deleted!"<<endl;
		system("cls");
		home();
	}
	else{
    	cout<<"Task not deleted!";
    	system("cls");
    	home();
    }
}
