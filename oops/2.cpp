#include<iostream>
using namespace std;
class Bank{
    public:
    int balance;
    string Name;
    void check_balance(){
        cout<<balance<<endl;
    };
    void withdraw(){
        balance-=100;
        cout<<"100 rs nikal liye";
    };
};
int main(){
    Bank obj;
    obj.balance = 500;
    obj.Name = "vishal";
    obj.check_balance();
    obj.withdraw();
    obj.check_balance();
}