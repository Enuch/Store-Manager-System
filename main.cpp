#include <iostream>

// Codigo criado por Jean Fernandes e Enuch Santos.
// TADS 2020.5 Unidade 2

using namespace std;

struct Departamentos
{
    int codigo;
    string descricao;
    int qtdFuncionario;
};

struct Lojas
{
    string nome;
    string descricao;
    Departamentos dep[100];
    int CNPJ;
    int nDepartamentos = 0;
};

void menu()
{
    cout << "TADS GERENCIAMENTO DE LOJA E DEPARTAMENTOS" << endl;
    cout << "Escolha uma opcao!" << endl;
    cout << "1 - Buscar lojas e excluir departamentos" << endl;
    cout << "2 - Buscar departamentos e alterar dados" << endl;
    cout << "3 - Registrar uma Loja" << endl;
    cout << "4 - Excluir dados de uma Loja" << endl;
    cout << "5 - Alterar dados de uma Loja" << endl;
    cout << "6 - Relatorio de todas as Lojas e departamentos" << endl;
    cout << "0 - Sair do sistema" << endl;
}

void opInvalido()
{
    cout << "Opcao invalida!" << endl;
}

int saida()
{
    cout << "Saindo do sistema" << endl;
    return 0;
}

void relatorio(int nLojas, Lojas store[100])
{

    cout << nLojas << " Loja ja registradas. \nAbaixo a lista com relatorio de todas as lojas e seus departamentos ja registrados: " << endl;
    for (int i = 0; i < nLojas; i++)
    {
        cout << "---------------------------------------";
        cout << "\nLoja - " << store[i].nome << endl;
        cout << "Descricao: '" << store[i].descricao << "'" << endl;
        cout << "CNPJ: " << store[i].CNPJ << endl;
        cout << "\n"
             << store[i].nDepartamentos << " departamentos registrados na loja " << store[i].nome << " \nAbaixo a lista de departamentos: " << endl;
        for (int b = 0; b < store[i].nDepartamentos; b++)
        {
            cout << "Codigo - " << store[i].dep[b].codigo << endl;
            cout << "Descricao: '" << store[i].dep[b].descricao << "'" << endl;
            cout << "Numero de funcionarios: " << store[i].dep[b].qtdFuncionario;
            cout << '\n';
        }
        cout << "------------------------------" << endl;
    }
}

int verificar_CNPJreg(Lojas store[100], int CNPJaux, int nLojas, bool bol, bool bol2, int i)
{
    if (i == 0)
    {
        cin >> store[i].CNPJ;
    }
    else
    {
        cin >> CNPJaux;
        getchar();
        while (bol2 == false)
        {
            for (int j = 0; j < nLojas; j++)
            {
                if (store[j].CNPJ == CNPJaux)
                {
                    bol = true;
                }
            }
            if (bol == true)
            {
                bol = false;
                cout << "'CNPJ' ja cadastrado \nPor favor digite outro: " << endl;
                cout << "Digite o CNPJ da loja: " << i + 1 << endl;
                cin >> CNPJaux;
            }
            else
            {
                bol2 = true;
                store[i].CNPJ = CNPJaux;
            }
        }
        bol2 = false;
    }

    return store[i].CNPJ;
}

int verificar_CNPJ(Lojas store[100], int nLojas, int CNPJaux, bool bol, bool bol2, int b, int i)
{
    while (bol2 == false)
    {
        for (int j = 0; j < nLojas; j++)
        {
            if (store[j].CNPJ == CNPJaux)
            {
                bol = true;
            }
        }
        if (bol == true)
        {
            bol = false;
            cout << "'CNPJ' ja cadastrado \nPor favor digite outro: " << endl;
            cout << "Digite o CNPJ da loja: " << i + 1 << endl;
            cin >> CNPJaux;
        }
        else
        {
            bol2 = true;
            store[b].CNPJ = CNPJaux;
            cout << "\nDados da loja alterados!!" << endl;
        }
    }
    bol2 = false;

    bol = true;

    return store[b].CNPJ;
}

int apagarLojas(Lojas store[100], int b, int *loja)
{
    int *nLojas = loja;
    int l = *nLojas;

    for (int a = b; a < l; a++)
    {
        store[a] = store[a + 1];
    }

    l = l - 1;
    cout << "APAGANDO TODOS OS DADOS!!" << endl;
    return l;
}

void apagarDepartamentos(Lojas store[100], int c, int b, bool bol4, int CNPJaux)
{
    do
    {
        cout << "Digite o CNPJ da loja para excluir todos os seus departamentos: ";
        cin >> CNPJaux;
        if (CNPJaux == store[b].CNPJ)
        {
            for (c = 0; c < store[b].nDepartamentos; c++)
            {
                store[b].dep[c].codigo = 0;
                store[b].dep[c].descricao = "vazio";
                store[b].dep[c].qtdFuncionario = 0;
            }
            bol4 = true;
            store[b].nDepartamentos = 0;
            cout << "\nApagando informacoes de departamentos..." << endl;
            cout << "Apagado!" << endl;
        }
        else
        {
            cout << "CNPJ invalido!";
        }
    } while (bol4 == false);
}

void buscaDepartamento(Lojas store[100], int a, int b, int codigoBusca, int nLojas)
{
    for (a = 0; a < nLojas; a++)
    {
        for (b = 0; b < store[a].nDepartamentos; b++)
        {
            if (store[a].dep[b].codigo == codigoBusca)
            {
                cout << "-----------------------------" << endl;
                cout << "Loja: " << store[a].nome << endl;
                cout << "Codigo - " << store[a].dep[b].codigo << endl;
                cout << "Descricao: '" << store[a].dep[b].descricao << "'" << endl;
                cout << "Numero de funcionarios: " << store[a].dep[b].qtdFuncionario << endl;
                cout << "Posicao: " << b << endl;
                cout << '\n';
            }
        }
    }
}

int main()
{
    int posicao = 0, i = 0, c, opcao = -1, nLojas = 0, opcao1 = 1, opcao3, CNPJaux = -5, a = 0, b = 0, nDepartamentos = 0, buscaCNPJ, opcao4, codigoBusca, opcao5;
    string nomeBusca;
    bool bol = false, bol2 = false, bol3, bol4 = false, bol5 = false;

    Lojas store[100];

    while (opcao != 0)
    {
        menu();

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            if (nLojas == 0)
            {
                cout << "Nao ha lojas registradas no sistema! \nCaso deseje registrar escolha a opcao no menu principal" << endl;
            }
            else
            {
                while (opcao4 != 0)
                {
                    cout << "Para acessar as informacoes da loja digite o nome e o CNPJ da loja: " << endl;
                    getchar();
                    cout << "Nome: ";
                    getline(cin, nomeBusca);
                    cout << "CNPJ: ";
                    cin >> buscaCNPJ;
                    for (b = 0; b < nLojas; b++)
                    {
                        if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                        {
                            cout << "------------------------------" << endl;
                            cout << "Loja - " << store[b].nome << endl;
                            cout << "Descricao: '" << store[b].descricao << "'" << endl;
                            cout << "CNPJ: " << store[b].CNPJ << endl;
                            bol = true;
                            cout << "\n"
                                 << "Departamentos registrados na loja " << store[i].nome << ": " << store[b].nDepartamentos << "\nAbaixo a lista de departamentos: " << endl;
                            for (c = 0; c < store[b].nDepartamentos; c++)
                            {
                                cout << "Codigo - " << store[b].dep[c].codigo << endl;
                                cout << "Descricao: '" << store[b].dep[c].descricao << "'" << endl;
                                cout << "Numero de funcionarios: " << store[b].dep[c].qtdFuncionario << endl;
                                cout << '\n';
                            }
                            for (int a = 0; a < store[b].nDepartamentos; b++)
                            {

                                cout << "1 - Para excluir todos os departamentos \n2 - Para sair " << endl;
                                cin >> opcao5;
                                switch (opcao5)
                                {
                                case 1:
                                    //funcao aqui kk
                                    apagarDepartamentos(store, c, b, bol4, CNPJaux);

                                    break;
                                default:
                                    bol5 = true;
                                    cout << "Saindo..." << endl;
                                    break;
                                }
                                if (bol5 == true)
                                    break;
                            }
                            bol5 = false;
                        }
                    }
                    if (bol == false)
                    {
                        cout << "Loja nao encontrada! " << endl;
                    }
                    bol = false;

                    cout << "Para acessar outra loja digite '1' para sair digite '0'";
                    cin >> opcao4;
                }
                opcao4 = 1;
            }

            break;
        case 2:
            if (nDepartamentos == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << "Digite um codigo de departamento para busca-lo: ";
                cin >> codigoBusca;

                buscaDepartamento(store, a, b, codigoBusca, nLojas);

                cout << "Para alterar os dados do departamento informe a loja e CNPJ a qual pertence e sua posicao na lista: " << endl;
                cout << "Nome: ";
                getchar();
                getline(cin, nomeBusca);
                cout << "Posicao: ";
                cin >> b;
                cout << "CNPJ: ";
                cin >> CNPJaux;
                for (a = 0; a < nLojas; a++)
                {
                    for (b = 0; b < store[a].nDepartamentos; b++)
                    {
                        if (nomeBusca == store[a].nome && posicao == b && CNPJaux == store[a].CNPJ)
                        {
                            cout << "Codigo anterior - " << store[a].dep[b].codigo << " -> Digite o novo codigo: ";
                            cin >> store[a].dep[b].codigo;
                            getchar();
                            cout << "Ultima descricao posta: '" << store[a].dep[b].descricao << "' -> Digite a nova descricao: ";
                            getline(cin, store[a].dep[b].descricao);
                            cout << "Funcionario contratados atualmente: " << store[a].dep[b].qtdFuncionario << " -> Digite a atualizacao do numero de funcionarios: ";
                            cin >> store[a].dep[b].qtdFuncionario;
                            cout << "\nAtualizando informacoes de departamentos..." << endl;
                            cout << "Atualizado!" << endl;
                            bol = false;
                        }
                    }
                }
            }
            if (bol == true)
                cout << "O CNPJ, Nome da loja ou posicao do departamento invalido!" << endl;

            bol = false;

            break;
        case 3:
            while (opcao1 != 0)
            {
                nLojas++;

                cout << "Digite o nome da loja a ser registrada: " << i + 1 << endl;
                getchar();
                getline(cin, store[i].nome);
                cout << "De um descricao a sua loja" << endl;
                getline(cin, store[i].descricao);
                cout << "Digite o CNPJ da loja: " << i + 1 << endl;
                store[i].CNPJ = verificar_CNPJreg(store, CNPJaux, nLojas, bol, bol2, i);

                cout << "Informe quantos departamentos sua loja tem" << endl;
                cin >> nDepartamentos;
                store[i].nDepartamentos = nDepartamentos;

                for (a = 0; a < nDepartamentos; a++)
                {
                    cout << "Digite o codigo do departamento: ";
                    cin >> store[i].dep[a].codigo;
                    getchar();
                    cout << "Digite a descricao do departamento: ";
                    getline(cin, store[i].dep[a].descricao);
                    cout << "Digite a quantidade funcionario: ";
                    cin >> store[i].dep[a].qtdFuncionario;
                }
                cout << "Loja e informacoes registradas!! \n";
                cout << "Nome - " << store[i].nome << endl;
                cout << "Descricao: '" << store[i].descricao << "'" << endl;
                cout << "CNPJ: " << store[i].CNPJ << endl;
                cout << "Departamentos: " << store[i].nDepartamentos << endl;

                cout << "Caso deseje parar de registrar digite '0': ";
                cin >> opcao1;

                i++;
            }

            opcao1 = 1;

            break;
        case 4:
            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << "Para excluir os dados de uma loja do sistema: " << endl;

                cout << "Informe o nome da loja desejada e depois seu CNPJ: " << endl;
                getchar();
                cout << "Nome: ";
                getline(cin, nomeBusca);
                cout << "CNPJ: ";
                cin >> buscaCNPJ;
                for (b = 0; b < nLojas; b++)
                {
                    if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                    {
                        //funcao fica aqui
                        nLojas = apagarLojas(store, b, &nLojas);
                        i--;
                        bol = true;
                    }
                }
                if (bol == false)
                {
                    cout << "CNPJ ou nome da loja invalidos" << endl;
                }
                bol = false;
            }

            break;
        case 5:

            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << "Para alterar os dados da loja: " << endl;
                cout << "Iforme o nome da loja desejada e depois seu CNPJ: " << endl;
                getchar();
                cout << "Nome: ";
                getline(cin, nomeBusca);
                cout << "CNPJ: ";
                cin >> buscaCNPJ;
                for (int b = 0; b < nLojas; b++)
                {

                    if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                    {
                        bol5 = true;
                        cout << "Loja: " << store[b].nome << " -> Digite o novo nome da loja: ";
                        cin >> store[b].nome;
                        getchar();
                        cout << "Descricao: '" << store[b].descricao << "'"
                             << " -> Digite a nova descricao: ";
                        getline(cin, store[b].descricao);
                        cout << "CNPJ: " << store[b].CNPJ << " -> Digite o novo CNPJ: ";
                        cin >> CNPJaux;
                        getchar();
                        verificar_CNPJ(store, nLojas, CNPJaux, bol, bol2, b, i);
                    }
                    bol = false;
                }
                if (bol5 == false)
                    cout << "Loja nao encontrada! " << endl;
            }
            bol5 = false;
            break;
        case 6:
            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                relatorio(nLojas, store);
            }
            break;
        case 0:
            saida();
            break;
        default:
            opInvalido();
            break;
        }
        system("Pause");
        system("cls");
    }

    return 0;
}
