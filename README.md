# AES project

Source code from OpenSSL project (https://github.com/openssl/openssl) to run AES-CBC-128 and AES-ECB-128

- For AES-CBC-128:

Use function AES_cbc_encrypt()

Run command:

gcc -o a aes_test_lib.c aes_lib/aes_cbc.c aes_lib/aes_core.c aes_lib/modes/cbc128.c

./a

- For AES-ECB-128:

Use function AES_ecb_encrypt()

Run command:

gcc -o a aes_test_lib.c aes_lib/aes_ecb.c aes_lib/aes_core.c

./a

