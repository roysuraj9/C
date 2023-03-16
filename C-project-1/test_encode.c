/*Name : Suraj Roy
Date : 09/08/2022
Decription : Project_1: Steganography
*/
#include <stdio.h>
#include<string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int agrc, char *argv[] )
{
       //check 3 cla is passed or not
       if (agrc < 3)
       {
	      printf("Invalid Arguments\n");
	      return 1;
       }
       //check if required number of command line arguements are passed
       //return from check_operation will tell encode or decode
       if(check_operation_type(argv) == e_encode)
       {
	      printf("Selected encoding\n");
	      //struct
	      EncodeInfo encInfo;
	      if(read_and_validate_encode_args(argv, &encInfo) == e_success)
	      {
		     printf("Read and validate encode arguments is a success\n");
		     printf("Started encoding\n");
		     //encode is completed or not
		     if(do_encoding(&encInfo) == e_success)
		     {
			    printf("Encoding is successful\n");
		     }
		     else
		     {
			    printf("Failed to encode\n");
		     }
	      }
	      else
	      {
		     printf("Read and validate encode arguments is a failure\n");
		     return -1;
	      }
       }
       //for decode
       else if (check_operation_type(argv) == e_decode)
       {
	      printf("Selected decoding\n");
	      DecodeInfo decInfo;	
	      if(read_and_validate_decode_args(argv, &decInfo) == e_success)
	      {

			printf("Read and validate decode arguments is a success\n");
			printf("Started Decoding\n");
			//decode is complete or not
			if(do_decoding(&decInfo, argv) == e_success)
			{
			       printf("Decoding is successful\n");
			}
			else
			{
		       	       printf("Failed to decode\n");
	       		       return -1;
			}
	      }
	      else
	      {
		     printf("Read and validate encode arguments is a failure\n");
		     return -1;
	      }
       }
       else
       {
	      printf("Invalid option\nPlease pass\nFor Encoding : ./a.out -e beautiful.bmp secret.txt [stego.bmp]\nFor decoding: ./a.out -d stego.bmp [decode.txt]\n");
       }
       return 0;
}

OperationType check_operation_type(char *argv[])
{
       //compare cla argv[1] with -e &-d
       if (strcmp(argv[1], "-e") == 0)
	      return e_encode;
       else if(strcmp(argv[1], "-d") == 0)
	      return e_decode;
       else
	      return e_unsupported;
}
