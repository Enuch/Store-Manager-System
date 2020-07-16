#include <iostream>

//cout << "1 - Escolher Departamento" << endl;
//cout << "2 - Excluir Departamento" << endl;

using namespace std;

int main() 
{
  

  struct Lojas {
    string nome;
    int CNPJ;
    struct Departamentos{
      int codigo;
      string descricao;
      int qtdFuncionario;
    };
  };

  int qtdDepartamentos, i = 0, opcao = -1, nLojas = 0, opcao1 = 1, CNPJaux = -5;
  bool bol = false, bol2 = false;

  Lojas store[100];

  while(opcao != 0){
  system("cls");
  cout << "Escolha uma opcao!" << endl;
  cout << "1 - Lojas" << endl;
  cout << "2 - Registrar Loja" << endl;
  cout << "3 - Excluir Loja" << endl;
  cout << "0 - Sair do sistema" << endl;
  
  cin >> opcao;

  switch (opcao)
  {
    case 1:
      if (nLojas == 0)
      {
        cout << "Nao ha lojas registradas no sistema! \nCaso deseje registrar escolha a opcao no menu principal" << endl;
      }
      else{
        cout << "Escolha uma loja para acessar seus departamentos: " << endl;
        for (i = 0; i < nLojas; i++)
        {
          cout << i << " - "<< store[i].nome << endl;

        }
        
      }

      break;
    case 2:
      while (opcao1 != 0){
        nLojas++;
      
    cout << "Digite o nome da loja a ser registrada: " << i + 1 << endl;
    getchar();
    getline(cin, store[i].nome);
    cout << "Digite o CNPJ da loja: " << i + 1 << endl;
    cin >> CNPJaux;
    getchar();
    while(bol2 == false)
    {
      for (int j = 0; j < nLojas; j++)
      {
        if (store[j].CNPJ == CNPJaux)
        {
          bol = true;
        }
      }
      if(bol == true)
      {
        bol = false;
        cout << "'CNPJ' já cadastrado \nPor favor digite outro: " << endl;
        cout << "Digite o CNPJ da loja: " << i + 1 << endl;
        cin >> CNPJaux;
      }
      else
      {
        
        bol2 = true;
        store[i].CNPJ = CNPJaux;
        cout << bol << endl;
      }
    }
    bol2 = false;

    i++;
    
    cout << "Caso deseje parar de registrar digite '0': ";
    cin >> opcao1;
    }
    opcao1 = 1;
  for (i = 0; i < nLojas; i++)
  {
    cout << store[i].nome << endl;
    cout << store[i].CNPJ << endl;
  }
      break;
    case 3:
      break;
    case 0:
      cout << "Saindo do sistema";
      break;
    default:
      cout << "Opcao invalida!";
      break;
  }
}  

  return 0;
}
