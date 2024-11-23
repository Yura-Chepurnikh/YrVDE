#ifndef LOGIC_GATE_FACTORY_H
#define LOGIC_GATE_FACTORY_H

#include <iostream>
#include <string>
#include <type_traits>
#include "../LogicGate/logicgate.h"
#include "../LogicGate/and_gate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/xnor_gate.h"

// template <typename T, typename = void>
// struct LogicGateFactory;

class LogicGateFactory {
public:
    static LogicGate* CreateLogicGate(const std::string& gate_type);
};

#endif // LOGIC_GATE_FACTORY_H
