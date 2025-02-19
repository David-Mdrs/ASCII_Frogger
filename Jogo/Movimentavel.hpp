#ifndef MOVIMENTAVEL_HPP
#define MOVIMENTAVEL_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <string>

enum Direcao { ESQUERDA, DIREITA };

class Movimentavel : public ObjetoDeJogo {
public:
    Movimentavel(const ObjetoDeJogo &obj, const Direcao direcao, const int velocidade = 2) : ObjetoDeJogo{obj}, m_direcao{direcao}, m_velocidade{velocidade} {}
    virtual ~Movimentavel() {}

    Direcao getDirecao() const { return m_direcao; }

    int getVelocidade() const { return m_velocidade; }
    void setVelocidade(const int velocidade) { m_velocidade = velocidade; }

    virtual void update() {
        ObjetoDeJogo::update();
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(getVelocidade());
        } else {
            this->moveRight(getVelocidade());
        }
    }

private:
    int m_velocidade;
    Direcao m_direcao;
};

#endif
