// #include<iostream>
// using namespace std;
// class Car{
//     int cost;
//     int mileage;
//     public:
//     Car(int in,int mil){
//         cost = in;
//         mileage = mil;
//         cout<<"Hello Constructor";
//     };
//     void Print(){
//         cout<<cost<<" "<<mileage;

//     };
// };
// int main(){
//     Car obj(20,10);// parmeterize constructor
//     obj.Print();
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Car{
//     int cost;
//     int mileage;
//     public:
//     Car(int cost,int mileage){
//         this->cost = cost;
//         this->mileage = mileage;
//         cout<<"Hello Constructor";
//     };
//     void Print(){
//         cout<<cost<<" "<<mileage;

//     };
// };
// int main(){
//     Car obj(20,10);// parmeterize constructor
//     obj.Print();
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class Car{
//     public:
//     int cost;
//     int mileage;
    
   
// };
// int main(){
//     Car *p = new Car();
//     p->cost = 20;//(*p).cost = 20;
//     p->mileage= 70;
//     cout<<p->cost;
//     return 0;
// }


#include<iostream>
using namespace std;
class Car{
    public:
    int cost;
    int mileage;
    Car(){
        cout<<"constructor executed\n";
    }
    ~Car(){
        cout<<"Destructor extecuted";
    }
    
   
};
int main(){
   //Car obj;
   Car *p = new Car;
   delete p;

    return 0;
}