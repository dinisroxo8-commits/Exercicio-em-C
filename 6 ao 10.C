// Exercício 6: Conversão de Temperatura
#include <stdio.h>
int main() {
    int op;
    float temp;
    do {
        printf("\n1-C to F\n2-F to C\n0-Sair\nOpção: ");
        scanf("%d", &op);
        if(op == 1) { printf("Celsius: "); scanf("%f", &temp); printf("F: %.2f\n", (temp * 9/5) + 32); }
        if(op == 2) { printf("Fahr: "); scanf("%f", &temp); printf("C: %.2f\n", (temp - 32) * 5/9); }
    } while(op != 0);
    return 0;
}

// Exercício 7: Soma ignora negativos
#include <stdio.h>
int main() {
    int n, soma = 0;
    do {
        printf("Número (0 sair): "); scanf("%d", &n);
        if(n > 0) soma += n;
    } while(n != 0);
    printf("Soma total: %d\n", soma);
    return 0;
}

// Exercício 8: Jogo de Adivinhação
#include <stdio.h>
int main() {
    int secreto = 42, tentativa;
    do {
        printf("Adivinhe o número: "); scanf("%d", &tentativa);
        if(tentativa != secreto) printf("Errado!\n");
    } while(tentativa != secreto);
    printf("Acertou!\n");
    return 0;
}

// Exercício 9: Validação de Nota (0-20)
#include <stdio.h>
int main() {
    float nota;
    printf("Nota (0-20): "); scanf("%f", &nota);
    if(nota < 0 || nota > 20) printf("Inválida\n");
    else if(nota >= 9.5) printf("Aprovado\n");
    else printf("Reprovado\n");
    return 0;
}

// Exercício 10: Sistema com Menu Geral
#include <stdio.h>
int main() {
    int op;
    do {
        printf("\n1-Tabuada\n2-Calculadora\n3-Verificar Num\n0-Sair\nOpção: ");
        scanf("%d", &op);
        // Lógica simplificada para o menu
    } while(op != 0);
    return 0;
}