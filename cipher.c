#include <stdio.h>


int main(){
	printf("Menu");
	int choose;
	scanf("%i", &choose);
	switch (choose){
	case 1:
		char * filename = "txt.txt";
		char buffer[256];
		//scanf("%s", filename);
		FILE *fp = fopen(filename, "r");
		if (fp){
			while ((fgets(buffer, 256, fp))!= NULL){
			       printf("%s", buffer);	
	
			}
		
		fclose(fp);
		printf("\n");
		}
		break;
	case -1:
		break;
	default:
		printf("n/a");
		break;	
	}
	return 0;

}
