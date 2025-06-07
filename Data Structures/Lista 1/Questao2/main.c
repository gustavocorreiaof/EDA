#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data{
    int Dia;
    int Mes;
    int Ano;
} typedef Data;

struct Pessoa{
    Data DataDeNascimento;
    char Nome[50];
} typedef Pessoa;

int main()
{
    time_t agora;
    struct tm *data;
    time(&agora);
    agora -= 60 * 60 * 24;
    data = localtime(&agora);

    Data ontem;

    ontem.Dia = data->tm_mday;
    ontem.Mes = data->tm_mon + 1;
    ontem.Ano = data->tm_year + 1900;

    printf("%d/%d/%d", ontem.Dia, ontem.Mes, ontem.Ano);

    Pessoa pessoa;

    //essa daqui se tu entender pode se declarar um nerd fedido
    pessoa.DataDeNascimento = ontem;
    strcpy(pessoa.Nome, "Visao");

    Pessoa gustavo;

    Data hoje;
    hoje.Dia = data->tm_mday + 1;
    hoje.Mes = data->tm_mon + 1;
    hoje.Ano = data->tm_year + 1900;

    gustavo.DataDeNascimento = hoje;
    strcpy(gustavo.Nome, "Gustavo Correia Dias");



    return 0;
}
