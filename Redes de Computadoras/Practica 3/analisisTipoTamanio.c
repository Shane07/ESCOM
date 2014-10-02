#include <stdio.h>
#define MAX 500

// MARTES 25 MZO: TRAMA 1 INDICA SI ES O NO MODO EXTENDIDO, en caso de SNRME | SABME | SARME then activar una bandera

int checkTamTipo(const unsigned char *tr) // Se comporta distinto si no se considera del tipo 'unsigned'
{
	if((tr[12]*256)+tr[13] < 1500)
		return 1;
	else
		return 0;
}

unsigned int getEthernetType(const unsigned char *tr)
{
	unsigned int d, x[2];
	x[0] = (unsigned int) tr[12];
	x[1] = (unsigned int) tr[13];
	return d = (x[0]<<8) | x[1];
}

char checkTipoTrama(const unsigned char *tr) // Saber si la trama es de Informacion, Supervision o Unsigned (HDLC)
{
	/*
		Hacer dos comparaciones a la vez
	   a7 a6 a5 a4 a3 a2 a1 a0
      & 0  0   0  0  0  0  1  1
      ___________________________
        0  0   0  0  0  0  a1  a0

     a1 a0 == 00 -> Informacion
     a1 a0 == 01 -> Informacion
     a1 a0 == 10 -> Supervision
     a1 a0 == 11 -> Unsigned
    */

	switch(tr[16] & 3)
	{
		case 0:
			return 'I';
			break;
		case 1:
			return 'I';
			break;
		case 2:
			return 'S';
			break;
		case 3:
			return 'U';
			break;
	}
}

int main(void)
{
	unsigned char trama[MAX], z, hex[3];
	unsigned int eth, flag = 0, sync = 0, pos = 0, j;
	FILE *arch = fopen("tramas", "r"), *salida = fopen("analisisTipo", "w");
	
	if(arch == NULL || salida == NULL)
	{
		perror("Error [Archivo]");
		return -1;
	}

	hex[2] = '\0';

	while(feof(arch) == 0)
	{
		z = (char) fgetc(arch);

		if(z != ' ')
		{
			if(z == '\n')
			{
				if(flag == 1)
				{
					trama[pos] = '\0';

					fprintf(salida, "MAC destino:\t");
					for(j = 0; j < 6; j++)
					{
						fprintf(salida, "%02X", trama[j]);
						if(j < 5)
							fprintf(salida, ":");
					}
					fprintf(salida, "\n");

					fprintf(salida, "MAC origen:\t");
					for(j = 6; j < 12; j++)
					{
						fprintf(salida, "%02X", trama[j]);
						if(j < 11)
							fprintf(salida, ":");
					}
					fprintf(salida, "\n");

					if(checkTamTipo(trama))
					{
						fprintf(salida, "Trama:\t\tIEEE 802.3\n");
						fprintf(salida, "Tamanio:\t%d bytes\n", trama[13]);
						fprintf(salida, "Tipo:\t\t[%c]\n", checkTipoTrama(trama));
					}
					else
					{
						eth = getEthernetType(trama);
						fprintf(salida, "Trama:\t\tEthernet\n");
						fprintf(salida, "Ethertype:\t0x%04X = %d ", eth, eth);
						if(eth == 2048)
							fprintf(salida, "(DOD IP)\n");
						else if(eth == 2054)
							fprintf(salida, "(ARP)\n");
					}
					fprintf(salida, "\n");
					pos = 0;
				}
				else
					flag = 1;
			}
			else
			{
				if(sync == 0)
				{
					hex[sync] = z;
					sync = 1;
				}
				else
				{
					hex[sync] = z;
					sscanf(hex, "%2x", &trama[pos]);
					sync = 0;
					pos++;
				}
				flag = 0;
			}
		}
	}

	fprintf(salida, "Ortega Ortunio Eder - 2CM9 | multiaportes.com\n");
	fclose(salida);
	fclose(arch);

	return 0;
}