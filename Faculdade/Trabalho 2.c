#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum especialidade

typedef struct{
char CRM[6],nome[50],bday[10];
float salário;
int espc;
} medicos;

typedef struct{
char CPF[11],nome[30],bday[10],telefone[11];

} pacientes;

typedef struct{
char CRM[6],CPF[11],data[10],sintoma[100], encaminhamentos[100];
} consultas;

char **especialidade;
