#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>


int main(int argc,char* argv[])
{
	
	FILE* fp1 = fopen(argv[1],"rb");
	FILE* fp2 = fopen(argv[2],"rb");
	uint32_t network_buffer[2];	


	if(fp1 == NULL || fp2 == NULL){
		return -1;
	}
	
	fread(&network_buffer[0],sizeof(uint32_t),1,fp1);
	fread(&network_buffer[1],sizeof(uint32_t),1,fp2);


	uint32_t n1 = ntohl(network_buffer[0]);
	uint32_t n2 = ntohl(network_buffer[1]);
	uint32_t n3 = n1+n2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",n1,n1,n2,n2,n3,n3);



	fclose(fp1);
	fclose(fp2);
}
