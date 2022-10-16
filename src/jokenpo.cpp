/*-----------------------------------------
* Jokenpô
* Cleber Moretti
* https://github.com/mcleber
* v.0.1 : 03/04/2022
-----------------------------------------
* v.0.2 : 16/10/2022
* Correção no srand() e rand().
* Substituição da seleção de jogadas para
* switch.
-----------------------------------------*/

#include <iostream>
#include <tchar.h>
#include <Windows.h> // Sleep

void jogadas();

int jogador, continuarJogo, vencedor;
int totalJogador{ 0 }, totalComputador{ 0 };
bool verificacao{ true };

int main()
{
	_tsetlocale(LC_ALL, _T("portuguese"));
	
	while (verificacao)
	{
		system("CLS");
		std::cout << "--- OPÇÕES ---" << "\n[ 0 ] PEDRA\n" << "[ 1 ] PAPEL\n" << "[ 2 ] TESOURA\n";
		std::cout << "\nEscolha sua jogada: ";
		std::cin >> jogador;

		std::cout << "\nJO";
		Sleep(530);
		std::cout << "KEN";
		Sleep(530);
		std::cout << "PÔ\n";
		Sleep(530);

		/* RESULTADOS */
		jogadas();

		/* CONITNUAR JOGO? */
		std::cout << "\nDeseja jogar novamente? (Digite 0 para Não e 1 para Sim) ";
		std::cin >> continuarJogo;

		if ((continuarJogo == 0) || (continuarJogo == 1))
		{
			verificacao = (continuarJogo == 1) ? true : false;
		}
		else
		{
			do
			{
				system("CLS");
				std::cout << "\nOpção inválida.";
				std::cout << "\nDeseja jogar novamente? (Digite 0 para Não e 1 para Sim) ";
				std::cin >> continuarJogo;

			} while ((continuarJogo != 1) && (continuarJogo != 0));

			verificacao = (continuarJogo == 1) ? true : false;

		}

	}

	system("CLS");
	std::printf("\nO Jogador fez %d ponto(s) e o Computador fez %d ponto(s)", totalJogador, totalComputador);

	std::cout << "\nJogo encerrado...\n\n";

	system("PAUSE");
	return 0;
}

void jogadas()
{
	// gera seed
	srand(time(NULL));
	int computador{ rand() % 3 };

	switch (jogador) {
	case 0: 
		std::cout << "\nVocê escolheu PEDRA." << std::endl;
		break;
	case 1: 
		std::cout << "\nVocê escolheu PAPEL." << std::endl;
		break;
	case 2: 
		std::cout << "\nVocê escolheu TESOURA." << std::endl;
		break;
	}

	switch (computador) {
	case 0: 
		std::cout << "Computador escolheu PEDRA." << std::endl;
		break;
	case 1: 
		std::cout << "Computador escolheu PAPEL." << std::endl;
		break;
	case 2: 
		std::cout << "Computador escolheu TESOURA." << std::endl;
		break;
	}
	
	/* TESTES */

	if (jogador == 0 && computador == 1)
	{
		std::cout << "\nComputador ganhou!" << std::endl;
		totalComputador++;
	}
	else if (jogador == 0 && computador == 2)
	{
		std::cout << "\nVocê ganhou!" << std::endl;
		totalJogador++;
	}
	else if (jogador == 1 && computador == 0)
	{
		std::cout << "\nVocê ganhou!" << std::endl;
		totalJogador++;
	}
	else if (jogador == 1 && computador == 2)
	{
		std::cout << "\nComputador ganhou!" << std::endl;
		totalComputador++;
	}
	else if (jogador == 2 && computador == 0)
	{
		std::cout << "\nComputador ganhou!" << std::endl;
		totalComputador++;
	}
	else if (jogador == 2 && computador == 1)
	{
		std::cout << "\nVocê ganhou!" << std::endl;
		totalJogador++;
	}
	else if (jogador == computador)
	{
		std::cout << "\nEmpate!" << std::endl;
	}

}