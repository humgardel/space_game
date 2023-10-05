//Proyecto creador por: Humberto Garcia Delgado (c) 2015

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#define MAX_PLANETA 12
#define MAX_NAVE 10
#define MAX_INTENTOS 20
#define MAX_PORCENTAJE 0.75
void ActivarDefensasP(int ArrPlaneta[MAX_PLANETA]);
void ActivarEscudoP(int ArrPlaneta[MAX_PLANETA],int ArrEscudo[MAX_PLANETA]);
void ActivarDefensasN(int ArrNave[MAX_NAVE]);
void ActivarDefensasN2(int ArrNave2[MAX_NAVE]);
int AtaquePlaneta();
int AtaqueNave();
void VerificarAtaqueP(int ArrNave[MAX_NAVE], int ataquep);
void VerificarAtaqueN(int ArrPlaneta[MAX_PLANETA], int ArrEscudo[MAX_PLANETA], int ataquen, int intentos);
void MostrarDefensasP(int ArrPlaneta[MAX_PLANETA]);
void MostrarDefensasN(int ArrNave[MAX_NAVE]);
void MostrarDefensasN2(int ArrNave2[MAX_NAVE]);
int ContarBajasP(int ArrPlaneta[MAX_PLANETA]);
int ContarBajasN(int ArrNave[MAX_NAVE]);
int ContarBajasN(int ArrNave2[MAX_NAVE]);
void main()
{
	int ArrPlaneta[MAX_PLANETA], ArrEscudo[MAX_PLANETA], ArrNave[MAX_NAVE], ArrNave2[MAX_NAVE], op=0,intentos=0,ataquep,ataquen,opif=0;
	char bandera[]="Dd",atacar[]=" ";
	srand(time(NULL));

	while(op<4)
	{

		printf("1. Activar Defensas\n");
		printf("2. Empezar Combate\n");
		printf("3. Mostrar Resumen Final\n");
		printf("4. Salir\n");

		scanf("%d",&op);
		switch(op)
		{
		case 1:
			{
			ActivarDefensasP(ArrPlaneta);
			ActivarEscudoP(ArrPlaneta,ArrEscudo);
			ActivarDefensasN(ArrNave);
			ActivarDefensasN2(ArrNave2);
			for(int i=0;i<MAX_NAVE;i++)
			{
				printf("|%d|",ArrNave[i]);
			}
			printf("\t");
			for(int k=0;k<MAX_NAVE;k++)
			{
				printf("|%d|",ArrNave2[k]);
			}
			printf("\n\n\n");
			printf("\t\t ");
			for(int l=0;l<MAX_PLANETA;l++)
			{
				printf("|%d|",ArrEscudo[l]);
			}
			printf("\n");
			printf("\t\t");
			for(int j=0;j<MAX_PLANETA;j++)
			{
				printf("|%d|",ArrPlaneta[j]);
			}
			printf("\n\n");
			break;
			}
		case 2:
			{
			if(intentos<MAX_INTENTOS && ContarBajasP(ArrPlaneta)==0 && ContarBajasN(ArrNave)==0)
			{
				for(int i=intentos;i<MAX_INTENTOS;i++)
				{

					printf("\nPresione la letra D para disparar: ");
					scanf("%s",atacar);
					if(atacar[0]==bandera[0]||atacar[0]==bandera[1])
					{
						printf("\n%cA que nave desea atacar? (1 o 2): ",168);
						scanf("%d",&opif);
						if(opif==1)
						{
							ataquep=AtaquePlaneta();
							printf("\nEl Planeta ataca a la defensa %d de la Nave1",ataquep);
							VerificarAtaqueP(ArrNave, ataquep);
							getch();
							if(intentos>5 && (intentos%5)==0)
							{
								ataquen=AtaqueNave();
								printf("\n\nLa Nave2 ataca a la defensa %d del planeta ",ataquen);
								VerificarAtaqueN(ArrPlaneta, ArrEscudo, ataquen, intentos);
								intentos++;
								printf("\n\n");
								getch();
							}
							else
							{
								ataquen=AtaqueNave();
								printf("\n\nLa Nave1 ataca a la defensa %d del planeta ",ataquen);
								VerificarAtaqueN(ArrPlaneta, ArrEscudo, ataquen, intentos);
								intentos++;
								printf("\n\n");
								getch();
							}
						}
						if(opif==2)
						{
							ataquep=AtaquePlaneta();
							printf("\nEl Planeta ataca a la defensa %d de la Nave2",ataquep);
							VerificarAtaqueP(ArrNave2, ataquep);
							getch();
							if(intentos>5 && (intentos%5)==0)
							{
								ataquen=AtaqueNave();
								printf("\n\nLa Nave2 ataca a la defensa %d del planeta ",ataquen);
								VerificarAtaqueN(ArrPlaneta, ArrEscudo, ataquen, intentos);
								intentos++;
								printf("\n\n");
								getch();
							}
							else
							{
								ataquen=AtaqueNave();
								printf("\n\nLa Nave1 ataca a la defensa %d del planeta ",ataquen);
								VerificarAtaqueN(ArrPlaneta, ArrEscudo, ataquen, intentos);
								intentos++;
								printf("\n\n");
								getch();
							}
						}

					}
					else
					{
						i=MAX_INTENTOS;

					}
					if(ContarBajasP(ArrPlaneta)==1)
					{
						printf("\n***Planeta conquistado***\n\n");
						i=MAX_INTENTOS;
					}
					if(ContarBajasN(ArrNave)==1)
					{
						printf("\n***Nave1 derrotada***\n\n");
						i=MAX_INTENTOS;
					}
					if(ContarBajasN(ArrNave2)==1)
					{
						printf("\n***Nave2 derrotada***\n\n");
						i=MAX_INTENTOS;
					}

				}
				if(intentos==MAX_INTENTOS)
				{
					printf("\nCompleto los %d intentos\n",MAX_INTENTOS);
					getch();
				}
				break;

			}

			else
			{
				printf("\n--JUEGO TERMINADO--\n",MAX_INTENTOS);
				break;
			}

			}
		case 3:
			{
			printf("\n");
			for(int i=0;i<MAX_NAVE;i++)
				printf("|%d|",ArrNave[i]);
			printf("\t");
			for(int k=0;k<MAX_NAVE;k++)
				printf("|%d|",ArrNave2[k]);
			printf("\n\n\n");
			printf("\t\t ");
			for(int l=0;l<MAX_PLANETA;l++)
			{
				printf("|%d|",ArrEscudo[l]);
			}
			printf("\n");
			printf("\t\t");
			for(int j=0;j<MAX_PLANETA;j++)
				printf("|%d|",ArrPlaneta[j]);
			printf("\n\n");
			if(intentos==MAX_INTENTOS)
				printf("\n*****Tregua Diplomatica*****\n\n");
			else
				{
				if(ContarBajasP(ArrPlaneta)==1)
					printf("\n***Planeta conquistado***\n\n");
				if(ContarBajasN(ArrNave)==1)
					printf("\n***Nave derrotada***\n\n");
				}
			break;
			}
		case 4:
			{
			op=4;
			break;
			}
		default:
			{
			printf("\nTecla no valida\n");
			break;
			}
		}
	}
	getch();
}


void ActivarDefensasP(int ArrPlaneta[MAX_PLANETA])
{
	int aleatorio,repetido;
	for(int i=0;i<MAX_PLANETA;i++)
	{
		aleatorio=2+rand()%MAX_PLANETA;
		repetido=0;
		for(int j=0;j<=i;j++)
		{
			if(aleatorio==ArrPlaneta[j])
				repetido=1;
		}
		if(repetido==1)
			i--;
		else
			ArrPlaneta[i]=aleatorio;
	}
}
void ActivarEscudoP(int ArrPlaneta[MAX_PLANETA], int ArrEscudo[MAX_PLANETA])
{
	
	for(int i=0;i<MAX_PLANETA;i++)
		ArrEscudo[i]=0;
	for(int i=0+4;i<MAX_PLANETA-4;i++)
		ArrEscudo[i]=ArrPlaneta[i];
		
}
void ActivarDefensasN(int ArrNave[MAX_NAVE])
{
	int aleatorio,repetido;
	for(int i=0;i<MAX_NAVE;i++)
	{
		aleatorio=3+rand()%MAX_NAVE;
		repetido=0;
		for(int j=0;j<=i;j++)
		{
			if(aleatorio==ArrNave[j])
				repetido=1;
		}
		if(repetido==1)
			i--;
		else
			ArrNave[i]=aleatorio;
	}
}
void ActivarDefensasN2(int ArrNave2[MAX_NAVE])
{
	int aleatorio,repetido;
	for(int i=0;i<MAX_NAVE;i++)
	{
		aleatorio=3+rand()%MAX_NAVE;
		repetido=0;
		for(int j=0;j<=i;j++)
		{
			if(aleatorio==ArrNave2[j])
				repetido=1;
		}
		if(repetido==1)
			i--;
		else
			ArrNave2[i]=aleatorio;
	}
}
int AtaquePlaneta()
{
	int num;
	for(int i=0;i<1;i++)
	{
		num=3+rand()%MAX_NAVE;

	}
	return num;
}
int AtaqueNave()
{
	int num;
	for(int i=0;i<1;i++)
	{
	       num=2+rand()%MAX_PLANETA;

	}
	return num;
}
void VerificarAtaqueP(int ArrNave[MAX_NAVE], int ataquep)
{
	for(int i=0;i<MAX_NAVE;i++)
	{
		if(ArrNave[i]==ataquep)
			ArrNave[i]=0;
	}
}
void VerificarAtaqueN(int ArrPlaneta[MAX_PLANETA], int ArrEscudo[MAX_PLANETA], int ataquen, int intentos)
{
	for(int i=0;i<MAX_PLANETA;i++)
	{
		if(intentos>5 && (intentos%5)==0 && ArrEscudo[i]==0 && ArrPlaneta[i]==ataquen)
			ArrPlaneta[i]=0;
		else
			ArrPlaneta[i]=0;
	}
}
int ContarBajasP(int ArrPlaneta[MAX_PLANETA])
{
	double bajasp=0;
	for(int i=0;i<MAX_PLANETA;i++)
	{
		if(ArrPlaneta[i]==0)
			bajasp++;
	}
	if(bajasp>MAX_PORCENTAJE*MAX_PLANETA)
		return 1;
	else
		return 0;
}
int ContarBajasN(int ArrNave[MAX_NAVE])
{
	double bajasn=0;
	for(int i=0;i<MAX_NAVE;i++)
	{
		if(ArrNave[i]==0)
			bajasn++;
	}
	if(bajasn>=MAX_PORCENTAJE*MAX_PLANETA)
		return 1;
	else
		return 0;
}