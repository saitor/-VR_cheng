#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_x,length_y,length_z;
int ratio_x,ratio_y,ratio_z;
float max= -1.0f,min = 999999.0f,graMax=-1.0f,graMin=999999.0f;
float * data;
float **grdntVec;
float *grdntMag;

//not decided yet
float *ColorTable;
float   p[8][3];

void readFile(const char *filename) {
	
	char buffer[100];
	char temp[50];
	char raw_filename[50],type[15];
    FILE *fp;
    fp = fopen(filename,"r");
	
	if(!fp)
	{
		printf(" not exist\n");
		system("pause");
		exit(1) ;
	}
    
	//first row data
    fgets(buffer,100,fp);
	sscanf(buffer,"raw-file=\"%[^\"]s",temp);
	strcpy(raw_filename,temp);
	
	fgets(buffer,100,fp);
	sscanf(buffer, "resolution=%dx%dx%d", &length_x,&length_y,&length_z);

	fgets(buffer,100,fp);
	sscanf(buffer, "sample-type=%[ a-z]s",temp);
	strcpy(type,temp);

	if( !feof( fp ))
	{	
		fgets(buffer,100,fp);
		sscanf(buffer,"ratio=%d:%d:%d", &ratio_x, &ratio_y, &ratio_z);
	}
	//setValue_Init(raw_filename,x,y,z,type,ratio_x,ratio_y,ratio_z);

	fclose(fp);
    
}