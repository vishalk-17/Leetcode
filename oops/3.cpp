#include<iostream>
using namespace std;
class Bank{
   
    int balance;
    string Name;
    public:
    void SetValue(int amount,string person){
        balance = amount;
        Name = person;
    };
    void check_balance(){
        cout<<balance<<endl;
        cout<<Name<<" ";
    };
    void withdraw(){
        balance-=100;
        cout<<"100 rs nikal liye";
    };
};
int main(){
    Bank obj;
    obj.SetValue(1000,"vishal");
    obj.check_balance();
    obj.withdraw();
    obj.check_balance();
    return 0;
}