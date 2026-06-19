#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   // For time(

using namespace std;

// 1. Abstract Base Class
class Compartment {
public:
   
    virtual string notice() = 0;

 
    virtual ~Compartment() {} 
};

// 2. Derived Classes
class FirstClass : public Compartment {
public:
    string notice() override {
        return "Notice: This is a First Class compartment. Please ensure you have a valid premium ticket.";
    }
};

class Ladies : public Compartment {
public:
    string notice() override {
        return "Notice: This compartment is strictly reserved for Ladies.";
    }
};

class General : public Compartment {
public:
    string notice() override {
        return "Notice: This is a General compartment. Open seating for unreserved ticket holders.";
    }
};

class Luggage : public Compartment {
public:
    string notice() override {
        return "Notice: This is a Luggage compartment. Only heavy baggage allowed.";
    }
};

// 3. Main Function
int main() {
    
    srand(time(0));

   
    Compartment* train[10];

    cout << "=== Generating Train Compartments ===\n";
    
   
    for (int i = 0; i < 10; i++) {
       
        int randomNum = (rand() % 4) + 1; 

        switch (randomNum) {
            case 1:
                train[i] = new FirstClass();
                cout << "Compartment " << (i + 1) << ": Created FirstClass\n";
                break;
            case 2:
                train[i] = new Ladies();
                cout << "Compartment " << (i + 1) << ": Created Ladies\n";
                break;
            case 3:
                train[i] = new General();
                cout << "Compartment " << (i + 1) << ": Created General\n";
                break;
            case 4:
                train[i] = new Luggage();
                cout << "Compartment " << (i + 1) << ": Created Luggage\n";
                break;
        }
    }

    cout << "\n=== Checking Polymorphic Behavior ===\n";
    
 
    for (int i = 0; i < 10; i++) {
        cout << "Coach " << (i + 1) << " -> ";
       
        cout << train[i]->notice() << "\n";
    }

 
    for (int i = 0; i < 10; i++) {
        delete train[i];
    }

    return 0;
}
