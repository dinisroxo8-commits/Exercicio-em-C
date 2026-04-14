// Exercício 11: Submenus (Esqueleto)
#include <stdio.h>
int main() {
    int op, sub;
    do {
        printf("\n1-Matemática\n2-Conversões\n0-Sair: ");
        scanf("%d", &op);
        if(op == 1) {
            printf("  1-Soma\n  2-Sub: "); scanf("%d", &sub);
        }
    } while(op != 0);
    return 0;
}

// Exercício 12: Pares num intervalo
#include <stdio.h>
int main() {
    int a, b, cont = 0;
    printf("Início e Fim: "); scanf("%d %d", &a, &b);
    for(int i=a; i<=b; i++) if(i % 2 == 0) cont++;
    printf("Total de pares: %d\n", cont);
    return 0;
}

// Exercício 13: Soma positivos até negativo
#include <stdio.h>
int main() {
    int n, soma = 0;
    while(1) {
        printf("Número: "); scanf("%d", &n);
        if(n < 0) break;
        soma += n;
    }
    printf("Soma: %d\n", soma);
    return 0;
}

// Exercício 14: Simulação Multibanco
#include <stdio.h>
int main() {
    float saldo = 100, valor;
    int op;
    do {
        printf("\n1-Saldo\n2-Depósito\n3-Levantar\n0-Sair: ");
        scanf("%d", &op);
        if(op == 1) printf("Saldo: %.2f\n", saldo);
        if(op == 2) { printf("Valor: "); scanf("%f", &valor); saldo += valor; }
        if(op == 3) { 
            printf("Valor: "); scanf("%f", &valor);
            if(valor <= saldo) saldo -= valor; else printf("Sem saldo!\n");
        }
    } while(op != 0);
    return 0;
}

// Exercício 15: Tabuadas 1 a 10 (Ciclos aninhados)
#include <stdio.h>
int main() {
    for(int i=1; i<=10; i++) {
        printf("\nTabuada do %d:\n", i);
        for(int j=1; j<=10; j++) printf("%d x %d = %d\n", i, j, i*j);
    }
    return 0;
}