#include "goloso.h"


int main(){
	int n,m,k,u,v,w;
	cin >> n;
	cin >> m;
	cin >> k;

	list<arista> aristas;

	/* Creo la lista de aristas */
	for (int i = 0; i < m; i++){
		cin >> u;
		cin >> v;
		cin >> w;
		u--;
		v--;
		aristas.push_back(arista(u,v,w));
	}

	/* Llamo a la función que resuelve el ejercicio. */
	vector<int> posiciones = iniciar_golosa(aristas, n, k);

	/* Muestro el resultado por salida estandar. */
	mostrar_res(posiciones);
	return 0;
}
