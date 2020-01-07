// stacktest.cpp -- a small program to test the stack machine
// Thomas Padron-McCarthy (Thomas.Padron-McCarthy@oru.se) 2003, 2012

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

#include "StackMachine.h"

int main() {
    StackMachine sm;
    try {
        sm.append(Instruction(push, 10));
        sm.append(Instruction(lvalue, 17));
        sm.append(Instruction(push, 4711));
        sm.append(Instruction(assign));
        sm.append(Instruction(push, 100));
        sm.append(Instruction(gofalse, 1));
        // sm.append(Instruction(pop, 100));
        sm.append(Instruction(pop));
        sm.append(Instruction(push, 20));
        sm.append(Instruction(rvalue, 17));
        sm.append(Instruction(rvalue, 17));
        sm.append(Instruction(rvalue, 17));
        // sm.append(Instruction(rvalue, 18));
        sm.append(Instruction(push, 30));
        sm.append(Instruction(push, 10000));
        sm.append(Instruction(plus));
        sm.append(Instruction(plus));
        sm.append(Instruction(label, 1));
        sm.append(Instruction(label, 2));

        sm.append(Instruction(push, 10));
        sm.append(Instruction(label, 999));
        sm.append(Instruction(push, 1));
        sm.append(Instruction(minus));
        sm.append(Instruction(copy));
        sm.append(Instruction(gotrue, 999));

        sm.append(Instruction(label, 1000));
        sm.append(Instruction(push, 1));
        sm.append(Instruction(push, 2));
        sm.append(Instruction(push, 3));
        sm.append(Instruction(push, 4));
        sm.append(Instruction(push, 5));
        sm.append(Instruction(push, 6));
        sm.append(Instruction(plus));
        sm.append(Instruction(minus));
        sm.append(Instruction(times));
        // sm.append(Instruction(push, 0));
        sm.append(Instruction(push, 47));
        sm.append(Instruction(push, 48));
        sm.append(Instruction(push, 49));
        sm.append(Instruction(assign));
        sm.append(Instruction(divide));
        sm.append(Instruction(push, 50));
        sm.append(Instruction(modulo));
        sm.append(Instruction(halt));

        //sm.showstate();
        //sm.list_program();
        //sm.set_trace(1);
        sm.run();
        //sm.showstate();
    }
    catch(Exception& e) {
        std::cout << "*** Exception caught: " << e.message() << std::endl;
        sm.showstate();
        sm.list_program();
    }
    catch(...) {
        std::cout << "Unknown exception." << std::endl;
    }

    StackMachine sm2;

    try {
        sm2.append(Instruction(push, 10));
        sm2.append(Instruction(plus));
        std::cout << "--- Now, a deliberate error should be caught:" << std::endl;
        sm2.run();
    }
    catch(Exception& e) {
        std::cout << "*** Exception caught: " << e.message() << std::endl;
        sm2.showstate();
        sm2.list_program();
    }
    catch(...) {
        std::cout << "Unknown exception." << std::endl;
    }

    StackMachine sm3;

    try {
        sm3.append(Instruction(lvalue, 13));
        sm3.append(Instruction(stackop_read));
        sm3.append(Instruction(assign));
        sm3.append(Instruction(lvalue, 22));
        sm3.append(Instruction(stackop_read));
        sm3.append(Instruction(assign));
        sm3.append(Instruction(rvalue, 13));
        sm3.append(Instruction(rvalue, 22));
        sm3.append(Instruction(plus));
        sm3.append(Instruction(stackop_write));
        sm3.append(Instruction(halt));

        sm3.list_program();
        sm3.run();
    }
    catch(Exception& e) {
        std::cout << "*** Exception caught: " << e.message() << std::endl;
        sm3.showstate();
        sm3.list_program();
    }
    catch(...) {
        std::cout << "Unknown exception." << std::endl;
    }

    return 0;
}
