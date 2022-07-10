#include <SoftwareSerial.h>

class StateMachine{
public:
    void* (StateMachine::*current_state_function)() =nullptr;

};
typedef void* (StateMachine::*state_machine_state)();
class BTStateMachine: public StateMachine{

    void entry(){
        bt_serial.print("AT\r\n");
        //this->current_state_function = reinterpret_cast<state_machine_state>(check_at_ok);
        this->current_state_function = reinterpret_cast<state_machine_state>(&BTStateMachine::check_at_ok);

    }

    void check_at_ok(){
        bt_serial.print("AT\r\n");
    }

const uint8_t bt_ok = 0b00000001;
String hc05_in_buff;
SoftwareSerial& bt_serial;
String& bt_name;
String& bt_pin;
};
