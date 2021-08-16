#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream> // Communication with the user - Cin - Cout
#include <stdlib.h> // Memory allocation - malloc, calloc, realloc, free
#include <stdint.h> // types uint8_t and uint16_t.

#include "Fletcher16.h"

// The *Message* class stores a sequence of data and verifies its integrity.
//
// The integrity verification is made through the communication with *Fletcher16* class.
//@see Fletcher16.h
class Message {
    public:
        // Default constructor
        Message();

        // Two parameters constructor
        //
        // This overloaded constructor makes it easier to initialize and verify the integrity of the message.
        // @param data is the message desired to initialize.
        // @param _size is the number of bytes in the message.
        Message(uint8_t* data, unsigned int _size);

        // Default destructor
        ~Message();

        // Number of bytes without the checksum bytes
        //
        //@returns the number of bytes in the stored sequence without the two checksum bytes.
        unsigned int num_bytes() const;

        // Number of bytes with checksum bytes
        //
        //@returns the number of bytes in the stored sequence with the two checksum bytes.
        unsigned int total_num_bytes() const;

        // Deallocate the memory of the sequence stored.
        void clear_bytes();

        // Getter function for the sequence with the checksum bytes.
        //
        // @returns the sequence stored appended with the two checksum bytes.
        uint8_t* get_sequence();

        // Inserts the byte parameter in the sequence stored.
        //
        // @param byte is the byte to be stored.
        void append_byte(uint8_t byte);

        // Verification of the integrity of data.
        //
        // @returns the two checksum bytes in a 16 bits word.
        uint16_t checksum_value() const;

        // Getter function for the sequence without the checksum bytes.
        //
        // Simply copies the sequence stored without the checksum bytes.
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