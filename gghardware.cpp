#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


//VARIÁVEL WHILE LOGIN
int while_login = 1;


//VARIÁVEL WHILE GERAL(PÓS LOGIN)
int i;


//STRUCT LOGIN
typedef struct { //criando um sistema de login e senha

	char login[10];
	char senha[10]; //limite de 10 caracteres para a senha e o  login

}user; user usuario[1]; //criando login para o unico usuario


//DESIGN - CARREGANDO...
void carregando() {

	float carregamento = 0;
	time_t start = time( 0 );
		
	for (int x = 0; x < 10; x++) {
		
		system("cls");
		
		carregamento = carregamento + 5;
				
		cout << "\n\n\n        Loading... [ " << carregamento << "% ] [=         ]";
				 
		while (difftime( time( 0 ), start ) < 2.0);
	}
	
	start = time( 0 );
	
	for (int x = 0; x < 9; x++) {
		
		system("cls");
		
		carregamento = carregamento + 5;
		
		cout << "\n\n\n        Loading... [ " << carregamento << "% ] [=====     ]";
		
		while (difftime( time( 0 ), start ) < 1.0);
	}
	
	system("cls");
	start = time( 0 );
	cout << "\n\n\n        Loading... [ 95% ] [========= ]";
	while (difftime( time( 0 ), start ) < 1.0);
	
	system("cls");
	start = time( 0 );
	cout << "\n\n\n        Loading... [ 100% ] [==========]";
	while (difftime( time( 0 ), start ) < 0.5);
	system("cls");	
}


//MENU PRINCIPAL #########################	
int x;

void menu_prin() {
			 
	printf ("\n\n ______________ Menu Principal ______________ \n");
	printf ("|                                            |\n");
	printf ("|_ 1 -> Produtos                             |\n");
	printf ("|                                            |\n");
	printf ("|_ 2 -> Clientes                             |\n");
	printf ("|                                            |\n");
	printf ("|_ 3 -> Fornecedores                         |\n");
	printf ("|                                            |\n");
	printf ("|_ 4 -> Parceiros                            |\n");
	printf ("|                                            |\n");
	printf ("|_ 5 -> Ajuda                                |\n");
	printf ("|                                            |\n");
	printf ("|_ 6 -> Sobre                                |\n");
	printf ("|                                            |\n");
	printf ("|_ 7 -> Voltar ao Menu login                 |\n");
	printf ("|                                            |\n");
	printf ("|_ 0 -> Sair                                 |\n");
	printf ("|____________________________________________|\n\n");
	
	printf ("__ Escolha uma opção: ");
	scanf ("%d", &x);
	
	system("cls");
	
} 


//LOGIN
void Login() {

	char login[10];
	char senha[10];
	
	//usando a biblioteca string.h para copiar uma informação
	strcpy(usuario[0].senha, "admin");
	strcpy(usuario[0].login, "admin"); 		
	 
	printf (" ________ Login ________\n\n\n");
	printf (" __ Usuário: ");						  
	scanf("%s", login);
	printf ("\n __ Senha: ");
	scanf("%s", senha);
	
	
	//usando a função strcmp para comparar as strings, caso seja correto (0) sera liberado o acesso
	if ((strcmp(login,usuario[0].login)==0) &&  (strcmp(senha, usuario[0].senha)==0)){ 
		
		system("cls");
		
	}
	else{
		
		system("cls");
		printf("\n\t*** Usuário ou senha incorretos ***\n\n");
		
		system("pause");
		system("cls");
		
		Login();		
	}

}


//CRIAR FORNECEDORES
void criar_fornecedores() {
	
	system("cls");
	
	fstream fin, fout;
	
	fin.open("fornecedores.csv", ios::in);
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	int x = 0;
		
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {			
			linhas.push_back(palavra);			
		}
		
		x = stoi(linhas[0]);		
	}
	
	
	fout.open("fornecedores.csv", ios::out | ios::app);
	
	int n;
	
	cout << "__ Quantos fornecedores você deseja cadastrar? ";
	cin >> n;
	cin.sync();
	system("cls");
	
	int codigo;
	string nome, contato, cnpj, produto;
	
	codigo = x;
	
	for (int z = 0; z < n; z++) {
		
		codigo++;
		
		cout << " _________ Adicionar Fornecedor " << codigo << " _________\n\n";
		
		cout << "_ Informe o nome do fornecedor: ";
		getline(cin, nome);		
		cout << "\n_ Informe o contato do fornecedor (e-mail ou telefone): ";
		getline(cin, contato);		
		cout << "\n_ Informe o CNPJ do fornecedor: ";
		getline(cin, cnpj);		
		cout << "\n_ Qual produto fornece: ";
		getline(cin, produto);
		
		fout << ", " << codigo << ", " << nome << ", " << contato << ", " << cnpj << ", " << produto << "\n";
			 
		system("cls");		
		
	}
	
	cout << " *** Dados gravados com sucesso ***\n\n";		
}


//BUSCAR FORNECEDORES
void buscar_fornecedores() {
	
	system("cls");
	
	cout << " _________ Buscar Fornecedor _________\n\n";
	
	fstream fin;
	
	fin.open("fornecedores.csv", ios::in);
	
	int linhan1, linhan2, cont = 0;
	
	cout << "__ Digite o código do fornecedor para vizualizar seus dados: ";
	cin >> linhan1;
	
	system("cls");
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			
			linhas.push_back(palavra);
			
		}
		
		linhan2 = stoi(linhas[0]);
		
		if (linhan2 == linhan1) {
			
			cont = 1;
					 
			cout << " _________ Fornecedor " << linhas[0] << " _________\n\n";
			cout << "  Código: " << linhas[0] << "\n";
			cout << "  Nome: " << linhas[1] << "\n";
			cout << "  Contato: " << linhas[2] << "\n";
			cout << "  CNPJ: " << linhas[3] << "\n";
			cout << "  Produto fornecido: " << linhas[4] << "\n";
			cout << " _______________________________\n\n";
			break;
			
		}		
		
	}	
	
	if (cont == 0) {
		
		cout << " *** Dados não encontrados *** \n\n";
		system("pause");
		system("cls");
	}	
}


//LISTAR FORNECEDORES
void listar_fornecedores() {
	
	system("cls");
	
	fstream fin;
	
	fin.open("fornecedores.csv", ios::in);
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	cout << " _________ Lista de Fornecedores Cadastrados _________ \n\n\n";
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);
		}
				 
		cout << " _________ Fornecedor " << linhas[0] << " _________ \n\n";
		
		cout << "  Nome: " << linhas[1] << "\n";
		cout << "  Contato: " << linhas[2] << "\n";
		cout << "  CNPJ: " << linhas[3] << "\n";
		cout << "  Produto fornecido: " << linhas[4] << "\n";
		
		cout << " _______________________________\n\n\n";
		
	}
	
}


//ATUALIZAR FORNECEDORES
void atualizar_fornecedores() {
	
	system("cls");
	
	cout << " _________ Atualizar Dados dos Fornecedores _________ \n\n";
	
	fstream fin, fout;
	
	fin.open("fornecedores.csv", ios::in);
	
	fout.open("attfornecedores.csv", ios::out);
	
	int linhan1, linhan2, indice, sub, cont = 0;
	vector<string> linhas;
	string linha, palavra, novo, temp;
	
	cout << "__ Digite o código do fornecedor para atualizar os dados: ";
	cin >> linhan1;
	cin.sync();
	
	cout << "\n\n_ 1 - Alterar nome\n";
	cout << "_ 2 - Alterar contato\n";
	cout << "_ 3 - Alterar CNPJ\n";
	cout << "_ 4 - Alterar produto fornecido\n\n";
	cout << "__ Escolha uma opção: ";
	
	cin >> sub;
	cin.sync();
	system("cls");
	
	switch (sub) {
		
		case 1:					
			cout << " _________ Alterar nome do Fornecedor " << linhan1 << " _________\n\n";
			indice = 1;
			break;			
			
		case 2:			
			cout << " _________ Alterar contato do Fornecedor " << linhan1 << " _________\n\n";
			indice = 2;
			break;
			
		case 3:			
			cout << " _________ Alterar CNPJ do Fornecedor " << linhan1 << " _________\n\n";
			indice = 3;
			break;
			
		case 4:			
			cout << " _________ Alterar produto do Fornecedor " << linhan1 << " _________\n\n";
			indice = 4;
			break;
			
		default:			
			cout << " *** Opção inválida *** \n\n";
			system("pause");
			atualizar_fornecedores();
			break;
		
	}
	
	cout << "__ Informe o novo dado: ";
	getline(cin, novo);
	system("cls");
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);
		}
		
		linhan2 = stoi(linhas[0]);
		
		int row_size = linhas.size();
		
		if (linhan2 == linhan1) {
			
			cont = 1;
			
			stringstream convert;
			
			convert << novo;
			
			linhas[indice] = convert.str();
			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";
					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}			
		}		
		else {			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}			
		}		
		if (fin.eof()) {			
			break;			
		}				
	}
	
	if (cont == 1) {
		
		cout << " *** Dados atualizados com sucesso!! ***\n\n";		
	} else if (cont == 0) {
		
		cout << " *** Dados não encontrados ***\n\n";
		system("pause");
		atualizar_fornecedores();
	}
	
	fin.close();
	fout.close();
	
	remove("fornecedores.csv");
	rename("attfornecedores.csv", "fornecedores.csv");
		
}


//DELETAR FORNECEDORES
void deletar_fornecedores() {
	
	system("cls");
	
	fstream fin, fout;
	
	fin.open("fornecedores.csv", ios::in);
	
	fout.open("attfornecedores.csv", ios::out);
	
	int linhan1, linhan2, cont = 0;
	
	vector<string> linhas;
	
	string linha, palavra, temp;	
	
	cout << " _________ Excluir dados de Fornecedores _________\n\n";
	
	cout << "__ Digite o código do Fornecedor para excluir os dados: ";
	cin >> linhan1;
	system("cls");
	
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {			
			linhas.push_back(palavra);
		}
		
		int row_size = linhas.size();
		
		linhan2 = stoi(linhas[0]);
		
		if (linhan2 != linhan1) {
			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}
						
		} else {
			
			cont = 1;
		}		
		if (fin.eof()) {		
			break;	
		}
	}	
	
	if (cont == 1) {
		
		cout << " *** Dados deletados com sucesso!! *** \n\n";		
	} else {
		
		cout << " *** Dados não encontrados!! ***\n\n";
	}	
	
	fin.close();
	fout.close();
	
	remove("fornecedores.csv");
	rename("attfornecedores.csv", "fornecedores.csv");	
}


//MENU FORNECEDORES #########################
void menu_fornecedores() {
	
	int while_fornecedores = 1;
	
	while (while_fornecedores > 0) {
		
		cout << "  _________ Fornecedores _________\n";
		cout << " |                                |\n";		
		cout << " | 1 -> Cadastrar novo            |\n";
		cout << " |                                |\n";
		cout << " | 2 -> Listar todos              |\n";
		cout << " |                                |\n";
		cout << " | 3 -> Buscar Fornecedor         |\n";
		cout << " |                                |\n";
		cout << " | 4 -> Atualizar Fornecedor      |\n";
		cout << " |                                |\n";
		cout << " | 5 -> Deletar Fornecedor        |\n";
		cout << " |                                |\n";
		cout << " | 0 -> Voltar                    |\n";
		cout << " |________________________________|\n\n";
		
		cout << "__ Escolha uma opção: ";		
		cin >> while_fornecedores;
		system("cls");
		
		switch (while_fornecedores) {
			
			case 1:
				criar_fornecedores();
				system("pause");				
				system("cls");				
				break;
				
			case 2:
				listar_fornecedores();
				system("pause");				
				system("cls");	
				break;
				
			case 3:
				buscar_fornecedores();
				system("pause");				
				system("cls");	
				break;
				
			case 4:
				atualizar_fornecedores();
				system("pause");				
				system("cls");	
				break;
				
			case 5:
				deletar_fornecedores();
				system("pause");				
				system("cls");	
				break;
				
			case 0:
				while_fornecedores = 0;
				break;
				
			default:
				cout << " *** Opção inválida *** \n\n";
				break;		
		}				
	}	
}


//CRIAR PARCEIROS
void criar_parceiros() {
	
	system("cls");
	
	fstream fin, fout;
	
	fin.open("parceiros.csv", ios::in);
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	int x = 0;
		
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {			
			linhas.push_back(palavra);			
		}
		
		x = stoi(linhas[0]);		
	}
	
	
	fout.open("parceiros.csv", ios::out | ios::app);
	
	int n;
	
	cout << "__ Quantos parceiros você deseja cadastrar? ";
	cin >> n;
	cin.sync();
	system("cls");
	
	int codigo;
	string nome, contato, cnpj, produtos;
	
	codigo = x;
	
	for (int z = 0; z < n; z++) {
		
		codigo++;
		
		cout << " _________ Adicionar Parceiro " << codigo << " _________\n\n";
		
		cout << "_ Informe o nome do parceiro: ";
		getline(cin, nome);
		
		cout << "\n_ Informe o contato do parceiro (e-mail ou telefone): ";
		getline(cin, contato);
		
		cout << "\n_ Informe o CNPJ do parceiro: ";
		getline(cin, cnpj);
		
		cout << "\n_ Informe o(s) produto(s) anunciados pelo parceiro: ";
		getline(cin, produtos);
		
		fout << ", "
			 << codigo << ", "
			 << nome << ", "
			 << contato << ", "
			 << cnpj << ", "
			 << produtos
			 << "\n";
			 
		system("cls");		
		
	}
	
	cout << " *** Dados gravados com sucesso ***\n\n";	
}


//BUSCAR PARCEIROS
void buscar_parceiros() {
	
	system("cls");
	
	cout << " _________ Pesquisar Parceiros _________\n\n";
	
	fstream fin;
	
	fin.open("parceiros.csv", ios::in);
	
	int linhan1, linhan2, cont = 0;
	
	cout << "__ Digite o código do parceiro para vizualizar seus dados: ";
	cin >> linhan1;
	
	system("cls");
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			
			linhas.push_back(palavra);
			
		}
		
		linhan2 = stoi(linhas[0]);
		
		if (linhan2 == linhan1) {
			
			cont = 1;
					 
			cout << " _________ Parceiro " << linhas[0] << " _________\n\n";
			
			cout << "  Código: " << linhas[0] << "\n";
			cout << "  Nome: " << linhas[1] << "\n";
			cout << "  Contato: " << linhas[2] << "\n";
			cout << "  CNPJ: " << linhas[3] << "\n";
			cout << "  Produto(s) anunciado(s): " << linhas[4] << "\n";			
			cout << " _______________________________\n\n";
			break;
			
		}		
		
	}	
	
	if (cont == 0) {
		
		cout << " *** Dados não encontrados *** \n\n";
		system("pause");
		system("cls");
	}	
}


//LISTAR PARCEIROS
void listar_parceiros() {
	
	system("cls");
	
	fstream fin;
	
	fin.open("parceiros.csv", ios::in);
	
	vector<string> linhas;
	string linha, palavra, temp;
	
	cout << " _________ Lista de Parceiros Cadastrados _________ \n\n\n";
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);
		}
				 
		cout << " _________ Parceiro " << linhas[0] << " _________ \n\n";
		
		cout << "  Nome: " << linhas[1] << "\n";
		cout << "  Contato: " << linhas[2] << "\n";
		cout << "  CNPJ: " << linhas[3] << "\n";
		cout << "  Produto(s) anunciado(s): " << linhas[4] << "\n";		
		cout << " _______________________________\n\n\n";
		
	}
	
}


//ATUALIZAR PARCEIROS
void atualizar_parceiros() {
	
	system("cls");
	
	cout << " _________ Atualizar Dados dos Parceiros _________ \n\n";
	
	fstream fin, fout;
	
	fin.open("parceiros.csv", ios::in);
	
	fout.open("attparceiros.csv", ios::out);
	
	int linhan1, linhan2, indice, sub, cont = 0;
	vector<string> linhas;
	string linha, palavra, novo, temp;
	
	cout << "__ Digite o código do parceiro para atualizar os dados: ";
	cin >> linhan1;
	cin.sync();
	
	cout << "\n\n_ 1 -> Alterar nome\n";
	cout << "_ 2 -> Alterar contato\n";
	cout << "_ 3 -> Alterar CNPJ\n";
	cout << "_ 4 -> Alterar Produto(s) anunciado(s)\n\n";
	
	cout << "__ Escolha uma opção: ";	
	cin >> sub;
	cin.sync();
	system("cls");
	
	switch (sub) {
		
		case 1:					
			cout << " _________ Alterar nome do Parceiro " << linhan1 << " _________\n\n";
			indice = 1;
			break;			
			
		case 2:			
			cout << " _________ Alterar contato do Parceiro " << linhan1 << " _________\n\n";
			indice = 2;
			break;
			
		case 3:			
			cout << " _________ Alterar CNPJ do Parceiro " << linhan1 << " _________\n\n";
			indice = 3;
			break;
			
		case 4:			
			cout << " _________ Alterar Produto(s) do Parceiro " << linhan1 << " _________\n\n";
			indice = 4;
			break;
			
		default:			
			cout << " *** Opção inválida *** \n\n";
			system("pause");
			atualizar_parceiros();
			break;
		
	}
	
	cout << "__ Informe o novo dado: ";
	getline(cin, novo);
	system("cls");
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);
		}
		
		linhan2 = stoi(linhas[0]);
		
		int row_size = linhas.size();
		
		if (linhan2 == linhan1) {
			
			cont = 1;
			
			stringstream convert;
			
			convert << novo;
			
			linhas[indice] = convert.str();
			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";
					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}			
		}		
		else {			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}			
		}		
		if (fin.eof()) {			
			break;			
		}				
	}
	
	if (cont == 1) {
		
		cout << " *** Dados atualizados com sucesso!! ***\n\n";		
	} else if (cont == 0) {
		
		cout << " *** Dados não encontrados!! ***\n\n";
		system("pause");
		atualizar_parceiros();
	}
	
	fin.close();
	fout.close();
	
	remove("parceiros.csv");
	rename("attparceiros.csv", "parceiros.csv");
		
}


//DELETAR PARCEIROS
void deletar_parceiros() {
	
	system("cls");
	
	fstream fin, fout;
	
	fin.open("parceiros.csv", ios::in);
	
	fout.open("attparceiros.csv", ios::out);
	
	int linhan1, linhan2, cont = 0;
	
	vector<string> linhas;
	
	string linha, palavra, temp;	
	
	cout << " _________ Excluir dados de Parceiros _________\n\n";
	
	cout << "__ Digite o código do Parceiro para excluir os dados: ";
	cin >> linhan1;
	system("cls");
	
	
	while (fin >> temp) {
		
		linhas.clear();
		
		getline(fin, linha);
		
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) {			
			linhas.push_back(palavra);
		}
		
		int row_size = linhas.size();
		
		linhan2 = stoi(linhas[0]);
		
		if (linhan2 != linhan1) {
			
			if (!fin.eof()) {
				
				fout << ",";
				
				for (int i = 0; i < row_size - 1; i++) {
					
					fout << linhas[i] << ",";					
				}
				
				fout << linhas[row_size - 1] << "\n";				
			}
						
		} else {
			
			cont = 1;
		}		
		if (fin.eof()) {		
			break;	
		}
	}	
	
	if (cont == 1) {
		
		cout << " *** Dados deletados com sucesso!! *** \n\n";		
	} else {
		
		cout << " *** Dados não encontrados!! Não foi possível excluir ***\n\n";
	}	
	
	fin.close();
	fout.close();
	
	remove("parceiros.csv");
	rename("attparceiros.csv", "parceiros.csv");	
}


//MENU PARCEIROS #########################
void menu_parceiros() {
	
	int while_parceiros = 1, op_parceiros;
	
	while (while_parceiros > 0) {
		
		cout << "  _________ Parceiros _________\n";
		cout << " |                             |\n";		
		cout << " | 1 -> Cadastrar novo         |\n";
		cout << " |                             |\n";
		cout << " | 2 -> Listar todos           |\n";
		cout << " |                             |\n";
		cout << " | 3 -> Buscar Parceiro        |\n";
		cout << " |                             |\n";
		cout << " | 4 -> Atualizar Parceiro     |\n";
		cout << " |                             |\n";
		cout << " | 5 -> Deletar Parceiro       |\n";
		cout << " |                             |\n";
		cout << " | 0 -> Voltar                 |\n";
		cout << " |_____________________________|\n\n";	
		
		cout << "__ Escolha uma opção: ";	
		cin >> while_parceiros;
		system("cls");
		
		switch (while_parceiros) {
			
			case 1:
				criar_parceiros();	
				system("pause");				
				system("cls");				
				break;
				
			case 2:
				listar_parceiros();
				system("pause");				
				system("cls");	
				break;
				
			case 3:
				buscar_parceiros();
				system("pause");				
				system("cls");	
				break;
				
			case 4:
				atualizar_parceiros();
				system("pause");				
				system("cls");	
				break;
				
			case 5:
				deletar_parceiros();
				system("pause");				
				system("cls");	
				break;
				
			case 0:
				while_parceiros = 0;
				break;
				
			default:
				cout << " *** Opção inválida *** \n\n";
				break;		
		}	
	}	
}


//MENU PRODUTOS #########################
int opp1, opp2, cont, opex;

void menuP(){
	
	cout << "  _________ Produtos _________\n";
	cout << " |                            |\n";		
	cout << " | 1 -> Listar todos          |\n";
	cout << " |                            |\n";
	cout << " | 2 -> Cadastrar novo        |\n";
	cout << " |                            |\n";
	cout << " | 3 -> Atualizar Produto     |\n";
	cout << " |                            |\n";
	cout << " | 4 -> Deletar Produto       |\n";
	cout << " |                            |\n";
	cout << " | 5 -> Vendas                |\n";
	cout << " |                            |\n";
	cout << " | 0 -> Voltar                |\n";
	cout << " |____________________________|\n\n";
		
	cout << "__ Escolha uma opção: ";
	cin >> opp1;

}	


//LISTAR PRODUTOS
void listarP(){
	int opp2;
	system("cls");
	cout << " _________ Lista de Fornecedores Cadastrados _________ \n\n\n";
	
	fstream fin; 
	
	fin.open("produtos.csv",ios::in);
	
	vector<string> linhas; 
	string linha, palavra, temp; 

	int op;
	
	while(fin >> temp) { 
	
		linhas.clear();
		getline(fin, linha);
		stringstream s(linha);
		
		char virgula = ',';
		
		while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);
        }
        
        cout << " _________ Produto " << linhas[0] << " _________ \n\n";
		
		cout << "  Categoria: " << linhas[1] << "\n\n";
		cout << "  Tipo: " << linhas[2] << "\n";
		cout << "  Marca: " << linhas[3] << "\n";
		cout << "  Modelo: " << linhas[4] << "\n";
        cout << "  Preco: " << linhas[5] << "\n";
		
		cout << " _______________________________\n\n\n";  
	}
 }


//DELETAR PRODUTOS
void excluirP(){ 
	
 	system("cls");

    fstream fin, fout; 
    				  
    fin.open("produtos.csv", ios::in); 

    fout.open("attprodutos.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
    
    cout << " _________ Excluir Produtos _________\n\n";

	cout << "__ Digite o código do produto para excluir: ";
    cin >> linhan1;
    system("cls");

    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
            if (!fin.eof()) { 
            	fout << ",";
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
        } else {
            cont = 1;
        }
        if (fin.eof()) {
            break;
        }
    }
    if (cont == 1) {
        cout << " *** Produto deletado com sucesso!! *** \n\n";
    } else {
        cout << " *** Produto não encontrado!! *** \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("produtos.csv"); 
    rename("attprodutos.csv", "produtos.csv"); 
}	


//ATUALIZAR PRODUTOS
void atualizarP(){
	
	system("cls");
	cout << " _________ Atualizar Dados dos Produtos _________ \n\n";
	fstream fin, fout;
	fin.open("produtos.csv", ios::in);
	fout.open("attprodutos.csv", ios::out);

	int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 
    cout << "__ Digite o código do Produto que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "\n\n_ 1 - Alterar a Categoria (Hardware/Periférico): \n";
    cout << "_ 2 - Alterar o Tipo: \n";
    cout << "_ 3 - Alterar a Marca: \n";
    cout << "_ 4 - Alterar o Modelo: \n";
    cout << "_ 5 - Alterar o Preço: \n\n";
	
	cout << "__ Escolha uma opção: ";
    cin >> sub;
  	cin.sync();
  	system("cls");

	switch(sub) { 
  		case 1:					
			cout << " _________ Alterar Categoria do Produto " << linhan1 << " _________\n\n";
  			indice = 1;
  			break;
  		case 2:					
			cout << " _________ Alterar Tipo do Produto " << linhan1 << " _________\n\n";
  			indice = 2;
  			break;
  		case 3:					
			cout << " _________ Alterar Marca do Produto " << linhan1 << " _________\n\n";
  			indice = 3;
  			break;
  		case 4:					
			cout << " _________ Alterar Modelo do Produto " << linhan1 << " _________\n\n";
  			indice = 4;
  			break;
  		case 5:					
			cout << " _________ Alterar Preço do Produto " << linhan1 << " _________\n\n";
  			indice = 5;
  			break;
  		default:
	        cout << " *** Opção inválida *** \n\n";
			system("pause");
			atualizarP();
			break;  			
	}

    cout << "__ Informe o novo dado: ";
	getline(cin, novo);
	system("cls");

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo;

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    
    if (cont == 1) {
		
		cout << " *** Dados atualizados com sucesso!! ***\n\n";		
	} else if (cont == 0) {
		
		cout << " *** Dados não encontrados ***\n\n";
		system("pause");
		atualizarP();
	}

    		fin.close();
    		fout.close(); 

		    remove("produtos.csv"); 
    		rename("attprodutos.csv", "produtos.csv");
	
}


//CADASTRAR PRODUTOS
void cadastroP(){
	system("cls"); 
	    
    fstream fin, fout; 
    				 
    fin.open("produtos.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}
	
	fout.open("produtos.csv", ios::out | ios::app);
	
	int n;
	    
    cout << "__ Você deseja cadastrar quantos Produtos? ";
	cin >> n;
    cin.sync();
    system("cls");
	
	int codigo;
	string hp, preco, tipo, marca, modelo;
	
	codigo = x; 
	
	 for(int i =0; i < n ; i++){
	 	
	 	codigo++;
	 	
    	cout << " _________ Adicionar Produto " << codigo << " _________\n\n";
    	
		cout << "__ Hardware/Periférico: ";
		getline(cin, hp);
		cout << "__ Digite o tipo (placa de vídeo, processador e etc): ";
		getline(cin, tipo);
		cout << "__ Digite a marca do(a) "<< tipo << ": ";
		getline(cin, marca);
		cout << "__ Digite o modelo do produto:  ";
		getline(cin, modelo);
		cout << "__ Digite o preço do produto: ";
		getline(cin, preco);
		
		fout << ", " << codigo << ", " << hp << ", " << tipo << ", " << marca << ", " << modelo << ", R$" << preco << ", "<< "\n";
		system("cls");
	}	
	
	cout << " *** Dados gravados com sucesso ***\n\n";
}


//VENDAS PRODUTOS
void vendas(){
	
	int opv;
	
	system("cls");
	
	cout << " __________ Vendas ___________\n\n";
	
	cout << "_ 1 - Hardwares\n";
	cout << "_ 2 - Periféricos\n";
	cout << "_ 3 - Total\n\n";
	
	cout << "__ Escolha uma opção: ";
	cin >> opv;
	system("cls");
	
	switch (opv) {
		
		case 1:
			cout << " __________ Hardwares ___________\n\n";
			cout << "_ Quantidade vendidos: 18\n\n";
			cout << "_ Total vendido: R$30.545,00\n\n";
			break;
		case 2:
			cout << " __________ Periféricos ___________\n\n";
			cout << "_ Quantidade vendidos: 196\n\n";
			cout << "_ Total vendido: R$10.793,00\n\n";
			break;
		case 3:
			cout << " __________ Todos Produtos ___________\n\n";
			cout << "_ Quantidade vendidos: 214\n\n";
			cout << "_ Total de vendas: R$41.338,00\n\n";
			break;
		default:
			cout << " *** Opção inválida ***\n\n";
			system("pause");
			vendas();
			break;
		
	}	
}


//ESCOLHA PRODUTOS
void escolhaP(){
	menuP();
	switch(opp1) {
		case 1: 
			listarP();
			system("pause");
			system("cls");
			escolhaP();
			break;
			
		case 2: 
			cadastroP();
			system("pause");
			system("cls");
			escolhaP();
			break; 
		case 3:
			atualizarP();
			system("pause");
			system("cls");
			escolhaP();
			break;
		case 4: 
			excluirP();
			system("pause");
			system("cls");
			escolhaP();
			break; 
		case 5:
			vendas();
			system("pause");
			system("cls");
			escolhaP();
			break; 
		case 0: 
			break; 			 
		default:
			cout << " *** Opção inválida *** \n\n";
			escolhaP();
			break;
	}
}


//MENU CLIENTES #########################
int opc1, op, opex1, opc2, opa1, opa2;

void menuC(){
	
	cout << "  ___________ Clientes ___________\n";
	cout << " |                                |\n";
	cout << " | 1 -> Cadastrar clientes        |\n";
	cout << " |                                |\n";
	cout << " | 2 -> Buscar clientes           |\n";
	cout << " |                                |\n";
	cout << " | 3 -> Listar todos              |\n";
	cout << " |                                |\n";
	cout << " | 4 -> Atualizar dados           |\n";
	cout << " |                                |\n";
	cout << " | 5 -> Excluir Clientes          |\n";
	cout << " |                                |\n";
	cout << " | 0 -> Voltar                    |\n";
	cout << " |________________________________|\n";
			
	cout << "__ Escolha uma opção: ";
	cin >> opc1;

}


//CADASTRO CLIENTES
void cadastroC() {
	
	system("cls"); 
	    
    fstream fin, fout; 
    				 

    fin.open("clientes.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("clientes.csv", ios::out | ios::app); 
    
    int n;
	    
    cout << "__ Digite quantos clientes deseja cadastrar: ";
	cin >> n;
    cin.sync();
    system("cls");
  
  
    int codigo;
    string nome, telefone, email, sobrenome, cep, numerores,  idade, cpf, compras;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << " _________ Adicionar Cliente " << codigo << " _________\n\n";
  		cout << "_ Nome do cliente: ";
        getline(cin, nome);
        cout << "_ Sobrenome do cliente: ";
        getline(cin, sobrenome);
        cout << "_ Informe o idade do cliente: ";
        getline(cin, idade);
        cout << "_ Informe o cpf do cliente: ";
        getline(cin, cpf);
        cout << "_ CEP do cliente: ";
        getline(cin, cep);
        cout<< "_ Numero da residência do cliente: ";
        getline(cin, numerores);
        cout << "_ Telefone do cliente: ";
        getline(cin, telefone);
        cout << "_ E-mail do cliente: ";
        getline(cin, email);
        cout << "_ Compras do cliente (produtos): ";
        getline(cin, compras);
        cin.sync();
  
        fout << ", " << codigo << ", " << nome << ", " << sobrenome << ", " << idade << ", " << cpf << ", " << cep << ", " << numerores << ", " << telefone << ", " <<  email << ", " << compras << ", " <<  "\n";
        system("cls");
    }
    
	cout << " *** Dados gravados com sucesso ***\n\n";
}


//BUSCAR CLIENTES
void buscarC() {
	
	system("cls");  
	
    fstream fin; 
    			
    fin.open("clientes.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "__ Digite o código do cliente para exibir seu cadastro: ";
    cin >> linhan1;
    system("cls");
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); 
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            
            cout << " ____________ Cliente " << linhas[0] << " ____________ \n\n";
            cout << "_ Código: " << linhas[0] << "\n";
            cout << "_ Nome: " <<  linhas[1];
            cout << "\t Sobrenome:" << linhas[2]<< "\n";
            cout << "_ Idade: " << linhas[3];
            cout << "\tCpf: " << linhas[4] << "\n";
            cout << "_ Cep: " << linhas[5] << "\n";
            cout << "_ Número da residencia: " << linhas[6];
            cout << "\tTelefone: " << linhas[7] << "\n";
            cout << "_ E-mail: " << linhas[8] << "\n";
            cout << "_ Produtos comprados: " << linhas[9] << "\n";
            cout << " ___________________________________\n\n";
            break;
        }
    }
    if (cont == 0) {
		
		cout << " *** Dados não encontrados *** \n\n";
		system("pause");
		system("cls");
	}	
} 


//LISTAR CLIENTES
void listarC() {
	
	system("cls"); 
	
	fstream fin; 

    fin.open("clientes.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    
    cout << "__________ Lista de Clientes Cadastrados __________ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 

        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

		cout << " ____________ Cliente " << linhas[0] << " ____________ \n\n";
        cout << "_ Código: " << linhas[0] << "\n";
        cout << "_ Nome: " <<  linhas[1];
        cout << "\t Sobrenome:" << linhas[2]<< "\n";
        cout << "_ Idade: " << linhas[3];
        cout << "\tCpf: " << linhas[4] << "\n";
        cout << "_ Cep: " << linhas[5] << "\n";
        cout << "_ Número da residencia: " << linhas[6];
        cout << "\tTelefone: " << linhas[7] << "\n";
        cout << "_ E-mail: " << linhas[8] << "\n";
        cout << "_ Produtos comprados: " << linhas[9] << "\n";
        cout << " ___________________________________\n\n";

    }
}
  
  
//ATUALIZAR CLIENTES
void atualizarC(){
	system("cls"); 
	
	cout << " _________ Atualizar dados dos Clientes _________ \n\n";
	
    fstream fin, fout; 
    				  
    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 

    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "__ Digite o código do cliente para atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "\n\n_ 1 - Alterar o Nome \n";
    cout << "_ 2 - Alterar o Sobrenome \n";
    cout << "_ 3 - Alterar a Idade \n";
    cout << "_ 4 - Alterar o CPF \n";
    cout << "_ 5 - Alterar o CEP \n";
    cout << "_ 6 - Alterar o Numero da residencia\n";
    cout << "_ 7 - Alterar o Telefone\n";
    cout << "_ 8 - Alterar o Email\n ";
    cout << "_ 9 - Alterar Produtos comprados\n\n";
    
	cout << "__ Escolha uma opção: ";
    cin >> sub;
  	cin.sync();
  	system("cls");
  	
  	switch(sub) { 
  		case 1:
  		    cout << " _________ Alterar nome do cliente _________ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << " _________ Alterar Sobrenome do cliente _________ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << " _________ Alterar a Idade do cliente _________ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << " _________ Alterar o CPF do cliente _________ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << " _________ Alterar CEP do cliente _________ \n\n";
  			indice = 5;
  			break;
        case 6:
            cout << " _________ Alterar o Numero da Residencia do cliente _________ \n\n";
  			indice = 6;
            break; 
        case 7: 
            cout << " _________ Alterar o Telefone do cliente _________ \n\n";
  			indice = 7;
            break; 
        case 8: 
            cout << " _________ Alterar Email do cliente _________ \n\n";
  			indice = 8;
            break;
        case 9: 
            cout << " _________ Alterar Produtos Comprados do cliente _________ \n\n";
  			indice = 9;
            break;
  		default:
	        cout << " *** Opção inválida *** \n\n";
			system("pause");
			atualizarC();
			break; 			
	  }

    cout << "__ Informe o novo dado: "; 
    getline(cin, novo);
    system("cls");

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 

        char virgula = ','; 

        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert;

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) {
		
		cout << " *** Dados atualizados com sucesso!! ***\n\n";		
	} else if (cont == 0) {
		
		cout << " *** Dados não encontrados ***\n\n";
		system("pause");
		atualizarC();
	}

    fin.close(); 
    fout.close(); 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv"); 
}


//DELETAR CLIENTES
void excluirC() {
	
	system("cls"); 
	
	cout << " __________ Excluir Clientes __________ \n\n";

    fstream fin, fout; 
    				  
    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 

    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 

	cout << "__ Digite o código do cliente para excluir: ";
    cin >> linhan1;
    system("cls");

    while (fin >> temp) { 

        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra);
        }
  
        int row_size = linhas.size();
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 

            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << " *** Dados deletados com sucesso!! *** \n";
    } else {
        cout << " *** Dados não encontrados!! *** \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv"); 	
}


//ESCOLHA CLIENTES
void escolhaC(){
	
    menuC();
    
    switch (opc1) {
    	
	    case 1:
	        cadastroC();
	        system("pause");
	        system("cls");
	        escolhaC();
	        break;
	    case 2: 
	        buscarC();
	        system("pause");
	        system("cls");
	        escolhaC();
	        break;
	    case 3:
	        listarC();	
	        system("pause");
	        system("cls");
	        escolhaC();
	        break;
	    case 4: 
	        atualizarC();
	        system("pause");
	        system("cls");
	        escolhaC();
	        break;
	    case 5: 
	        excluirC();
	        system("pause");
	        system("cls");
	        escolhaC();
	        break;
	    case 0:
	    	system("cls");
	        break;
	    default:
			cout << " *** Opção inválida *** \n\n";
			escolhaC();
			break;
	}
}


//AJUDA
void ajuda(){
	
	system("cls");
	cout << "  _______________ Ajuda _______________\n";
	cout << " |                                     |\n";
	cout << " |__ Dúvidas em:                       |\n";
	cout << " |                                     |\n";
	cout << " |_ 1 - Produtos                       |\n";
	cout << " |                                     |\n";
	cout << " |_ 2 - Clientes                       |\n";
	cout << " |                                     |\n";
	cout << " |_ 3 - Parceiros                      |\n";
	cout << " |                                     |\n";
	cout << " |_ 4 - Fornecedores                   |\n";
	cout << " |                                     |\n";
	cout << " |_ 0 - Voltar                         |\n";
	cout << " |_____________________________________|\n\n";
	cout << "__ Escolha uma opção: ";
	cin >> opa1;
	switch(opa1){
		case 1:
			system("cls");
			cout << "  ________ Dúvidas em Produtos ________\n";
			cout << " |                                     |\n";
			cout << " |_ 1 - Como listar produtos:          |\n";
			cout << " |                                     |\n";
			cout << " |_ 2 - Como Cadastrar um Produto:     |\n";
			cout << " |                                     |\n";
			cout <<	" |_ 3 - Como Atualizar um Produto:     |\n";
			cout << " |                                     |\n";
			cout << " |_ 4 - Como Excluir um produto:       |\n";
			cout << " |                                     |\n";
			cout << " |_ 0 - Voltar                         |\n";
			cout << " |_____________________________________|\n\n";
			cout << "__ Escolha uma opção: ";
			cin >> opa2;
			switch(opa2){
				case 1: 
					system("cls");
					cout << " ____ Listar Produtos ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Listar Produtos para vê-la\n\n";
					system("pause");
					ajuda();
					break;
				case 2: 
					system("cls");
					cout << "____ Cadastrar Produtos ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Cadastrar Produtos\n\n";
					cout << "_ Passo 2 \n\n";
					cout<< "R: Digite quantos produtos deseja cadastrar (Automaticamente ele irá organizar os dados no banco de dados)\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Digite os dados do Produto\n\n";
					system("pause");
					ajuda();
					break; 
				case 3:
					system("cls");
					cout << "____ Atualizar Produtos ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Atualizar Produtos\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do produto que deseja atualizar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Selecione a informação que deseja alterar, após isso basta digitar a nova informação.\n\n";
					system("pause");
					ajuda();
					break; 
				case 4: 
					system("cls");
					cout << "__ Excluir Produtos__\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Excluir Produtos\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do produto que deseja excluir\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do produto, caso exista no banco de dados, ele será excluido.\n\n";
					system("pause");
					ajuda();
					break;
				case 0:
					system("cls");
					ajuda();
					break; 
				default:
					system("cls");
					cout << " *** Opção Inválida! Tente Novamente ***\n\n";
					system("pause");
					ajuda();
					break;
			}
			break;
		case 2: 
			system("cls");
			cout << "  _______ Dúvidas em Clientes _______\n";
			cout << " |                                   |\n";
			cout << " |_ 1 - Como listar Clientes:        |\n";
			cout << " |                                   |\n";
			cout << " |_ 2 - Como Cadastrar Clientes:     |\n";
			cout << " |                                   |\n";
			cout <<	" |_ 3 - Como Atualizar Clientes:     |\n";
			cout << " |                                   |\n";
			cout << " |_ 4 - Como Excluir Clientes:       |\n";
			cout << " |                                   |\n";
			cout << " |_ 5 - Como buscar Clientes:        |\n";
			cout << " |                                   |\n";
			cout << " |_ 0 - Voltar                       |\n";
			cout << " |___________________________________|\n\n";
			cout << "__ Escolha uma opção: ";
			cin >> opa2;
			switch(opa2){
				case 1: 
					system("cls");
					cout << "____ Listar Clientes ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Listar Produtos para vê-la\n\n";
					system("pause");
					ajuda();
					break;
				case 2: 
					system("cls");
					cout << "____ Cadastrar Clientes ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Cadastrar Clientes\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite quantos Clientes deseja cadastrar (Automaticamente ele irá organizar os dados no banco de dados)\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Digite os dados do Clientes\n\n";
					system("pause");
					ajuda();
					break; 
				case 3:
					system("cls");
					cout << "____ Atualizar Clientes ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Atualizar Clientes\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Cliente que deseja atualizar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Selecione a informação que deseja alterar, após isso basta digitar a nova informação.\n\n";
					system("pause");
					ajuda();
					break; 
				case 4: 
					system("cls");
					cout << "____ Excluir Clientes ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Excluir Clientes\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Cliente que deseja excluir\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Cliente, caso exista no banco de dados, ele será excluido.\n\n";
					system("pause");
					ajuda();
					break;
				case 5: 
					system("pause");
					cout << "____ Buscar Clientes ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Buscar Clientes\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Cliente que deseja buscar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Cliente, caso exista no banco de dados, exibirá seus dados.\n\n";
					system("pause");
					ajuda();
					break;
				case 0:
					system("cls");
					ajuda();
					break; 
				default:
					system("cls");
					cout << " *** Opção Inválida! Tente Novamente ***\n\n";
					system("pause");
					ajuda();
					break;
			}
			break;
		case 3:
			system("cls");
			cout << "  _______ Dúvidas em Parceiros _______\n";
			cout << " |                                   |\n";
			cout << " |_ 1 - Como listar Parceiros:       |\n";
			cout << " |                                   |\n";
			cout << " |_ 2 - Como Cadastrar Parceiros:    |\n";
			cout << " |                                   |\n";
			cout <<	" |_ 3 - Como Atualizar Parceiros:    |\n";
			cout << " |                                   |\n";
			cout << " |_ 4 - Como Excluir Parceiros:      |\n";
			cout << " |                                   |\n";
			cout << " |_ 5 - Como buscar Parceiros:       |\n";
			cout << " |                                   |\n";
			cout << " |_ 0 - Voltar                       |\n";
			cout << " |___________________________________|\n\n";
			cout << "__ Escolha uma opção: ";
			cin >> opa2;
			switch(opa2){
				case 1: 
					system("cls");
					cout << "____ Listar Parceiros ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Listar Parceiros para vê-la\n";
					system("pause");
					ajuda();
					break;
				case 2: 
					system("cls");
					cout << "____ Cadastrar Parceiros ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Cadastrar Parceiros\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite quantos Parceiros deseja cadastrar (Automaticamente ele irá organizar os dados no banco de dados)\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Digite os dados do Parceiro\n\n";
					system("pause");
					ajuda();
					break; 
				case 3:
					system("cls");
					cout << "____ Atualizar Parceiros ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Atualizar Parceiros\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Parceiro que deseja atualizar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Selecione a informação que deseja alterar, após isso basta digitar a nova informação.\n\n";
					system("pause");
					ajuda();
					break; 
				case 4: 
					system("cls");
					cout << "____ Excluir Parceiros ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Excluir Parceiros\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Parceiro que deseja excluir\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Parceiro, caso exista no banco de dados, ele será excluido.\n\n";
					system("pause");
					ajuda();
					break;
				case 5: 
					system("pause");
					cout << "____ Buscar Parceiros ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Buscar Parceiros\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Parceiro que deseja buscar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Parceiro, caso exista no banco de dados, exibirá seus dados.\n\n";
					system("pause");
					ajuda();
					break;
				case 0:
					system("cls");
					ajuda();
					break; 
				default:
					system("cls");
					cout << " *** Opção Inválida! Tente Novamente ***\n\n";
					system("pause");
					ajuda();
					break;
			}
			break; 
		case 4: 
			system("cls");
			cout << "  _______ Dúvidas em Fornecedores _______\n";
			cout << " |                                       |\n";
			cout << " |_ 1 - Como listar Fornecedores:        |\n";
			cout << " |                                       |\n";
			cout << " |_ 2 - Como Cadastrar Fornecedores:     |\n";
			cout << " |                                       |\n";
			cout <<	" |_ 3 - Como Atualizar Fornecedores:     |\n";
			cout << " |                                       |\n";
			cout << " |_ 4 - Como Excluir Fornecedores:       |\n";
			cout << " |                                       |\n";
			cout << " |_ 5 - Como buscar Fornecedores:        |\n";
			cout << " |                                       |\n";
			cout << " |_ 0 - Voltar                           |\n";
			cout << " |_______________________________________|\n\n";
			cout << "__ Escolha uma opção: ";
			cin >> opa2;
			switch(opa2){
				case 1: 
					system("cls");
					cout << "____ Listar Fornecedores ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Listar Fornecedores para vê-la\n";
					system("pause");
					ajuda();
					break;
				case 2: 
					system("cls");
					cout << "____ Cadastrar Fornecedores ____\n\n";
					cout << "_ Passo 1 \n\n";
					cout << "R: Pressione a tecla correspondente a Cadastrar Fornecedores\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite quantos Fornecedores deseja cadastrar (Automaticamente ele irá organizar os dados no banco de dados)\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Digite os dados do Fornecedor\n\n";
					system("pause");
					ajuda();
					break; 
				case 3:
					system("cls");
					cout << "____ Atualizar Fornecedores ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Atualizar Fornecedores\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Fornecedor que deseja atualizar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Selecione a informação que deseja alterar, após isso basta digitar a nova informação.\n\n";
					system("pause");
					ajuda();
					break; 
				case 4: 
					system("cls");
					cout << "____ Excluir Fornecedores ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Excluir Fornecedores\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Fornecedor que deseja excluir\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Fornecedor, caso exista no banco de dados, ele será excluido.\n\n";
					system("pause");
					ajuda();
					break;
				case 5: 
					system("pause");
					cout << "____ Buscar Fornecedores ____\n\n";
					cout << "_ Passo 1\n\n";
					cout << "R: Pressione a tecla correspondente a Buscar Fornecedores\n\n";
					cout << "_ Passo 2 \n\n";
					cout << "R: Digite o código do Fornecedor que deseja buscar\n\n";
					cout << "_ Passo 3 \n\n";
					cout << "R: Após digitar o código do Fornecedor, caso exista no banco de dados, exibirá seus dados.\n\n";
					system("pause");
					ajuda();
					break;
				case 0:
					system("cls");
					ajuda();
					break; 
				default:
					system("cls");
					cout << " *** Opção Inválida! Tente Novamente ***\n\n";
					system("pause");
					ajuda();
					break;
			}
			break; 
		case 0: 
			system("cls");
			break; 
		default:
			system("cls");
			cout << " *** Opção Inválida! Tente Novamente ***\n\n";
			system("pause");
			ajuda();
			break;
	}	
}



//Sobre
void sobre(){
	system("cls");
	cout << "\n\n  _______________________________ Sobre o Sistema _______________________________\n";
	cout << " |                                                                               |\n";
	cout << " |_ Nome: Argus                                                                  |\n";
	cout << " |                                                                               |\n";
	cout << " |_ Versão: 1.01                                                                 |\n";
	cout << " |                                                                               |\n";
	cout << " |_ Desenvolvedores: André Santos, Patrick Souza, João Vitor e Pedro Paiva.      |\n";
	cout << " |                                                                               |\n";
	cout << " |_ Funcionalidades: O Argus foi desenvolvido com o objetivo de administrar      |\n";
	cout << " |  da melhor maneira a empresa GGHARDWARE, o programa possui várias             |\n";
	cout << " |  funcionalidades, dentre elas, Cadastrar e controlar os dados de: Produtos,   |\n";
	cout << " |  clientes, fornecedores e parceiros.                                          |\n";
	cout << " |_______________________________________________________________________________|\n\n\n";
	system("pause");
}



//WHILE GERAL
void while_geral() {
	
	//WHILE MENU PRINCIPAL	
		i = 1;
		
		while (i > 0) {
		
			menu_prin();
			
			while (x < 0 || x > 7) {
				
				printf (" *** Opção inválida ***\n\n");
				system("pause");
				system("cls");			
				menu_prin();
								
			}
			
			switch (x) {
				
				//PRODUTOS
				
				case 1:
					
					escolhaP();
					system("cls");
					break;
					
				//CLIENTES	
				
				case 2:
					
					escolhaC();
					system("cls");
					break;
				
				//FORNECEDORES
					
				case 3:					
					menu_fornecedores();
					system("cls");
					break;
				
				//PARCEIROS	
				
				case 4:					
					menu_parceiros();
					system("cls");
					break;
				
				
				//AJUDA	
				
				case 5:
					
					ajuda();
					system("cls");
					break;
				
				//SOBRE	
				
				case 6:
					
					sobre();
					system("cls");
					break;
					
				// VOLTAR AO LOGIN
					
				case 7:					
					
					i = 0;
					break;
				
				//SAIR	
							
				case 0:
					
					while_login = 0;
					i = 0;
					break;
									
				
			}
			
			while (i < 0 || i > 1) {
						
				printf ("   *** Opção inválida ***\n \n");
				printf ("_ 1 -> Voltar ao menu principal \n");
				printf ("_ 0 -> Sair \n\n");
				printf ("__ Escolha uma opção: ");
				scanf ("%d", &i);
				if (i == 0) {
					while_login = 0;
				}				
				system("cls");
				
			};				
		}	
}


int main(int argc, char** argv) {
	
	
	setlocale(LC_ALL, "Portuguese");
	
	
	//LOGIN
	
	while (while_login > 0) {	
	
		Login();		
					
		carregando();
		
		system("cls");	
				
		while_geral();
	}
	
	return 0;
}
