#include <stdio.h>
#include <stdlib.h>
#include <math.h> // gcc -o {nome do output} {arquivo.c} -lm --> sem os "-lm" o código não executa, motivo: https://stackoverflow.com/questions/12824134/undefined-reference-to-pow-in-c-despite-including-math-h 

/*
Escreva um programa implementando uma calculadora, deverá ser apresentado um menu com as seguintes opções:
1) Adição
2) Subtração
3) Multiplicação
4) Divisão
5) Exponenciação
6) Bhaskara
pesquise as funções "pow" e "sqrt" da biblioteca math.h.
referência:
    https://brasilescola.uol.com.br/matematica/formula-bhaskara.htm
pow referência:
	https://www.programiz.com/c-programming/library-function/math.h/pow
	https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm
	https://codingpointer.com/c-tutorial/undefined-reference-to-pow
	https://iqcode.com/code/c/bhaskaras-formula-in-c
Aluno: José Luis B. Donin
Eng. Compt. 1o periodo.
fiz em inglês porque as letras estavam aparecendo estranhas quando compilei no windows 11, no linux tava funcionando bem  ¯\_(ツ)_/¯
*/



//Função de adição 
int adFunc(){
    int num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    result = num1 + num2;
    printf("Result: %d", result);
    return 0;
}

//subtração
int subFunc(){
    int num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    result = num1 - num2;
    printf("\nResult: %d", result);
    return 0;
}
//multiplicação
int multFunc(){
    int num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    result = num1 * num2;
    printf("\nResult: %d", result);
    return 0;
}
//divisão
int divFunc(){
    float num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%g", &num1);

    printf("\nEnter the second number: ");
    scanf("%g", &num2);


    if(num2 == 0){
        printf("Can't divide by 0!");
        divFunc();
    }
    else{
        result = num1 / num2;
        printf("Result: %g", result);
    }
    return 0;
}
//exponenciação
int expoFunc(){
/*
	Quando inicializei as variaveis com "int" o código quebra quando  "baseNum = 10" e "powerNum = 10"
*/
	long int baseNum = 0; 
	long int powerNum =0;
	long int result = 0;
	printf("\nEnter the base number: ");
	scanf("%d", &baseNum);
	printf("\nEnter the power number: ");
	scanf("%d", &powerNum);
	result = pow(baseNum,powerNum);
	printf("\nResult: %d ", result);
    return 0;
}


int bhaskFunc(){
    float a = 0, b = 0, c = 0, delta = 0, x=0;
    float rootPositive = 0, rootNegative = 0;
    /*Coeficientes da equação*/
    printf("Enter with coefitient A: ");
    scanf("%g", &a);
    printf("Enter with coefitient B: ");
    scanf("%g", &b);
    printf("Enter with coefitient C: ");
    scanf("%g", &c);
    delta = pow(b,2) - 4 * (a * c);
    //delta = b*b - 4 * a * c;
    printf("Delta: %g\n", delta);
    if (delta < 0){
        printf("There are no real roots!");
        
    }
    else if(delta == 0){
        rootPositive = (-b + sqrt(delta)) / (2*a); 
        printf("Positive root: %f", rootPositive);
    }
    else{
        rootPositive = (-b + sqrt(delta)) / (2*a); 
        rootNegative = (-b - sqrt(delta)) / (2*a);
        printf("\nPositive root: %g", rootPositive);
        printf("\nNegative root: %g", rootNegative);
    }
}
//Função de menu
int menuFunc(){
    
    int choice = 0;
    printf("What operation do you want to perform?: \n");
    printf("\n1-Addition, 2-Subtraction, 3-Multiplication, 4-Division, 5-Exponential, 6- Bhaskara: ");
    scanf("%d", &choice);
    if (choice == 1){
        adFunc();
    }
    else if (choice == 2){
        subFunc();
    }
    else if (choice == 3){
        multFunc();
    }
    else if (choice == 4){
        divFunc();
    }
    else if (choice == 5){
        expoFunc();
    }
	else if (choice == 6){
		bhaskFunc();
	}
    else if (choice > 6){
        printf("Can't choose bigger than 5, sorry!\n");
        menuFunc();
    }
    printf("\nDo you want to do it again? (Press 1 to repeat & 2 to quit): ");
    scanf("%d", &choice);
    if (choice == 1){
        return menuFunc();
    }
    else{
        return 0;
    }
    
}

int main(){
    menuFunc();
    return 0;
}