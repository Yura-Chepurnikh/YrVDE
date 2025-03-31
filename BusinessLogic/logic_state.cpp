#include "logic_state.h"

std::ostream& operator<<(std::ostream& stream, LogicState& state) {
    switch(state) {
        case LogicState::LOGIC_ZERO_STATE:
        {
            stream << "logic 0";
            break;
        }
        case LogicState::LOGIC_ONE_STATE:
        {
            stream << "logic 1";
            break;
        }
        case LogicState::HIGH_IMPEDANCE_STATE:
        {
            stream << "high impedance state";
            break;
        }
        case LogicState::UNKNOWN_STATE:
        {
            stream << "unknown state";
            break;
        }
    }
    return stream;
}
