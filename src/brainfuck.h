/** @file
 * Brainf*ck interpreter module.
 * @author Aleksander "Tudny" Tudruj
 * @date 24/02/2020
 * */

#ifndef BF_BRAINFUCK_H
#define BF_BRAINFUCK_H

#include <string>

namespace brainfuck {

    const int BUFFER_SIZE = 1u << 5u; ///< Default size of a buffer.

    /**
     * Exception thrown when the bracketing of the code is wrong.
     * */
    class bad_bracketing : public std::exception {
    public:
        const char *
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    };

    /**
     * Exception thrown when there is a wrong character in the code.
     * */
    class bad_character : public std::exception {
    public:
        const char *
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    };

    /**
     * Function interpreting Brainf*ck code.
     * Brainf*ck code is being interpreted and all the results are being
     * printed to std::out.
     * @param[in] input : pointer to the string with Brainf*ck code
     * @param[in] debug : flag enabling printing the whole Brainf*ck's table
     * @throws brainfuck::bad_bracketing when the bracketing is incorrect
     * @throws brainfuck::bad_character when there is one
     * */
    void interpret(const std::string &input, bool debug = false);
}

#endif //BF_BRAINFUCK_H
