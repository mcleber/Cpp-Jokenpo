/* 
Jokenpô 

Cleber Moretti
https://github.com/mcleber

v.0.1
03/04/2022
*/

#include <iostream>
#include <tchar.h>
#include <Windows.h> // Sleep

void ganhou();
void perdeu();
void empate();


int main()
{
	_tsetlocale(LC_ALL, _T("portuguese"));
	srand(time(NULL)); // inicializa random seed

	int jogador, continuarJogo, vencedor;
	int totalJogador{ 0 }, totalComputador{ 0 };
	int computador{ (rand() % 3) + 1 };
	bool verificacao{ true };

	while (verificacao)
	{
		system("CLS");
		std::cout << "--- OPÇÕES ---" << "\n[ 1 ] PEDRA\n" << "[ 2 ] PAPEL\n" << "[ 3 ] TESOURA\n";
		std::cout << "\nEscolha sua jogada: ";
		std::cin >> jogador;

		std::cout << "\nJO";
		Sleep(530);
		std::cout << "KEN";
		Sleep(530);
		std::cout << "PÔ\n";
		Sleep(530);

		/* ESCOLHAS */

		if (jogador == 1)
		{
			std::cout << "\nVocê escolheu PEDRA." << std::endl;
		}
		else if (jogador == 2)
		{
			std::cout << "\nVocê escolheu PAPEL." << std::endl;
		}
		else if (jogador == 3)
		{
			std::cout << "\nVocê escolheu TESOURA." << std::endl;
		}
		else
		{
			std::cout << "\nOpção inválida." << std::endl;
			return 1;
		}

		if (computador == 1)
		{
			std::cout << "Computador escolheu PEDRA." << std::endl;
		}
		else if (computador == 2)
		{
			std::cout << "Computador escolheu PAPEL." << std::endl;
		}
		else if (computador == 3)
		{
			std::cout << "Computador escolheu TESOURA." << std::endl;
		}

		/* TESTES */

		if (jogador == computador)
		{
			empate();
		}

		if (jogador == 1)
		{
			if (computador == 2)
			{
				perdeu();
				totalComputador++;
			}
			else if (computador == 3)
			{
				ganhou();
				totalJogador++;
			}
		}
		else if (jogador == 2)
		{
			if (computador == 1)
			{
				ganhou();
				totalJogador++;
			}
			else if (computador == 3)
			{
				perdeu();
				totalComputador++;
			}
		}
		else if (jogador == 3)
		{
			if (computador == 1)
			{
				perdeu();
				totalComputador++;
			}
			else if (computador == 2)
			{
				ganhou();
				totalJogador++;
			}
		}

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
	std::printf ("\nO Jogador fez %d ponto(s) e o Computador fez %d ponto(s)", totalJogador, totalComputador);

	std::cout << "\nJogo encerrado...\n\n";

	system("PAUSE");
	return 0;
}

void ganhou()
{
	std::cout << "\nVocê ganhou!" << std::endl;
}

void perdeu()
{
	std::cout << "\nComputador ganhou!" << std::endl;
}

void empate()
{
	std::cout << "\nEmpate!" << std::endl;;
}