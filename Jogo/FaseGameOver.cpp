#include "FaseGameOver.hpp"

#include "../ASCII_Engine/input/Keyboard.hpp"
#include "../ASCII_Engine/Cores.hpp"

void FaseGameOver::init() {
	objs.push_back(new ObjetoDeJogo("frogger", Sprite("rsc/Design/Contorno.txt", COR::VERDE), 1, 35));
	objs.push_back(new ObjetoDeJogo("olhoesq", Sprite("rsc/Design/Olho.txt", COR::BRANCA), 8, 80));
	objs.push_back(new ObjetoDeJogo("olhodir", Sprite("rsc/Design/Olho.txt", COR::BRANCA), 8, 106));
    objs.push_back(new ObjetoDeJogo("boca", Sprite("rsc/Design/Boca.txt", COR::MARROM), 19, 58));
    objs.push_back(new ObjetoDeJogo("lingua", Sprite("rsc/Design/Lingua.txt", COR::VERMELHA), 22, 69));

    gameOver = new ObjetoDeJogo("gameOver", Sprite("rsc/Design/GameOver.txt", COR::BRANCA), 33, 30);
	objs.push_back(gameOver);
	objs.push_back(new ObjetoDeJogo("continuar",TextSprite("Pressione ENTER"), 2, 20));
    objs.push_back(new ObjetoDeJogo("continuar",TextSprite("para continuar!!"), 3, 20));
    // objs.push_back(new ObjetoDeJogo("continuar",TextSprite("Pressione Q para sair!!"), 5, 15));


    sapo1 = new ObjetoDeJogo("sapo1", SpriteAnimado("rsc/Frogger.anm", 1, COR::VERDE), 6, 25);
	objs.push_back(sapo1);
    sapo2 = new ObjetoDeJogo("sapo2", SpriteAnimado("rsc/Frogger.anm", 1, COR::VERDE), 30, 135);
	objs.push_back(sapo2);

    objs.push_back(new ObjetoDeJogo("github",TextSprite("@GitHub/David-Mdrs"), 3, 129));
}

unsigned FaseGameOver::run(SpriteBuffer &screen) {
	std::string ent;
	
	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);

	Keyboard::setMode(Keyboard::NONBLOCKING);
	
    bool alturaS1{false};
    bool alturaS2{true};

	while (true) {

        // Animando nome
        if (gameOver->getPosC() == 30)
            gameOver->moveRight(1);
        else
            gameOver->moveLeft(1);

        // Analisando posição dos froggers
        if (sapo1->getPosL() == 6)
            alturaS1 = false;
        else if (sapo1->getPosL() == 30)
            alturaS1 = true;

        if (sapo2->getPosL() == 6)
            alturaS2 = false;
        else if (sapo2->getPosL() == 30)
            alturaS2 = true;

        // Movimentando froggers
        if (alturaS1)
            sapo1->moveUp(2);
        else
            sapo1->moveDown(2);

            if (alturaS2)
            sapo2->moveUp(2);
        else
            sapo2->moveDown(2);

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
		system("sleep 0.15");
	}
	
	return Fase::END_GAME; // não necessário
}