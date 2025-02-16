#include <iostream>
#include <string>

// #include "Game.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Movimentavel.hpp"

int main() {

	system("clear");

	SpriteBuffer screen(80, 40);

	ObjetoDeJogo background("background", Sprite("rsc/Fase1.txt"), 0, 0);

	ObjetoDeJogo sapo("sapo", SpriteAnimado("rsc/Sapo.anm", 1, COR::VERDE), 34, 38); 

	ObjetoDeJogo carro("carro", SpriteAnimado("rsc/CarroDir.anm", 1, COR::VERDE), 24, 20); 

	// Movimentavel carro(ObjetoDeJogo("carro", SpriteAnimado("rsc/CarroDir.anm", 1, COR::AZUL), 15, 2), DIREITA);

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

		//carro.movimentar();

		background.update();		
		sapo.update();
		carro.update();	

		background.draw(screen, background.getPosL(), background.getPosC());
		sapo.draw(screen, sapo.getPosL(), sapo.getPosC());
		carro.draw(screen, carro.getPosL(), carro.getPosC());


		std::cout << screen << std::endl;
	}
	
	return 0;
}
