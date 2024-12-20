# include <iostream>
# include <string>
using namespace std;
class College;
class Student
{
    private:
	        string name, dOB, bloodGroup, address, licenseNo, telephone;
	public:
			Student()
			{
				name="",dOB="",bloodGroup="",address="",licenseNo="",telephone="";
				cout<<"Default Student Constructor called."<<endl;
			}
			Student(string n, string dB, string bG, string add, string l ,string tele)
			{
				name=n, dOB=dB , bloodGroup=bG , address=add , licenseNo=l, telephone=tele;
				cout<<"Parametrized Student Constructor called."<<endl;
			}
			Student(const Student &stud)
			{
				cout<<"Copy Student Constructor called."<<endl;
			}
			~Student()
			{
				cout<<"Student Destructor called."<<endl;
			}
			inline void acceptStudent()
			{
				cout<<"Enter your Name : "<<endl;
				cin>>name;
				cout<<"Enter your Date of Birth : "<<endl;
				cin>>dOB;
				cout<<"Enter your Blood Group : "<<endl;
				cin>>bloodGroup;
				cout<<"Enter your Address : "<<endl;
				cin.get();
				getline(cin,address);
				cout<<"Enter your License Number : "<<endl;
				cin>>licenseNo;
				cout<<"Enter your Telephone Number : "<<endl;
				cin>>telephone;
			}
			friend class College;
};
class College
{
	private:
		string className;
		char division;
		int roll;
	public:
			College()
			{
				roll=0;
				cout<<"Default College Constructor called."<<endl;
			}
			College(int r, string cN, char div)
			{
				roll=r,division = div, className = cN;
				cout<<"Parametrized College Constructor called."<<endl;
			}
			void acceptCollege()
			{
				cout<<"Enter your Roll Number : "<<endl;
				cin>>roll;
				cout<<"Enter your Class : "<<endl;
				cin>>className;
				cout<<"Enter your Division : "<<endl;
				cin>>division;
			}
			void printData(Student &stud)
			{
				cout<<"|Name:"<<stud.name;
				cout<<"|DOB:"<<stud.dOB;
				cout<<"|Blood Group:"<<stud.bloodGroup;
				cout<<"|Address:"<<stud.address;
				cout<<"|License:"<<stud.licenseNo;
				cout<<"|Telephone:"<<stud.telephone;
				cout<<"|Roll Number:"<<roll;
				cout<<"|Class:"<<className;
				cout<<"|Division:"<<division;
                cout<<endl;
			}
			~College()
			{
				cout<<"College Destructor called."<<endl;
			}
				
};
int main()
{
	Student s1("Sam","1/1/20","AB","KBTCOE","E-10001","0253-2345678");
	Student s2=s1;
    Student *s[10];
    College *c[10];
    int i =0;
	while(1)
	{
		int ch;
		cout<<"Enter 1-Enter | 2-Display | 0-exit : "<<endl;
		cin>>ch;
		if(ch==1)
		{	
			cout<<"**** Accepting New Student -- "<<endl;
            s[i] = new Student();
            c[i] = new College();
			s[i]->acceptStudent();
			c[i]->acceptCollege();
			cout<<"**** Printing the Student -- "<<endl;
			c[i]->printData(*s[i]);
            i++;
		}
        else if(ch==2)
		{	
			cout<<"**** Printing the Database -- "<<endl;
            for(int j=0;j<i;j++)
			{    c[j]->printData(*s[j]); }
            
		}
		else(ch == 0)
		{
			break;
		}
	}
	return 0;
}
