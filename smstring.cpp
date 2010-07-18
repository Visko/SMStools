#include "smstring.h"
#include <iostream>
#include <cstdlib>

SMString::SMString() {
    std::cout << "SMString initialized" << endl;
    myString = NULL;
}

QString SMString::toBit7() {
    int bit7_arr_size = 0;
    bit7_arr_size = ((myString->size()+1) * 7) / 8;
    char* text = new char[bit7_arr_size];
    convert_8_to_7_bit((byte*)text,
                       (byte*)myString->toAscii().data(),
                       bit7_arr_size);
    QString *return_value = new QString(text);
    return *return_value;
}

void SMString::fromBit7(QString& bit7) {
    QByteArray bit7Bytes;
    char* asciiBytes = NULL;
    int num_of_blocks = 0;

    bit7.replace(" ", ""); //removing spaces
    bit7Bytes =  QByteArray::fromHex( bit7.toAscii() );
    num_of_blocks = (bit7Bytes.size() + 7) / 8;
    asciiBytes = new char[num_of_blocks * 8 + 1];
    convert_7_to_8_bit((byte*)asciiBytes,
                       (byte*)bit7Bytes.data(),
                       num_of_blocks * 8 + 1,
                       num_of_blocks * 8);
    if (myString != NULL) {
        delete myString;
    }
    myString = new QString(asciiBytes);
    return;
}

void SMString::convert_7_to_8_bit(byte* output,
                                  byte* input,
                                  unsigned int len_of_8bit_arr,
                                  unsigned int num_of_chars) {
        unsigned int i = 0;
        unsigned int num_of_blocks = (num_of_chars + 7) / 8;

        /* if boundary conditions fail, errorlog + return */
        if (len_of_8bit_arr < num_of_blocks * 8 + 1) {
            std::cout << "Invalid 8-bit array size!" << std::endl;
                exit(EXIT_FAILURE);
        }

        /* output should not contain trash */
        memset(output, 0, len_of_8bit_arr);

        /* block conversion for maximum effeciency. Drawback is that it iterates
         * through a block even if not needed */
        for (i = 0; i < num_of_blocks; ++i) {
                output[i*8+0] = (input[i*7+0] & LOWER_7BITS_MASK__C);
                output[i*8+1] = ((input[i*7+1] & LOWER_6BITS_MASK__C) << 1) | ((input[i*7+0] & UPPER_1BITS_MASK__C) >> 7);
                output[i*8+2] = ((input[i*7+2] & LOWER_5BITS_MASK__C) << 2)	| ((input[i*7+1] & UPPER_2BITS_MASK__C) >> 6);
                output[i*8+3] = ((input[i*7+3] & LOWER_4BITS_MASK__C) << 3)	| ((input[i*7+2] & UPPER_3BITS_MASK__C) >> 5);
                output[i*8+4] = ((input[i*7+4] & LOWER_3BITS_MASK__C) << 4)	| ((input[i*7+3] & UPPER_4BITS_MASK__C) >> 4);
                output[i*8+5] = ((input[i*7+5] & LOWER_2BITS_MASK__C) << 5)	| ((input[i*7+4] & UPPER_5BITS_MASK__C) >> 3);
                output[i*8+6] = ((input[i*7+6] & LOWER_1BITS_MASK__C) << 6)	| ((input[i*7+5] & UPPER_6BITS_MASK__C) >> 2);
                output[i*8+7] = ((input[i*7+6] & UPPER_7BITS_MASK__C) >> 1);
        }
        /* memset(output + num_of_chars, 0, len_of_8bit_arr - len_of_7bit_arr); */
}

void SMString::convert_8_to_7_bit(byte* output, byte* input, unsigned int len_of_7bit_arr) {
        unsigned int i = 0;
        unsigned int num_of_blocks = (strlen((char*) input) + 7) / 8;

        /* if boundary conditions fail, errorlog + return */
        if (len_of_7bit_arr < num_of_blocks * 7) {
            std::cout << "Invalid 7-bit array size!" << std::endl;
                exit(EXIT_FAILURE);
        }

        /* output should not contain trash */
        memset(output, 0, len_of_7bit_arr);

        for (i = 0; i < num_of_blocks; ++i) {
                output[i*7+0] = (input[i*8+0] & LOWER_7BITS_MASK__C)       | ((input[i*8+1] & LOWER_1BITS_MASK__C) << 7);
                output[i*7+1] = (input[i*8+1] & AUPPER_6BITS_MASK__C) >> 1 | ((input[i*8+2] & LOWER_2BITS_MASK__C) << 6);
                output[i*7+2] = (input[i*8+2] & AUPPER_5BITS_MASK__C) >> 2 | ((input[i*8+3] & LOWER_3BITS_MASK__C) << 5);
                output[i*7+3] = (input[i*8+3] & AUPPER_4BITS_MASK__C) >> 3 | ((input[i*8+4] & LOWER_4BITS_MASK__C) << 4);
                output[i*7+4] = (input[i*8+4] & AUPPER_3BITS_MASK__C) >> 4 | ((input[i*8+5] & LOWER_5BITS_MASK__C) << 3);
                output[i*7+5] = (input[i*8+5] & AUPPER_2BITS_MASK__C) >> 5 | ((input[i*8+6] & LOWER_6BITS_MASK__C) << 2);
                output[i*7+6] = (input[i*8+6] & AUPPER_1BITS_MASK__C) >> 6 | ((input[i*8+7] & LOWER_7BITS_MASK__C) << 1);
        }
}

QString SMString::toASCII() {
    QString myVar(*myString);
    return myVar;
}

QString SMString::toUCS() {
    QString myVar(*myString);
    return myVar;
}

QString SMString::toUTF8() {
    QString myVar(*myString);
    return myVar;
}

QString SMString::toQString() {
    return QString(*myString);
}

void SMString::fromQString(QString& inputString) {
    if (myString != NULL) {
        delete myString;
    }
    myString = new QString(inputString);
    return;
}
