#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {
    private:
        int age, standard;
        string first_name, last_name;
    public:

        int get_age(){
            return this->age;
        } 
        void set_age(int n){
            this->age = n;
        }
        string get_first_name(){
            return this->first_name;
        }
        void set_first_name(string s){
            this->first_name = s;
        }
        string get_last_name(){
            return this->last_name;
        } 
        void set_last_name(string s){
            this->last_name = s;
        }
        int get_standard(){
            return this->standard;
        }
        void set_standard(int n){
            this->standard = n;
        }
        string to_string(){
            stringstream s;
            s << age << "," << first_name << "," << last_name << "," << standard;
            return s.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

