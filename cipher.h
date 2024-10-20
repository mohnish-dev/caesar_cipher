#pragma once

#ifndef Cipher_H
#define Cipher_H
using namespace std;
#include <string>
#include <iostream>

class Cipher
{
public:
    Cipher();
    Cipher(string text);
    void encode(int shift);
    void decode(int shift);
    string getText() const;
    void setText(string text);

private:
    string text;
    static const int ALPHABET_SIZE = 26;
};

// Constructor to initialize text to an empty string
Cipher::Cipher() : text("") {}

// Constructor to initialize with a given string
Cipher::Cipher(string text) : text(text) {}

// Encode function with support for negative shifts
void Cipher::encode(int shift) {
    shift = shift % ALPHABET_SIZE; // Normalize the shift
    for (int i = 0; i < text.size(); ++i) {
        char encoded_char = text[i];
        if (isalpha(text[i])) {
            if (islower(text[i])) {
                encoded_char = 'a' + ((text[i] - 'a' + shift + ALPHABET_SIZE) % ALPHABET_SIZE);
            }
            else if (isupper(text[i])) {
                encoded_char = 'A' + ((text[i] - 'A' + shift + ALPHABET_SIZE) % ALPHABET_SIZE);
            }
        }
        text[i] = encoded_char;
    }
}

// Decode function with support for negative shifts
void Cipher::decode(int shift) {
    encode(-shift); // Decoding is equivalent to encoding with a negative shift
}

// Getter for the text
string Cipher::getText() const {
    return text;
}

// Setter for the text
void Cipher::setText(string my_text) {
    text = my_text;
}

#endif // Cipher_H
