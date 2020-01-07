// StackMachine.h -- interface file for the stack machine
// Thomas Padron-McCarthy (Thomas.Padron-McCarthy@oru.se) 2003, 2012, 2018
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

class Exception {
 private:
    std::string the_message;
 public:
 Exception(const std::string& m) : the_message(m) { }
    const std::string& message() const { return the_message; }
};

// Stack operations according to ASU-86 pp 65-66
// Warning! If you change this, you must change StackMachine.cpp too!
enum StackOp {
    push,         // Push a number
    rvalue,       // Push the contents of a variable
    lvalue,       // Push a reference to a variable
    pop,
    assign,
    copy,
    plus, minus, times, divide, modulo,
    eq, ne, lt, gt, le, ge, // ==, !=, <, >, <=, >=
    stackop_or, stackop_and, stackop_not, // |, &, !
    stackop_read, stackop_write,
    label,        // Realistically, this shouldn't really be an instruction
    jump,
    gofalse,
    gotrue,
    halt
};

class Instruction {
 private:
    enum StackOp the_op;
    int the_argument;

    struct OpInfo {
        enum StackOp op;
        std::string name;
        int nr_args;
    };

    static OpInfo op_info[];

 public:
    Instruction(enum StackOp op, int argument);
    Instruction(enum StackOp op);
    enum StackOp op() const { return the_op; }
    int argument() const { return the_argument; }

    friend std::ostream& operator<< (std::ostream& o, const Instruction& i);
};

class StackMachine {
 private:
    std::vector<int> stack; // Not std::stack, if we want to print it
    std::vector<Instruction> program;
    std::map<int, int, std::less<int> > labels;
    std::map<int, int, std::less<int> > variables;
    unsigned int pc;
    int running;
    int trace;
    std::ostream& outstream;

    void stackpush(int x);
    int stackpop();
    void internal_run();
    void internal_cont();
    void internal_step();

 public:
    StackMachine(std::ostream& os = std::cout);
    void append(const Instruction& i);
    void showstate() const;
    void list_program() const;
    void run();
    void cont();
    void single_step();
    void set_trace(int t);
};
