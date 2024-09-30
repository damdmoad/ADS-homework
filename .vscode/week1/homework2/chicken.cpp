#include <iostream>  
#include <cstring>  
  
class Chicken  
{  
    private:  
        int age = 24;  
        char *name = nullptr;  
    public:  
        Chicken(){};  
        Chicken(int _age) : age(_age) {};  
        Chicken(int _age, const char *_name) : age(_age)   
        {  
            int len = strlen(_name) + 1;  
            name = new char[len];  
            strcpy(name, _name);  
        };  
        Chicken(const Chicken &other) : age(other.age)  
        {  
            if(other.name)  
            {  
                name = new char[strlen(other.name) + 1];  
                strcpy(name, other.name);  
            }  
        }  
        Chicken& operator=(const Chicken &other) 
        {  
            if(this == &other)  
                return *this;  
            delete[] name;  
            age = other.age;  
            name = nullptr;  
            if(other.name)  
            {  
                name = new char[strlen(other.name) + 1];  
                strcpy(name, other.name);  
            }  
            return *this;  
        }  
        ~Chicken()  
        {  
            delete[] name;  
        }  
        void setAge(int _age)  
        {  
            age = _age;  
        }  
        void setName(const char *_name)  
        {  
            delete[] name;  
            name = nullptr;  
            if(_name)  
            {  
                name = new char[strlen(_name) + 1];  
                strcpy(name, _name);  
            }  
        }  
        const char *getName() const  
        {  
            return name;  
        }  
        const int &getAge() const  
        {  
            return age;  
        }  
};  
//cece dingzhen de code
int main(){
auto print = [](const Chicken &c){
std::cout << "Hi, everyone! My name is " << c.getName()
<< ", I am " << c.getAge() << " years old." << std::endl;
};
Chicken c(24, "Kunkun");
print(c);
Chicken d;
d = c;
print(d); 
Chicken a = c;
print(a); 
c.setName("Xukun Cai");
print(c);
print(a);
print(d); 
Chicken b;
b = d = c;
print(b);
print(d); 
return 0;
}