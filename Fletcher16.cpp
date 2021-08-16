#include "Fletcher16.h"

Fletcher16::Fletcher16(){
    _C0 = 0;
    _C1 = 0;
}

uint8_t Fletcher16::get_first_checksum() const{
    return _C0;
}

uint8_t Fletcher16::get_second_checksum() const{
    return _C1;
}

void Fletcher16::reset_checksum(){
    _C0 = 0;
    _C1 = 0;
}

void Fletcher16::update_checksum_byte(uint8_t data){
    _C0 = (_C0 + data) % 255;
    _C1 = (_C0 + _C1) % 255;
}

void Fletcher16::update_checksum_message(uint8_t *data, unsigned int num_bytes){
    for (unsigned int i = 0; i < num_bytes; ++i){
      _C0 = (_C0 + data[i]) % 255;
      _C1 = (_C0 + _C1) % 255;
   }
}