#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


//Variáveis Globais
int tema,k,ret=0,contagem1=0,contagem2=0,jogadorAT=1;




//Funções
void artes();
void entretenimento();
void esporte();
void historia();
void geografia();
void ciencias();
int sortearTEMA();
void definirTEMA();
int definirPERG();
void resp1();
void resp2();
void resp3();
void resp4();
int trocaJogador(int jogadorAT);
void testeVEN();



int main()
{
     int i,a;
     printf("Ol%c, bem vindo ao jogo 'PERGUNTADOS em C',\nProcuramos desenvolver uma jogo divertido e pr%ctico,\nE para ganhar o jogador precisa acertar pelo menos 10 perguntas,\nBom,divirta-se e Boa Sorte\n\nAperte qualquer tecla para sortear o tema,\n\n",a=160,a=160);
     
     
     while((contagem1<10)&&(contagem2<10))
     {
         ret=0;
         
	     while(ret==0)
	     {
	     
		     i=sortearTEMA();
		     
		     definirTEMA();
		     
		     system("cls");
		     
	 	 }
	 	
			jogadorAT=trocaJogador(jogadorAT);
			printf("Agora %c a vez do jogador %d\n\n\n",a=130,jogadorAT);
			printf("\tPLACAR\n\t%d para o jogador 1\n\t%d para o jogador 2\n",contagem1,contagem2); 
			
	 }
	 testeVEN();
}






    //FUNÇÕES
    
    int sortearTEMA()
    {
        int a,b,c;
         srand(time(NULL));
         
         
         getch();
         
         tema=rand()%5;
         
         return tema;
    }
         
    void definirTEMA()
    {
        if(tema==0)//artes
        {
                          k=definirPERG();
                          artes();
        }
        else if(tema==1)//entretenimento
        {
                          k=definirPERG();
                          entretenimento();
        }
        else if(tema==2)//esporte  
        {
                          k=definirPERG();
                          esporte();
        }
        else if(tema==3)//história
        {
                          k=definirPERG();
                          historia();
        }
        else if(tema==4)//geografia
        {
                          k=definirPERG();
                          geografia();
        }
        else
        {
                          k=definirPERG();
                          ciencias();
        }
    }            
    
    
    void artes()
    {
        system("cls");
        int a,b,c,d,e;
        
        printf("TEMA: ARTES\t\n");
        
        if(k==0)
        {
             printf("Qual a nacionalidade de Leonardo Da Vinci?\n");
             printf("1=Grego\n2=Alem%co\n3=Espanhol\n4=Italiano\n",a=198);
             resp4();
        }
        else if(k==1)
        {
             printf("'A Hospedeira' %c um livro escrito pela mesma autora de...\n",a=130);
             printf("1=Harry Potter\n2=Instrumentos Mortais\n3=Crep%csculo\n4=Jogos Vorazes\n",b=163);
             resp3();
        }
        else if(k==2)
        {
             printf("Qual %c o livro mais editado e traduzido da hist%cria, perdendo apenas para a B%cblia?\n",a=130,b=162,c=161);
             printf("1=Dom Quixote\n2=Harry Potter\n3=Evolu%c%co das Esp%ccies\n4=Guerra dos Tronos\n",d=135,e=198,a=130);
             resp1();
        }
        else if(k==3)
        {
             printf("Qual o nome da cadela de 'Vidas Secas', do escritor alagoano Graciliano Ramos?\n");
             printf("1=Xuxa\n2=Baleia\n3=Galinha\n4=Dilma\n");
             resp2();
        }
        else if(k==4)
        {
             printf("O que o soldadinho de chumbo perdeu?\n");
             printf("1=Nariz\n2=Uma Perna\n3=Um Bra%co\n4=Um Dedo\n",a=135);
             resp2();
        }
        else 
        {
             printf("Qual a nacionalidade do escultor Pablo Picasso?\n");
             printf("1=Italiano\n2=Espanhol\n3=Ingles\n4Alem%co=\n",a=198);
             resp2();
        }
    }
    
    void entretenimento()
    {
         system("cls");
         int a,b;
         
         printf("TEMA: ENTRETENIMENTO\t\n");
         
         if(k==0)
         {
              printf("Qual desses personagens n%co pertencem %c Marvel?\n",a=198,b=133);
              printf("1=Coisa\n2=Gear\n3=Gavi%co Arqueiro\n4=Homem de Ferro\n",a=198);
              resp2();
         }
         else if(k==1)
         {
              printf("Quem venceu o The Voice Brasil 2014?\n");
              printf("1=Danilo Reis e Rafael\n2=Sam Alves\n3=Luana Camarah\n4=Kelvin Dias\n");
              resp1();
         }
         else if(k==2)
         {
              printf("Qual dessas m%csicas pertence a banda AC/DC?\n",a=163);
              printf("1=Sweet Child O'Mine\n2=Cubert\n3=Muri%coca\n4=Hell's Bells\n",b=135);
              resp4();
         }
         else if(k==3)
         {
              printf("Qual desses atores da Globo virou apresentador de programa na Record?\n");
              printf("1=Murilo Rosa\n2=Rodrigo Lombardi\n3=Rodrigo Faro\n4=Chay Suede\n");
              resp3();
         }
         else if(k==4)
         {
              printf("Que novela teve uma vil%c chamada Carminha?\n",a=198);
              printf("1=Fina Estampa\n2=Salve Jorge\n3=Amor %c Vida\n4=Avenida Brasil\n",b=133);
              resp4();
         }
        else
        {
             printf("Qual a maior plataforma de streaming da Internet?\n");
             printf("1=YouTube\n2=Twitch\n3=Netflix\n4=Azubu.tv\n");
             resp3();
        }
     
    }
    
    void esporte()
    {
         system("cls");
         int a,b;
         
         printf("TEMA: ESPORTE\t\n");
         
         if(k==0)
         {
              printf("Quem ganhou mais bolas de ouro?\n");
              printf("1=Messi\n2=Ronaldinho\n3=Pel%c\n4=Cristiano Ronaldo\n",a=130);
              resp1();
         }
         else if(k==1)
         {
              printf("Qual desses esportes n%co se utiliza taco?\n",b=198);
              printf("1=Baseball\n2=T%cnis\n3=Golf\n4=Hockey\n",a=136);
              resp2();
         }
         else if(k==2)
         {
              printf("Quantas bolas pretas existem na sinuca?\n");
              printf("1=Uma\n2=Duas\n3=Nenhuma\n4=Todas\n");
              resp1();
         }
         else if(k==3)
         {
              printf("Qual desses esporte tem nas Ol%cmpiadas?\n",a=131);
              printf("1=Skate\n2=Patins\n3=Surf\n4=Badminton\n");
              resp4();
         }
         else if(k==4)
         {
              printf("Qual %c o segundo esporte mais popular no Brasil?\n",a=130);
              printf("1=Basquete\n2=Futebol/n3=Volei/n4=Handebol\n");
              resp3();
         }
        else 
        {
             printf("Quais desses esportes se joga com tacos?\n");
             printf("1=E-Sports\n2=Polo\n3=Rugby\n4=Tenis de Mesa\n");
             resp2();
        }
    }
    
    void historia()
    {
         system("cls");
         
         int a,b,c;
         
         printf("TEMA: HISTORIA\t\n");
         
         if(k==0)
         {
              printf("Qual cidade do Espirito Santo foi abandonada pelos colonizadores europeus por n%co conseguirem derrotar os indios?\n",a=198);
              printf("1=Vila Velha\n2=Vila Val%crio\n3=Vila Isabel\n4=Porto Velho\n",a=130);
              resp1();
         } 
         else if(k==1)
         {
              printf("Em que ano terminou a primeira guerra mundial?\n");
              printf("1=1914\n2=1918\n3=1910\n4=1916\n");
              resp2();
         }
         else if(k==2)
         {
              printf("Em que ano se iniciou o Arcadismo?\n");
              printf("1=1777\n2=1717\n3=1756\n4=1657\n");
              resp3();
         }
         else if(k==3)
         {
              printf("Qual foi o imperador responsav%cl pelo oficializa%c%co do Cristianismo?\n",a=130,b=135,c=198); 
              printf("1=Dilma Roussef\n2=Constantino\n3=Augusto\n4=Papa Pio V\n");
              resp2();
         }
         else if(k==4)
         {
              printf("Em que ano come%cou a Segunda Guerra Mundial?\n",a=135);
              printf("1=1935\n2=1930\n3=1941\n4=1938\n");
              resp4();
         } 
        else 
        {
             printf("Qual foi o estopim da primeira guerra mundial?\n");
             printf("1=Invas%co da Espanha\n2=Quebra de Tratados comerciais por parte da Alemanha\n3=Assassinato do Rei da Inglaterra\n4=Assassinato de Francisco Ferdinando\n",a=198);
             resp4();
        }

    }
    
    void geografia()
    {
         system("cls");
         
         int a,b,c,d;
         
         printf("TEMA: GEOGRAFIA\t\n");
         
         if(k==0)
         {
              printf("Em que oceano est%c localizado a ilha do Taiti?\n",a=160);
              printf("1=Atl%cntico\n2=Pac%cfico\n3=%cndico\n4=Mar Morto\n",b=131,c=161,d=214);
              resp2();
         }
         else if(k==1)
         {
              printf("Qual era a antiga moeda da Italia?\n");
              printf("1=Euro\n2=Lira\n3=Peso\n4=Dolar\n");
              resp2();
         }
         else if(k==2)
         {
              printf("Em que pa%cs da Europa %c poss%cvel vermos a Aur%cra Boreal?\n",a=161,b=130,a=161,c=162);
              printf("1=Italia\n2=Turquia\n3=Su%ccia\n4=Noru%cga\n",a=130,a=130);
              resp4();
         }
         else if(k==3)
         {
              printf("Qual %c a maior divisa de pa%cses do mundo?\n",a=130,b=161);
              printf("1=Brasil e Argentina\n2=Espanha e Portugal\n3=Paquist%co e Russia\n4=Estados Unidos e Canad%c\n",a=198,b=160);
              resp4();
         }
         else if(k==4)
         {
              printf("Qual %c a segunda maior montanha do mundo?\n",a=130);
              printf("1=Pedra do Cruzeiro\n2=Pico da Bandeira\n3=K2\n4=K7\n");
              resp3();
         }
        else 
        {
             printf("Quantos tempo durou a Guerra dos Cem Anos?\n");
             printf("1=100 anos\n2=80 anos\n3=106 anos\n4=116 anos\n");
             resp2();
        }

    }
    
    void ciencias()
    {
         system("cls");
         int a,b,c,d,e;

         printf("TEMA: CIENCIAS\t\n");

         if(k==0)
         {
                 printf("O que est%c presente nas c%clulas e definem nossas caracter%csticas?\n",a=160,b=130,c=161);
                 printf("1=Energia\n2=DNA\n3=Digitais\n4=Dados\n");
                 resp2();
         }
         else if(k==1)
         {
              printf("Qual letra n%co %c encontrada na tabela peri%cdica?\n",a=198,b=130,c=162);
              printf("1=J\n2=Z\n3=V\n4=X\n");
              resp1();
         }
         else if(k==2)
         {
              printf("Qual a fun%c%co do ribossomo em uma c%clula?\n",a=135,b=198,c=130);
              printf("1=Gerar Energia\n2=Proteger\n3=S%cntese de Prote%cna\n4=Armazenar Energia\n",d=161,d=161);
              resp3();
         }
         else if(k==3)
         {
              printf("Qual a cor de um Hem%ccia?\n",a=160);
              printf("1=Azul\n2=Branca\n3=Vermelha\n4=Preta\n");
              resp3();
         }
         else if(k==4)
         {
             printf("Quantos cromossomos temos?\n");
             printf("1=48\n2=46\n3=44\n4=42\n");
             resp2();
         }
        else 
        {
             printf("'Grandeza cuja o valor vem do produto resistencia e da corrente'. A grandeza expressa na frase %c\n",a=130);
             printf("1=Energia\n2=Tens%co\n3=Rendimento\n4=Campo El%ctrico\n",b=198,c=130);
             resp2();
        }
     
    }


   int definirPERG()
   {
         int p;
     
         srand(time(NULL));
         p=rand()%5;
         return p;
   }
   
   
   void resp1()
   {
   	         int resp;
   	         
   	         scanf("%d",&resp);
   	         
             if(resp!=1)
             {
             	printf("\nRESPOSTA INCORRETA\n");
             	ret=1;
             }
             else
             {
             	printf("\nRESPOSTA CORRETA\n");
             	if(jogadorAT==1)
             	{
             		contagem1=contagem1+1;
             	}
             	else
             	{
             		contagem2=contagem2+1;
             	}
             	ret=0;
             	
             }
             getch();
	}
	
	
	void resp2()
   {
   	         int resp;
   	         
   	         scanf("%d",&resp);
   	         
             if(resp!=2)
             {
             	printf("\nRESPOSTA INCORRETA\n");
             	ret=1;
             }
             else
             {
             	printf("\nRESPOSTA CORRETA\n");
             	if(jogadorAT==1)
             	{
             		contagem1=contagem1+1;
             	}
             	else
             	{
             		contagem2=contagem2+1;
             	}
             	ret=0;
             }
             getch();
	}
	void resp3()
   {
   	         int resp;
   	         
   	         scanf("%d",&resp);
   	         
             if(resp!=3)
             {
             	printf("\nRESPOSTA INCORRETA\n");
             	ret=1;
             }
             else
             {
             	printf("\nRESPOSTA CORRETA\n");
             	if(jogadorAT==1)
             	{
             		contagem1=contagem1+1;
             	}
             	else
             	{
             		contagem2=contagem2+1;
             	}
             	ret=0;
             }
             getch();
	}
	void resp4()
   {
   	         int resp;
   	         
   	         scanf("%d",&resp);
   	         
             if(resp!=4)
             {
             	printf("\nRESPOSTA INCORRETA\n");
             	ret=1;
             }
             else
             {
             	printf("\nRESPOSTA CORRETA\n");
             	if(jogadorAT==1)
             	{
             		contagem1=contagem1+1;
             	}
             	else
             	{
             		contagem2=contagem2+1;
             	}
             	ret=0;
             }
             getch();
	}
	
	
	int trocaJogador(int jogadorAT)
	{
		if(jogadorAT==1)
		{
			return 2;
	    }
	    else
	    {
	    	return 1;
	    }
	}
	
	
	void testeVEN()
	{
		int a;
		
		if(contagem1>=10)
		{
			printf("Parab%cns jogador 1, voce GANHOU\n",a=130);
		}
		if(contagem2>=10)
		{
			printf("Parab%cns jogador 2, voce GANHOU\n",a=130);
		}
	}
	