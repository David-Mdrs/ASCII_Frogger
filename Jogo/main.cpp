#include <iostream>
#include <string>

// #include "Game.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

int main() {

	system("clear");

	SpriteBuffer screen(80, 40);

	ObjetoDeJogo background("background", Sprite("rsc/Fase1.txt"), 0, 0);

	ObjetoDeJogo sapo("sapo", SpriteAnimado("rsc/Sapo.anm", 1, COR::VERDE), 35, 38); 

	// SpriteAnimado trem("rsc/Trem.anm", 1, COR::CIANO);
	// Game::run();

	std::string str;

	while(true) {
		getline(std::cin, str);

		screen.clear();
		system("clear");

		if(str == "w")
			sapo.moveUp();
		else if(str == "a")
			sapo.moveLeft(2);
		else if(str == "s")
			sapo.moveDown();
		else if(str == "d")
			sapo.moveRight(2);

		background.update();		
		sapo.update();		

		background.draw(screen, background.getPosL(), background.getPosC());
		sapo.draw(screen, sapo.getPosL(), sapo.getPosC());

		// trem.draw(screen, 23, 15);
		// trem.update();


		std::cout << screen << std::endl;
	}
	
	return 0;
}
