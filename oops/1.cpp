#include <iostream>

using namespace std;

class Student{
    public:
    string name;
    int roll_no;
    string branch;
    int fees;
};

int main(){
    Student s1;// object 
    s1.name="vishal";
    s1.roll_no = 101;
    s1.branch = "CSE";  
    s1.fees = 50000;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Roll No: "<<s1.roll_no<<endl;
    cout<<"Branch: "<<s1.branch<<endl;
    cout<<"Fees: "<<s1.fees<<endl;
    return 0;
}
