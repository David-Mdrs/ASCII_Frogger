#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStart.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run() {

        system("clear");
        SpriteBuffer screen(80, 40);
        SpriteAnimado trem("Sprites/Trem.anm");
        std::string str;

        while(true) {
            getline(std::cin, str);

            trem.update();
            trem.draw(screen, 20, 20);
            
            system("clear");
            std::cout << screen << std::endl;
        }
    }

};

#endif // GAME_HPP
