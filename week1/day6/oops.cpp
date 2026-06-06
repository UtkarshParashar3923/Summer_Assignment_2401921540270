#include <iostream>
#include <string>

class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
    virtual ~LibraryUser() = default; 
};

class KidUsers : public LibraryUser {
public:
    int age;
    std::string bookType;

    void registerAccount() override {
        if (age < 12) {
            std::cout << "You have successfully registered under a Kids Account\n";
        } else {
            std::cout << "Sorry, Age must be less than 12 to register as a kid\n";
        }
    }

    void requestBook() override {
        if (bookType == "Kids") {
            std::cout << "Book Issued successfully, please return the book within 10 days\n";
        } else {
            std::cout << "Oops, you are allowed to take only kids books\n";
        }
    }
};


// 2 & 3. Create "AdultUser" class with required instance variables

class AdultUser : public LibraryUser {
public:
    int age;
    std::string bookType;

    // 5. Methods in AdultUser performing the required logic
    void registerAccount() override {
        if (age > 12) {
            std::cout << "You have successfully registered under an Adult Account\n";
        } else {
            std::cout << "Sorry, Age must be greater than 12 to register as an adult\n";
        }
    }

    void requestBook() override {
        if (bookType == "Fiction") {
            std::cout << "Book Issued successfully, please return the book within 7 days\n";
        } else {
            std::cout << "Oops, you are allowed to take only adult Fiction books\n";
        }
    }
};


// 6. Main function implementing Test Case #1 and Test Case #2

int main() {
    // --- Test Case #1: KidUsers ---
    std::cout << "--- Test Case #1: Kid Users ---\n";
    KidUsers kid;

    // Set the age as specified in the table and invoke registerAccount
    kid.age = 10;
    kid.registerAccount();

    kid.age = 18;
    kid.registerAccount();

    kid.bookType = "Kids";
    kid.requestBook();

    kid.bookType = "Fiction";
    kid.requestBook();

    std::cout << "\n"; 
    
    std::cout << "--- Test Case #2: Adult Users ---\n";
    AdultUser adult;

    adult.age = 5;
    adult.registerAccount();

    adult.age = 23;
    adult.registerAccount();

    adult.bookType = "Kids";
    adult.requestBook();

    adult.bookType = "Fiction";
    adult.requestBook();

    return 0;
}
