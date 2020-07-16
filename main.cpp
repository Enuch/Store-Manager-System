#include <iostream>

using namespace std;

int main() 
{
  cout << "1 - Lojas" << endl;
  cout << "2 - Registrar Loja" << endl;
  cout << "3 - Excluir Loja" << endl;
  cout << "1 - Escolher Departamento" << endl;
  cout << "2 - Excluir Departamento" << endl;

  struct Lojas {
    string nome;
    int CNPJ;
    struct Departamentos{
      int codigo;
      string descricao;
      int qtdFuncionario;
    };
  };

  int qtdLojas, qtdDepartamentos, i;

  cout << "Digite a quantidade de lojas que vai ser registrada: ";
  cin >> qtdLojas;

  Lojas store[qtdLojas];

  for (i = 0; i < qtdLojas; i++)
  {
    cout << "Digite o nome da loja: " << i + 1 << endl;
    getchar();
    getline(cin, store[i].nome);
    cout << "Digite o CNPJ da loja: " << i + 1 << endl;
    cin >> store[i].CNPJ;
  }

  for (i = 0; i < qtdLojas; i++)
  {
    cout << store[i].nome << endl;
    cout << store[i].CNPJ << endl;
  }

  

  return 0;
}
