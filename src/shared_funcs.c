#include "shared_funcs.h"

char mygetch()	//ncurses에서 키보드 입력을 받기 위함
{
	char ch;
	noecho();
	ch = getch();
	echo();
	return ch;
}

void time_to_str(int y, int m, int d, char str[])
{
	int idx_i = 0;
	int y_v = y;
	int m_v = m;
	int d_v = d;
	
	for(idx_i = 3; idx_i >= 0; idx_i--)
	{
		str[idx_i] = '0' + y_v % 10;
		y_v = y_v / 10;
	}
	
	str[4] = '_';
	
	for(idx_i = 1; idx_i >= 0; idx_i--)
	{
		str[5+idx_i] = '0' + m_v % 10;
		m_v = m_v / 10;
	}
	str[7] = '_';

	for(idx_i = 1; idx_i >= 0; idx_i--)
	{
		str[8+idx_i] = '0' + d_v % 10;
		d_v = d_v / 10;
	}
	str[10] = '-';
}

char check_userinput_checkchange(char inp)	//입력값이 메뉴 변경이 아니면 0, 맞으면 해당 번호를 반환
{
	if (inp == 'z' || inp == 'x' || inp == 'c' || inp == 'v' || inp == 'Z' || inp == 'X' || inp == 'C' || inp == 'V')
	{
		switch (inp)
		{
			case 'Z':
			case 'z':
				return 1;
			case 'X':
			case 'x':
				return 2;
			case 'C':
			case 'c':
				return 3;
			case 'V':
			case 'v':
				return 4;
		}
		return 0;
	}
	else
	{
		return 0;
	}
	
}
