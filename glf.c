#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct s_matric{
	int X;
	int Y;
}Matrice;

int ALIVE = 1;
int DEAD = 0;

void apply(int x, int y, int maxX, int maxY, int MatriceData[Matrice.Y][Matrice.X], int Matrice2[Matrice.Y][Matrice.X]){
    int status = MatriceData[y][x];
    
    /*
        ###
        #O#
        ###
    */
    
    int aliveCount = 0;
    int deadCount = 0;
    
    for(int offY = -1; offY < 2; offY++){
        for(int offX = -1; offX < 2; offX++){
            int targetY = y + offY;
            int targetX = x + offX;
            
            if(targetY < 0 || targetX < 0 || targetY - 1 > maxY || targetX - 1 > maxX)
                continue;
            
            if(offY == 0 && offX == 0)
                continue;
                
            int statusTarget = MatriceData[targetY][targetX];
            if(statusTarget == ALIVE){
                aliveCount++;
            } else if (statusTarget == DEAD){
                deadCount++;
            }
        }
    }
    
    if(status == DEAD && aliveCount == 3){
        Matrice2[y][x] = ALIVE;
    }
	if(status == ALIVE && aliveCount < 2 || aliveCount > 3){
		Matrice2[y][x] = DEAD;
	}
}

int main(void)
{
	Matrice.X = 45;
	Matrice.Y = 45;

	int MatriceData[Matrice.X][Matrice.Y];
	int Matrice2[Matrice.X][Matrice.Y];

	printf("Matrix-Data:%d X:%d Y:%d\n", MatriceData[1][0], Matrice.X, Matrice.Y);

    // Définition des valeurs par défaut
	int k;
	int l;

	k = 0;
	while (k < Matrice.Y)
	{
		l = 0;
		while (l < Matrice.X)
		{
			Matrice2[k][l] = 0;
			l++;
		}
		k++;
	}

	int i;
	int j;

    // On défini les première valeur
/*
	Matrice2[10][15] = 1;
	Matrice2[10][15+1] = 1;
	Matrice2[10+1][16+1] = 1;
	Matrice2[13][16] = 1;
	Matrice2[13-1][15-1] = 1;
	Matrice2[13][16-1] = 1;
*/
	Matrice2[1][0] = 1;
	Matrice2[2][1] = 1;
	Matrice2[2][2] = 1;
	Matrice2[1][2] = 1;
	Matrice2[0][2] = 1;

	while (0 != 1)
	{
		printf("Matrix-Data: X:%d Y:%d\n", Matrice.X, Matrice.Y);

		i = 0;
		while (i < Matrice.Y)
		{
			j = 0;
			while (j < Matrice.X)
			{  
				if (Matrice2[j][i] == 0)
					printf("██");
				else
					printf("  ");
				apply(i, j, Matrice.Y, Matrice.X, MatriceData, Matrice2);
				j++;
			}
			printf("\n");

			i++;
		}
		sleep(1);
		system("clear");
	  int w;
      int z;
             
     w = 0;  
     while (w < Matrice.Y)
     {   
         z = 0;
         while (z < Matrice.X)
         {
             MatriceData[w][z] = Matrice2[w][z];
             z++;
         }
         w++;
     }
	
	}
    return(0);
}
