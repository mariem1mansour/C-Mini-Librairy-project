#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<unistd.h>
#include<conio.h>
#define max_doc 5 

typedef struct loc {
	int salle;
	int rayon;
}loc;
typedef struct date {
	int j;
	int m;
	int a;
}date;
/****personne***/
typedef struct personne {
	    char nom[20];
       char prenom[20];
       int id ; 
       char adr [20];
       struct emprunt {
    	int nb_eff;
    	int nb_en_cours;
    	int nb_depasse;
}doc[3];
       int duree;
       	char type [20];
}personne;
/****document***/
typedef struct livre {
	char titre [50];
	struct loc localisation;
	char code [10] ;
	int nb_exemp ;
	char auteur [20];
	char editeur[20];
    struct date date_edition ;
}livre;
typedef struct article {
	char titre [50];
	struct loc localisation;
	char code [10] ;
	int nb_exemp ;
	char auteur [20];
    struct date date_pub ;
}article;
typedef struct magazine {
	char titre [50];
	struct loc localisation;
	char code [10] ;
	int nb_exemp ;
    int freq;
}magazine;
/****saisir fiche d'une personne ***/
void saisirfiche_per(){
	FILE*g;
	  personne *f;
	  int n,i,j;
	  printf ("combien de personnes veulent faire inscription ici ? \n");
	  scanf("%d",&n);
	f=(personne*) malloc (sizeof(personne));
    g=fopen ("personne.txt","a");

	for(i=0;i<n;i++) {
		f[i].doc->nb_eff =0;
		f[i].doc->nb_en_cours=0;
		f[i].doc->nb_depasse=0; 
		personne*f=(personne*) malloc (n*sizeof(personne));
		fflush(stdin);
	printf("donner votre nom \n");
	scanf ("%[^\n]s",f[i].nom);
		fflush(stdin);
		printf("donner votre prenom\n");
	scanf ("%[^\n]s",f[i].prenom);
		printf("donner votre ID\n");
	scanf ("%d",&f[i].id);
		fflush(stdin);
		printf("donner votre adresse\n");
	scanf ("%[^\n]s",f[i].adr); 
	printf("donner le nombre des emprunts effectues\n");
	scanf ("%d",&f[i].doc->nb_eff);
		printf("donner le nombre des emprunts en cours\n");
	scanf ("%d",&f[i].doc->nb_en_cours);
		printf("donner le nombre des emprunts d้pass้s\n");
	scanf ("%d",&f[i].doc->nb_depasse); 
		printf("veuillez saisir la duree de pret en jours (7jours pour visiteur / 14 jours pour etudiant / 30 jours pour enseignant) \n");
	scanf ("%d",&f[i].duree);
//	printf("Tapez Etudiant ou prof ou visiteur\n ");
//	scanf("%s",f[i].type );
		fwrite (&f[i],sizeof(personne),1,g);
	 }

	fclose (g);
	}

/**********************************affichage personne***/	
	void aff_info_per(){
		personne f1;
		FILE* g; 
	g=fopen("personne.txt","r");	
	while(fread(&f1,sizeof(personne),1,g)){
	
	 	printf ("votre nom est  ");
	    puts(f1.nom);
	    	 	printf ("\nvotre prenom est  ");
	    puts(f1.prenom);
		//	printf ("votre prenom est %s \n", f1.prenom);
			//printf("vous etes %s \n");puts(f1.type);
			printf ("votre ID est %d \n", f1.id);
		//	printf ("votre adresse est %s \n", f1.adr);
			 	printf ("votre address est  ");
	        puts(f1.adr);
			printf ("\nle nombre de documents effectues est %d \n", f1.doc->nb_eff);
			printf ("le nombre de documents en cours est %d \n", f1.doc->nb_en_cours);
			printf ("le nombre de documents depassee est %d \n", f1.doc->nb_depasse);
			printf ("la duree de pret en jours est %d \n", f1.duree);
	    	printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n");
		
	}
	fclose(g);
	}
	
/************************************chercher personne selon id****/	
	void chercher_personne(){
				personne f1;
		FILE* g; int id;int test;
	g=fopen("personne.txt","r");
	printf ("donner votre identifiant pour la recherche: \n"); scanf ("%d",&id );	
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
			printf ("votre nom est %s \n", f1.nom);
			printf ("votre prenom est %s \n", f1.prenom);
				//	printf("vous etes %s \n", f1.type);
			printf ("votre ID est %d \n", f1.id);
			printf ("votre adresse est %s \n", f1.adr);
			printf ("le nombre de documents effectues est %d \n", f1.doc->nb_eff);
			printf ("le nombre de documents en cours est %d \n", f1.doc->nb_en_cours);
			printf ("le nombre de documents depassee est %d \n", f1.doc->nb_depasse);
			printf ("la duree de pret en jours est %d \n", f1.duree);
	    	printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n");
	

}
}
	if (!test) printf ("\npersonne non trouve(e) ! \n");
	fclose(g);
	}

	/**************************************modif personne***/
void modif_per_data(){
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant pour la modification: \n"); scanf ("%d",&id );	
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
				fflush(stdin);
	printf("donner votre nouveau nom \n");
	scanf ("%[^\n]s",f1.nom);
		fflush(stdin);
		printf("donner votre nouveau prenom\n");
	scanf ("%[^\n]s",f1.prenom);
		printf("donner votre nouveau ID\n");
	scanf ("%d",&f1.id);
		fflush(stdin);
		printf("donner votre nouvelle adresse\n");
	scanf ("%[^\n]s",f1.adr); 
	printf("donner le nouveau nombre des emprunts effectues\n");
	scanf ("%d",&f1.doc->nb_eff);
		printf("donner le nouveau nombre des emprunts en cours\n");
	scanf ("%d",&f1.doc->nb_en_cours);
		printf("donner le nouveau nombre des emprunts depasses\n");
	scanf ("%d",&f1.doc->nb_depasse); 
		printf("veuillez saisir la nouvelle duree de pret en jours (7jours pour visiteur / 14 jours pour etudiant / 30 jours pour enseignant)\n");
	scanf ("%d",&f1.duree);
	//	printf("Tapez Etudiant ou prof ou visiteur\n ");
//	scanf("%s",f1.type );
	

		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		fclose(g);
		fclose(gg);
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! \n");
			fclose(g);
		}
	/************************************supp personne**/
	void supp_fiche_pers(){
							personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant pour supprimer vos donnees: \n"); scanf ("%d",&id );	
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
	printf("\nSuppression effectuee avec succes !\n");
	}else 
	fwrite(&f1,sizeof(personne),1,gg);
	}
	fclose(g);
	fclose(gg);
		if (test) 
		{
			gg=fopen("personneAUX.txt","r");
			g=fopen("personne.txt","w");
			while(fread(&f1,sizeof(personne),1,gg)){
				fwrite(&f1,sizeof(personne),1,g);
			}
			fclose(g); fclose(gg);
	}
	 else printf ("\npersonne non trouve(e) ! \n");
	fclose(g);
}
	/****trie personnes ****/
		void trie_fiche_pers (){
			personne *p ; personne p1; FILE *g; int nb ;int i;
			g=fopen("personne.txt","r");
			fseek (g, 0, SEEK_END);
			nb=ftell(g)/sizeof(personne);
			p=(personne*)calloc(nb,sizeof(personne));
			
			rewind(g);
			for(i=0; i<nb;i++ ) 
			fread (&p[i],sizeof(personne),1,g);
			for(i=0; i<nb;i++ ){
				for(int j =0 ; j<nb;j++){
					if(p[i].id > p[j].id){
						p1=p[i];
						p[i]=p[j];
						p[j]=p1;
					}
				}
			}
			for (i=0; i<nb ; i++){
			printf ("votre nom est %s \n", p[i].nom);
			printf ("votre prenom est %s \n", p[i].prenom);
		//	printf("vous etes %s \n", p[i].type);
			printf ("votre ID est %d \n", p[i].id);
			printf ("votre adresse est %s \n", p[i].adr);
			printf ("le nombre de documents effectues est %d \n", p[i].doc->nb_eff);
			printf ("le nombre de documents en cours est %d \n", p[i].doc->nb_en_cours);
			printf ("le nombre de documents depassee est %d \n", p[i].doc->nb_depasse);
			printf ("la duree de pret en jours est %d \n", p[i].duree);
	    	printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX \n");
			}
			fclose(g);
		}
		/****creation fiche d'un livre*******/
void saisir_liv()
		{
	FILE*g;
	  livre *f;
	  int n,i,j;
	  printf ("combien de livres a ajout ? \n");
	  scanf("%d",&n);
	f=(livre*) malloc (sizeof(livre));
    g=fopen ("livre.txt","a");

	for(i=0;i<n;i++) {
		f[i].nb_exemp =0;
		
	livre*f=(livre*) malloc (n*sizeof(livre));
	fflush(stdin);
	printf("donner le titre \n");
	scanf ("%[^\n]s",f[i].titre);
		printf("donner la salle ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.salle);
		printf("donner le rayon ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.rayon);
	fflush(stdin);
		printf("donner le code du document \n");
	scanf ("%[^\n]s",f[i].code);
	printf("donner le nombre des exemplaires\n");
	scanf ("%d",&f[i].nb_exemp);
	fflush(stdin);
		printf("donner le nom d' auteur \n");
	scanf ("%[^\n]s",f[i].auteur);
	fflush(stdin);
		printf("donner l 'editeur\n");
	scanf ("%[^\n]s",f[i].editeur);
		printf("donner le jour qui correspond au date d 'edition \n");
	scanf ("%d",&f[i].date_edition.j);
		printf("donner le mois qui correspond au date d 'edition \n");
	scanf ("%d",&f[i].date_edition.m);
		printf("donner l'annee qui correspond au date d'edition \n");
	scanf ("%d",&f[i].date_edition.a);
		fwrite (&f[i],sizeof(livre),1,g);
	 }

	fclose (g);
	}
		
		

/******affichage des infos de livre******/
		void aff_info_liv() {
				livre f1;
		FILE* g; int i=1;
	g=fopen("livre.txt","r");	
	while(fread(&f1,sizeof(livre),1,g)){
	
            printf ("le titre est ");
            puts (f1.titre);
			printf (" \nla salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du livre est : ");
			puts (f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf ("le nom d'auteur est : ");
			puts (f1.auteur);
			printf ("l ''editeur est : ");
			puts (f1.editeur);
			printf ("la date d'edition'est %d /%d /%d \n", f1.date_edition.j,f1.date_edition.m,f1.date_edition.a);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	}
		
	
	fclose(g);		
		};
		/******suppression de livre เ partir de son code*****/
			void supp_liv(){
								livre f1;int i;char code[10];
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("livre.txt","r");
	gg=fopen("livreAUX.txt","w");fflush(stdin);
	printf ("donner le code pour supprimer : \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(livre),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;

	
	
	}else 
	fwrite(&f1,sizeof(livre),1,gg);
	}
	fclose(g);
	fclose(gg);
		if (test) 
		{
			gg=fopen("livreAUX.txt","r");
			g=fopen("livre.txt","w");
			while(fread(&f1,sizeof(livre),1,gg)){
				fwrite(&f1,sizeof(livre),1,g);
			}
			fclose(g); fclose(gg);
	}
	 else printf ("\nlivre non trouve(e) ! \n");
	fclose(g);
			};
/************************************chercher livre selon code****/	
	void chercher_livre(){
				livre f1;
		FILE* g; char code[10];int test;
	g=fopen("livre.txt","r");fflush(stdin);
	printf ("donner le code du livre pour la recherche: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(livre),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
	
            printf ("le titre est %s \n", f1.titre);
			printf (" la salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du livre est %s \n", f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf (" le nom d'auteur est %d \n", f1.auteur);
			printf ("l'editeur est %d \n", f1.editeur);
			printf ("la date d'edition'est %d /%d /%d \n", f1.date_edition.j,f1.date_edition.m,f1.date_edition.a);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	

}
}
	if (!test) printf ("\nlivre non trouve(e) ! \n");
	fclose(g);
	}			
			
	/**************************************modif livre***/
void modif_liv_data(){
					livre f1;int i;
		FILE* g ;FILE *gg; char code [10];int test;
	g=fopen("livre.txt","r");
	gg=fopen("livreAUX.txt","w");fflush(stdin);
	printf ("donner le code pour la modification: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(livre),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
			fflush(stdin);
	printf("donner le nv titre \n");
	scanf ("%[^\n]s",f1.titre);
		printf("donner la nv salle ou se trouve le document \n");
	scanf ("%d",&f1.localisation.salle);
		printf("donner le nv rayon ou se trouve le document \n");
	scanf ("%d",&f1.localisation.rayon);
	fflush(stdin);
		printf("donner le nv code du document \n");
	scanf ("%[^\n]s",f1.code);
	printf("donner le nv nombre des exemplaires\n");
	scanf ("%d",&f1.nb_exemp);
	fflush(stdin);
		printf("donner le nv nom d'auteur \n");
scanf ("%[^\n]s",f1.auteur); 
fflush(stdin);			
		printf("donner le nv editeur\n");
	scanf ("%[^\n]s",f1.editeur);
		printf("donner le nv jour qui correspond au date d 'edition \n");
	scanf ("%d",&f1.date_edition.j);
		printf("donner le nv mois qui correspond au date d 'edition \n");
	scanf ("%d",&f1.date_edition.m);
		printf("donner nv l'annee qui correspond au date d 'edition \n");
	scanf ("%d",&f1.date_edition.a);
	

		}
		fwrite(&f1,sizeof(livre),1,gg);
		}
		fclose(g);
		fclose(gg);
			if (test) 
			{
				gg=fopen("livreAUX.txt","r");
				g=fopen("livre.txt","w");
				while(fread(&f1,sizeof(livre),1,gg)){
					fwrite(&f1,sizeof(livre),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\nlivre non trouve(e) ! \n");
			fclose(g);
		}			

	/****creation fiche d'un article*******/
void saisir_art()
		{
	FILE*g;
	  article *f;
	  int n,i,j;
	  printf ("combien de articles a ajout ? \n");
	  scanf("%d",&n);
	f=(article*) malloc (sizeof(article));
    g=fopen ("article.txt","a");

	for(i=0;i<n;i++) {
		f[i].nb_exemp =0;
		
	article*f=(article*) malloc (n*sizeof(article));
	fflush(stdin);
	printf("donner le titre \n");
	scanf ("%[^\n]s",f[i].titre);
		printf("donner la salle ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.salle);
		printf("donner le rayon ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.rayon);
	fflush(stdin);
		printf("donner le code du document \n");
	scanf ("%[^\n]s",f[i].code);
	printf("donner le nombre des exemplaires\n");
	scanf ("%d",&f[i].nb_exemp);
	fflush(stdin);
		printf("donner le nom d'auteur \n");
	scanf ("%[^\n]s",f[i].auteur);
		printf("donner le jour qui correspond au date d publication \n");
	scanf ("%d",&f[i].date_pub.j);
		printf("donner le mois qui correspond au date d publication \n");
	scanf ("%d",&f[i].date_pub.m);
		printf("donner l'annee qui correspond au date d publication \n");
	scanf ("%d",&f[i].date_pub.a);
		fwrite (&f[i],sizeof(article),1,g);
	 }

	fclose (g);
	}
		
		

/******affichage des infos de article******/
		void aff_info_art() {
				article f1;
		FILE* g; int i=1;
	g=fopen("article.txt","r");	
	while(fread(&f1,sizeof(article),1,g)){
	
            printf ("le titre est ");
            puts (f1.titre);
			printf (" la salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du article est :");
			puts (f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf ("le nom d'auteur est : ");
			puts (f1.auteur);
			printf ("la date de publication est %d /%d /%d \n", f1.date_pub.j,f1.date_pub.m,f1.date_pub.a);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	}
		
	
	fclose(g);		
		};
/******suppression de article เ partir de son code*****/
			void supp_art(){
								article f1;int i;char code[10];
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("article.txt","r");
	gg=fopen("articleAUX.txt","w");fflush(stdin);
	printf ("donner le code pour supprimer : \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(article),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;

	
	
	}else 
	fwrite(&f1,sizeof(article),1,gg);
	}
	fclose(g);
	fclose(gg);
		if (test) 
		{
			gg=fopen("articleAUX.txt","r");
			g=fopen("article.txt","w");
			while(fread(&f1,sizeof(article),1,gg)){
				fwrite(&f1,sizeof(article),1,g);
			}
			fclose(g); fclose(gg);
	}
	 else printf ("\narticle non trouve(e) ! \n");
	fclose(g);
			};

/************************************chercher article selon code****/	
	void chercher_article(){
				article f1;
		FILE* g; char code[10];int test;
	g=fopen("article.txt","r");fflush(stdin);
	printf ("donner le code du article pour la recherche: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(article),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
	
             printf ("le titre est ");
            puts (f1.titre);
			printf (" la salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du article est :");
			puts (f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf ("le nom d'auteur est : ");
			puts (f1.auteur);
			printf ("la date de publication est %d /%d /%d \n", f1.date_pub.j,f1.date_pub.m,f1.date_pub.a);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	

}
}
	if (!test) printf ("\narticle non trouve(e) ! \n");
	fclose(g);
	}			
			
	/**************************************modif article***/
void modif_article_data(){
					article f1;int i;
		FILE* g ;FILE *gg; char code [10];int test;
	g=fopen("article.txt","r");
	gg=fopen("articleAUX.txt","w");fflush(stdin);
	printf ("donner le code pour la modification: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(article),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
			fflush(stdin);
	printf("donner le nv titre \n");
	scanf ("%[^\n]s",f1.titre);
		fflush(stdin);
		printf("donner la nv salle ou se trouve le document \n");
	scanf ("%d",&f1.localisation.salle);
		printf("donner le nv rayon ou se trouve le document \n");
	scanf ("%d",&f1.localisation.rayon);
		fflush(stdin);
		printf("donner le nv code du document \n");
	scanf ("%[^\n]s",f1.code);
	printf("donner le nv nombre des exemplaires\n");
	scanf ("%d",&f1.nb_exemp);
		fflush(stdin);
		printf("donner le nv nom d'auteur \n");
scanf ("%[^\n]s",f1.auteur); 			
	
		printf("donner le nv jour qui correspond au date d pub \n");
	scanf ("%d",&f1.date_pub.j);
		printf("donner le nouveau mois qui correspond au date d 'pub \n");
	scanf ("%d",&f1.date_pub.m);
		printf("donner nouveau l'annee qui correspond au date d 'pub \n");
	scanf ("%d",&f1.date_pub.a);
	

		}
		fwrite(&f1,sizeof(article),1,gg);
		}
		fclose(g);
		fclose(gg);
			if (test) 
			{
				gg=fopen("articleAUX.txt","r");
				g=fopen("article.txt","w");
				while(fread(&f1,sizeof(article),1,gg)){
					fwrite(&f1,sizeof(article),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\narticle non trouve(e) ! \n");
			fclose(g);
		}
	/****creation fiche d'un magazine*******/
void saisir_magazine()
		{
	FILE*g;
	  magazine *f;
	  int n,i,j;
	  printf ("combien de magazines a ajout ? \n");
	  scanf("%d",&n);
	f=(magazine*) malloc (sizeof(magazine));
    g=fopen ("magazine.txt","a");

	for(i=0;i<n;i++) {
		f[i].nb_exemp =0;
		
	magazine*f=(magazine*) malloc (n*sizeof(magazine));
	fflush(stdin);
	printf("donner le titre \n");
	scanf ("%[^\n]s",f[i].titre);
		printf("donner la salle ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.salle);
		printf("donner le rayon ou se trouve le document \n");
	scanf ("%d",&f[i].localisation.rayon);
		printf("donner le code du document \n");
	scanf ("%s",f[i].code);
	printf("donner le nombre des exemplaires\n");
	scanf ("%d",&f[i].nb_exemp);
		printf("donner la freq \n");
	scanf ("%d",&f[i].freq);

		fwrite (&f[i],sizeof(magazine),1,g);
	 }

	fclose (g);
	}
		
		

/******affichage des infos de magazine******/
void aff_info_mag() {
				magazine f1;
		FILE* g; int i=1;
	g=fopen("magazine.txt","r");	
	while(fread(&f1,sizeof(magazine),1,g)){
	
            printf ("le titre est ");
            puts (f1.titre);
			printf (" la salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du magazine est :");
			puts (f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf ("la fr้quence est : %d \n ",f1.freq);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	}
	fclose(g);		
		};
/******suppression de magazine เ partir de son code*****/
			void supp_mag(){
								magazine f1;int i;char code[10];
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("magazine.txt","r");
	gg=fopen("magazineAUX.txt","w"); 	fflush(stdin);
	printf ("donner le code pour supprimer : \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(magazine),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;

	
	
	}else 
	fwrite(&f1,sizeof(magazine),1,gg);
	}
	fclose(g);
	fclose(gg);
		if (test) 
		{
			gg=fopen("magazineAUX.txt","r");
			g=fopen("magazine.txt","w");
			while(fread(&f1,sizeof(magazine),1,gg)){
				fwrite(&f1,sizeof(magazine),1,g);
			}
			fclose(g); fclose(gg);
	}
	 else printf ("\nmagazine non trouve(e) ! \n");
	fclose(g);
			};

/************************************chercher magazine selon code****/	
	void chercher_magazine(){
				magazine f1;
		FILE* g; char code[10];int test;
	g=fopen("magazine.txt","r");fflush(stdin);
	printf ("donner le code du magazine pour la recherche: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(magazine),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
	
             printf ("le titre est ");
            puts (f1.titre);
			printf (" la salle ou se trouve le document est %d \n", f1.localisation.salle);
			printf ("le rayon ou se trouve le document est %d \n", f1.localisation.rayon);
			printf ("le code du magazine est :");
			puts (f1.code);
			printf ("le nombre des exemplaires est %d \n", f1.nb_exemp);
			printf ("la fr้quence est : %d \n ",f1.freq);
			printf("\n XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx\n");
	

}
}
	if (!test) printf ("\nmagazine non trouve(e) ! \n");
	fclose(g);
	}			
			
	/**************************************modif magazine***/
void modif_magazine_data(){
					magazine f1;int i;
		FILE* g ;FILE *gg; char code [10];int test;
	g=fopen("magazine.txt","r");
	gg=fopen("magazineAUX.txt","w");fflush(stdin);
	printf ("donner le code pour la modification: \n"); scanf ("%[^\n]s",code );	
	while(fread(&f1,sizeof(magazine),1,g)){
	if (strcmp(f1.code,code)==0)
	    {
	    	test=1;
	fflush(stdin);
	printf("donner le nouveau titre de la magazine \n");
	scanf ("%[^\n]s",f1.titre);
		printf("donner la nouveau salle ou se trouve le document \n");
	scanf ("%d",&f1.localisation.salle);
		printf("donner le nouveau rayon ou se trouve le document \n");
	scanf ("%d",&f1.localisation.rayon);
		printf("donner le nouveau code du document \n");
	scanf ("%s",f1.code);
	printf("donner le nouveau nombre des exemplaires\n");
	scanf ("%d",&f1.nb_exemp);
		printf("donner la nouveau fr้quence de parution \n");
	scanf ("%d",&f1.freq);
	

		}
		fwrite(&f1,sizeof(magazine),1,gg);
		}
		fclose(g);
		fclose(gg);
			if (test) 
			{
				gg=fopen("magazineAUX.txt","r");
				g=fopen("magazine.txt","w");
				while(fread(&f1,sizeof(magazine),1,gg)){
					fwrite(&f1,sizeof(magazine),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\nmagazine non trouve(e) ! \n");
			fclose(g);
		}
/*****emprunter un livre*******/
void emp_livre()
{
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    livre f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("livre.txt","r");
	gg2=fopen("livreAUX.txt","w");fflush(stdin);
	printf ("donner le code du livre: \n"); scanf ("%[^\n]s",code );
	/****/
		while(fread(&f2,sizeof(livre),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
		do{
		printf ("donner le nombre d'exemplaires du ce livre vous voulez emprunter (vous avez le droit d avoir 5 doc au max)\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc));
	
	    if(f2.nb_exemp<=0) printf("nbre insuffisant des livres !\n ");
	    else {
	    		f1.doc->nb_eff=f1.doc->nb_eff+x;
		f1.doc->nb_en_cours=f1.doc->nb_en_cours+x;
	        f2.nb_exemp=f2.nb_exemp-x;
	/***/
	    printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	printf("\nLa date pour rendre le livre est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) printf("\nvous etes retardaire ! vous n'avez pas le droit d'emprunter encore!\n");
	      else {
	      	printf("\nemprunter livre ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce livre de notre biblio \n");
		printf ("\nN'oubliez pas de le rendre avant ou au maximum le jour de la date limite %s!\n'",s);
	}
		}
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(livre),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("livreAUX.txt","r");
				g2=fopen("livre.txt","w");
				while(fread(&f2,sizeof(livre),1,gg2)){
					fwrite(&f2,sizeof(livre),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\nlivre non trouve(e) ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! echec ! \n");
			fclose(g);
			
	}


		/*****emprunter un article*******/
void emp_article() 
{
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    article f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("article.txt","r");
	gg2=fopen("articleAUX.txt","w");fflush(stdin);
	printf ("donner le code du article: \n"); scanf ("%[^\n]s",code );

		
		
		/****/
		while(fread(&f2,sizeof(article),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
	do{
		printf ("donner le nombre d'exemplaires du ce livre vous voulez emprunter (vous avez le droit d avoir 5 doc au max)\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc));
	
	    if(f2.nb_exemp<=0) printf("nbre insuffisant des articles !\n ");
	    else {
	    		f1.doc->nb_eff=f1.doc->nb_eff+x;
		f1.doc->nb_en_cours=f1.doc->nb_en_cours+x;
	        f2.nb_exemp=f2.nb_exemp-x;
	    	
	
	/***/
	    printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	printf("\nLa date pour rendre le article est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) printf("\nvous etes retardaire ! vous n'avez pas le droit d'emprunter encore!\n");
	      else {
	      	printf("\nemprunter article ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce article de notre biblio \n");
		printf ("\nN'oubliez pas de le rendre avant ou au maximum le jour de la date limite %s!\n'",s);
		
	}
		}
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(article),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("articleAUX.txt","r");
				g2=fopen("article.txt","w");
				while(fread(&f2,sizeof(article),1,gg2)){
					fwrite(&f2,sizeof(article),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\narticle non trouve(e) ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! echec ! \n");
			fclose(g);
			
	}
/*****emprunter une magazine*****/
		void emp_magazine(){
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    magazine f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("magazine.txt","r");
	gg2=fopen("magazineAUX.txt","w");fflush(stdin);
	printf ("donner le code du magazine: \n"); scanf ("%[^\n]s",code );

		
		
		/****/
		while(fread(&f2,sizeof(magazine),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
	do{
		printf ("donner le nombre d'exemplaires du ce livre vous voulez emprunter (vous avez le droit d avoir 5 doc au max)\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc));
	
	    if(f2.nb_exemp<=0) printf("nbre insuffisant des magazines !\n ");
	    else {
	    		f1.doc->nb_eff=f1.doc->nb_eff+x;
		f1.doc->nb_en_cours=f1.doc->nb_en_cours+x;
	        f2.nb_exemp=f2.nb_exemp-x;
	    	
	
	/***/
	    printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	printf("\nLa date pour rendre le magazine est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) printf("\nvous etes retardaire ! vous n'avez pas le droit d'emprunter encore!\n");
	      else {
	      	printf("\nemprunter magazine ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce magazine de notre biblio \n");
		printf ("\nN'oubliez pas de le rendre avant ou au maximum le jour de la date limite %s!\n'",s);
		
	}
		}
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(magazine),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("magazineAUX.txt","r");
				g2=fopen("magazine.txt","w");
				while(fread(&f2,sizeof(magazine),1,gg2)){
					fwrite(&f2,sizeof(magazine),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\nmagazine non trouvee ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouvee ! echec ! \n");
			fclose(g);
			
	}
/****recherche des retardaires***/
			void chercher_retard(){
				personne f1;
		FILE* g; int id;int test;
	g=fopen("personne.txt","r");
	while(fread(&f1,sizeof(personne),1,g)){
				time_t now = time(NULL);
	char * string_now = ctime (&now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];

	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
	
	double diff = difftime(new_time,now);
	//printf ("diff : %f \n",diff);
	if(diff<=0)	
	    {	printf("\n XXXXXXXXXXXXXListe NOIR des RetardaireXXXXXXXXXXXXXXXXX \n");
			printf ("le nom  du retardaire est %s \n", f1.nom);
			printf ("le prenom du retardaire est %s \n", f1.prenom);
			printf ("son ID est %d \n", f1.id);
	    	printf("\n XXXXXXXXXXXXXListe NOIR des RetardaireXXXXXXXXXXXXXXXXX \n");
}
}
	fclose(g);
	}
	/*****rendre un livre*******/
void back_livre()
{
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    livre f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("livre.txt","r");
	gg2=fopen("livreAUX.txt","w");fflush(stdin);
	printf ("donner le code du livre: \n"); scanf ("%[^\n]s",code );
	/****/
		while(fread(&f2,sizeof(livre),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
		do{
		printf ("donner le nombre d'exemplaires du ce livre vous avez empruntee :\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc)) ;
	
	/***/
	  //  printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	//printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	//printf("\nLa date pour rendre le livre est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
//	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) {
		printf("\nvotre situation est reglee ! vous avez maintenant le droit d'emprunter !\n");
	     f1.doc->nb_depasse =f1.doc->nb_depasse-x;
	     f2.nb_exemp=f2.nb_exemp+x;
	     f1.duree=-f1.duree; 
		 } 
		 else {
	      	printf("\nRetour du livre ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce livre de notre biblio \n");
	f1.doc->nb_en_cours=f1.doc->nb_en_cours-x;
	f2.nb_exemp=f2.nb_exemp+x;
	}
		
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(livre),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("livreAUX.txt","r");
				g2=fopen("livre.txt","w");
				while(fread(&f2,sizeof(livre),1,gg2)){
					fwrite(&f2,sizeof(livre),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\nlivre non trouve(e) ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! echec ! \n");
			fclose(g);
			
	}

	/*****rendre un article*******/
void back_article()
{
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    article f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("article.txt","r");
	gg2=fopen("articleAUX.txt","w");fflush(stdin);
	printf ("donner le code du article: \n"); scanf ("%[^\n]s",code );
	/****/
		while(fread(&f2,sizeof(article),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
		do{
		printf ("donner le nombre d'exemplaires du ce article vous avez empruntee :\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc)) ;
	
	/***/
	  //  printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	//printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	//printf("\nLa date pour rendre le article est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
//	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) {
		printf("\nvotre situation est reglee ! vous avez maintenant le droit d'emprunter !\n");
	     f1.doc->nb_depasse =f1.doc->nb_depasse-x;
	     f2.nb_exemp=f2.nb_exemp+x;
	     f1.duree=-f1.duree; 
		 } 
		 else {
	      	printf("\nRetour du article ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce article de notre biblio \n");
	f1.doc->nb_en_cours=f1.doc->nb_en_cours-x;
	f2.nb_exemp=f2.nb_exemp+x;
	}
		
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(article),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("articleAUX.txt","r");
				g2=fopen("article.txt","w");
				while(fread(&f2,sizeof(article),1,gg2)){
					fwrite(&f2,sizeof(article),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\narticle non trouve(e) ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! echec ! \n");
			fclose(g);
			
	}
	/*****rendre un magazine*******/
void back_magazine()
{
					personne f1;int i;
		FILE* g ;FILE *gg; int id;int test;
	g=fopen("personne.txt","r");
	gg=fopen("personneAUX.txt","w");
	printf ("donner votre identifiant : \n"); scanf ("%d",&id );	
    magazine f2;
		FILE* g2 ;FILE *gg2; char code [10];int test1;
	g2=fopen("magazine.txt","r");
	gg2=fopen("magazineAUX.txt","w");fflush(stdin);
	printf ("donner le code du magazine: \n"); scanf ("%[^\n]s",code );
	/****/
		while(fread(&f2,sizeof(magazine),1,g2)){
	if (strcmp(f2.code,code)==0)
	    {
	    	test1=1;
	while(fread(&f1,sizeof(personne),1,g)){
	if (f1.id==id)
	    {
	    	test=1;
 int x;
		do{
		printf ("donner le nombre d'exemplaires du ce magazine vous avez empruntee :\n");
		scanf ("%d",&x); 
		}while(!(x<=max_doc)) ;
	
	/***/
	  //  printf("\nla duree du pret est :  %d jours ",f1.duree);
	time_t now = time(NULL);
	char * string_now = ctime (&now);
	//printf("\nAujourd'hui est la date du pret : %s\n",string_now);
	struct tm * cur_time = localtime(&now);
	cur_time->tm_mday =cur_time->tm_mday + f1.duree;
	time_t new_time = mktime(cur_time);

	char s[100];
	//printf("\nLa date pour rendre le magazine est Le  ");
	strftime(s,100,"%d / %B / %Y", cur_time ); /***date de rendre le doc***/
//	printf ("%s\n",s);
	double diff = difftime(new_time,now);
		if(diff<=0) {
		printf("\nvotre situation est reglee ! vous avez maintenant le droit d'emprunter !\n");
	     f1.doc->nb_depasse =f1.doc->nb_depasse-x;
	     f2.nb_exemp=f2.nb_exemp+x;
	     f1.duree=-f1.duree; 
		 } 
		 else {
	      	printf("\nRetour du magazine ayant le titre %s avec succes\n ",f2.titre);
			printf("\nmerci d'emprunter ce magazine de notre biblio \n");
	f1.doc->nb_en_cours=f1.doc->nb_en_cours-x;
	f2.nb_exemp=f2.nb_exemp+x;
	}
		
		}
		fwrite(&f1,sizeof(personne),1,gg);
		}
		
		fclose(g);
		fclose(gg);

	}
		fwrite(&f2,sizeof(magazine),1,gg2);
		}
		fclose(g2);
		fclose(gg2);
			if (test1) 
			{
				gg2=fopen("magazineAUX.txt","r");
				g2=fopen("magazine.txt","w");
				while(fread(&f2,sizeof(magazine),1,gg2)){
					fwrite(&f2,sizeof(magazine),1,g2);
				}
				fclose(g2); fclose(gg2);
			}
			 else printf ("\nmagazine non trouve(e) ! echec !\n");
			fclose(g2); 
		
		/****/
		
			if (test) 
			{
				gg=fopen("personneAUX.txt","r");
				g=fopen("personne.txt","w");
				while(fread(&f1,sizeof(personne),1,gg)){
					fwrite(&f1,sizeof(personne),1,g);
				}
				fclose(g); fclose(gg);
			}
			 else printf ("\npersonne non trouve(e) ! echec ! \n");
			fclose(g);
			
	}

int main (){
	int choix;
	system("COLOR 80");
		printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("             บ                                                      บ\n");
		printf("             บ          Bienvenue dans notre bibliotheque           บ\n");
		printf("             บ                                                      บ\n");
		printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

do{ //system("cls");
	printf("*******************************************************\n");
	 printf ("voila les activites que vous pouvez faire : \n");
		printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("             บ                                                      บ\n");
		printf("             บ                    Menu Principal                    บ\n");
		printf("             บ                                                      บ\n");
		printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
			    printf("01/creer d'une fiche pour vos donnees \n");
			    printf ("02/Afficher vos donnees personnelles\n");
			    printf("03/chercher une personne \n");
			    printf ("04/Modifier vos donnees sur la fiche \n");
			    printf ("05/supprimer vos donnees\n");
			    printf ("06/trier la liste des personnes \n");
			    printf("07/ajout livre  \n");
			    printf("08/ affichage un livre  \n");
			    printf("09/ suppression d'un livre  \n");
			    printf("10/ chercher un livre selon son code   \n");
			    printf("11/ modifier les donnees un livre  \n");
			    printf("12/ajouter un article  \n");
			    printf("13/ afficher un article  \n");
			    printf("14/ suppression d'un article  \n");
			    printf("15/chercher un article selon son code \n");
			    printf("16/ modifier les donnees d'un article  \n");
			    printf("17/ajouter une magazine  \n");
			    printf("18/ affichage d'une magazine  \n");
			    printf("19/ supprimer d'une  magazine  \n");
			    printf("20/chercher d'une magazine selon son code \n");
			    printf("21/ modifier d'une magazine  \n");
			    printf("22/ emprunter un livre \n");
			    printf("23/ emprunter un article \n");
			    printf("24/ emprunter une magazine \n");
			    printf("25/ affichage de la liste des retardaires \n");
			    printf("26/ rendre un livre \n");
			    printf("27/ rendre un article \n");
			    printf("28/ rendre une magazine \n");
			    printf("00/ Quitter le programme \n");
		    printf("****************Menu Principal***********************");
		printf ("entrer votre choix : ");
		scanf ("%d",&choix);
		switch (choix){
			case 1 :
				system("cls");
				system("COLOR 60");
				saisirfiche_per();
				break;
				case 2:
					system("cls");
				system("COLOR 30");
					aff_info_per();
					break;
					case 3 :
						system("cls");
				system("COLOR 20");
						chercher_personne();
						break;
						case 4:
							modif_per_data();
							break;
							case 5:
								supp_fiche_pers();
								break;
								case 6 :
									trie_fiche_pers ();
									break;
									case 7:
										saisir_liv();
										break;
									 case 8 :
										aff_info_liv();
										break;
										case 9:
											supp_liv();
											break;
											case 10 :
												chercher_livre();
												break;
												case 11 :
													modif_liv_data();
													break;
													case 12 :
														saisir_art();
														break;
														case 13 :
															aff_info_art();
															break;
															case 14 :
																supp_art();
																break;
																case 15 :
																	chercher_article();
																	break;
																	case 16 :
																		modif_article_data();
																		break;
																		case 17 :
																			saisir_magazine();
																			break;
																			case 18:
																				aff_info_mag();
																				break;
																				case 19 :
																					supp_mag();
																					break;
																					case 20:
																						chercher_magazine();
																						break;
																						case 21 :
																							modif_magazine_data();
																							break;
																							case 22 :
																								emp_livre();
																								break;
																								case 23:
																									emp_article();
																									break;
																									case 24:
																										emp_magazine();
																										break;
																										case 25 :
																											chercher_retard();
																											break;
																											case 26 :
																												back_livre();
																												break;
																												case 27 :
																													back_article();
																													break;
																													case 28 :
																														back_magazine();
																														break;
					
					
		}} while (choix!=0);
	//	printf ("***********************Merci*****************************");
}


	

	
		

		
		
	


