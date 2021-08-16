#include <iostream> // Communication with the user - Cin - Cout
#include <stdint.h> // types uint8_t and uint16_t.
#include <stdlib.h> // Memory allocation - malloc, calloc, realloc, free

#include "Fletcher16.h"
#include "Message.h"

// Show data in binary
//
// this is helpfull to visualize changes in each byte, bit by bit.
void binary_print(uint8_t value);

int main(){
    unsigned short a, b, c; // Prevents having to look in ASCII.
    uint8_t byte1, byte2, byte3;
    std::cout << "insert bytes with spaces between them: ";
    std::cin >> a;
    byte1 = a;
    std::cin >> b;
    byte2 = b;
    std::cin >> c;
    byte3 = c;
    
    std::cout << "First test: inserts the first byte typed and prints the results" << std::endl;
    Message msg1;
    msg1.append_byte(byte1);
    std::cout << "First byte: ";
    msg1.print_message();
    msg1.print_checksum();
    msg1.print_checksum_value();
    std::cout << "Binary checksum value: ";
    
    uint8_t *seq0 = (uint8_t*) malloc(msg1.num_bytes()*sizeof(uint8_t));
    seq0 = msg1.get_sequence();
    binary_print(seq0[1]);
    binary_print(seq0[2]);

    uint8_t sequencia[3] = {byte1, byte2, byte3};

std::cout << "\n\nSecond test: inserts all bytes typed and prints the results" << std::endl;
    Message msg2(sequencia, 3);
    std::cout << "Bytes typed: ";
    msg2.print_message();
    msg2.print_checksum();
    msg2.print_checksum_value();

    std::cout << "\nNumber of bytes in the message (without checksum): " << msg2.num_bytes() << std::endl;
    std::cout << "Number of bytes in the message (with checksum): " << msg2.total_num_bytes();
    
    uint8_t *seq1 = (uint8_t*) malloc(msg2.num_bytes()*sizeof(uint8_t));
    uint8_t *seq2 = (uint8_t*) malloc(msg2.total_num_bytes()*sizeof(uint8_t));;
    
    
    
    seq1 = msg2.get_sequence_copy();
    
    seq2 = msg2.get_sequence();
    
    
    std::cout << "\n\nMessage without checksum:\n";
    for(int i = 0; i < msg2.num_bytes(); i++){
        binary_print(seq1[i]);
    }
    std::cout << std::endl;
    
    std::cout << "Message with checksum:\n";
    for(int i = 0; i < msg2.total_num_bytes(); i++){
        binary_print(seq2[i]);
    }
    
    free(seq1);
    free(seq2);
    
    return 0;
}

void binary_print(uint8_t value){
    for(int i = 7; i >= 0; i--) {
    uint8_t r = 0;
    r = value >> i;
      if(r & 1)
        std::cout << "1";
      else
        std::cout << "0";
    }
    std::cout << " ";
}