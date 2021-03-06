#include <iostream>
#include <list>
#include <vector>
#include <set>
#include "string.h"
#include "trie.h"
typedef int hora;
typedef int vuelo_id;
typedef int ciudad_id;
#define MAX_INT 2147483647 

struct vuelo{
	string ori;
	string des;
	hora salida;
	hora llegada;
	vuelo_id id;

	vuelo():ori(""), des(""), salida(-1), llegada(-1), id(-1) {}
	vuelo(string a, string b, hora c, hora d, vuelo_id e):ori(a), des(b), salida(c), llegada(d), id(e) {}
	bool operator<(vuelo) const;

};

struct camino{
	ciudad_id c;
	vuelo_id v;

	camino():c(-1), v(-1){}
	camino(ciudad_id a, vuelo_id b):c(a), v(b) {}
};

bool vuelo::operator<(vuelo b) const{
		return (this->llegada <  b.llegada) || (this->llegada == b.llegada && this->salida < b.salida) || (this->llegada == b.llegada && this->salida == b.salida && this->id < b.id);
}

