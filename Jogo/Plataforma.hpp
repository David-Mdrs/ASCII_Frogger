#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include "Movimentavel.hpp"
#include <string>

class Plataforma : public Movimentavel {
public:
    Plataforma(const ObjetoDeJogo &obj, const Direcao direcao, const int velocidade = 2) : Movimentavel{obj, direcao, velocidade} {}
    virtual ~Plataforma() {}
};

#endif
