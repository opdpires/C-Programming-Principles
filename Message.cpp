#include "Message.h"

Message::Message(){
    sequence = nullptr;
    size = 0;
}

Message::Message(uint8_t* data, unsigned int _size){
    size = _size;
    sequence = (uint8_t*) calloc (_size, sizeof(uint8_t));
    for (int i = 0; i < _size; i++){
        sequence[i] = data[i];
    }
    checksum.update_checksum_message(data, _size);
}

Message::~Message(){
    free(sequence);
}

unsigned int Message::num_bytes() const{
    return size;
}

unsigned int Message::total_num_bytes() const{
    return (size + 2);
}

void Message::clear_bytes(){
    free(sequence);
}

uint8_t* Message::get_sequence(){
    uint8_t* mensagem_completa;
    mensagem_completa = (uint8_t*) malloc((size+2)*sizeof(uint8_t));
    for(int i = 0; i < size; i++){
        mensagem_completa[i] = sequence[i];
    }
    mensagem_completa[size] = checksum.get_first_checksum();
    mensagem_completa[size+1] = checksum.get_second_checksum();
    return mensagem_completa;
}

void Message::append_byte(uint8_t byte){
    size++;
    sequence = (uint8_t*) realloc(sequence, size*sizeof(uint8_t));
    sequence[size-1] = byte;
    checksum.update_checksum_byte(byte);
}

uint16_t Message::checksum_value() const{
    uint16_t C0 = checksum.get_first_checksum();
    uint16_t C1 = checksum.get_second_checksum();
    return ((C1 << 8) | C0);
}

uint8_t* Message::get_sequence_copy() const{
    uint8_t* mensagem;
    mensagem = (uint8_t*) malloc((size)*sizeof(uint8_t));
    for(int i = 0; i < size; i++){
        mensagem[i] = sequence[i];
    }
    return mensagem;
}

void Message::print_message() const{
    for(int i = 0; i < size; i++){
        std::cout << (int) sequence[i] << " ";
    }
    std::cout << std::endl;
}

void Message::print_checksum() const{
    std::cout << "C_0: " << (int) checksum.get_first_checksum() << std::endl;
    std::cout << "C_1: " << (int) checksum.get_second_checksum() << std::endl;
}

void Message::print_checksum_value() const{
    std::cout << "checksum value: " << (int) checksum_value() << std::endl;
}