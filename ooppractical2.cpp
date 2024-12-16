#include<iostream>
#include<string.h>
using namespace std;

class StudentData;
class Student
{
  string name;
  int roll_no;
  string cls;
  char* division;
  string dob;
  char* bloodgroup;
  static int count;

  public:
  Student()          
  {
    name="";
    roll_no=0;
    cls="";
    division=new char;
    dob="dd/mm/yyyy";
    bloodgroup=new char[4];
  }
  ~Student()
  {
    delete division;
    delete[] bloodgroup;
  }
  static int getCount()
  {
    return count;
  }
  void getData(StudentData*);
  void displayData(StudentData*);
};

class StudentData
{
  string caddress;
  long int* telno;
  long int* dlno;
  friend class Student;

  public:
  StudentData()
  {
     caddress="";
     telno=new long;
     dlno=new long;
  }
  ~StudentData()
  {
    delete telno;
    delete dlno;
  }
  void getStudentData()
  {
     cout<<"Enter Contact Address : ";
     cin.get();
     getline(cin,caddress);
     cout<<"Enter Telephone Number : ";  
     cin>>*telno;
     cout<<"Enter Driving License Number : ";
     cin>>*dlno;
  }
  void displayStudentData()
  {
     cout<<"Contact Address : "<<caddress<<endl;
     cout<<"Telephone Number : "<<*telno<<endl;
     cout<<"Driving License Number : "<<*dlno<<endl;
  }
};

inline void Student::getData(StudentData* st)
{
  cout<<"Enter Student Name : ";
  getline(cin,name);
  cout<<"Enter Roll Number : ";
  cin>>roll_no;
  cout<<"Enter Class : ";
  cin.get();
  getline(cin,cls);
  cout<<"Enter Division : ";
  cin>>division;
  cout<<"Enter Date of Birth : ";
  cin.get();
  getline(cin,dob);
  cout<<"Enter Blood Group : ";
  cin>>bloodgroup;
  st->getStudentData();
  count++;
}

inline void Student::displayData(StudentData* st1)
{
  cout<<"Student Name : "<<name<<endl;
  cout<<"Roll Number : "<<roll_no<<endl;
  cout<<"Class : "<<cls<<endl;
  cout<<"Division : "<<division<<endl;
  cout<<"Date of Birth : "<<dob<<endl;
  cout<<"Blood Group : "<<bloodgroup<<endl;
  st1->displayStudentData();
}

int Student::count;

int main()
{
  Student* stud1[100];
  StudentData* stud2[100];
  int n=0;
  char ch;

  do
  {
    stud1[n]=new Student;
    stud2[n]=new StudentData;
    stud1[n]->getData(stud2[n]);
    n++;
    cout<<"Do you want to add another student (y/n) : ";
    cin>>ch;
    cin.get();
  } 
  while (ch=='y' || ch=='Y');
  {
  for(int i=0;i<n;i++)
   {
     cout<<"---------------------------------------------------------------"<<endl;
     stud1[i]->displayData(stud2[i]);
   } 
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Total Students : "<<Student::getCount();
    cout<<endl<<"---------------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
  } 
 cout<<"\nName:- Parth Jayant Kulkarni, Roll.no:SEAD231250, Div:A";
return 0;
}