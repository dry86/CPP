#include<iostream>
using namespace std;
class CTyre{
    public:
        CTyre(){ cout<<"CTyre contructor"<<endl;}
        ~CTyre(){ cout<<"CTyre destructor"<<endl;}
        
};
class CEngine{
    public:
        CEngine(){ cout<<"CEngine destructor"<<endl;}
        ~CEngine(){ cout<<"CEngine destructor"<<endl;}
        
};
class CCar{
    private:
        CEngine engine;
        CTyre tyre; 
    public:
        CCar(){ cout<<"CCar destructor"<<endl;}
        ~CCar(){ cout<<"CCar destructor"<<endl;}
        
};
int main()
{
    CCar car;
    return 0;
}