#include "type_include.h"


void affgrille(int grille[Y][X]){
  int x,y;
  for(y=0;y<Y;y++){
    for(x=0;x<X;x++){
      printf("%d ",grille[y][x]);
    }
    printf("\n");
  }
}
      
void consgrille(int grille[Y][X]){
  /* 0 = vide 
     1 = mur
     2 = à acheter
     3 = terre
     4 = terre préparer
     10 = graine
     20 = jeune pousse
     30 = pousse
     40 = prés a la récolte
  */
  
  int x,y;
  for(y=0;y<Y;y++){
    for(x=0;x<X;x++){
      if(y==0 || y==199){
	grille[y][x] = 1;
      }
      else{
	if(x==0 || x==199){
	  grille[y][x] = 1;
	}
	else{
	  if(y > 2){
	    grille[y][x] = 2;
	  }
	  else{
	    grille[y][x] = 0;
	  }
	}
      }
    }
  }
  grille[1][4] = 3;
}

coord init(int grille[Y][X],coord joueur){
  joueur.y = 0;
  joueur.x = 0;
  consgrille(grille);
  return joueur;
}

int main(){
  int grille[Y][X];
  coord joueur;
  joueur.y = 0;
  init(grille,joueur);
  affgrille(grille);
  exit(0);
}
