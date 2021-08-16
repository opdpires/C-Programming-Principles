#ifndef FLETCHER16_H
#define FLETCHER16_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class Fletcher16 {
    public:
        Fletcher16();
        uint8_t get_first_checksum() const;
        uint8_t get_second_checksum() const;
        void reset_checksum();
        void update_checksum_byte(uint8_t data);
        void update_checksum_message(uint8_t *data, unsigned int num_bytes);

    private:
        uint8_t _C0;
        uint8_t _C1;
};

#endif