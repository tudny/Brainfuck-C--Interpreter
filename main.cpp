#include <iostream>
#include "brainfuck.h"

int main() {

    try {
        std::cout << "Effect {" << "\n";
        brainfuck::interpret("+++[>+++[>+++[>+++<-]<-]<-]>>> [>>+>+<<<-]>>>[<<<+>>>-]<<+>[<->[>++++++++++<[->-[>+>>]>[+[-<+>]>+>>]<<<<<]>[-]++++++++[<++++++>-]>[<<+>>-]>[<<+>>-]<<]>]<[->>++++++++[<++++++>-]]<[.[-]<]<");
        std::cout << "\n} End" << "\n";
    } catch (std::runtime_error& e){
        std::cerr << e.what() << "\n";
    }

    return 0;
}
