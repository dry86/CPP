#include<iostream>
#include<string.h>

using namespace std;
class String{
    private:
        char * str;
    public:  
        String ():str(new char[1]) { str[0] = 0;}
        const char * c_str()  { return str;};
        String & operator = ( const char * s);
        String & operator = (const String & s){
            delete [] str;
            str = new char[strlen(s.str)+1];
            strcpy( str , s.str);
            return * this;
        } 
        ~String ( ){ delete [] str;};
};
String & String::operator = (const char * s)
{

    delete [] str;
    str = new char[strlen(s)+1];
    strcpy( str , s);
    return * this;
}

int main()
{
    String s;
    s = "Good Luck，";
    cout<<s.c_str()<<endl;
    s = "tiankong 1!";
    cout<<s.c_str()<<endl;
    return 0;

}