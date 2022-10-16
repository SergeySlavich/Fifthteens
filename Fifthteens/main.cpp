#include <iostream>
#include <conio.h>
using namespace std;

#define FIFTHTEENS

#ifdef FIFTHTEENS
	const int SIZE = 4;
	int f0[SIZE][SIZE] = { {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 0} };
	int f[SIZE][SIZE] = { {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 0} };
	int X = 4, Y = 4, bord = 0;
	bool check = 0;
	int checking = 0;

void print_field()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	cout << "Игра в пятнашки.\nПравила игры:"
		<< "\nВы можете клавишами со стрелками перемещать числа на пустое поле."
		<< "\nЗа пределы поля числа перемещать невозможно."
		<< "\nКогда все числа окажутся в исходном положении, игра считается оконченной.\n\n\n";
	checking = 0;
	//
	//for (int i = 0; i < 192; i++)
	//{
	//	cout << i << " - " << char(i) << endl;
	//}
	//1 raw
	cout << '\t'<< char(134);
	for (int i = 0; i < SIZE; i++)
	{
		cout << char(150) << char(150) << char(150);
	}
	cout << char(134) << endl;
	for (int y = 0; y < SIZE; y++)
	{
		cout << "\t" << char(166);
		for (int x = 0; x < SIZE; x++)
		{
			if (f[x][y] != 0)
			{
				printf("%3d", f[x][y]);
			}
			else cout << "   ";
			if (f[x][y] == f0[x][y])
			{
				check = 1;
				checking++;
			}
		}
		cout << char(166) << endl;
	}
	//Last raw
	cout << '\t' << char(134);
	for (int i = 0; i < SIZE; i++)
	{
		cout << char(173) << char(173) << char(173);
	}
	cout << char(134) << endl;
	if (checking == 16) bord = 16;
	switch (bord)
	{
	case 1: cout << "\n\nВы достигли правой границы поля."; break;
	case 2: cout << "\n\nВы достигли нижней границы поля."; break;
	case 3: cout << "\n\nВы достигли левой границы поля."; break;
	case 4: cout << "\n\nВы достигли верхней границы поля."; break;
	case 16: cout << "\n\nВсе числа находятся в исходном положении."; break;
	default: cout << "";
	}
}

void leftt()
{
	if (X < SIZE)
	{
		X++;
		f[X - 2][Y - 1] = f[X - 1][Y - 1];
		f[X - 1][Y - 1] = 0;
	}
	else bord = 1;
}

void rightt()
{
	if (X > 1)
	{
		X--;
		f[X][Y - 1] = f[X - 1][Y - 1];
		f[X - 1][Y - 1] = 0;
	}
	else bord = 3;
}

void down()
{
	if (Y > 1)
	{
		Y--;
		f[X - 1][Y] = f[X - 1][Y - 1];
		f[X - 1][Y - 1] = 0;
	}
	else bord = 4;
}

void up()
{
	if (Y < SIZE)
	{
		Y++;
		f[X - 1][Y - 2] = f[X - 1][Y - 1];
		f[X - 1][Y - 1] = 0;
	}
	else bord = 2;
}

void main()
{
	setlocale(LC_ALL, "Russian");

	char key;
	print_field();
	f[X][Y] = 0;
	do
	{
		key = _getch();
		bord = 0;
		switch (key)
		{
		case -32: break;
		case 72: up(); break; //стрелка вперед/вверх
		case 80: down(); break;	//стрелка назад/вниз
		case 75: leftt(); break;	//стрелка влево
		case 77: rightt(); break;	//стрелка вправо
		case 27: cout << "Выход из игры"; break;
		}
		print_field();
	} while (key != 27);
}
#endif