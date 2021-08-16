#ifndef FLETCHER16_H
#define FLETCHER16_H

#include <stdint.h> // types uint8_t and uint16_t.


// *Fletcher16* class has two checksum bytes to be used to verify the integrity of data.
class Fletcher16 {
    public:
        // Default constructor
        //
        // Initializes the checksum bytes to 0.
        Fletcher16();

        // Getter for _C0
        uint8_t get_first_checksum() const;

        // Getter for _C1
        uint8_t get_second_checksum() const;

        // Resets checksums to 0
        void reset_checksum();

        // Recalculates the cheksum bytes with the value of the byte inserted
        //
        // _C0 = (_C0 + data) % 255;
        // _C1 = (_C0 + _C1) % 255;
        void update_checksum_byte(uint8_t data);

        // Recalculates the cheksum bytes with the value of the bytes inserted
        //
        // for each byte, makes the previous calculation in update_checksum_byte(uint8_t) .
        void update_checksum_message(uint8_t *data, unsigned int num_bytes);

    private:
        uint8_t _C0;
        uint8_t _C1;
};

#endif