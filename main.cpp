#include <iostream>

// Codigo criado por Jean Fernandes e Enuch Santos.
// TADS 2020.5 Unidade 2

using namespace std;

int main()
{
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

    int posicao = 0, i = 0, c, opcao = -1, nLojas = 0, opcao1 = 1, opcao3, CNPJaux = -5, a = 0, b = 0, nDepartamentos = 0, buscaCNPJ, opcao4, codigoBusca, opcao5;
    string nomeBusca;
    bool bol = false, bol2 = false, bol3, bol4 = false;

    Lojas store[100];

    while (opcao != 0)
    {
        cout << "TADS GERENCIAMENTO DE LOJA E DEPARTAMENTOS" << endl;

        cout << "Escolha uma opcao!" << endl;
        cout << "1 - Buscar lojas e alterar/excluir departamentos" << endl;
        cout << "2 - Buscar departamentos" << endl;
        cout << "3 - Registrar uma Loja" << endl;
        cout << "4 - Excluir dados de uma Loja" << endl;
        cout << "5 - Alterar dados de uma Loja" << endl;
        cout << "6 - Relatorio de todas as Lojas e departamentos" << endl;
        cout << "0 - Sair do sistema" << endl;

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

                                cout << "1 - Para excluir um departamento \n2 - Para sair " << endl;
                                cin >> opcao5;
                                switch (opcao5)
                                {
                                case 1:
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
                                            cout << "\nApagando informacoes de departamentos..." << endl;
                                            cout << "Apagado!" << endl;
                                        }
                                        else
                                        {
                                            cout << "CNPJ invalido!";
                                        }
                                    } while (bol4 == false);

                                    break;
                                default:
                                    cout << "Saindo..." << endl;
                                    break;
                                }
                            }
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
            cout << "Digite um codigo de departamento para busca-lo: ";
            cin >> codigoBusca;
            for (a = 0; a < nLojas; a++)
            {
                for (b = 0; b < store[a].nDepartamentos; b++)
                {
                    if (store[a].dep[b].codigo == codigoBusca)
                    {
                        cout << "-----------------------------" << endl;
                        cout << "Codigo - " << store[a].dep[b].codigo << endl;
                        cout << "Descricao: '" << store[a].dep[b].descricao << "'" << endl;
                        cout << "Numero de funcionarios: " << store[a].dep[b].qtdFuncionario << endl;
                        cout << "Posicao: " << b << endl;
                        cout << '\n';
                    }
                }
            }
            cout << "Para alterar os dados do departamento informe a loja a qual pertence e sua posicao na lista: " << endl;
            cout << "Nome: ";
            getchar();
            getline(cin, nomeBusca);
            cout << "Posicao: ";
            cin >> posicao;
            for (a = 0; a < nLojas; a++)
            {
                for (b = 0; b < store[a].nDepartamentos; b++)
                {
                    if (nomeBusca == store[a].nome && posicao == b)
                    {
                        cout << "Codigo anterior - " << store[a].dep[b].codigo << " Digite o novo codigo: ";
                        cin >> store[a].dep[b].codigo;
                        getchar();
                        cout << "Ultima descricao posta: '" << store[a].dep[b].descricao << "' Digite a nova descricao: ";
                        getline(cin,store[a].dep[b].descricao);
                        cout << "Funcionario contratados atualmente: " << store[a].dep[b].qtdFuncionario << " Digite a atualizacao do numero de funcionarios: ";
                        cin >> store[a].dep[b].qtdFuncionario;
                        cout << "\nAtualizando informacoes de departamentos..." << endl;
                        cout << "Atualizado!" << endl;
                    }
                }
            }

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
                        cout << "Loja - " << store[b].nome << " - APAGANDO! " << endl;
                        store[b].nome = "Vazio";
                        cout << "Descricao: '" << store[b].descricao << "'"
                             << " - APAGANDO!" << endl;
                        store[b].descricao = "Vazio";
                        cout << "CNPJ - " << store[b].CNPJ << " - APAGANDO! " << endl;
                        store[b].CNPJ = 0;
                        cout << "Departamentos - " << store[b].nDepartamentos << " - APAGANDO!" << endl;
                        store[b].nDepartamentos = 0;
                        for (a = 0; a < store[b].nDepartamentos; a++)
                        {
                            store[b].dep[a].codigo = 0;
                            store[b].dep[a].descricao = "vazio";
                            store[b].dep[a].qtdFuncionario = 0;
                        }
                        bol = true;
                    }
                    if (bol = false)
                    {
                        cout << "Vazio!" << endl;
                    }
                    bol = false;
                }
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
                for (b = 0; b < nLojas; b++)
                {
                    if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                    {
                        cout << "Loja: " << store[b].nome << " -> Digite o novo nome da loja: ";
                        cin >> store[b].nome;
                        getchar();
                        cout << "Descricao: '" << store[b].descricao << "'"
                             << " -> Digite a nova descricao: ";
                        getline(cin, store[b].descricao);
                        cout << "CNPJ: " << store[b].CNPJ << " -> Digite o novo CNPJ: ";

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
                                store[b].CNPJ = CNPJaux;
                                cout << "\nDados das loja alterados!!" << endl;
                            }
                        }
                        bol2 = false;

                        bol = true;
                    }
                    else if (store[b].nome != nomeBusca || store[b].CNPJ != buscaCNPJ)
                    {
                        cout << "Loja nao encontrada! " << endl;
                    }
                    bol = false;
                }
            }

            break;
        case 6:
            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << nLojas << " Loja ja registradas. \nAbaixo a lista com relatorio de todas as lojas e seus departamentos ja registrados: " << endl;
                for (i = 0; i < nLojas; i++)
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
                }
            }

            break;
        case 0:
            cout << "Saindo do sistema" << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
        system("Pause");
        system("cls");
    }

    return 0;
}
