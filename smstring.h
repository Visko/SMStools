#ifndef SMSTRING_H
#define SMSTRING_H

#include <QObject>
#include <QString>

typedef unsigned char byte;

class SMString
{
public:
    SMString();
    QString toBit7();
    QString toASCII();
    QString toUCS();
    QString toUTF8();
    QString toQString();
    void fromBit7(QString&);
    void fromASCII(QString&);
    void fromUCS(QString&);
    void fromUTF8(QString&);
    void fromQString(QString&);
private:
    QString* myString;
    void convert_7_to_8_bit(byte* output,
                            byte* input,
                            unsigned int len_of_8bit_arr,
                            unsigned int num_of_chars);
    void convert_8_to_7_bit(byte* output,
                            byte* input,
                            unsigned int len_of_7bit_arr);
};

#define UPPER_1BITS_MASK__C  0x80
#define UPPER_2BITS_MASK__C  0xC0
#define UPPER_3BITS_MASK__C  0xE0
#define UPPER_4BITS_MASK__C  0xF0
#define UPPER_5BITS_MASK__C  0xF8
#define UPPER_6BITS_MASK__C  0xFC
#define UPPER_7BITS_MASK__C  0xFE

#define LOWER_1BITS_MASK__C  0x01
#define LOWER_2BITS_MASK__C  0x03
#define LOWER_3BITS_MASK__C  0x07
#define LOWER_4BITS_MASK__C  0x0F
#define LOWER_5BITS_MASK__C  0x1F
#define LOWER_6BITS_MASK__C  0x3F
#define LOWER_7BITS_MASK__C  0x7F

#define AUPPER_1BITS_MASK__C  0x40
#define AUPPER_2BITS_MASK__C  0x60
#define AUPPER_3BITS_MASK__C  0x70
#define AUPPER_4BITS_MASK__C  0x78
#define AUPPER_5BITS_MASK__C  0x7C
#define AUPPER_6BITS_MASK__C  0x7E

#endif // SMSTRING_H
