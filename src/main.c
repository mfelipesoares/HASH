#include <stdio.h>
#include "../lib/hash.h"

int main(){
	Dicionario * dici = new_dici();
	menu(dici);
	libera(dici);
	return 0;
}
