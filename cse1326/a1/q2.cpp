#include <iostream>
bool check(char b[3][3],char player)
{
	//    there are 8 possibilities for a win
		// down
	if ( (b[0][0] == player && b[0][1] == player && b[0][2] == player) ||
             (b[1][0] == player && b[1][1] == player && b[1][2] == player) ||
	     (b[2][0] == player && b[2][1] == player && b[2][2] == player) )
		return true;
		// across
	if ( (b[0][0] == player && b[1][0] == player && b[2][0] == player) ||
             (b[0][1] == player && b[1][1] == player && b[2][1] == player) ||
	     (b[0][2] == player && b[1][2] == player && b[2][2] == player) )
		return true;
		// diagonal
	if ( (b[0][0] == player && b[1][1] == player && b[2][2] == player) ||
             (b[0][2] == player && b[1][1] == player && b[2][0] == player) ) 
		return true;

	return false;
	// if you didn't want to make this function, the code could have been cut and
	// pasted twice in game_over
}

char game_over(char b[3][3])
{
	// check for a win by X
	if (check(b,'X')) return 'X';
	// check for a win by O
	if (check(b,'O')) return 'O';
	// check for a draw or game not over
	//        if all squares are occupied, it is a draw, else
	//        the game is not over
	int count=0;
	for (auto row:{0,1,2})
	{
		for (auto col:{0,1,2})
		{
			if (b[row][col]==0)
				count++;
		}
	}
        if (count<10)
	        return ' ';	
	if (count==0)
		return 'D';
	return '!'; // this is an error
}

int main()
{
	{
		char b[3][3] = { { 'O','X','X'},
			         { 'O','O','X'},
				 { 'O','O', 0 } };
		std::cout << "o should win " << game_over(b) << std::endl;
	}
	{
		char b[3][3] = { { 'O','X','O'},
			         { 'O','O','X'},
				 { 'X','X','X' } }; // not a legal game
		std::cout << "X should win " << game_over(b) << std::endl;
	}
	{
		char b[3][3] = { { 'O','X', 0 },
			         {  0 , 0 , 0 },
				 {  0 , 0 , 0 } }; // not a legal game
		std::cout << "not over " << game_over(b) << std::endl;
	}
	{
		char b[3][3] = { { 'O', 'X', 'O' },
			         { 'X', 'X', 'O' },
				 { 'O', 'O', 'X' } }; // not a legal game
						      // there are draws that happen before this one...
		std::cout << "draw " << game_over(b) << std::endl;
	}
	return 0;
}
