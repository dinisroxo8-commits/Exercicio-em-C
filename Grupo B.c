#include <stdio.h>
#include <string.h>

#define MAX 100

// --- ESTRUTURAS DE DADOS ---

typedef struct {
    int id;
    char nome[50];
    int idade;
    char contacto[20];
} Paciente;

typedef struct {
    int idConsulta;
    int idPaciente; // Chave que liga ao Paciente
    char data[15];
    char hora[10];
    char tipo[30]; // Ex: Geral, Dentista
    int estado;    // 1 = Agendada, 0 = Realizada
} Consulta;

// --- VARIÁVEIS GLOBAIS ---
Paciente pacientes[MAX];
Consulta consultas[MAX];
int contP = 0; // Contador de pacientes
int contC = 0; // Contador de consultas

// --- FUNÇÕES ---

void cadastrarPaciente() {
    printf("\nID do Paciente: ");
    scanf("%d", &pacientes[contP].id);
    printf("Nome: ");
    scanf(" %[^\n]", pacientes[contP].nome);
    printf("Idade: ");
    scanf("%d", &pacientes[contP].idade);
    printf("Contacto: ");
    scanf(" %[^\n]", pacientes[contP].contacto);
    contP++;
    printf("Paciente registado!\n");
}

void listarPacientes() {
    printf("\n--- LISTA DE PACIENTES ---");
    for(int i=0; i<contP; i++) {
        printf("\nID: %d | Nome: %s", pacientes[i].id, pacientes[i].nome);
    }
    printf("\n--------------------------\n");
}

void marcarConsulta() {
    int idBusca, existe = 0;
    printf("\nDigite o ID do paciente para a consulta: ");
    scanf("%d", &idBusca);

    // Validação: Só marca se o paciente existir (Regra de Implementação)
    for(int i=0; i<contP; i++) {
        if(pacientes[i].id == idBusca) {
            existe = 1;
            break;
        }
    }

    if(existe) {
        consultas[contC].idPaciente = idBusca;
        printf("ID da Consulta: ");
        scanf("%d", &consultas[contC].idConsulta);
        printf("Data (dd/mm/aaaa): ");
        scanf(" %[^\n]", consultas[contC].data);
        printf("Hora (hh:mm): ");
        scanf(" %[^\n]", consultas[contC].hora);
        printf("Tipo de especialidade: ");
        scanf(" %[^\n]", consultas[contC].tipo);
        consultas[contC].estado = 1; // 1 = Agendada
        contC++;
        printf("Consulta marcada com sucesso!\n");
    } else {
        printf("Erro: Paciente nao encontrado!\n");
    }
}

void verConsultasPaciente() {
    int idBusca;
    printf("\nConsultas de qual ID de paciente? ");
    scanf("%d", &idBusca);
    
    printf("\n--- HISTORICO DO PACIENTE %d ---", idBusca);
    for(int i=0; i<contC; i++) {
        if(consultas[i].idPaciente == idBusca) {
            printf("\nData: %s | Especialidade: %s | Estado: %s", 
                consultas[i].data, consultas[i].tipo, 
                consultas[i].estado == 1 ? "Agendada" : "Finalizada");
        }
    }
}

void eliminarPaciente() {
    int idBusca, temConsulta = 0;
    printf("\nID do paciente a eliminar: ");
    scanf("%d", &idBusca);

    // Validação: Não elimina se tiver consultas (Regra de Negócio)
    for(int i=0; i<contC; i++) {
        if(consultas[i].idPaciente == idBusca) {
            temConsulta = 1;
            break;
        }
    }

    if(temConsulta) {
        printf("Erro: Nao pode eliminar paciente com consultas marcadas!\n");
    } else {
        for(int i=0; i<contP; i++) {
            if(pacientes[i].id == idBusca) {
                // "Apaga" movendo os outros para trás
                for(int j=i; j < contP - 1; j++) pacientes[j] = pacientes[j+1];
                contP--;
                printf("Paciente removido.\n");
                return;
            }
        }
        printf("Paciente nao encontrado.\n");
    }
}

// --- MENU PRINCIPAL ---
int main() {
    int opcao;
    do {
        printf("\n\n=== SISTEMA HOSPITALAR ===");
        printf("\n1. Cadastrar Paciente\n2. Listar Pacientes\n3. Marcar Consulta");
        printf("\n4. Ver Consultas de um Paciente\n5. Eliminar Paciente\n9. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: listarPacientes(); break;
            case 3: marcarConsulta(); break;
            case 4: verConsultasPaciente(); break;
            case 5: eliminarPaciente(); break;
            case 9: printf("Adeus!"); break;
            default: printf("Invalido.");
        }
    } while(opcao != 9);
    return 0;
}