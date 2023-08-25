#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Função para exibir a forca e a palavra oculta com as letras adivinhadas
// corretamente
void exibirForca(int erros) {
  cout << "\n  _____" << endl;
  cout << " |     |" << endl;
  cout << " |     " << (erros >= 1 ? "O" : "") << endl;
  cout << " |    " << (erros >= 3 ? "/" : " ") << (erros >= 2 ? "|" : "")
       << (erros >= 4 ? "\\" : "") << endl;
  cout << " |    " << (erros >= 5 ? "/" : "") << " " << (erros >= 6 ? "\\" : "")
       << endl;
  cout << "_|_\n" << endl;
}

int main() {

  do {
    // Lista de palavras para o jogo
    vector<string> palavras = {"computador",
                               "programacao",
                               "desenvolvimento",
                               "algoritmo",
                               "linguagem",
                               "software",
                               "hardware",
                               "internet",
                               "teclado",
                               "mouse",
                               "compilador",
                               "depurador",
                               "memoria",
                               "processador",
                               "interface",
                               "estrutura",
                               "variavel",
                               "funcao",
                               "classe",
                               "objeto",
                               "heranca",
                               "polimorfismo",
                               "encapsulamento",
                               "abstracao",
                               "interface",
                               "algoritmo",
                               "logica",
                               "loop",
                               "condicional",
                               "vetor",
                               "matriz",
                               "ponteiro",
                               "endereco",
                               "byte",
                               "bit"};

    // Inicialização do gerador de números aleatórios
    srand(time(0));

    // Escolha aleatória de uma palavra da lista
    string palavra = palavras[rand() % palavras.size()];

    // Inicialização da palavra adivinhada com underscores
    string palavraAdivinhada(palavra.size(), '_');

    int erros = 0;
    char letra;

    cout << "\nBem-vindo ao jogo da forca!" << endl;

    while (erros < 6 && palavraAdivinhada != palavra) {
      exibirForca(erros);
      cout << "\nPalavra: " << palavraAdivinhada << endl;
      cout << "\nDigite uma letra: ";
      cin >> letra;

      bool letraCorreta = false;

      // Verifica se a letra está presente na palavra
      for (int i = 0; i < palavra.size(); ++i) {
        if (palavra[i] == letra) {
          palavraAdivinhada[i] = letra;
          letraCorreta = true;
        }
      }

      if (!letraCorreta) {
        ++erros;
        cout << "Letra errada. Tente novamente." << endl;
      }
    }

    exibirForca(erros);

    if (erros == 6) {
      cout << "Forca! A palavra correta era: " << palavra << endl;
    } else {
      cout << "Parabéns! Você acertou a palavra: " << palavra << endl;
    }

    // Pergunta ao jogador se deseja jogar novamente
    char playAgain;
    printf("Deseja jogar novamente? (S/N) ");
    scanf(" %c", &playAgain); // O espaço antes de %c evita o problema do
    // caractere de nova linha

    if (playAgain == 'S' || playAgain == 's') {
      erros = 0;
    } else {
      cout << "Obrigado por jogar! Até a próxima." << endl;
      break;
    }
  } while (1);

  return 0;
}