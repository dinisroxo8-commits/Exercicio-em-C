// Exercício 16: Média de notas até -1
#include <stdio.h>
int main() {
    float nota, soma = 0;
    int cont = 0;
    while(1) {
        printf("Nota (-1 para sair): "); scanf("%f", &nota);
        if(nota == -1) break;
        soma += nota; cont++;
    }
    if(cont > 0) printf("Média: %.2f\n", soma/cont);
    return 0;
}

// Exercício 17: Adivinhação com contador
#include <stdio.h>
int main() {
    int secreto = 7, t, tentativas = 0;
    do {
        printf("Tenta: "); scanf("%d", &t);
        tentativas++;
    } while(t != secreto);
    printf("Acertou em %d tentativas!\n", tentativas);
    return 0;
}

// Exercício 18: Menu Paridade/Sinal/Tabuada
#include <stdio.h>
int main() {
    int op, n;
    printf("Número: "); scanf("%d", &n);
    printf("1-Paridade\n2-Sinal\n3-Tabuada: "); scanf("%d", &op);
    if(op == 1) printf("%s\n", n % 2 == 0 ? "Par" : "Ímpar");
    if(op == 2) printf("%s\n", n >= 0 ? "Positivo" : "Negativo");
    if(op == 3) for(int i=1; i<=10; i++) printf("%d x %d = %d\n", n, i, n*i);
    return 0;
}

// Exercício 19: Fatorial
#include <stdio.h>
int main() {
    int n;
    long long fat = 1;
    printf("Número: "); scanf("%d", &n);
    for(int i=1; i<=n; i++) fat *= i;
    printf("Fatorial: %lld\n", fat);
    return 0;
}

// Exercício 20: Sistema Completo (Loop)
#include <stdio.h>
int main() {
    int op;
    do {
        printf("\n--- SISTEMA ---\n1-Calc\n2-Tabuada\n3-Média\n4-Par/Ímpar\n0-Sair\nEscolha: ");
        scanf("%d", &op);
        // Aqui chamarias as lógicas dos exercícios anteriores
    } while(op != 0);
    return 0;
}