#include <iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;
class Singleton;
class Person
{
public:
    string name;
    int age;
    int id;
    Person(string n,int a,int ID)
    {
        name=n;
        age=a;
        id=ID;
    }
    virtual void role()=0;
};
/////////////////////////////////////
class Singleton:public Person
{
    int salary;
    static Singleton* instance;
public:
    Singleton(string n,int a,int ID):Person(n, a, ID)
    {
        //salary=s;
    }
    static Singleton* getInstance(string n, int a, int ID)
    {
        if(instance==nullptr)
        {
            instance = new Singleton(n, a, ID);;
        }
        return instance;
    }
    void setSalary(int s)
    {
        salary=s;
    }
    int getSalary()
    {
        return salary;
    }
    void role()
    {
        cout<<"This is Manager person"<<endl;
    }
};
Singleton* Singleton::instance=nullptr;
/////////////////////////////////
class Student:public Person
{
public:
    float GPA;
    Student(string n,int a,int ID,float gpa):Person( n, a, ID)
    {
        GPA=gpa;
    }
    void role()
    {
        cout<<"I am a student "<<endl;
    }

};
//////////////////////////////////////////////
class Employee: public Person
{
public:
    Employee(string n,int a,int ID):Person(n,a,ID)
    {
    }
    int salary;
    void role()
    {
        cout<<"I am Employee"<<endl;
    }

};
/////////////////////////////////////////////
class Instructor:public Person
{
public:
    Instructor(string n,int a,int ID):Person(n,a,ID)
    {
    }
    int salary;
    int hours;
    void role()
    {
        cout<<"I am Instructor"<<endl;
    }
};
////////////////////////////////////////////////
/////////////////////////////////////////////////
////////////////////////////////////////////////
class Course
{
  public:
      string title;
      int icourse_id;
       void details()
    {

        cout<<" this is course "<<endl;
    }

};
/////////////////////////////////////////////////
class Department{
    public:
    string title;
    vector<Course>courses;
      void addCourse( Course s)
    {

        ofstream output;
        output.open("university.txt",ios_base::app);

        if (!output)
        {
            cout<< "Error" << endl;
        }

        output <<  s.title<<" Course"<<endl;
        output.close();
    }
    void detail()
    {

        cout<<" this is department"<<endl;
    }

};
//////////////////////////////////////////////////

class Faculty
{
public:

    string title;
    Faculty()
    {

    }
    vector<Student>students;
     vector<Instructor>instructors;
      vector<Employee>employees;
      vector<Department>departments ;
      void detail()
      {

          cout<<"this is faculty"<<endl;
      }
      void addStudent(Student s)
      {

          ofstream output;
          output.open("university.txt",ios_base::app);

          if (!output)
          {
              cout<< "Error" << endl;
          }

          output <<  s.name<<"   Student "<< endl;
          output.close();
      }

      void addInstractor( Instructor s)
      {

          ofstream output;
          output.open("university.txt",ios_base::app);

          if (!output)
          {
              cout<< "Error" << endl;
          }

          output <<  s.name<<"   Instructor "<< endl;
          output.close();
      }
      void addDepartment( Department s)
      {

          ofstream output;
          output.open("university.txt",ios_base::app);

          if (!output)
          {
              cout<< "Error" << endl;
          }

          output <<  s.title<<endl;
          output.close();
      }
      void addEmployee( Employee s)
      {

          ofstream output;
          output.open("university.txt",ios_base::app);

          if (!output)
          {
              cout<< "Error" << endl;
          }

          output <<  s.name<<"   Instructor "<< endl;
          output.close();
      }



};
class University
{
public:

    string title;
    vector<Faculty>facultys;
    Singleton *manager;
    University(Faculty f)
    {
        facultys.push_back(f);

    }


    void addFaculty( Faculty s)
    {

        ofstream output;
        output.open("university.txt",ios_base::app);

        if (!output)
        {
            cout<< "Error" << endl;
        }

        output<<s.title <<endl;
        output.close();
    }
    void detail()
    {

        cout<<"this university "<<title;
    }

};
////////////////////////////////////////////


int main()
{
    cout<<"****************class Manager***************** "<<endl;
    Singleton* s1=Singleton::getInstance("aye",22,201977);
    cout<<"Nmae Manager: "<<s1->name<<" Age: "<<s1->age<<" ID : "<<s1->id<<endl;
    s1->setSalary(2000);
    cout<<"Salary: "<<s1->getSalary()<<endl;
    cout<<endl;

    /////////////////////////////////////////
    cout<<"********class student*********************"<<endl;
    Student st("nada",19,202144,3.4);
    cout<<"Name: "<<st.name<<" ID: "<<st.id<<" Age: "<<st.age<<" GPA: "<<st.GPA<<endl;
    cout<<endl;

    ///////////////////////////////////////////////
    cout<<"*********Employee class******************"<<endl;
    Employee e("ali",10,272782);
    e.salary=400;
    cout<<"Name: "<<e.name<<" ID: "<<e.id<<" Age: "<<e.age<<" Salary: "<<e.salary<<endl;
    cout<<endl;

    //////////////////////////////////////////////
    cout<<"**************Instructor class******************"<<endl;
    Instructor is("noor",18,353873);
    is.salary=4000;
    is.hours=8;
    cout<<"Name: "<<is.name<<" ID: "<<is.id<<" Age: "<<is.age<<" Salary: "<<is.salary<<" Hors: "<<is.hours<<endl;
    cout<<endl;
    ///////////////////////////////////////////////////////////////////////
     ////////////////////////////////////////////
      cout<<"**************course class******************"<<endl;
    Course c;
    c.title="Data Structure";
    cout<<"Course: "<<c.title<<endl;
    cout<<endl;
    /////////////////////////////////////////////////////
     cout<<"**************Department class******************"<<endl;

    Department d;
    d.title="CS";
    cout<<"Department : "<<d.title<<endl;
   // d.addCourse(c);
    cout<<endl;


    //////////////////////////////////////////////
    cout<<"**************Faculty class******************"<<endl;
    Faculty f;
    f.title="Computer Science";
    cout<<"Faculty : "<<f.title<<endl;
    /// add student
    f.addStudent(st);
    f.addInstractor(is);
    //f.addDepartment(d);
    f.addEmployee(e);

    cout<<endl;

    ////////////////////////////////////////////
    cout<<"**************University class******************"<<endl;
    University un(f);
    un.title="south valley university";
    un.addFaculty(f);
    cout<<"university: "<<un.title<<endl;
    /////////////////////////////////////////////




    return 0;
}
