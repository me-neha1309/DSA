#include <stdio.h>
	int main() {
  		char res[100], s1[100] , s2[100];
  		
  		scanf("%[^\n]%*c", s1);
  		fflush(stdin);
  		
  		scanf("%[^\n]%*c", s2);
  		int length, j;

  		length = 1;   //Error  
  		while (s1[length] != '\0') {
    			res[length] = s1[length]; 
    			length+=1; 
  		}
  		
  		res[length++] = ' ';

  		for (j = 1; s2[j] != '\0'; ++j, ++length) {  
    			res[length++] = s2[j];  //Error
  		}

  		res[length] = '\0';

  		printf("After concatenation: ");
  		puts(res);

  		return 0;
	}