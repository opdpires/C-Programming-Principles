#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Fletcher16.h"

class Message {
    public:
        Message();
        Message(uint8_t* data, unsigned int _size);
        ~Message();
        unsigned int num_bytes() const;
        unsigned int total_num_bytes() const;
        void clear_bytes();
        uint8_t* get_sequence();
        void append_byte(uint8_t byte);
        uint16_t checksum_value() const;
        uint8_t* get_sequence_copy() const;
        void print_message() const;
        void print_checksum() const;
        void print_checksum_value() const;

    private:
        uint8_t *sequence;
        Fletcher16 checksum;
        unsigned int size;
};

#endif