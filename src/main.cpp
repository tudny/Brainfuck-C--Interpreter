#include <iostream>
#include "brainfuck.h"

int main() {

    try {
        brainfuck::interpret(
                "+++[>+++[>+++[>+++<-]<-]<-]>>> [>>+>+<<<-]>>>[<<<+>>>-]"
                "<<+>[<->[>++++++++++<[->-[>+>>]>[+[-<+>]>+>>]<<<<<]>[-]+++++"
                "+++[<++++++>-]>[<<+>>-]>[<<+>>-]<<]>]<[->>++++++++"
                "[<++++++>-]]<[.[-]<]<");

        std::cout << "\n";
    } catch (brainfuck::bad_bracketing &e) {
        std::cerr << e.what() << "\n";
    } catch (brainfuck::bad_character &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
