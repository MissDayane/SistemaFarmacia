#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definir Estruturas e Variáveis Globais
typedef struct {
    char nome[50];
    float preco;
    char tarja[10];
    int estoque;
} Produto;

Produto produtos[100]; // Array para armazenar produtos
int numProdutos = 0; // Número atual de produtos

// Função para cadastrar um novo produto (Adm)
void cadastrarProduto() {
    if (numProdutos >= 100) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;

    printf("Nome do produto: ");
    scanf("%s", novoProduto.nome);

    printf("Preço: ");
    scanf("%f", &novoProduto.preco);

    printf("Tarja: ");
    scanf("%s", novoProduto.tarja);

    printf("Estoque: ");
    scanf("%d", &novoProduto.estoque);

    produtos[numProdutos++] = novoProduto;

    printf("Produto cadastrado com sucesso.\n");
}

// Função para listar todos os produtos (Adm e Cliente)
void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Nome: %s, Preço: %.2f, Tarja: %s, Estoque: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].tarja, produtos[i].estoque);
    }
}

// Função para controlar o estoque de produtos (Adm)
void controlarEstoque() {
    int opcao;
    char nomeProduto[50];
    int quantidade;

    do {
        printf("\n===== Controle de Estoque =====\n");
        printf("1. Aumentar estoque de um produto\n");
        printf("2. Diminuir estoque de um produto\n");
        printf("3. Verificar quantidade em estoque de um produto\n");
        printf("4. Listar todos os produtos e quantidades em estoque\n");
        printf("0. Voltar ao menu anterior\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Aumentar estoque de um produto
                printf("Nome do produto: ");
                scanf("%s", nomeProduto);
                printf("Quantidade a adicionar: ");
                scanf("%d", &quantidade);
                for (int i = 0; i < numProdutos; i++) {
                    if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                        produtos[i].estoque += quantidade;
                        printf("Estoque de %s aumentado em %d unidades. Total: %d\n", nomeProduto, quantidade, produtos[i].estoque);
                        break;
                    }
                }
                break;

            case 2: // Diminuir estoque de um produto
                printf("Nome do produto: ");
                scanf("%s", nomeProduto);
                printf("Quantidade a subtrair: ");
                scanf("%d", &quantidade);
                for (int i = 0; i < numProdutos; i++) {
                    if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                        if (produtos[i].estoque >= quantidade) {
                            produtos[i].estoque -= quantidade;
                            printf("Estoque de %s diminuído em %d unidades. Total: %d\n", nomeProduto, quantidade, produtos[i].estoque);
                        } else {
                            printf("Estoque insuficiente para %s. Quantidade disponível: %d\n", nomeProduto, produtos[i].estoque);
                        }
                        break;
                    }
                }
                break;

            case 3: // Verificar quantidade em estoque de um produto
                printf("Nome do produto: ");
                scanf("%s", nomeProduto);
                for (int i = 0; i < numProdutos; i++) {
                    if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                        printf("Estoque de %s: %d unidades\n", nomeProduto, produtos[i].estoque);
                        break;
                    }
                }
                break;

            case 4: // Listar todos os produtos e quantidades em estoque
                listarProdutos();
                break;

            case 0: // Voltar ao menu anterior
                printf("Voltando ao menu anterior...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

// Função para comprar um produto (cliente)
void comprarProduto() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado para compra.\n");
        return;
    }
    char nomeProduto[50];
    int quantidade;

    printf("Nome do produto a comprar: ");
    scanf("%s", nomeProduto);
    
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Quantidade disponível em estoque: %d\n", produtos[i].estoque);
            printf("Quantidade desejada: ");
            scanf("%d", &quantidade);

            if (produtos[i].estoque >= quantidade) {
                produtos[i].estoque -= quantidade;
                printf("%d unidades de %s compradas com sucesso.\n", quantidade, nomeProduto);
                return;
            } else {
                printf("Estoque insuficiente para %s.\n", nomeProduto);
                return;
            }
        }
    }

    printf("Produto %s nao encontrado.\n", nomeProduto);
}

// Função para realizar o login do usuário(Adm e Cliente)
int fazerLogin() {
    char username[50];
    int senha;

    printf("Username: ");
    scanf("%s", username);

    printf("Senha: ");
    scanf("%d", &senha);

    if (strcmp(username, "admin") == 0 && senha == 1234) {
        printf("Login de administrador bem sucedido.\n");
        return 1; // Administrador logado
    } else if (strcmp(username, "cliente") == 0 && senha == 5678) {
        printf("Login de cliente bem sucedido.\n");
        return 2; // Cliente logado
    } else {
        printf("Credenciais inválidas. Tente novamente.\n");
        return 0; // Login falhou
    }
}

int main() {
    // Produtos pré-estabelecidos
    strcpy(produtos[numProdutos].nome, "Paracetamol");
    produtos[numProdutos].preco = 2.99;
    strcpy(produtos[numProdutos].tarja, "N/A");
    produtos[numProdutos].estoque = 10;
    numProdutos++;

    strcpy(produtos[numProdutos].nome, "Rivotril");
    produtos[numProdutos].preco = 30.00;
    strcpy(produtos[numProdutos].tarja, "preta");
    produtos[numProdutos].estoque = 7;
    numProdutos++;

    int tipoUsuario = fazerLogin();

    if (tipoUsuario == 0) {
        return 1; // Encerrar o programa se o login falhar
    }

    int opcao;
    do {
        if (tipoUsuario == 1) { // Menu para administrador
            printf("\n===== MENU DO ADMINISTRADOR =====\n");
            printf("1. Cadastrar Produto\n");
            printf("2. Listar Produtos\n");
            printf("3. Controlar Estoque\n");
            printf("0. Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrarProduto();
                    break;
                case 2:
                    listarProdutos();
                    break;
                case 3:
                    controlarEstoque();
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida.\n");
            }
        } else if (tipoUsuario == 2) { // Menu para cliente
            printf("\n===== MENU DO CLIENTE =====\n");
            printf("1. Listar Produtos\n");
            printf("2. Comprar Produto\n");
            printf("0. Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    listarProdutos();
                    break;
                case 2:
                    comprarProduto();
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida.\n");
            }
        }
    } while (opcao != 0);

    return 0;
}
