/*****************************************/
/****************LEVEL3.C*****************/
/***************CREATED*BY****************/ 
/******* dan passy boussougou ************/
/*************PROJECT*OTHELLO*************/
/********************℗********************/
/*****************************************/

#include"level3.h"

void ia_3(game *g,int p){

    coup cp;   
    arbre a=creer_arbre_avec_prof3(g,&cp,0,p);

    int max=0;
    int count=0;
    for(int i = 0; i < a->nb_fils; i++){
        MLV_draw_text((taille_place*a->fils[i]->cp.pos_x)+x_i, (taille_place_y*a->fils[i]->cp.pos_y)+y_i,"%d",MLV_COLOR_ORANGE1,a->fils[i]->eval);
        MLV_actualise_window();
        MLV_wait_milliseconds(300);
        if(a->fils[i]->eval > max){
            count = i;
            max = a->fils[i]->eval;
        }
    }
    MLV_wait_seconds(2);

    cp.pos_x = a->fils[count]->cp.pos_x;
    cp.pos_y = a->fils[count]->cp.pos_y;

    jouer(&cp,g);
    g->debutant=1;

    free_arbre(a);
    //printf("Best POS! nb = %d. Avec coup x=%d y=%d\n",best_pos,tablu_i[best_pos],tablu_j[best_pos]);
    a=NULL;
   
    
}

game mode_3(MLV_Image *board, MLV_Image *black, MLV_Image *white, MLV_Image *options,int prof){
    game g=init_game();
    g.debutant=1; //if == 1 player begins else if == 2 AI begins
    //get_names(&g);
    affichage_MLV(&g,board,white,black);
    coup cp;
    int taille_pos;
    
    while(!est_fini(&g)){
        taille_pos=existe_affiche_coup(&g,options);
        if(taille_pos==0){
            return g;
        }
        
        if(g.debutant==1){
            cp=lire_coup();
       
            if(jouer(&cp,&g)==1){
                g.debutant=2;
            }
        }
        else{
            MLV_wait_seconds(2);
            ia_3(&g,prof);
            
        }
        affichage_MLV(&g,board,white,black);
        //printf("%d vien de jouer\n\n",debutan);
        affiche_board(&g);
        eval_board(&g);
    }
    return g;
}
