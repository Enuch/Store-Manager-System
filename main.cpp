#include <iostream>

//cout << "1 - Escolher Departamento" << endl;
//cout << "2 - Excluir Departamento" << endl;

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

    int i = 0, c, opcao = -1, nLojas = 0, opcao1 = 1, opcao3, CNPJaux = -5, a = 0, b = 0, nDepartamentos = 0, buscaCNPJ, opcao4, codigoBusca, opcao5;
    string nomeBusca;
    bool bol = false, bol2 = false, bol3, bol4 = false;

    Lojas store[100];

    while (opcao != 0)
    {
        cout << "BEM VINDO AO SISTEMA DE GERENCIAMENTO E LOJAS ONLINE!" << endl;

        cout << "Escolha uma opcao!" << endl;
        cout << "1 - Lojas" << endl;
        cout << "2 - Registrar Loja" << endl;
        cout << "3 - Excluir Loja" << endl;
        cout << "4 - Alterar Loja" << endl;
        cout << "5 - Relatorio de todas as Lojas" << endl;
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
                    for (i = 0; i < nLojas; i++)
                    {
                        cout << i << " - " << store[i].nome << endl;
                    }
                    cout << "Para acessar as informacoes da loja digite o nome e o CNPJ da loja: " << endl;
                    getchar();
                    getline(cin, nomeBusca);
                    cin >> buscaCNPJ;
                    for (b = 0; b < nLojas; b++)
                    {
                        if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                        {
                            cout << "Loja - " << store[b].nome << endl;
                            cout << "Descricao: '" << store[b].descricao << "'" << endl;
                            cout << "CNPJ - " << store[b].CNPJ << endl;
                            bol = true;
                            cout << "\n"
                                 << store[b].nDepartamentos << " departamentos registrados na loja " << store[i].nome << " \nAbaixo a lista de departamentos: " << endl;
                            for (int a = 0; a < store[b].nDepartamentos; b++)
                            {
                                cout << "Codigo - " << store[b].dep[a].codigo << endl;
                                cout << "Descricao - " << store[b].dep[a].descricao << endl;
                                cout << "Numero de funcionarios - " << store[b].dep[a].qtdFuncionario << endl;
                                cout << '\n';

                                cout << "Para excluir um departamento digite 1 \nPara alterar digite 2 \nPara sair 3" << endl;
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
                                        }
                                        else
                                        {
                                            cout << "CNPJ invalido!";
                                        }
                                    } while (bol4 == false);

                                        break;
                                case 2:
                                    cout << "Digite o codigo do departamento para alterar seus dados: ";
                                    cin >> codigoBusca;
                                    for (c = 0; c < store[b].nDepartamentos; c++)
                                    {
                                        if (codigoBusca == store[b].dep[c].codigo)
                                        {
                                            cout << "Codigo anterios - " << store[b].dep[c].codigo << " Digite o novo codigo: ";
                                            cin >> store[b].dep[c].codigo;
                                            cout << "Ultima descricao posta: '" << store[b].dep[c].descricao << "' Digite a nova descricao: ";
                                            cin >> store[b].dep[c].descricao;
                                            cout << "Funcionario contratados atualmente: " << store[b].dep[c].qtdFuncionario << "Digite a atualizacao do numero de funcionarios: ";
                                            cin >> store[b].dep[c].qtdFuncionario;
                                        }
                                    }
                                    break;
                                default:
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

                cout << store[i].nome << endl;
                cout << store[i].descricao << endl;
                cout << store[i].CNPJ << endl;

                cout << "Caso deseje parar de registrar digite '0': ";
                cin >> opcao1;

                i++;
            }

            opcao1 = 1;

            break;
        case 3:
            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << "Escolha a loja que deseja excluir do sistema: " << endl;
                for (i = 0; i < nLojas; i++)
                {
                    cout << "\nLoja - " << store[i].nome << endl;
                    cout << "Descricao: '" << store[i].descricao << "'" << endl;
                    cout << "CNPJ: " << store[i].CNPJ << endl;
                }
                cout << "Busque digitando o nome da loja desejada e depois seu CNPJ: " << endl;
                getchar();
                getline(cin, nomeBusca);
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
                        cout << "CNPJ - " << store[b].CNPJ << " - APAGANDO!: " << endl;
                        store[b].CNPJ = 0;
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
        case 4:

            if (nLojas == 0)
            {
                cout << "Sistema vazio!" << endl;
            }
            else
            {
                cout << "Escolha a loja que vai ser alterada: " << endl;
                for (i = 0; i < nLojas; i++)
                {
                    cout << "\nLoja - " << store[i].nome << endl;
                    cout << "Descricao: '" << store[i].descricao << "'" << endl;
                    cout << "CNPJ: " << store[i].CNPJ << endl;
                }
                cout << "Busque digitando o nome da loja desejada e depois seu CNPJ: " << endl;
                getchar();
                getline(cin, nomeBusca);
                cin >> buscaCNPJ;
                for (b = 0; b < nLojas; b++)
                {
                    if (store[b].nome == nomeBusca && store[b].CNPJ == buscaCNPJ)
                    {
                        cout << "Loja - " << store[b].nome << " - Digite o novo nome da loja: ";
                        cin >> store[b].nome;
                        getchar();
                        cout << "Descricao: '" << store[b].descricao << "'"
                             << " - Digite a nova descricao: ";
                        getline(cin, store[b].descricao);
                        cout << "CNPJ - " << store[b].CNPJ << " - Digite o novo CNPJ: ";

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
                            }
                        }
                        bol2 = false;

                        bol = true;
                    }
                    if (bol = false)
                    {
                        cout << "Loja nao encontrada! " << endl;
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
                cout << nLojas << " Loja ja registradas. \nAbaixo a lista com relatorio de todas as lojas e seus departamentos ja registrados: " << endl;
                for (i = 0; i < nLojas; i++)
                {
                    cout << "\nLoja - " << store[i].nome << endl;
                    cout << "Descricao: '" << store[i].descricao << "'" << endl;
                    cout << "CNPJ: " << store[i].CNPJ << endl;
                    cout << "\n"
                         << store[i].nDepartamentos << " departamentos registrados na loja " << store[i].nome << " \nAbaixo a lista de departamentos: " << endl;
                    for (int b = 0; b < store[i].nDepartamentos; b++)
                    {
                        cout << "Codigo - " << store[i].dep[b].codigo << endl;
                        cout << "Descricao - " << store[i].dep[b].descricao << endl;
                        cout << "Numero de funcionarios - " << store[i].dep[b].qtdFuncionario << endl;
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
