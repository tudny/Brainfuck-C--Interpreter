//
// Created by aleks on 2/24/2020.
//

#include "brainfuck.h"
#include <string>
#include <iostream>

namespace brainfuck {

    void print_data(int* tab, int __size){
        for(int i = 0; i < __size; i++) {
            std::cout << i << " ";
        }

        std::cout << "\n";

        for(int i = 0; i < __size; i++){
            std::cout << tab[i] << " ";
        }
        std::cout << "\n";
    }

    bool bracket_check(const std::string &input){
        int cnt = 0;
        for(char c : input){
            if(cnt < 0) return false;
            if(c == '[') cnt++;
            if(c == ']') cnt--;
        }
        return (cnt == 0);
    }

    void interpret(const std::string &input, bool debug) {
        signed __size = (1u << 5u);
        int* tab = new int[__size];
        std::fill(tab, tab + __size, 0);
        int* p = tab;

        if(!bracket_check(input)){
            throw std::runtime_error("Bracket match error");
        }

        for(int i = 0 ; i < input.size(); i++){
            char c = input[i];

            if(debug) print_data(tab, __size);

            if(c == '+'){
                (*p)++;
            } else if(c == '-'){
                (*p)--;
            } else if(c == '>'){
                p++;
            } else if(c == '<'){
                p--;
            } else if(c == '.'){
                std::cout << (char)(*p) << "";
            } else if(c == ','){
                std::cin >> (*p);
            } else if(c == '['){
                if((*p) == 0){
                    int cnt = 0;
                    i++;
                    while(i < input.length()){
                        if(input[i] == ']' && cnt == 0) break;
                        if(input[i] == '[') cnt++;
                        if(input[i] == ']') cnt--;
                        i++;
                    }
                }
            } else if(c == ']'){
                if((*p) != 0){
                    int cnt = 0;
                    i--;
                    while(i >= 0){
                        if(input[i] == '[' && cnt == 0) break;
                        if(input[i] == ']') cnt++;
                        if(input[i] == '[') cnt--;
                        i--;
                    }
                }
            } else if(c == ' '){
                continue;
            } else {
                throw std::runtime_error("Bad character");
            }
        }
    }
}
