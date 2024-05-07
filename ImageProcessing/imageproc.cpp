/**********************************************************************************
* imageproc.c
* Usage: imageproc in_file_name out_file_name width height
 **********************************************************************************/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
	FILE  *in, *out;
	int   j, k, width, height;
	int ** image_in, ** image_out;
	float sum1, sum2;
	float new_T, old_T, delta_T;
	long count1, count2;
	errno_t err;

	if(argc<5) { printf("ERROR: Insufficient parameters!\n"); return(1);}

	width = atoi(argv[3]);
	height = atoi(argv[4]);

	image_in = (int**) calloc(height, sizeof(int*));
	if(!image_in)
	{
		printf("Error: Can't allocate memmory!\n");
		return(1);
	}

	image_out = (int**) calloc(height, sizeof(int*));
	if(!image_out)
	{
		printf("Error: Can't allocate memmory!\n");
		return(1);
	}

	for (j=0; j<height; j++)
	{
		image_in[j] = (int *) calloc(width, sizeof(int));
		if(!image_in[j])
		{
			printf("Error: Can't allocate memmory!\n");
			return(1);
		}

		image_out[j] = (int *) calloc(width, sizeof(int));
		if(!image_out[j])
		{
			printf("Error: Can't allocate memmory!\n");
			return(1);
		}

	}

	if((err=fopen_s(&in, argv[1],"rb"))!=0)
	{
		printf("ERROR: Can't open in_file!\n");
		return(1);
	}

	if((err=fopen_s(&out, argv[2],"wb"))!=0)
	{
		printf("ERROR: Can't open out_file!\n");
		return(1);
	}

	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	    	{
			if((image_in[j][k]=getc(in))==EOF)
			{
				printf("ERROR: Can't read from in_file!\n");
				return(1);
		      }
	    	}
      if(fclose(in)==EOF)
	{
		printf("ERROR: Can't close in_file!\n");
		return(1);
	}



/********************************************************************/
/* Image Processing begins                                          */
/********************************************************************/

	  float M[3][3] = { {-1.0, -1.0, -1.0},{-1.0, 9.0, -1.0},{-1.0, -1.0, -1.0} }; 
	  float V = 0.0;
	  int m, n;
	  float sum;

	  for (j = 0; j < height; j++)
		  for (k = 0; k < width; k++)
		  {
			  if (j == 0 || k == 0 || j == height - 1 || k == width - 1)
				  image_out[j][k] = image_in[j][k];
			  else
			  {
				  sum = 0.0;
				  for (m = 0; m < 3; m++)
					  for (n = 0; n < 3; n++)
					  {
						  sum += ((float)image_in[j + m - 1][k + n - 1]) * M[m][n];
					  }
				  V = sum;
				  V = (V > 255 ? 255 : V);
				  V = (V < 0 ? 0 : V);
				  image_out[j][k] = (int)V;
			  }
		  }

/********************************************************************/
/* Image Processing ends                                          */
/********************************************************************/



	/* save image_out into out_file in RAW format */
	for (j=0; j<height; j++)
		for (k=0; k<width; k++)
	    {
	            if((putc(image_out[j][k],out))==EOF)
	            {
		        	printf("ERROR: Can't write to out_file!\n");
				    return(1);
	            }
		}

    if(fclose(out)==EOF)
	{
		printf("ERROR: Can't close out_file!\n");
		return(1);
	}


	for (j=0; j<height; j++)
	{
		free(image_in[j]);
		free(image_out[j]);
	}
	free(image_in);
	free(image_out);

    return 0;
}



