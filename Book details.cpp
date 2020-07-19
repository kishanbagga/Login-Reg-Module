#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
	private:
		int bookid;
		char title[20];
		float price;
	
	public:
		Book()
		{
			bookid=0;
			strcpy(title,"no title");
			price=0;
		}
		
		void getBookData()
		{
			cout<<"Enter Book details: \n";
			cout<<"Bookid: ";
			cin>>bookid;
			cin.ignore();
			cout<<"Title: ";
			cin.getline(title,19);
			cout<<"Price: ";
			cin>>price;
		}
		
		void showBookData()
		{
			cout<<bookid<<"\t"<<title<<"\t"<<price<<"\n"<<endl;
		}
		
		int storeBook();
		void viewAllBooks();
		void searchBook(char*);
		
};
//how to save all the records in file
int Book::storeBook()
{
	if(price==0 && bookid==0)
	{
		cout<<"Book details are not initialized. \n\n ";
		return 1;
	}
	
	ofstream fout;
	fout.open("file1.txt",ios::app);
	fout.write((char*)this,sizeof(*this));
	fout.close();
	 
	return 0;
}
//how to see all the records in a file
void Book::viewAllBooks()
{
	
	ifstream fin;
	fin.open("file1.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\nFile not found!!";
		return;
	}
	else{
	cout<<"\nHere is the list of all books!!!\n\n";
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		showBookData();
		fin.read((char*)this,sizeof(*this));
	}
	}
	fin.close();
}

void Book::searchBook(char*t)
{
	int counter=0;
	ifstream fin;
	fin.open("file1.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\nFile not found\n";
		return;
	}
	else{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!strcmp(t,title))
			{
				cout<<"\nMatch found!!\n";
				showBookData();
				counter++;
				break;
			}
			fin.read((char*)this,sizeof(*this));
		}
		if(counter==0)
			cout<<"\nRecord not found\n";
		fin.close();
	}
}
int main()
{
	Book b1,b2;
	b1.getBookData();
	b1.showBookData();
	b1.storeBook();
	b2.showBookData();
	b2.storeBook();
	b1.viewAllBooks();
	b2.searchBook("abcdefghijk");
}


































































/*#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class reg
{

};
void reg();
void login();
int main()
{
    int n;
    cout<<"\nEnter 1 for Registration and 2 for Login : ";
    cin>>n;
    switch(n)
    {
    case 1:
        reg();
        break;
    case 2:
        login();
        break;
    default:
        cout<<"\nInvalid Input!!!"<<endl;
    }

    return 0;
}

void reg()
{
    ofstream fout;
    fout.open("Registration Details.txt",ios::app);
    char data[100];

    cin.ignore();
    cout<<"\nPlease enter your details and register.....\n"<<endl;
    cout<<"\nName: ";
    cin.getline(data, 100);
    // write inputted data into the file.
    fout <<data<< endl;

    cout<<"\nMobile no. : ";
    cin >> data;
    // again write inputted data into the file.
   	fout << data << endl;
    
    cout<<"\nAge: ";
    cin >> data;
   	fout << data << endl;
    
    cout<<"\nUsername: ";
    cin >> data;
   	fout <<  data << endl;

    cout<<"\nPassword: ";
    cin >> data;
   	fout << data << endl;

   	fout<<endl<<endl;

    cout<<"\nRegistration done successfully!!!"<<endl;
}

void login()
{
    cout<<"\nPlease enter your login credentials: \n"<<endl;
    cout<<"\nUsername: ";

    cout<<"\nPassword: ";
}
*/

