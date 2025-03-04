#ifndef PLANTA_HPP
#define PLANTA_HPP

#include "Plataforma.hpp"

class Planta : public Plataforma {
public:
    Planta(const ObjetoDeJogo &obj, const Direcao direcao, const int velocidade = 2) : Plataforma{obj, direcao, velocidade} {}
    ~Planta() {}

    bool getAtivo() const { return m_ativo; }
    void setAtivo(const bool ativo) { m_ativo = ativo; }

    int getContador() const { return m_contador; }
    void setContador() { m_contador++; }

    void update() override {
        ObjetoDeJogo::update();
        if(getDirecao() == ESQUERDA) {
            this->moveLeft(getVelocidade());
        } else {
            this->moveRight(getVelocidade());
        }

        if (getAtivo() && getContador() < 5) {
            setContador();
        }
    }

private:
    int m_contador{0};
    bool m_ativo{false};
};

#endif
