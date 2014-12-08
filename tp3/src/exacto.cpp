#include "grafo.h"


/* Sirve para saber si ya encontre una solución.  */
bool hay_una = false;

/* Inicializado en el main*/
bool es_solucion(vector<particion>& res, vector<particion>& ss, particion& p, nodo n, vector<vector<int> > mz_ady);


/**
* Calcula la partición (de tamaño maximo bolsas.size) que optimiza
*	(minimiza) la suma de pesos totales.
**/
void mejor_particion(vector<particion>& res, vector<particion>& bolsas, list<nodo> candidatos, vector<vector<int> >& mz_ady) {
	if (candidatos.size() == 0) {
		res = bolsas;
		hay_una = true;
	}else {
		nodo elegido = *candidatos.begin();
		candidatos.pop_front();
		for (unsigned int i = 0; i < bolsas.size(); i++){
			bolsas[i].elementos.push_back(elegido);
			/* Si sigue siendo una solución, exploro la rama.*/
			if (es_solucion(res, bolsas, bolsas[i], elegido, mz_ady)){
				bolsas[i].peso += peso_asociado(elegido, bolsas[i], mz_ady);
				mejor_particion(res, bolsas, candidatos, mz_ady);
				bolsas[i].peso -= peso_asociado(elegido, bolsas[i], mz_ady);
			}
			bolsas[i].elementos.pop_back();
		}
	}
}


/**
* Indica si la sub-solución (al agregarle un elemento) sigue 
*	siendo solución. Es decir, si el peso total resultante de
*	agregar al nuevo elemento supera el de la solución obtenida
*	anteriormente.
**/
bool es_solucion(vector<particion>& res, vector<particion>& ss, particion& p, nodo n, vector<vector<int> > mz_ady){
	if (!hay_una) return true;
	int cota_max = suma_total(res);
	int acumulado = suma_total(ss);
	int peso_agregado = peso_asociado(n, p, mz_ady);
	return cota_max > acumulado + peso_agregado;
}

/**
*  Recorre linealmente la partición pasada como parámetro,
*	y para cada elemento i de la partición, asigna en 
* posiciones[i] el número del conjunto de la partición
*	en donde está i.
**/
void establecer_posiciones(vector<particion>& bolsas, vector<int>& posiciones){
	int n_part = 0;
	for (auto it = bolsas.begin(); it != bolsas.end(); it++){
		for (auto nd = it->elementos.begin(); nd != it->elementos.end(); nd++){
			posiciones[*nd] = n_part;
		}
		n_part++;
	}
}


/* Muestra el resultado por la salida estandar. */
void mostrar_res(vector<int> res){
	for (auto it = res.begin(); it != res.end(); it++) cout << *it << " ";
	cout << endl;
}

int main(){
	int n,m,k,u,v,w;
	cin >> n;
	cin >> m;
	cin >> k;
	vector<vector<int> > mz_ady(n, vector<int>(n));
	vector<nodo> posiciones(n);
	

	/* Inicializo matriz de adyacencias */
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mz_ady[i][j] = -1;
		}
	}


	/* Completado de matriz de adyacencias */
	for (int i = 0; i < m; i++){
		cin >> u;
		cin >> v;
		cin >> w;
		u--;
		v--;

		mz_ady[u][v] = w; 
		mz_ady[v][u] = w; 
	 	
	}

	/* Creo la partición resultado, y la particion parcial. */
	vector<particion> res(k);
	vector<particion> bolsas(k);

	/* Creacion de la lista de nodos. */
	list<nodo> ns;
	for (int i = 0; i < n; i++) ns.push_back(i);

	/* Funcion que resuelve el ejercicio. */
	mejor_particion(res, bolsas, ns, mz_ady);
	
	/* Preparacion del resultado. */
	establecer_posiciones(res, posiciones);
	
	/* Muestra por salida estandar el resultado. */
	mostrar_res(posiciones);

	return 0;
}
