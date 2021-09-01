#include <stdio.h>
#include "hanoi.h"

int main()
{
    /* Cria torre t1 cheia, t2 e t3 vazias */
    Torre t1 = criaTorreCheia();
    Torre t2 = criaTorreVazia();
    Torre t3 = criaTorreVazia();

    imprimeTorres(&t1, &t2, &t3);

    /* move o disco do topo da t1 para t2 */
    moveDisco(&t1, &t2);
    imprimeTorres(&t1, &t2, &t3);
 	
 	//move o disco do topo da t1 para t3
	 moveDisco(&t1, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	
	// depois move o disco do topo da t2 Vermelho  para o t3 
	moveDisco(&t2, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	
	 //depois move o disco do topo t1 Azul para t2 
	 moveDisco(&t1, &t2);
	 imprimeTorres(&t1, &t2, &t3);
	 
	// move o disco do topo t3 Vermelho para t1
	 moveDisco(&t3, &t1);
	 imprimeTorres(&t1, &t2, &t3);
	
	// move o disco do topo t3 Amarelo para t2
	 moveDisco(&t3, &t2);
	 imprimeTorres(&t1, &t2, &t3);
	 
	// depois move o disco do topo t1 Vermelho para t2
	 moveDisco(&t1, &t2);
	 imprimeTorres(&t1, &t2, &t3);
	 
	 // move o disco do topo t1 Verde para t3
	 moveDisco(&t1, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	  
	  
	  /*****/
	// move o disco do topo t2 Vermelho para t3
	 moveDisco(&t2, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	 	
	//depois move o disco do topo t2 Amarelo para t1
	 moveDisco(&t2, &t1);
	 imprimeTorres(&t1, &t2, &t3);
	 
	 // move o disco do topo t3 Vermelho para t1
	 moveDisco(&t3, &t1);
	 imprimeTorres(&t1, &t2, &t3);
	 
	 /******/
	 
	// move o disco do topo t2 Azul para t3
	 moveDisco(&t2, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	 
	// move o disco do topo t1 Vermelho para t2
	 moveDisco(&t1, &t2);
	 imprimeTorres(&t1, &t2, &t3);
	 
	 // depois move o disco do topo t1 Vermelho para t3
	 moveDisco(&t1, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	 
	  // move o disco do topo t2 Vermelho para t3
	 moveDisco(&t2, &t3);
	 imprimeTorres(&t1, &t2, &t3);
	 
	 
    return 0;
}
