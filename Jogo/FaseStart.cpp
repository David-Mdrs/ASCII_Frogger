#include "FaseStart.hpp"

#include "../ASCII_Engine/input/Keyboard.hpp"
#include "../ASCII_Engine/Cores.hpp"

void FaseStart::init() {
	objs.push_back(new ObjetoDeJogo("frogger", Sprite("rsc/Start/Frogger_Imagem.txt", COR::VERDE), 1, 35));
	objs.push_back(new ObjetoDeJogo("texto", Sprite("rsc/Start/Texto.txt", COR::BRANCA), 33, 20));
	objs.push_back(new ObjetoDeJogo("continuar",TextSprite("Pressione ENTER"), 3, 20));
    objs.push_back(new ObjetoDeJogo("continuar",TextSprite("para continuar !!"), 4, 20));
}

unsigned FaseStart::run(SpriteBuffer &screen) {
	std::string ent;
	
	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);

	Keyboard::setMode(Keyboard::NONBLOCKING);
	
	while (true) {
		//lendo entrada
		char ent = Keyboard::read();
		if (ent == 'q')
			return Fase::END_GAME;

        if (ent == '\n')
            return Fase::LEVEL_COMPLETE;

		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);
		system("sleep 0.125");
	}
	
	return Fase::END_GAME; // não necessário
}