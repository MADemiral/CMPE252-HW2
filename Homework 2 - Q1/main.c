#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.

    int sign = 1;
    int index = 0;
    *error = 0;
    float number = 0;
    int decimaltotal = 0;

    if(*string == '-'){
        sign = -1;
        string++;

    }
    if(*string == '+'){
        string++;

    }
    else if(!(string[index]>= '0' && string[index]<= '9')){
        *error = 1;
        goto exit;
    }
    while(string[index]>='0' && string[index]<='9'){
        number = number*10+(string[index]-'0');
        index++;
        }



        if(string[index] =='.'){
                index++;
        while(string[index]>='0' && string[index]<='9'){
            number = number*10+(string[index]-'0');
            index++;
            decimaltotal++;
           }




}
 if((!(string[index]>= '0' && string[index]<= '9')&&string[index]!='.')&&string[index]!='\0'){
            *error = 1;
            goto exit;
       }




number /= pow(10,decimaltotal);
    number*=sign;
    return number;
    exit:
        return 0;
}
