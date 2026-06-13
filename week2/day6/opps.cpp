#include <iostream>

namespace music {
    // Interface Playable
    class Playable {
    public:
        virtual void play() = 0;
        virtual ~Playable() {}  
    };
}

namespace music {
    namespace string_inst {
        class Veena : public music::Playable {
        public:
            void play() override {
                std::cout << "Veena is playing melodic string notes." << std::endl;
            }
        };
    }
}


namespace music {
    namespace wind {
        class Saxophone : public music::Playable {
        public:
            void play() override {
                std::cout << "Saxophone is playing smooth jazz wind notes." << std::endl;
            }
        };
    }
}


namespace live {
    void runTest() {
      
        music::string_inst::Veena myVeena;
        std::cout << "--- Testing Veena ---" << std::endl;
        myVeena.play();

       
        music::wind::Saxophone mySaxophone;
        std::cout << "\n--- Testing Saxophone ---" << std::endl;
        mySaxophone.play();

        std::cout << "\n--- Testing Polymorphism (Playable Interface Variable) ---" << std::endl;
        
        music::Playable* interfaceVariable;

    
        interfaceVariable = &myVeena;
        interfaceVariable->play();

       
        interfaceVariable = &mySaxophone;
        interfaceVariable->play();
    }
}


int main() {
    live::runTest();
    return 0;
}
