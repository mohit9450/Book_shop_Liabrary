#include<bits/stdc++.h>
using namespace std;
//-------------------choose an option-------------------------------//
int chooseAnOptions(){
	cout<<"Press 1 : add a new book in library : \n";
	cout<<"Press 2 : add a new student : \n";
	cout<<"Press 3 : list of all books : \n";
	cout<<"Press 4 : info of all student : \n";
	cout<<"Press 5 : get a book from liabrary : \n";
	cout<<"Press 6 : return a book to liabrary : \n";
	cout<<"Press 7 : get info of perticular student : \n";
	cout<<"Press 8 : get info all book inssue by perticular student : \n";
	cout<<"Press any key to exit : \n";
	int n;
	cin>>n;
	return n;
	
}

//-------------------add new book-------------------------------//
void AddNewBook(int id,string name,string author,int aval){
	Book book(id,name,author,aval);
	string info = book.getInfo();
	ofstream out;
	out.open("books.csv",ios::app);
	out<<info<<endl;
	out.close();
	system("cls");
	return;
}

//-----------------------add new student-----------------------------//
void AddNewStudent(int RollNo,string name,string address,int total_book){
	Student student(RollNo,name,address,total_book);
	string info = student.getInfo();
	ofstream out;
	out.open("student.csv",ios::app);
	out<<info<<endl;
	out.close();
	system("cls");
	return;
}

//---------------------list all books----------------------------------//
void listAllBooks(){
	ifstream in;
	in.open("books.csv");
	while(in.good()){
		string id;
		getline(in,id,',');
		string name;
		getline(in,name,',');
		string address;
		getline(in,address,',');
		string total_books;
		getline(in,total_books,'\n');
		if(id != "")
		cout<<id<<" , "<<name<<" , "<<address<<" , "<<total_books<<endl;
	}
	in.close();
	cout<<"Press any key to continue.........";
	system("pause");
	system("cls");
	return;
}

//---------------------info all students----------------------------------//
void infoAllStudents(){
	ifstream in;
	in.open("student.csv");
	while(in.good()){
		string RollNo;
		getline(in,RollNo,',');
		string name;
		getline(in,name,',');
		string address;
		getline(in,address,',');
		string total_books;
		getline(in,total_books,'\n');
		if(RollNo != "")
		cout<<RollNo<<" , "<<name<<" , "<<address<<" , "<<total_books<<endl;
	}
	in.close();
	cout<<"Press any key to continue.........";
	system("pause");
	system("cls");
	return;
}

//-----------------------getPerticular()---------------------//
void getPerticular(string RollNos){
	ifstream in;
	in.open("student.csv");
	while(in.good()){
		string RollNo;
		getline(in,RollNo,',');
		string name;
		getline(in,name,',');
		string address;
		getline(in,address,',');
		string total_books;
		getline(in,total_books,'\n');
		if(RollNo == RollNos)
		cout<<RollNo<<" , "<<name<<" , "<<address<<" , "<<total_books<<endl;
	}
	in.close();
	cout<<"Press any key to continue.........";
	system("pause");
	system("cls");
	return;
}

//----------------------------get books available for a perticular id------------------//
int get_books_amount(string id){
	ifstream in;
	in.open("books.csv");
	while(in.good()){
		string s1,s2,s3,s4;
		getline(in,s1,',');
		getline(in,s2,',');
		getline(in,s3,',');
		getline(in,s4,'\n');
		if(s1 == id){
			in.close();
			return stoi(s4);
		}
	}
	in.close();
	return 0;
}

//--------------------------update operation ---------------------//
void update_ope(string id,int ope){
				ofstream books2;
			books2.open("book.csv",ios::app);
			ifstream books;
			books.open("books.csv");
			while(books.good()){
				string s1,s2,s3,s4;
				getline(books,s1,',');
				getline(books,s2,',');
				getline(books,s3,',');
				getline(books,s4,'\n');
				if(s1 != id && s1 != ""){
					string ss = s1 + "," + s2 + "," + s3 + "," + s4;
					books2<<ss<<endl;
				}
				else if(s1 == id && s1 != ""){
					s4 = to_string(stoi(s4) + ope);
					string ss = s1 + "," + s2 + "," + s3 + "," + s4;
					books2<<ss<<endl;
				}
			}
			books.close();
			books2.close();
			remove("books.csv");
			rename("book.csv","books.csv");
}

//------------------------do operation update---------------//
void doOperationUpdate(string roll,int ope){
	ofstream students;
	students.open("students.csv",ios::app);
	ifstream student;
	student.open("student.csv");
	while(student.good()){
		string s1,s2,s3,s4;
		getline(student,s1,',');
		getline(student,s2,',');
		getline(student,s3,',');
		getline(student,s4,'\n');
		if(s1 == roll){
			string s = s1 + "," + s2 + "," + s3 + "," + to_string(stoi(s4) + ope);
			students<<s<<endl;
		}
		else{
			if(s1 != ""){
			string s = s1 + "," + s2 + "," + s3 + "," + s4;
			students<<s<<endl;
			}
		}
	}
	students.close();
	student.close();
	remove("student.csv");
	rename("students.csv","student.csv");
}
//-------------------------update book----------------------------//
bool update_book(string roll,string id,int ope){
	int avail = get_books_amount(id);
	if(ope == -1){
		if(avail == 0){
			cout<<"No books are available for this perticular id..\n";
			cout<<"Press any key to continue.........";
			system("pause");
			system("cls");
			return false;
		}
		else if(avail > 0){
			update_ope(id,ope);
			return true;
		}
	}
	update_ope(id,ope);
	
	return true;
}
//---------check student book--------------------------------//
bool check_student_book(string roll,string id){
	ifstream in;
	in.open("booksIssue.csv");
	while(in.good()){
		string s1,s2;
		getline(in,s1,',');
		getline(in,s2,'\n');
		if(s1 == roll && s2 == id){
			in.close();
			return 1;
		}
	}
	in.close();
	return 0;
}


//--------------------removePerticulerIdRoll(roll,id)--------------//
void removePerticulerIdRoll(string roll,string id){
	ofstream students;
	students.open("booksIssues.csv",ios::app);
	ifstream student;
	student.open("booksIssue.csv");
	while(student.good()){
		string s1,s2;
		getline(student,s1,',');
		getline(student,s2,'\n');
		if(s1 == roll && s2 == id){
			
		}
		else{
			if(s1 != ""){
			string s = s1 + "," + s2;
			students<<s<<endl;
			}
		}
	}
	students.close();
	student.close();
	
	remove("booksIssue.csv");
	rename("booksIssues.csv","booksIssue.csv");
	
}

//----------------update student------------------------------//
bool update_student(string roll,string id,int ope){
	bool avail = check_student_book(roll,id);
	if(ope == 1){
		if(avail == 1){
			cout<<"Sry you have already book to this perticular id : \n";
			cout<<"Press any key to continue : ";
			system("pause");
			system("cls");
			return false;
		}
		else if(avail == 0){
			ofstream out;
			out.open("booksIssue.csv",ios::app);
			string s = roll + "," + id;
			out<<s<<endl;
			out.close();
			return true;
		}
	}
	else{
		if(avail == 0){
			cout<<"sry no book issue for this perticular id : ";
			return false;
		}
		else{
			removePerticulerIdRoll(roll,id);
			return true;
		}
	}
	
}



//--------------------------get issue book---------------------//
void get_IssueBook(){
	cout<<"Enter your Roll No. : ";
	string roll;
	cin>>roll;
	cout<<"Your inforamation : \n";
	getPerticular(roll);
	cout<<endl;
	listAllBooks();
	cout<<"choose id of available book to issue : ";
	string id;
	cin>>id;
	if(update_book(roll,id,-1))
	if(update_student(roll,id,1))doOperationUpdate(roll,1);
	
}

//---------------------return issue book----------------------------//
void return_issueBook(){
	cout<<"Enter your Roll No. : ";
	string roll;
	cin>>roll;
	cout<<"Your inforamation : \n";
	getPerticular(roll);
	cout<<endl;
	listAllBooks();
	cout<<"choose id of available book to issue : ";
	string id;
	cin>>id;
	
	if(update_student(roll,id,-1))if(update_book(roll,id,1))doOperationUpdate(roll,-1);
	
}

//--------------------print all book for a pertucular student----------------------//
void printAllBook(string s){
	cout<<"These books issued : ";
	ifstream in;
	in.open("booksIssue.csv");
	while(in.good()){
		string s2;
		getline(in,s2,',');
		string s1;
		getline(in,s1,'\n');
		if(s == s2)
		cout<<s1<<" , ";
	}
	cout<<endl;
	in.close();
	cout<<"Please enter any key to continue : ";
	system("pause");
	return;
}