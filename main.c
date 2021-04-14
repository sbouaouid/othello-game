#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "human_vs_human.h"
#include "human_vs_machine.h"

void title(void)
{
    system("color 20");
    printf("\n\n\n   			                          WELCOME TO \n\n\n");
    Sleep(500);
    printf("		   * * *   * * * * * * * *     * * * * * * * * * *         * *           * * *\n");
    Sleep(250);
    printf("		 *       * * * * * * * * *     * * * * * * * * * *         * *         *       *\n");
    Sleep(250);
    printf("		*         *    * *     * *     * * * *         * *         * *        *         *\n");
    Sleep(250);
    printf("		*         *    * *     * * * * * * * * * * * * * *         * *        *         *\n");
    Sleep(250);
    printf("		*         *    * *     * * * * * * * * * * * * * *         * *        *         *\n");
    Sleep(250);
    printf("		*         *    * *     * *     * * * *         * *         * *        *         *\n");
    Sleep(250);
    printf("		 *       *     * *     * *     * * * * * * * * * * * * * * * * * * * * *       *\n");
    Sleep(250);
    printf("		   * * *       * *     * *     * * * * * * * * * * * * * * * * * * * *   * * *\n\n\n");
    printf("Cliquez pour continuez >>>>>");
    getch();



}
void MenuPrincipale(){

        system("cls");
        //system ("color 2A");
        printf("\n\n\n");
        printf("\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\tOTHELLO");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        Sleep(250);
        printf("\t\t\t\t\t   1- REGLES DU JEU");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t2- JOUER");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t3-QUITTER");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(500);
}
void regles(){
    system("cls");
    printf("\n\n\n");
    printf("   Othello se joue a 2, sur un plateau unicolore de 64 cases (8 sur 8),\navec des pions bicolores, noirs d'un cote et blancs de l'autre.\n\n");
    printf("   Le but du jeu est d'avoir plus de pions de sa couleur que l'adversaire \na la fin de la partie, celle-ci s'achevant lorsque aucun des deux \njoueurs ne peut plus jouer de coup legal, generalement lorsque les 64 \ncases sont occupees.\n\n");
    printf("   Au debut de la partie, les noirs commencent.\n\n");
    printf("   Chacun a son tour, les joueurs vont poser un pion de leur couleur sur\nune case vide, adjacente a un pion adverse. Chaque pion pose doit\nobligatoirement encadrer un ou plusieurs pions adverses avec un autre\n pion de sa couleur, deja place.\n\n");
    printf("   Il retourne alors le ou les pions adverse(s) qu'il vient d'encadrer. \nLes pions ne sont ni retirés de l'othellier, ni deplaces d'une case \na l'autre.\n\n");
    printf("   On peut encadrer des pions adverses dans les huit directions et \nplusieurs pions peuvent etre encadres dans chaque direction.\n\n");
}
void adversaire(){
        system("cls");

        printf("\n\n\n");
        printf("\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\tADVERSAIRE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t1- JOUEUR");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t2- MACHINE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t3-RETOURNER");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(500);
}
void difficulte(){
        system("cls");

        printf("\n\n\n");
        printf("\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t  NIVEAU DE DIFFICULTE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t1- FACILE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t2- MOYEN");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t      3- DIFFICILE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t       4- IMPOSSIBLE");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(250);
        printf("\t\t\t\t\t\t5-RETOURNER");
        Sleep(250);
        printf("\n\t\t\t\t   *********************************\n");
        Sleep(500);
}

int main()
{
    int x,x1,x2;
	int fini = 0;
	system("color 20");
	title();
    while (!fini)
    {
        MenuPrincipale();

        printf("\nVeuillez faire le choix que vous voulez >>>>> ");
        scanf("%d",&x);
        switch (x) {
        case 1: {
            regles();
            printf("\n\nCliquez pour retourner au menu >>>>> ");
            getch();
        }break;

        case 2: adversaire();
                printf("\nVeuillez saisir votre choix >>>>> ");
                scanf("%d",&x1);
                switch (x1)
                {
                     case 1: HumanVsHuman();
                             break;

                     case 2: difficulte();
                             printf("\nVeuillez choisir le niveau de difficulte >>>>> ");
                             scanf("%d",&x2);
                                switch (x2) {
                                case 1: HumanVsMachine(0);
                                         break;
                               case 2: HumanVsMachine(2);
                                         break;
                               case 3: HumanVsMachine(3);
                                         break;
                                case 4: HumanVsMachine(6);
                                        break;
                                case 5: break;
                               default: HumanVsMachine(0);
                                        break;
                                        }
                                break;
                      case 3: break;
                }
                break;
         case 3:	fini =1;
                break;
                }

       }
    return 0;

}

