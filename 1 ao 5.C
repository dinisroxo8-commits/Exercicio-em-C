// Exercício 1: Menu com repetição
#include <stdio.h>
int main() {
    int opcao;
    do {
        printf("\n1-Saudação\n2-Mostrar número\n0-Sair\nEscolha: ");
        scanf("%d", &opcao);
        if(opcao == 1) printf("Olá! Bem-vindo.\n");
        else if(opcao == 2) printf("O número é 10.\n");
    } while(opcao != 0);
    return 0;
}

// Exercício 2: Par ou Ímpar até 0
#include <stdio.h>
int main() {
    int n;
    while(1) {
        printf("Digite um número (0 para sair): ");
        scanf("%d", &n);
        if(n == 0) break;
        if(n % 2 == 0) printf("Par\n"); else printf("Ímpar\n");
    }
    return 0;
}

// Exercício 3: Calculadora Simples
#include <stdio.h>
int main() {
    float a, b;
    int op;
    do {
        printf("\n1-Soma 2-Sub 3-Mult 4-Div 0-Sair: ");
        scanf("%d", &op);
        if(op >= 1 && op <= 4) {
            printf("Dois números: "); scanf("%f %f", &a, &b);
            if(op == 1) printf("Result: %.2f\n", a+b);
            if(op == 2) printf("Result: %.2f\n", a-b);
            if(op == 3) printf("Result: %.2f\n", a*b);
            if(op == 4) b != 0 ? printf("Result: %.2f\n", a/b) : printf("Erro: Div/0\n");
        }
    } while(op != 0);
    return 0;
}

// Exercício 4: Tabuada com paridade
#include <stdio.h>
int main() { 
    int n;
    printf("Tabuada de: "); scanf("%d", &n);
    for(int i=1; i<=10; i++) {
        int res = n * i;
        printf("%d x %d = %d (%s)\n", n, i, res, res % 2 == 0 ? "Par" : "Ímpar");
    }
    return 0;
}

// Exercício 5: Divisíveis por 5 (1 a 50)
#include <stdio.h>
int main() {
    for(int i=1; i<=50; i++) {
        if(i % 5 == 0) printf("%d ", i);
    }
    return 0;
}