/*
 * Copyright (C) 2015 Francisco Domínguez Lerma
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*

Uso de la librería:

Esta librería sirve para extraer información de un archivo de configuración, para ello se usarán las funciones:

get_value_string -> obtiene el valor de un campo string y lo copiará al string expecificado, ejemplo: "get_value_string(archivo_conf, "campo", array_destino);", en caso de error devuelve 1, de lo contrario devuelve 0.

get_value_int -> devuelve el valor de un campo int, en caso de fallo, devolverá 0, ejemplo: "int valor=get_value_int(archivo_conf, "campo");"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_value_string(char [], char [], char []);
int get_value_int(char [], char []);
static void clear_array(char [], int);


int get_value_string(char file_conf[], char subject_i[], char value_i[]) {
	
	FILE * file;

	int file_line_size=50;
	int subject_size=25;
	int value_size=25;

	char buffer[file_line_size];
	char subject[subject_size];
	char value[value_size];

	file=fopen(file_conf, "r");
	if (file==NULL) {

		printf("Error al abrir el archivo\n");
		return(0);

	}

	int x, y;	
	while (!feof(file))
 	{
		clear_array(buffer, file_line_size);
		clear_array(subject, subject_size);
		clear_array(value, value_size);
		
 		fgets(buffer,file_line_size,file);
 		if (buffer[0]=='#') continue;
		x=0;
		for (x=0; x<subject_size; x++) {
			if(buffer[x]=='=') break;
			subject[x]=buffer[x];
		}
		y=0;
		for (x=x+1; x<file_line_size; x++) {		
			if(buffer[x]=='\n') break;
			value[y]=buffer[x];
			y++;

		}
		
		if (strcmp(subject_i, subject)==0) { strcpy(value_i, value); fclose(file); return(0); }
 	}
	printf("No existe el campo %s dentro del fichero\n", subject_i);
	fclose(file);
	return(1);
}

int get_value_int(char file_conf[], char subject_i[]) {
	
	FILE * file;

	int file_line_size=50;
	int subject_size=25;
	int value_size=25;

	char buffer[file_line_size];
	char subject[subject_size];
	char value[value_size];

	file=fopen(file_conf, "r");
	if (file==NULL) {

		printf("Error al abrir el archivo\n");
		return(0);

	}

	int x, y;	
	while (!feof(file))
 	{
		clear_array(buffer, file_line_size);
		clear_array(subject, subject_size);
		clear_array(value, value_size);
		
 		fgets(buffer,file_line_size,file);
 		if (buffer[0]=='#') continue;
		x=0;
		for (x=0; x<subject_size; x++) {
			if(buffer[x]=='=') break;
			subject[x]=buffer[x];
		}
		y=0;
		for (x=x+1; x<file_line_size; x++) {		
			if(buffer[x]=='\n') break;
			value[y]=buffer[x];
			y++;

		}
		
		if (strcmp(subject_i, subject)==0){fclose(file); return(atoi(value));}
 	}
	printf("No existe el campo %s dentro del fichero\n", subject_i);
	fclose(file);
	return(0);
}

static void clear_array(char array[], int size) {

int x;

for(x=0;x<size;x++) {

	array[x]='\0';


}

}

