/*Name : Suraj Roy
Date : 09/08/2022
Decrisption : Project_1: Steganography
Sample Input : ./a.out -d stego.bmp
Sample Output : secret text in file
*/
#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types
/* 
 * Structure to store information required for
 * decoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
       /* Stego Image Info this is source now */
       char *stego_image_fname; 
       FILE *fptr_stego_image;

       char magic_string[2+1];
       char image_data[MAX_IMAGE_BUF_SIZE];
  
       int extn_size;
       char extn_secret_file[MAX_FILE_SUFFIX+1];
       int size_secret_file;
       
       char *decode_fname;
       FILE *fptr_decode;
       
} DecodeInfo;

/* Decoding function prototype */

/* Check operation type */
OperationType check_operation_type(char *argv[]);

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo, char *argv[]);

/* Get File pointers for i/p and o/p files */
Status open_dfiles(DecodeInfo *decInfo);

/* Store Magic String */
Status decode_magic_string(char *magic_string, DecodeInfo *decInfo);

/* Decode Extn size */
Status decode_extn_size(int size, DecodeInfo *decInfo);

/* Decode secret file extenstion */
Status decode_secret_file_extn( char *extn_secret_file, DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo);

/* Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

/* Decode function, which does the real decoding */
Status decode_data_to_image(char *data, int size, FILE *fptr_stego_image, DecodeInfo *decInfo);

/* Decode a byte into LSB of image data array */
Status decode_byte_to_lsb(char data, char *image_buffer);

/* Decode int to LSB */
Status decode_size_to_lsb(int size, char *image_buffer);

#endif
