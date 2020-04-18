#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include<iostream>
using namespace std;

class VigenereCipher
{
private:
	char plainText[500];
	char encipherText[500];
	char key[100];
public:
	void setPlainText(char *pt);
	void setEncipherText(char *et);
	void setKey(char *k);
	const char * getPlainText();
	const char * getEncipherText();
	const char * getKey();
	void encipher();
	void decipher();
};

#endif