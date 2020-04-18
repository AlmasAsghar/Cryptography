#include"VigenereCipher.h"

void VigenereCipher::setPlainText(char *pt)
{
	strcpy_s(plainText, pt);
}
void VigenereCipher::setEncipherText(char *et)
{
	strcpy_s(encipherText, et);
}
void VigenereCipher::setKey(char *k)
{
	strcpy_s(key, k);
}
const char * VigenereCipher::getPlainText()
{
	return plainText;
}
const char * VigenereCipher::getEncipherText()
{
	return encipherText;
}
const char * VigenereCipher::getKey()
{
	return key;
}
void  VigenereCipher::encipher()
{
	int i,j;
	int keyLen = strlen(key);
	char newKey[500];
	for (i = 0,j=0; plainText[i]!='\0'; i++)
	{
		if (j == keyLen)
			j = 0;
		if (plainText[i] > 'A' && plainText[i] < 'Z' || plainText[i] > 'a' && plainText[i] < 'z')
		{
			if (key[j] >= 'A' && key[j] <= 'Z')
				newKey[i] = key[j];
			else if (key[j] >= 'a' && key[j] <= 'z')
				newKey[i] = key[j] - 32;
			else
				newKey[i] = plainText[i];
			 j++;
		}
		else
			newKey[i] = plainText[i];
	}
	newKey[i] = '\0';
	for (i = 0; plainText[i] != '\0';i++)
	{
			if (plainText[i] > 'A' && plainText[i] < 'Z')
			{
				encipherText[i] = ((plainText[i] + newKey[i]) % 26) + 'A';
			}
			else if (plainText[i] > 'a' && plainText[i] < 'z')
			{
				newKey[i] = newKey[i] - 32;
				encipherText[i] = ((plainText[i] + newKey[i]) % 26) + 'a';
			}
			else
			{
				encipherText[i] = plainText[i];
			}
	}
	encipherText[i] = '\0';
}
void VigenereCipher::decipher()
{
	int i, j;
	int keyLen = strlen(key);
	char newKey[500];
	for (i = 0, j = 0; plainText[i] != '\0'; i++)
	{
		if (j == keyLen)
			j = 0;
		if (plainText[i] > 'A' && plainText[i] < 'Z' || plainText[i] > 'a' && plainText[i] < 'z')
		{
			if (key[j] >= 'A' && key[j] <= 'Z')
				newKey[i] = key[j];
			else if (key[j] >= 'a' && key[j] <= 'z')
				newKey[i] = key[j] - 32;
			else
				newKey[i] = plainText[i];
			j++;
		}
		else
			newKey[i] = plainText[i];
	}
	newKey[i] = '\0';
	for (i = 0; encipherText[i] != '\0'; i++)
	{
		if (encipherText[i] > 'A' && encipherText[i] < 'Z')
		{
			plainText[i] = ((encipherText[i] - newKey[i]) )+ 'A';
		}
		else if (encipherText[i] > 'a' && encipherText[i] < 'z')
		{
			newKey[i] = newKey[i] + 32;
			plainText[i] = ((encipherText[i] - newKey[i])+26 )%26 + 'a';
		}
		else
		{
			plainText[i] = encipherText[i];
		}
	}
	plainText[i] = '\0';
}