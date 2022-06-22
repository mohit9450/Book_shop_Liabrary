#include<bits/stdc++.h>
#include "classes.h"
#include "allFunc.h"
#define input(a) int a;cin>>a;
int main(){
	while(1){
		int option = chooseAnOptions();
		switch(option){
			case 1:
				{
				cout<<"Enter Book id : ";
				input(id);
				string name;
				cout<<"Enter Book name : ";
				cin>>name;
				cout<<"Entre author name : ";
				string author;
				cin>>author;
				cout<<"Enter total number of book : ";
				int aval;
				cin>>aval;
				AddNewBook(id,name,author,aval);
				cout<<"book added successfully and press any key to continue.....";
				
				system("pause");
				system("cls");
				break;}
			case 2:
				{cout<<"Enter Student RoolNo. : ";
				input(RollNo);
				string name;
				cout<<"Enter Student name : ";
				cin>>name;
				cout<<"Entre Address name : ";
				string address;
				cin>>address;
				cout<<"Enter total number of book he has already issue  : ";
				int total_book;
				cin>>total_book;
				AddNewStudent(RollNo,name,address,total_book);
				cout<<"book added successfully and press any key to continue.....";
				system("pause");
				system("cls");
				break;
				}
			case 3:
				listAllBooks();
				break;
			case 4:
				infoAllStudents();
				break;
			case 5:
				get_IssueBook();
				break;
			case 6:
				return_issueBook();
				break;
			case 7:
				{cout<<"Enter RollNo. of student : ";
				string RollNo;
				cin>>RollNo;
				getPerticular(RollNo);
				break;
				}
			case 8:
				{
					system("cls");
					cout<<"Enter your Roll. : ";
					string s;
					cin>>s;
					printAllBook(s);
				}
				
		}
	}
}