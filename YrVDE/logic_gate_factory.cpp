#include "./logic_gate_factory.h"

LogicGate* LogicGateFactory::CreateLogicGate(const std::string& gate_type) {
    if (gate_type == "AND")
        return new ANDGate();

    else if (gate_type == "NAND")
        return new NANDGate();

    else if (gate_type == "OR")
        return new ORGate();

    else if (gate_type == "NOR")
        return new NORGate();

    else if (gate_type == "XOR")
        return new XORGate();

    else if (gate_type == "XNOR")
        return new XNORGate();

    else if (gate_type == "BUFFER")
        return new BUFFERGate();

    else return new NOTGate();
}

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, ANDGate>::value>>
// {
//     static LogicGate* create() {
//         return new ANDGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, NANDGate>::value>>
// {
//     static LogicGate* create() {
//         return new NANDGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, ORGate>::value>>
// {
//     static LogicGate* create() {
//         return new ORGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, NORGate>::value>>
// {
//     static LogicGate* create() {
//         return new NORGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, BUFFERGate>::value>>
// {
//     static LogicGate* create() {
//         return new BUFFERGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, NOTGate>::value>>
// {
//     static LogicGate* create() {
//         return new NOTGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, XORGate>::value>>
// {
//     static LogicGate* create() {
//         return new XORGate();
//     }
// };

// template <typename T>
// struct LogicGateFactory<T, std::enable_if_t<std::is_same<T, XNORGate>::value>>
// {
//     static LogicGate* create() {
//         return new XNORGate();
//     }
// };

