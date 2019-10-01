#include "ej3.h" 

using namespace std;

Concierto::Concierto() : _total_clientes(0), _total_conciertos(0) {};

void Concierto::an_concierto(ConCod con){   // O(1)

    Lista<CliCod> aux;
    if(!_concierto_espera.contiene(con)){
        _concierto_espera.inserta(con, aux);
        _total_conciertos++;
    }
    else
        throw EConciertoExistente();
    
}

void Concierto::an_cliente(CliCod cli, ConCod con){     // O(log(N))

    if(!_concierto_espera.contiene(con) || _clientes.contiene(cli))
        throw EAltaNoAdmitida();
    else{

        _clientes.inserta(cli, ' ');
        _cliente_concierto.inserta(cli, con);
        DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
        conIter.valor().pon_final(cli);
        DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
        posIter.valor().inserta(cli, conIter.valor().ultimo);
        _total_clientes++;

    }

}

void Concierto::borra_concierto(ConCod con){    // O(1)

    DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
    if(conIter == _concierto_espera.end()) throw EConciertoInexistente();
    if(!conIter.valor().esVacia()) throw EConciertoConEsperas();
    else{
        _concierto_espera.borra(con);
        _posicion_cliente.borra(con);
        _total_conciertos--;
    }

}

void Concierto::borra_cliente(CliCod cli){      //o(1)

    if(!_clientes.contiene(cli)) throw EClienteInexistente();
    else{

        ConCod con = _cliente_concierto.valorPara(cli);
        DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
        Lista<CliCod>::Iterator listaIter = posIter.valor().valorPara(cli);
        DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
        _posicion_cliente.borra(cli);
        conIter.valor().eliminar(listaIter);
        _cliente_concierto.borra(cli);
        _clientes.borra(cli);
        _total_clientes--;

    }

}

bool Concierto::hay_clientes_en_espera(ConCod con){     // O(1)

    DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
    if(conIter == _concierto_espera.end()) throw EConciertoExistente();
    else{

        return conIter.valor().longitud();

    }

}

Concierto::CliCod Concierto::proximo_cliente(ConCod con){   //O(1)

    DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
    if(conIter == _concierto_espera.end()) throw EConciertoExistente();
    else{

        return conIter.valor().primero();

    }

}

void Concierto::venta(ConCod con){     // O(1)

    DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
    if(conIter == _concierto_espera.end()) throw EConciertoExistente();
    else{

        if(conIter.valor().esVacia) throw EConciertoSinEsperas();
        else{
            CliCod cli = proximo_cliente(con);
            conIter.valor().quita_ppio();
            DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
            posIter.valor().borra(cli);
            _cliente_concierto.borra(cli);

        }

    }

}

void Concierto::abandona(CliCod cli){   //O(1)

    DiccionarioHash<CliCod, ConCod>::Iterator cliConIter = _cliente_concierto.busca(cli);
    ConCod con = cliConIter.valor();
    DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
    Lista<CliCod>::Iterator listaIter = posIter.valor().valorPara(cli);
    DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);

    conIter.valor().eliminar(listaIter);
    posIter.valor().borra(cli);
    _cliente_concierto.borra(cli);

}

void Concierto::pon_en_espera(CliCod cli, ConCod con){      //O(1)

    DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
    if(!_clientes.contiene(cli) || !_concierto_espera.contiene(con) || !posIter.valor().contiene(cli)) throw EEsperaNoAdmitida();
    else{

        _cliente_concierto.inserta(cli, con);
        DiccionarioHash<ConCod, Lista<CliCod>>::Iterator conIter = _concierto_espera.busca(con);
        conIter.valor().pon_final(cli);
        DiccionarioHash<ConCod, DiccionarioHash<CliCod, Lista<CliCod>::Iterator>>::Iterator  posIter= _posicion_cliente.busca(con);
        posIter.valor().inserta(cli, conIter.valor().ultimo);

    }

}

Lista<Concierto::CliCod> Concierto::clientes() const{       // O(N)

    Lista<CliCod> list;
    
    if(!_clientes.esVacio()){
    
        Diccionario<CliCod, char>::ConstIterator cliIter = _clientes.cbegin();
        while(cliIter != _clientes.cend()){

            list.pon_final(cliIter.clave());
            cliIter.next();

        }

    }

    return list;

}

int Concierto::num_clientes() const { return _total_clientes; }     // O(1)

int Concierto::num_conciertos() const { return _total_conciertos; } // O(1)