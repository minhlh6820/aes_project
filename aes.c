#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <stdint.h>

/* AES key for Encryption and Decryption */

// gcc -o a aes.c -I /usr/local/ssl/include -L /usr/local/ssl/lib -lcrypto


/* Print Encrypted and Decrypted data packets */
void print_data(const char *title, const void* data, int len);

int main()
{
	unsigned char aes_key[16] = "aesEncryptionKey";
	unsigned char aes_input[16] = "passwordpassword";
	unsigned char iv[16] = "encryptionIntVec";
	/* Buffers for Encryption and Decryption */
	unsigned char enc_out[sizeof(aes_input)];
	unsigned char dec_out[sizeof(aes_input)];

	//Add padding
	int ilenu = sizeof(aes_input);
    if (sizeof(aes_input) % 16) {
        ilenu += 16 - (sizeof(aes_input) % 16);
    }

	// int klenu = sizeof(aes_key);
    // if (sizeof(aes_key) % 16) {
    //     klenu += 16 - (sizeof(aes_key) % 16);
    // }

	// Make the uint8_t arrays
    uint8_t iexarray[ilenu];
    // uint8_t kexarray[klenu];
    
    // Initialize them with zeros
    memset( iexarray, 0, ilenu );
    // memset( kexarray, 0, klenu );
    
    // Fill the uint8_t arrays
    for (int i=0;i<sizeof(aes_input);i++) {
        iexarray[i] = (uint8_t)aes_input[i];
    }
    // for (int i=0;i<sizeof(aes_key);i++) {
    //     kexarray[i] = (uint8_t)aes_key[i];
    // }

	printf("The padded input in hex is = ");
    for (int i=0; i<ilenu;i++){
        printf("%02x",iexarray[i]);
    }
    printf("\n");
    
    // printf("The padded key in hex is = ");
    // for (int i=0; i<klenu;i++){
    //     printf("%02x",kexarray[i]);
    // }
    // printf("\n");                 
	
	/* AES-128 bit CBC Encryption */
	AES_KEY enc_key, dec_key;
	AES_set_encrypt_key(aes_key, sizeof(aes_key)*8, &enc_key);
	// AES_cbc_encrypt(aes_input, enc_out, sizeof(aes_input), &enc_key, iv, AES_ENCRYPT);
	// AES_cbc_encrypt(iexarray, enc_out, sizeof(aes_input), &enc_key, iv, AES_ENCRYPT);
	AES_ecb_encrypt(aes_input, enc_out, &enc_key, AES_ENCRYPT);
	/* AES-128 bit CBC Decryption */
	//memset(iv, 0x00, AES_BLOCK_SIZE); // don't forget to set iv vector again, else you can't decrypt data properly
	// AES_set_decrypt_key(aes_key, sizeof(aes_key)*8, &dec_key); // Size of key is in bits
	// AES_cbc_encrypt(enc_out, dec_out, sizeof(aes_input), &dec_key, iv, AES_DECRYPT);
	
	/* Printing and Verifying */
	print_data("\n Original ",aes_input, sizeof(aes_input)); // you can not print data as a string, because after Encryption its not ASCII
	
	print_data("\n Encrypted",enc_out, sizeof(enc_out));
	
	//print_data("\n Decrypted",dec_out, sizeof(dec_out));
	
	return 0;
}

void print_data(const char *title, const void* data, int len)
{
	printf("%s : ",title);
	const unsigned char * p = (const unsigned char*)data;
	int i = 0;
	
	for (; i<len; ++i)
		printf("%02X ", *p++);
	
	printf("\n");
}