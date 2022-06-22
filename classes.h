#include<bits/stdc++.h>
using namespace std;
class Book{
	public:
		int id;
		string name;
		string author;
		int aval;
		Book(int id,string name,string author,int aval){
			this->id = id;
			this->name = name;
			this->author = author;
			this->aval = aval;
		}
		string getInfo(){
			string info = to_string(id) + "," + name + "," +  author + "," + to_string(aval);
			return info;
		}
};

class Student{
	public:
		int RollNo;
		string name;
		string address;
		int total_book;
		Student(int RollNo,string name,string address,int total_book){
			this->RollNo = RollNo;
			this->name = name;
			this->address = address;
			this->total_book = total_book;
		}
		string getInfo(){
			string info = to_string(RollNo) + "," + name + "," + address + "," + to_string(total_book);
			return info;
		}
};