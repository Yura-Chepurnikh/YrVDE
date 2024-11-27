#ifndef GATE_LOGIC_H
#define GATE_LOGIC_H

#include "./businesslogic.h"
#include "../LogicGate/and_gate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/xnor_gate.h"

template<typename T, typename = void>
struct GateLogic;

template<>
struct GateLogic<ANDGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output &= inputs[i];
        return output;
    }
};

template<>
struct GateLogic<NANDGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output &= inputs[i];
        return !output;
    }
};

template<>
struct GateLogic<ORGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output |= inputs[i];
        return output;
    }
};

template<>
struct GateLogic<NORGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output |= inputs[i];
        return !output;
    }
};

template<>
struct GateLogic<BUFFERGate> {
    bool Evaluate(std::vector<bool> inputs) {
        if (inputs.size() > 1) {
            throw std::invalid_argument("Error: The number of buffer inputs cannot be more than one !!!");
        }
        return inputs[0];
    }
};

template<>
struct GateLogic<NOTGate> {
    bool Evaluate(std::vector<bool> inputs) {
        if (inputs.size() > 1) {
            throw std::invalid_argument("Error: The number of not gate inputs cannot be more than one !!!");
        }
        return inputs[0];
    }
};

template<>
struct GateLogic<XORGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output ^= inputs[i];
        return !output;
    }
};

template<>
struct GateLogic<XNORGate> {
    bool Evaluate(std::vector<bool> inputs) {
        bool output = inputs[0];
        for (size_t i = 1; i < inputs.size(); ++i)
            output ^= inputs[i];
        return !output;
    }
};



#endif // GATE_LOGIC_H
