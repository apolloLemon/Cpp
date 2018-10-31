using liste_entiers = std::array<int,100>;
using liste_decimales = std::array<float,100>;

struct loi_de_probabilite {
	liste_entiers x;
	liste_decimales Px;
	unsigned int cardinal;
};

loi_de_probabilite formule_de_transfert (loi_de_probabilite X, string formule) {
    X.x[i] = evaluer(formule, X.x[i]);
}

float Esperance(loi_de_probabilite X) {
	float out=0; 
	for(int i=0;i<X.cardinal;i++){
		out+=X.x[i]*X.Px[i];
	} return out;
}

float Variance(loi_de_probabilite X) {
	return Esperance(formule_de_transfert(X, "x ^ 2"))-pow(Esperance(X),2);
}