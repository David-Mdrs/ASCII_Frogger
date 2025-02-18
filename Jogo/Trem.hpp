#ifndef TREM_HPP
#define TREM_HPP

#include "Movimentavel.hpp"

class Trem : public Movimentavel {
public:
    Trem(const ObjetoDeJogo &obj, const Direcao direcao) : Movimentavel{obj, direcao} {}
    ~Trem() {}

    int getVelocidade() const { return m_velocidade; }
    bool getAtivo() const { return m_ativo; }

    void setAtivo(const bool ativo) { m_ativo = ativo; }
    void setVelocidade(const int velocidade) { m_velocidade = velocidade; }

    void update() override {
        ObjetoDeJogo::update();
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(getVelocidade());
        } else {
            this->moveRight(getVelocidade());
        }

        if(getAtivo()) {
            if(getVelocidade() < 10) {
                setVelocidade(getVelocidade() + 2);
                setAtivo(false); }
        } else {
            setAtivo(true);
        }
    }

private:
    bool m_ativo{false};
    int m_velocidade{1};
};

#endif
