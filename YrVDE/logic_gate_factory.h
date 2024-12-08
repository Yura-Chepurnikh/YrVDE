#ifndef LOGIC_GATE_FACTORY_H
#define LOGIC_GATE_FACTORY_H

#include "../LogicGate/and_gate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/xnor_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/input.h"
#include "../LogicGate/output.h"

template <typename T, typename = void>
struct LogicGateFactory;

template <>
struct LogicGateFactory<ANDGate> {
    static LogicGate* create() { return new ANDGate(); }
};

template <>
struct LogicGateFactory<NANDGate> {
    static LogicGate* create() { return new NANDGate(); }
};

template <>
struct LogicGateFactory<ORGate> {
    static LogicGate* create() { return new ORGate(); }
};

template <>
struct LogicGateFactory<NORGate> {
    static LogicGate* create() { return new NORGate(); }
};

template <>
struct LogicGateFactory<XORGate> {
    static LogicGate* create() { return new XORGate(); }
};

template <>
struct LogicGateFactory<XNORGate> {
    static LogicGate* create() { return new XNORGate(); }
};

template <>
struct LogicGateFactory<BUFFERGate> {
    static LogicGate* create() { return new BUFFERGate(); }
};

template <>
struct LogicGateFactory<NOTGate> {
    static LogicGate* create() { return new NOTGate(); }
};

template <>
struct LogicGateFactory<Input> {
    static LogicGate* create() { return new Input(); }
};

template <>
struct LogicGateFactory<Output> {
    static LogicGate* create() { return new Output(); }
};

#endif // LOGIC_GATE_FACTORY_H
