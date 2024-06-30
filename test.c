
#include <stdio.h>
#include <string.h>
#include "type.h"
#include "test.h"
#include "pbkdf2.h"

/* =====================  Function modules =====================*/
//revert string
void revert_str(char str[]){
    byte i = 0;
    word left = 0;
    word right = strlen(str)-1;
    char tmp;
    
    while(left<right){
        printf("loop time:%d\n",i++);
        tmp = str[left];
        str[left++] = str[right];
        str[right--] = tmp;
    }
}

void test_revert_str(){
    char data_str[] = "hello";
    printf("\nBefore reversing:%s\n",data_str);
    revert_str(data_str);
    printf("\nAfter reversing :%s\n",data_str);
}

void compute_sha_ex(unsigned char* dest, const uint8_t *msg, uint32_t mlen)
{
    uint8_t md[SHA256_DIGESTLEN] = {0};
    SHA256_CTX sha;
    sha256_init(&sha);
    sha256_update(&sha, msg, mlen);
    sha256_final(&sha, md);
    memcpy(dest, md, SHA256_DIGESTLEN);
}

void compute_hmac_ex(unsigned char* dest, const uint8_t *key, uint32_t klen, const uint8_t *msg, uint32_t mlen)
{
    uint8_t md[SHA256_DIGESTLEN] = {0};
    HMAC_SHA256_CTX hmac;
    hmac_sha256_init(&hmac, key, klen);
    hmac_sha256_update(&hmac, msg, mlen);
    hmac_sha256_final(&hmac, md);
    memcpy(dest, md, SHA256_DIGESTLEN);
}

unsigned int hexStringToInt(const char *hexString) {
    unsigned int hexValue = 0;
    sscanf(hexString, "%x", &hexValue);
    return hexValue;
}

// 函数：将每两个字符转换为一个十六进制数
void convertStringToHex(const char *input, unsigned char *hex_buff, size_t buff_size) {
    uint8_t i = 0;
    size_t input_length = strlen(input);
    size_t hex_length = input_length / 2;
    
    if (buff_size < hex_length) {
        printf("Buffer size is too small.\n");
        return;
    }
    for (i = 0; i < hex_length; ++i) {
        unsigned int value;
        sscanf(input + 2 * i, "%2x", &value);
        hex_buff[i] = (unsigned char)value;
    }
}

/**
 * @brief test_pbkdf2_sha256
 * @param none
 * if key is "hello"
 * salt is "12345678"
 * iteration is 1000
 * then the result should be: bcd1eddc7fbba0c2b75f270a6f32b1436689b79ea41a8174d64e366109cec056
 * reference website link: 
 *          1. https://www.jyshare.com/crypto/pbkdf2/
 *          2. https://www.dcode.fr/pbkdf2-hash
 */
void test_pbkdf2_sha256(){
    
    uint8_t i = 0;
    //standard result of hello processed by PBKDF2-SHA256 on-line according to the above 2 websites.
    const char *input_string = "bcd1eddc7fbba0c2b75f270a6f32b1436689b79ea41a8174d64e366109cec056";
    size_t hex_buff_size = strlen(input_string) / 2;
    unsigned char hex_buff[hex_buff_size];

    //change the sting rsl to hex byte data
    printf("String hello's origin rst before change:\n\t%s\n",input_string);
    convertStringToHex(input_string, hex_buff, hex_buff_size);
    // Print the hex num of standard result of hello on the Internet
    printf("After change ->> hex_buff is : \n\t");
    for ( i = 0; i < hex_buff_size; ++i) {
        printf("%02x", hex_buff[i]);
    }
    printf("\n");

    // Prepare PDKDF2 process data 
    const uint8_t key[] = "hello";
    uint32_t keylen = strlen((const char*)key);
    const uint8_t salt[] = "12345678";
    uint32_t salt_len = strlen((const char *)salt);
    uint32_t iteration = 1000;
    uint32_t dk_len = 32;
    uint8_t dk[32]={0};

    //PBKDF2 process
    pbkdf2_sha256(key,keylen,salt,salt_len,iteration,dk,dk_len);

    printf("The %s with %s as salt after PBKDF2 process is:\n\t",key,salt);
    for(i=0;i<dk_len;i++){
        printf("%02x",dk[i]);
    }
    printf("\n");

    if(memcmp(hex_buff,dk,32)){
        printf("The result is wrong.\n");
    }
    else{
        printf("The process is right.\n");
    }
}

// Entry of different function modules
void test(){
    // test_revert_str();
    test_pbkdf2_sha256();
}