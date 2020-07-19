#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void reg();
void login();

class LoginReg
{
	private:
	    char name[24];
		long long int mobNumber;
		int age;
		char userName[24];
		char passWord[24];

	public:
		LoginReg()
		{
		    strcpy(name,"no name");
			mobNumber=0;
			age=0;
		}

		void getUserData()
		{
			cout<<"Enter details: \n";
			cin.ignore();
			cout<<"Name: ";
			cin.getline(name,23);
			cout<<"Mobile Number: ";
			cin>>mobNumber;
			cout<<"Age: ";
			cin>>age;
			cin.ignore();
			cout<<"Username: ";
			cin.getline(userName,23);
			cout<<"Password: ";
			cin.getline(passWord,23);
		}

		void showUserData()
		{
			cout<<"Name: "<<name<<"\t"<<"Number: "<<mobNumber<<"\t"<<"Age: "<<age<<"\n\n"<<"Username: "<<userName<<"\t"<<"Password: "<<passWord<<"\n"<<endl;
		}

		int storeUserData();
		void viewAllRecords();
		void searchUser(char*);

};
//how to save all the records in file
int LoginReg::storeUserData()
{
	if(mobNumber==0 && age==0)
	{
		cout<<"User details are not initialized. \n\n ";
		return 1;
	}

	ofstream fout;
	fout.open("file1.txt",ios::app);
	fout.write((char*)this,sizeof(*this));
	fout.close();

	return 0;
}
//how to see all the records in a file
void LoginReg::viewAllRecords()
{

	ifstream fin;
	fin.open("file1.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\nFile not found!!";
		return;
	}
	else{
	cout<<"\nHere is the list of all Users!!!\n\n";
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		showUserData();
		fin.read((char*)this,sizeof(*this));
	}
	}
	fin.close();
}

void LoginReg::searchUser(char*un)
{
	int counter=0;
	char tempPass[24];
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
			if(!strcmp(un,userName))
			{
			    cout<<"Password: ";
                cin.getline(tempPass,23);
                if(!strcmp(tempPass,passWord)){
                        cout<<"\nDetails are as follows:\n\n";
                        showUserData();
                }
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



	/*LoginReg b1,b2;
	b1.getUserData();
	b1.showUserData();
	b1.storeUserData();
	b2.showUserData();
	b2.storeUserData();
	b1.viewAllRecords();
	b2.searchUser("kishan bagga");*/
}
void reg()
{
    LoginReg b1;
    b1.getUserData();
    b1.storeUserData();
    cout<<"\nRegistration done successfully!!!"<<endl;
}
void login()
{
    char tempUser[24];
    LoginReg temp;
    temp.viewAllRecords();
    cout<<"Username: ";
    cin.ignore();
    cin.getline(tempUser,23);
    temp.searchUser(tempUser);

}
