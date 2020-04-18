#include "VigenereCipher.h"

int main()
{
	VigenereCipher vc;
	vc.setPlainText("I've been there but I didn't do it!");
	vc.setKey("penguin");
	/*vc.setPlainText("THIS IS A CODED MESSAGE.");
	vc.setKey("rose");*/
	vc.encipher();
	cout << vc.getEncipherText();
	cout << '\n';
	vc.decipher();
	cout << vc.getPlainText();
	cout << '\n';
	return 0;
}