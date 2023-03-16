/*Name : Suraj Roy
Date : 09/08/2022
Decrisption : Project_1: Steganography
Sample Input : ./a.out -d stego.bmp
Sample Output : secret text in file
*/
#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
/* Function Definitions */

//The function calls of all the functions are written about the function definitions
//Below are the Printf to observe a function properly
					

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
 
 //checking valid cla is pass or not
Status read_and_validate_decode_args (char *argv[], DecodeInfo *decInfo)
{
       //chk if file format is .bmp
       if(strcmp(strstr(argv[2],"."),".bmp")==0)							
       {
      	      //image_fname
	      decInfo -> stego_image_fname =argv[2];							
       }
       else
       {
     	      return e_failure;
       }
       return e_success;
}

Status open_dfiles(DecodeInfo *decInfo)				
{																

       // stego Src Image file										
       decInfo -> fptr_stego_image = fopen(decInfo -> stego_image_fname, "r");
       // Do Error handling if file doesn't exist
       if (decInfo -> fptr_stego_image == NULL)					
       {
	      perror("fopen");
	      fprintf(stderr, "ERROR: Unable to open Stego file %s\n", decInfo -> stego_image_fname);
	      return e_failure;
       }
       //use fseek to skip ahead of header meta data of file
       fseek(decInfo -> fptr_stego_image, 54, SEEK_SET);				
       // No failure return e_success
       return e_success;
}

Status decode_data_to_image(char *data, int size, FILE *fptr_stego_image, DecodeInfo *decInfo)
{
       //8 bytes are read and sent for LSB extaction
       for(int i = 0; i < size; i++)
       {
	      fread(decInfo -> image_data, 8, 1, fptr_stego_image);
	      //each char preared is stored at an index				
	      data[i] = decode_byte_to_lsb(data[i], decInfo -> image_data);		
       }
       data[size] = 0;														
}
	
Status decode_magic_string(char *magic_string, DecodeInfo *decInfo)
{
       //used for decoding the magic String '#*'		
       decode_data_to_image(decInfo -> magic_string, 2, decInfo -> fptr_stego_image, decInfo);
       if(strcmp(decInfo -> magic_string, MAGIC_STRING) == 0)
       {
       	      return e_success;
       }
       else
       {
	      return e_failure;
       }
}

Status decode_byte_to_lsb(char data, char *image_buffer)
{
       //used to convert into chars
       for(int i = 0; i < 8; i++)
       {	
	      //lSB of the byte is taken and left shifted  8 tiime
	      data = (data << 1) | (image_buffer[i] & 0x01);      			
       }
       return data;													
}

Status decode_size_to_lsb(int size, char *image_buffer)
{
       //used to convert into char andlSB of the byte is taken and left shifted to accomodate 32 times to create 1 int
       for(int i = 0; i < 32; i++)
       {
	      size=(size<<1)|(image_buffer[i] & 0x01);  			
       }														 
       return size;											 
}
		
Status decode_extn_size(int extn_size, DecodeInfo *decInfo)		
{
       //used for decoding the length of the chars of extn of the secret file 
       char str[32];
       //use str buffer to read the chars and traverse through ptr
       fread(str, 32, 1, decInfo -> fptr_stego_image);
       //the 32 bytes are broken to get a 4byteint				
       decInfo -> extn_size=decode_size_to_lsb(extn_size, str);								
       return e_success;
}

Status decode_secret_file_extn(char *extn_secret_file, DecodeInfo *decInfo)													
{
       //used to decode the extension of secret file, it will be used to create 'decoded' file       
       decode_data_to_image(decInfo -> extn_secret_file, decInfo -> extn_size, decInfo -> fptr_stego_image, decInfo);
       return e_success;
}

Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)															
{
       //used to decode the size of file data, i.e. the amount of char text encoded
       char str[32];
       fread(str, 32, 1, decInfo -> fptr_stego_image);	
       //size of secret file data is stored in size_secret_file		
       decInfo->size_secret_file=decode_size_to_lsb(file_size,str);
       return e_success;
}

Status decode_secret_file_data(DecodeInfo *decInfo)				
{
       //used to decode the secret message in chars	
       char str[(decInfo -> size_secret_file) + 1];							
       fseek(decInfo -> fptr_decode, 0, SEEK_SET);							
       decode_data_to_image(str, decInfo -> size_secret_file, decInfo -> fptr_stego_image, decInfo);
       //write to the decoded.txt with fptr_decode
       fwrite(str, decInfo -> size_secret_file, 1, decInfo -> fptr_decode);	
       return e_success;
}

Status do_decoding(DecodeInfo *decInfo, char * argv[])
{	
       if(open_dfiles(decInfo) == e_success)
       {
	      printf("Open Files successfully\n");
	      if(decode_magic_string(decInfo -> magic_string, decInfo) == e_success)
	      {
		     printf("Decoded magic string position successfully\n");
		     if(decode_extn_size(decInfo -> extn_size, decInfo) == e_success)
		     {
			    printf("Decoded the extn_size successfully\n");
			    if(decode_secret_file_extn( decInfo -> extn_secret_file, decInfo) == e_success)
			    {
				   printf("Decoded the secret_file extn successfully\n");
				   //create file to store secret data
				   if (argv[3] != NULL)
				   {
					  decInfo -> decode_fname = argv[3];
					  printf("Created file %s\n", argv[3]);				
				   }
				   else
				   {
					  strcpy(decInfo -> decode_fname, "decoded");
					  strcat(decInfo -> decode_fname, decInfo -> extn_secret_file);
					  printf("Created file decoded.txt\n");
				   }
				   decInfo -> fptr_decode = fopen(decInfo -> decode_fname, "w");
				   if(decode_secret_file_size( decInfo -> size_secret_file , decInfo) == e_success)
				   {
					  printf("Decoded the secret_file size successfully\n");
					  if(decode_secret_file_data(decInfo) == e_success)
					  {
						 printf("Decoded the secret_file data successfully \n");									
					  }
				  	  else
				  	  {
			 			 printf("Failed to decode secret file Data\n");
						 return e_failure;
					  }						
				   }
			   	   else
		   		   {
					  printf("Failed to decode secret file Size\n");
  					  return e_failure;
				   }							
			    }
			    else
			    {
				   printf("Failed to decode secret file extn\n");
				   return e_failure;
			    }			
		     }
		     else
		     {
			    printf("Failed to decode extn_size\n");
			    return e_failure;
		     }		
	      }
	      else
	      {
		     printf("Failed to found Magic String\n");
		     return e_failure;
	      }		
       }
       else
       {
	      printf("Failed to Open Files\n");
	      return e_failure;
       }
       return e_success;
}
