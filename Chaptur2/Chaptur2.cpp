// Chaptur2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
	Game game;

	bool success = game.Initialize();

	if (!success) {
		return -1;
	}

	game.RunLoop();

	return 0;
}

