// StackMachine.cpp -- implementation file for the stack machine
// Thomas Padron-McCarthy (Thomas.Padron-McCarthy@oru.se) 2003, 2012, 2018

#include <iostream>
#include <vector>
// #include <stack> -- (Perhaps surprisingly) not.
#include <map>
#include <string>
#include <sstream>

#include "StackMachine.h"

Instruction::Instruction(enum StackOp op, int argument)
    : the_op(op), the_argument(argument)
{
    if (op_info[op].nr_args != 1) {
        std::stringstream s;
        s << "Tried to create " << op_info[op].name
          << " instruction with an argument (" << argument << ").";
        throw Exception(s.str());
    }
}

Instruction::Instruction(enum StackOp op)
    : the_op(op), the_argument(0)
{
    if (op_info[op].nr_args != 0) {
        std::stringstream s;
        s << "Tried to create " << op_info[op].name
          << " instruction without an argument.";
        throw Exception(s.str());
    }
}

std::ostream& operator<< (std::ostream& o, const Instruction& i) {
    o << i.op_info[i.op()].name;
    if (i.op_info[i.op()].nr_args == 1)
        o << "," << i.argument();
    return o;
}

// Warning! If you change this, you must change StackMachine.h too!
Instruction::OpInfo Instruction::op_info[] = {
    { push, "push", 1 },
    { rvalue, "rvalue", 1 },
    { lvalue, "lvalue", 1 },
    { pop, "pop", 0 },
    { assign, "assign", 0 },
    { copy, "copy", 0 },
    { plus, "plus", 0 },
    { minus, "minus", 0 },
    { times, "times",  0 },
    { divide, "divide", 0 },
    { modulo, "modulo", 0 },
    { eq, "eq", 0 },
    { ne, "ne", 0 },
    { lt, "lt", 0 },
    { gt, "gt", 0 },
    { le, "le", 0 },
    { ge, "ge", 0 },
    { stackop_or, "or", 0 },
    { stackop_and, "and", 0 },
    { stackop_not, "not", 0 },
    { stackop_read, "read", 0 },
    { stackop_write, "write", 0 },
    { label, "label", 1 },
    { jump, "jump", 1 },
    { gofalse, "gofalse", 1 },
    { gotrue, "gotrue", 1 },
    { halt, "halt", 0 }
};

void StackMachine::stackpush(int x) {
    stack.push_back(x);
}

int StackMachine::stackpop() {
    if (stack.empty())
        throw Exception("Program tried to pop from empty stack.");
    int result = stack.back();
    stack.pop_back();
    return result;
}

void StackMachine::internal_run() {
    pc = 0;
    stack.clear();
    variables.clear();
    internal_cont();
}

void StackMachine::internal_cont() {
    running = 1;
    while (running) {
        internal_step();
    }
}

void StackMachine::internal_step() {
    int r, l;
    if (pc >= program.size()) {
        std::stringstream s;
        s << "PC " << pc << " outside program (0.." << program.size() - 1 << ").";
        throw Exception(s.str());
    }
    int op = program[pc].op();
    int arg = program[pc].argument();
    if (trace) {
        outstream << "Trace: " << pc << ": ";
        outstream << program[pc];
        outstream << std::endl;
    }
    switch (op) {
    case push:
        stackpush(arg);
        pc++;
        break;
    case rvalue:
        if (variables.find(arg) == variables.end()) {
            std::stringstream s;
            s << "Program tried to get value of unset variable (number " << arg << ").";
            throw Exception(s.str());
        }
        stackpush(variables[arg]);
        pc++;
        break;
    case lvalue:
        stackpush(arg);
        pc++;
        break;
    case pop:
        stackpop();
        pc++;
        break;
    case assign:
        r = stackpop();
        l = stackpop();
        variables[l] = r;
        pc++;
        break;
    case copy:
        r = stackpop();
        stackpush(r);
        stackpush(r);
        pc++;
        break;
    case plus:
        r = stackpop();
        l = stackpop();
        stackpush(l + r);
        pc++;
        break;
    case minus:
        r = stackpop();
        l = stackpop();
        stackpush(l - r);
        pc++;
        break;
    case times:
        r = stackpop();
        l = stackpop();
        stackpush(l * r);
        pc++;
        break;
    case divide:
        r = stackpop();
        l = stackpop();
        if (r == 0) {
            std::stringstream s;
            s << "Program tried to calculate " << l << " / " << r << ".";
            throw Exception(s.str());
        }
        stackpush(l / r);
        pc++;
        break;
    case modulo:
        r = stackpop();
        l = stackpop();
        if (r == 0) {
            std::stringstream s;
            s << "Program tried to calculate " << l << " % " << r << ".";
            throw Exception(s.str());
        }
        stackpush(l % r);
        pc++;
        break;
    case eq:
        r = stackpop();
        l = stackpop();
        stackpush(l == r);
        pc++;
        break;
    case ne:
        r = stackpop();
        l = stackpop();
        stackpush(l != r);
        pc++;
        break;
    case lt:
        r = stackpop();
        l = stackpop();
        stackpush(l < r);
        pc++;
        break;
    case gt:
        r = stackpop();
        l = stackpop();
        stackpush(l > r);
        pc++;
        break;
    case le:
        r = stackpop();
        l = stackpop();
        stackpush(l <= r);
        pc++;
        break;
    case ge:
        r = stackpop();
        l = stackpop();
        stackpush(l >= r);
        pc++;
        break;
    case stackop_or:
        r = stackpop();
        l = stackpop();
        stackpush(l | r);
        pc++;
        break;
    case stackop_and:
        r = stackpop();
        l = stackpop();
        stackpush(l & r);
        pc++;
        break;
    case stackop_not:
        r = stackpop();
        stackpush(! r);
        pc++;
        break;
    case stackop_read:
        std::cout << "Enter an integer: ";
        int new_value;
        std::cin >> new_value;
        stackpush(new_value);
        pc++;
        break;
    case stackop_write:
        r = stackpop();
        std::cout << "Value: " << r << "\n";
        pc++;
        break;
    case label:
        // A nop ("no operation")
        pc++;
        break;
    case jump:
        if (labels.find(arg) == labels.end()) {
            std::stringstream s;
            s << "Program tried to jump to nonexistent label (number " << arg << ").";
            throw Exception(s.str());
        }
        pc = labels[arg]; // We know this is inside the program
        break;
    case gofalse:
        r = stackpop();
        if (!r) {
            if (labels.find(arg) == labels.end()) {
                std::stringstream s;
                s << "Program tried to jump to nonexistent label (number " << arg << ").";
                throw Exception(s.str());
            }
            pc = labels[arg]; // We know this is inside the program
        }
        else
            pc++;
        break;
    case gotrue:
        r = stackpop();
        if (r) {
            if (labels.find(arg) == labels.end()) {
                std::stringstream s;
                s << "Program tried to jump to nonexistent label (number " << arg << ").";
                throw Exception(s.str());
            }
            pc = labels[arg]; // We know this is inside the program
        }
        else
            pc++;
        break;
    case halt:
        pc++;
        running = 0;
        if (trace)
            outstream << "Program halted." << std::endl;
        break;
    default:
        std::stringstream s;
        s << "Illegal instruction in program (instruction "
          << op << " at position " << pc << ").";
        throw Exception(s.str());
        break;
    } // switch
} // internal_step

StackMachine::StackMachine(std::ostream& os)
    : pc(0), running(0), trace(0), outstream(os)
{ }

void StackMachine::append(const Instruction& i) {
    if (i.op() == label) {
        if (labels.find(i.argument()) != labels.end()) {
            std::stringstream s;
            s << "Tried to re-define label " << i.argument() << ".";
            throw Exception(s.str());
        }
        labels[i.argument()] = program.size();
    }
    program.push_back(i);
}

void StackMachine::showstate() const {
    outstream << "State of the stack machine:\n";
    outstream << "  pc = " << pc;
    if (pc >= program.size())
        outstream << " (last program instruction is at " << program.size() - 1 << ")";
    else {
        outstream << " (instruction: ";
        outstream << program[pc];
        outstream << ")";
    }
    outstream << "\n";

    outstream << "  trace = " << trace << "\n";

    outstream << "  Stack (size " << stack.size() << ")\n";
    if (!stack.empty()) {
        outstream << "    ";
        for (std::vector<int>::const_iterator p = stack.begin();
             p < stack.end();
             ++p)
            outstream << *p << " ";
        outstream << "\n";
    }

    outstream << "  Variables (" << variables.size() <<  " " <<
        (variables.size() == 1 ? "variable" : "variables") << ")\n";
    if (!variables.empty()) {
        outstream << "    ";
        for (std::map<int, int, std::less<int> >::const_iterator p = variables.begin();
             p != variables.end();
             ++p)
            outstream << (*p).first << "=" << (*p).second << " ";
        outstream << "\n";
    }

    outstream << std::endl;
} // showstate

void StackMachine::list_program() const {
    outstream << "Program listing (length " << program.size() << ")\n";
    if (!program.empty()) {
        unsigned int pos = 0;
        for (std::vector<Instruction>::const_iterator p = program.begin();
             p < program.end();
             ++p) {
            outstream << "  " << pos << ": ";
            outstream << *p;
            if (p->op() == label) {
                for (unsigned int cfp = 0; cfp < program.size(); ++cfp) {
                    enum StackOp cfp_op = program[cfp].op();
                    if (   program[cfp].argument() == p->argument()
                        && (cfp_op == jump || cfp_op == gofalse || cfp_op == gotrue)) {
                        outstream << " (target from " << cfp << ")";
                    }
                }
            }
            if (pos == pc)
                outstream << " <-- PC";
            outstream << "\n";
            ++pos;
        }
    }
    outstream << std::endl;
} // showsprogram

void StackMachine::run() {
    if (trace)
        outstream << "run(): Starting execution at position 0..." << std::endl;
    internal_run();
}

void StackMachine::cont() {
    if (trace)
        outstream << "cont(): Continuing execution at position "
                  << pc << "..." << std::endl;
    internal_cont();
}

void StackMachine::single_step() {
    if (trace)
        outstream << "single_step(): Stepping one instruction at position "
                  << pc << "..." << std::endl;
    internal_step();
}

void StackMachine::set_trace(int t) {
    trace = t;
}
