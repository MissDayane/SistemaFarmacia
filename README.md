# SistemaFarmacia
###Descrição do Projeto: Sistema de Farmácia em C 

Introdução: O projeto consiste em desenvolver um sistema de farmácia em linguagem C, oferecem funcionalidades básicas para gerenciar produtos, estoque e vendas com operações CRUD básicas (Create, Read, Update, Delete). A estrutura geral do sistema inclui um menu para administrador e um menu para cliente. O sistema é destinado a ser uma ferramenta de aprendizado acadêmico para aplicar conceitos de programação em C, manipulação de arrays, estruturas, funções e controle de fluxo. 

Inclusão de Bibliotecas: As bibliotecas padrão stdio.h, stdlib.h e string.h são incluídas para operações de entrada/saída, alocação de memória e manipulação de strings, respectivamente. 

 

Definição de Estrutura de Dados: A estrutura Produto é definida para representar cada produto, contendo nome, preço, tarja (indicativo de medicamentos) e quantidade em estoque. 

 

Variáveis Globais: Um array de Produto chamado produtos é declarado para armazenar os produtos, e uma variável numProdutos é usada para controlar o número atual de produtos. 

  

Função cadastrarProduto() - CREATE: Permite ao administrador cadastrar um novo produto. Ele solicita ao usuário que insira os detalhes do produto (nome, preço, tarja e estoque) e armazena-os no array produtos. 

 

Função listarProdutos() - READ: Lista todos os produtos cadastrados, mostrando seus detalhes como nome, preço, tarja e estoque. 

 

Função controlarEstoque() - UPDATE: Permite ao administrador controlar o estoque dos produtos. Ele fornece opções para aumentar, diminuir, verificar a quantidade em estoque de um produto específico ou listar todos os produtos e suas quantidades em estoque. 

 

Função comprarProduto() - DELETE: Permite que um cliente compre um produto. Ele verifica se o produto desejado está em estoque e, se sim, reduz o estoque conforme a quantidade comprada. 

 

Função fazerLogin(): Verifica as credenciais de login do usuário. Se o usuário for um administrador ("admin" com senha "1234") ou um cliente ("cliente" com senha "5678"), ele permite o acesso ao sistema. 

 

Função main(): É a função principal do programa. Inicialmente, são pré-estabelecidos dois produtos. Em seguida, o usuário é solicitado a fazer login. Dependendo do tipo de usuário (administrador ou cliente), é exibido um menu correspondente com opções adequadas. O programa continua executando até que o usuário escolha sair (opção 0). 
