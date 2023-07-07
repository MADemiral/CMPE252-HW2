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

    printf("Enter arithmetic operation:\n");
    gets(string);

    myAtof(string,&errorState);



    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.

    int sign = 1, op =0, sing2 = 1;
    int index = 0;
    *error = 0;
    float number = 0, number2= 0;
    int decimaltotal = 0,decimaltotal2 = 0;

    if(*string == '-'){
        sign = -1;
        string++;

    }
    if(*string == '+'){
        string++;
        op = 1;
        goto exit;

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
    if((!(string[index]>= '0' && string[index]<= '9')&&string[index]!='.')&&(string[index]!='\0')&&!(string[index] =='+'||string[index] == '-' ||string[index] =='*'||string[index] =='/')){
            *error = 1;
            goto exit;
       }







    number /= pow(10,decimaltotal);
    number*=sign;


    if(string[index] =='+'||string[index] == '-' ||string[index] =='*'||string[index] =='/'){

        if(string[index] =='+'){
            op = 1;
            index++;
        }
        if(string[index] =='-'){
            op = 2;
            index++;
        }
        if(string[index] =='*'){
            op = 3;
            index++;
        }
        if(string[index] =='/'){
            op = 4;
            index++;
        }
    }


    if(string[index] == '-'){
        sing2 = -1;
        string++;
        index;


    }
    if(string[index] == '+'){
        string++;
        index;



    }
    if(!(string[index]>= '0' && string[index]<= '9')){
        *error = 1;
        goto exit;

    }

    while(string[index]>='0' && string[index]<='9'){
        number2 = number2*10+(string[index]-'0');
        index++;
        }


        if(string[index] =='.'){
                index++;
        while(string[index]>='0' && string[index]<='9'){
            number2 = number2*10+(string[index]-'0');
            index++;
            decimaltotal2++;
           }
        }

        if((!(string[index]>= '0' && string[index]<= '9')&&string[index]!='.')&&(string[index]!='\0')&&!(string[index] =='+'||string[index] == '-' ||string[index] =='*'||string[index] =='/')){
            *error = 1;

       }

    number2 /= pow(10,decimaltotal2);
    number2*=sing2;

exit:
    if(*error ==1)
        printf("Error has been occurred due to inappropriate input!\n");
    else{
        if(op ==1){
            printf("%.2f + %.2f = %.2f",number,number2,(number+number2));
        }
        if(op ==2){
            printf("%.2f - %.2f = %.2f",number,number2,(number-number2));
        }
        if(op ==3){
            printf("%.2f * %.2f = %.2f",number,number2,(number*number2));
        }
        if(op ==4){
            if(number2 == 0){
                printf("Cannot divided into 0.");
            }
            else{
            printf("%.2f / %.2f = %.2f",number,number2,(number/number2));
            }
        }
    }



        return 0;
}
