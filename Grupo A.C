#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da constante para o limite do array
#define MAX_RESTAURANTES 100

// --- ESTRUTURA DE DADOS ---
typedef struct {
    char nome[50];
    char categoria[50];
    int estado; // 1 = Ativo, 0 = Inativo
} Restaurante;

// Variáveis Globais para facilitar o acesso entre funções
Restaurante lista[MAX_RESTAURANTES];
int contador = 0;

// --- PROTÓTIPOS DAS FUNÇÕES ---
void cadastrarRestaurante();
void listarRestaurantes();
void alternarEstado();
void pesquisarRestaurante();
void mostrarAtivos();
void limparEcra();

int main() {
    int opcao;

    // --- ETAPA 1: MENU COM CICLO DO WHILE E SWITCH ---
    do {
        printf("\n======= GESTAO DE RESTAURANTES =======");
        printf("\n1. Cadastrar restaurante");
        printf("\n2. Listar restaurantes");
        printf("\n3. Ativar/Desativar restaurante");
        printf("\n4. Pesquisar restaurante pelo nome");
        printf("\n5. Mostrar apenas restaurantes ativos");
        printf("\n6. Sair");
        printf("\nEscolha uma opcao: ");
        
        // Validação básica da entrada
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Digite um numero valido!\n");
            while(getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        switch (opcao) {
            case 1: cadastrarRestaurante(); break;
            case 2: listarRestaurantes(); break;
            case 3: alternarEstado(); break;
            case 4: pesquisarRestaurante(); break;
            case 5: mostrarAtivos(); break;
            case 6: printf("\nA sair do sistema...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

// --- ETAPA 2: CADASTRAR RESTAURANTE ---
void cadastrarRestaurante() {
    if (contador >= MAX_RESTAURANTES) {
        printf("\nErro: Limite de armazenamento atingido!\n");
        return;
    }

    printf("\nNome do restaurante: ");
    scanf(" %[^\n]", lista[contador].nome); // %[^\n] lê texto com espaços
    
    printf("Categoria: ");
    scanf(" %[^\n]", lista[contador].categoria);
    
    lista[contador].estado = 0; // Inicia obrigatoriamente como inativo
    contador++;
    
    printf("\nRestaurante cadastrado com sucesso!");
}

// --- ETAPA 3: LISTAR RESTAURANTES ---
void listarRestaurantes() {
    if (contador == 0) {
        printf("\nNenhum restaurante cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE RESTAURANTES ---");
    // Uso do ciclo FOR conforme requisito
    for (int i = 0; i < contador; i++) {
        printf("\nID: %d | Nome: %-15s | Cat: %-10s | Estado: %s", 
                i + 1, 
                lista[i].nome, 
                lista[i].categoria, 
                lista[i].estado == 1 ? "Ativo" : "Inativo");
    }
    printf("\n-----------------------------\n");
}

// --- ETAPA 4: ATIVAR/DESATIVAR ---
void alternarEstado() {
    char busca[50];
    int encontrado = 0;

    printf("\nNome do restaurante para alterar estado: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < contador; i++) {
        if (strcmp(lista[i].nome, busca) == 0) {
            lista[i].estado = !lista[i].estado; // Inverte 0 para 1 ou vice-versa
            printf("\nEstado do restaurante '%s' alterado para: %s\n", 
                    lista[i].nome, 
                    lista[i].estado == 1 ? "Ativo" : "Inativo");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("\nErro: Restaurante nao encontrado.\n");
}

// --- ETAPA 5: PESQUISAR ---
void pesquisarRestaurante() {
    char busca[50];
    int encontrado = 0;

    printf("\nDigite o nome para pesquisar: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < contador; i++) {
        if (strcmp(lista[i].nome, busca) == 0) {
            printf("\nEncontrado: %s | Categoria: %s | Estado: %s\n", 
                    lista[i].nome, lista[i].categoria, 
                    lista[i].estado == 1 ? "Ativo" : "Inativo");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("\nErro: Restaurante nao existe.\n");
}

// --- ETAPA 6: MOSTRAR ATIVOS ---
void mostrarAtivos() {
    int ativos = 0;
    printf("\n--- RESTAURANTES ATIVOS ---");
    for (int i = 0; i < contador; i++) {
        if (lista[i].estado == 1) {
            printf("\n- %s (%s)", lista[i].nome, lista[i].categoria);
            ativos++;
        }
    }
    if (ativos == 0) printf("\nNenhum restaurante ativo no momento.");
    printf("\n---------------------------\n");
}