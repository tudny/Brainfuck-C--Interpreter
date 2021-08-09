/** @file
 * Brainf*ck interpreter module implementation.
 * @author Aleksander "Tudny" Tudruj
 * @date 24/02/2020
 * */

#include "brainfuck.h"
#include <string>
#include <iostream>

namespace brainfuck {

    /**
     * Prints whole table of ints.
     * @param[in] tab : pointer to a table with ints
     * @param[in] _size : length of printed table
     * */
    void print_data(const int* const tab, const int _size) {
        for (int i = 0; i < _size; i++)
            std::cout << i << " ";

        std::cout << "\n";

        for (int i = 0; i < _size; i++)
            std::cout << tab[i] << " ";

        std::cout << "\n";
    }

    /**
     * Checks the correction of the brackets.
     * Function checks the correction of the brackets in the Brainf*ck code.
     * If any bracket is missing or the bracketing is incorrect the function
     * returns false otherwise true.
     * @param[in] input : checked code
     * @return if the bracketing is correct
     * */
    bool bracket_check(const std::string &input) {
        int cnt = 0;
        for (char c : input) {
            if (cnt < 0) return false;
            else if (c == '[') cnt++;
            else if (c == ']') cnt--;
        }
        return cnt == 0;
    }

    void interpret(const std::string &input, bool debug) {
        if (!bracket_check(input))
            throw bad_bracketing();

        signed _size = BUFFER_SIZE;
        int* tab = new int[_size];
        std::fill(tab, tab + _size, 0);
        int* p = tab;

        for (int i = 0; i < input.size(); i++) {
            char c = input[i];

            if (debug)
                print_data(tab, _size);

            if (c == '+') {
                (*p)++;
            } else if(c == '-') {
                (*p)--;
            } else if(c == '>') {
                p++;
            } else if(c == '<') {
                p--;
            } else if(c == '.') {
                std::cout << (char)(*p);
            } else if(c == ',') {
                std::cin >> (*p);
            } else if(c == '[') {
                if (*p == 0) {
                    int cnt = 0;
                    i++;
                    while (i < input.length()) {
                        if (input[i] == ']' && cnt == 0) break;
                        if (input[i] == '[') cnt++;
                        if (input[i] == ']') cnt--;
                        i++;
                    }
                }
            } else if(c == ']') {
                if ((*p) != 0) {
                    int cnt = 0;
                    i--;
                    while (i >= 0) {
                        if (input[i] == '[' && cnt == 0) break;
                        if (input[i] == ']') cnt++;
                        if (input[i] == '[') cnt--;
                        i--;
                    }
                }
            } else if(c == ' ') {
                continue;
            } else {
                throw bad_character();
            }
        }
    }

    const char *
    bad_bracketing::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return "Bad bracketing!";
    }

    const char *
    bad_character::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
        return "Bad character!";
    }
}
