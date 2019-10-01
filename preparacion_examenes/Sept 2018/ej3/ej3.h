#ifndef _CONCIERTOS_H
#define _CONCIERTOS_H

#include "diccionario.h"
#include "DiccionarioHash.h"
#include "lista.h"
#include <string>
#include <iostream>

class EConciertoExistente{};
class EAltaNoAdmitida{};
class EConciertoInexistente{};
class EConciertoConEsperas{};
class EClienteInexistente{};
class EConciertoSinEsperas{};
class EEsperaNoAdmitida{};

class Concierto {

typedef string CliCod;
typedef string ConCod;

public:

    Concierto();
    void an_concierto(ConCod con);
    void an_cliente(CliCod cli, ConCod cod);
    void borra_concierto(ConCod con);
    void borra_cliente(CliCod cli);
    bool hay_clientes_en_espera(ConCod con);
    CliCod proximo_cliente(ConCod con);
    void venta(ConCod con);
    void abandona(CliCod cli);
    void pon_en_espera(CliCod cli, ConCod con);
    Lista<CliCod> clientes() const;
    int num_clientes() const;
    int num_conciertos() const;

private:

    int _total_conciertos;
    int _total_clientes;
    DiccionarioHash<ConCod, Lista<CliCod>> _concierto_espera;
    DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>> _posicion_cliente;
    Diccionario<CliCod, char> _clientes;
    DiccionarioHash<CliCod, ConCod> _cliente_concierto;

};

#endif