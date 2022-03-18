// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (bit.ly/mathematicalramblings_github).

// Biblioteca C de funções e constantes pertencentes a Antonio Vandré Pedrosa Furtunato Gomes, versão de distribuição para antoniovandre_eval GUI.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 07-12-2020.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define __USE_GNU
#include <math.h>
#include <float.h>

#include "antoniovandre_constantes.c"

#include "antoniovandre_extra.c"

#define VERSION 20201206
#define TAMANHO_BUFFER_SMALL 75 // Para pequenos buffers.
#define TAMANHO_BUFFER_WORD 8192 // Para strings pequenas.
#define TAMANHO_BUFFER_PHRASE 81920 // Para strings grandes.
#define VALOR_MAX 1000000000 // Afim de evitar erros de saída.
#define VALOR_MAX_2 10000000 // Valor máximo. Segunda opção.
#define VALOR_MAX_3 50 // Valor máximo. Terceira opção.
#define MARCADORREAL VALOR_MAX + 1 // Útil para delimitar memórias alocadas.
#define TAMANHO_MAX_ARQUIVO 1000000000000 // Afim de evitar erros de saída.
#define NUMEROZERO 0
#define NUMEROUM 1
#define OPERADORSUBTRACAO '-'
#define OPERADORMULTIPLICACAO '*'
#define STRINGMENOSUM "-1"
#define VARIAVELPADRAO 'x'
#define ESPACOBRANCO ' '
#define STRINGVAZIA ""
#define DELIMITADORSTRING ',' // Deve ser um char;
#define DELIMITADORSTRING2 ';' // Deve ser um char, diferente de DELIMITADORSTRING;
#define DELIMITADORSTRING3 '/' // Mais uma opção de delimitador.
#define CARACTEREFIMLINHA '\n' // Caractere de fim de linha.
#define STRINGSAIDAERRO "Erro de saida de uma string."
#define STRINGSAIDAERROOVER "Erro de saida de uma string por over."
#define MENSAGEM_ERRO_OVER "Um dos números atingiu o limite máximo."
#define TENTATIVASLOGICAS 4 // Podem ser necessárias mais de uma verificação lógica em alguns trechos.
#define TOKENINICIOEVAL '('
#define TOKENFIMEVAL ')'
#define EPSILON 0.001 // Para funções de Cálculo Diferencial.
#define VARIAVELDESUBSTITUICAO VARIAVELPADRAO // Deve ser uma letra não presente nos nomes das funções.
#define VARIAVELDESUBSTITUICAO2 'y' // Deve ser uma letra não presente nos nomes das funções.
#define NUMEROPARTICOESSOMARIEMANN 100 // Para Cálculo Integral.
#define VERDADE NUMEROUM
#define FALSIDADE NUMEROZERO
#define INTERVALOPROGRESSO 100 // Para não haver flood quando mostrando progressos de processos.
#define INTERVALOPROGRESSO2 500000 // Para não haver flood quando mostrando progressos de processos, para processos mais rápidos.
#define INTERVALOPROGRESSO3 50 // Para não haver flood quando mostrando progressos de processos, para processos mais lentos.
#define INTERVALOPROGRESSO4 200 // Para não haver flood quando mostrando progressos de processos, quarta opção.
#define APROXIMACAO 0.0000000001 // Para verificação de aproximação numérica.
#define APROXIMACAO2 0.000001 // Para verificação de aproximação numérica. Segunda opção.
#define APROXIMACAO3 0.005 // Para verificação de aproximação numérica. Terceira opção.
#define APROXIMACAO4 0.05 // Para verificação de aproximação numérica. Quarta opção.
#define APROXIMACAO5 0.0005 // Para verificação de aproximação numérica. Quinta opção.
#define APROXIMACAO6 0.005 // Para verificação de aproximação numérica. Sexta opção.
#define MAXNUMERADORFRACOES 100000 // Para a conversão de números em frações. Útil para, dentre outras coisas, calcular potências de bases negativas.
#define MINPRECISAO 8 // Afim de garantir retornos corretos de algumas funções.
#define MAXPRECISAO 19 // Afim de evitar erros de saída.

typedef long double TIPONUMEROREAL;

typedef struct {char token [TAMANHO_BUFFER_WORD]; TIPONUMEROREAL valor; char comentario [TAMANHO_BUFFER_PHRASE];} tokenfuncaoconstante; // Estrutura para funções e constantes.

typedef struct {TIPONUMEROREAL real; TIPONUMEROREAL img;} NUMEROCOMPLEXO; // Estrutura número complexo.

#define ARQUIVO_MATHSOBRE "/usr/share/antoniovandre_sobre.txt"
// #define ARQUIVO_MATH_ESTATISTICAS "antoniovandre_math_estatisticas.txt"
#define ARQUIVO_PRECISAO_REAL "/usr/share/antoniovandre_precisao_real.txt"

// Função de output do sobre/about dos softwares matemáticos.

int antoniovandre_mathsobre ()
	{
	FILE * filesobre;
	char antoniovandre_sobre_buffer_char;

	filesobre = fopen (ARQUIVO_MATHSOBRE, "r");

	if (filesobre == NULL)
		{
		printf ("Erro ao abrir arquivo sobre.\n");
		return -1;
		}

	while (! feof (filesobre))
		{
		antoniovandre_sobre_buffer_char = fgetc (filesobre);
		if (! feof(filesobre)) printf ("%c", antoniovandre_sobre_buffer_char);
		}

	fclose (filesobre);
	}

// Função de salvar as estatísticas de uso dos softwares matemáticos.

int antoniovandre_salvarmathestatisticas (char * cabecalho)
	{
	FILE * filemathestatisticas;
	char antoniovandre_estatisticas_buffer [TAMANHO_BUFFER_WORD];
	unsigned long int antoniovandre_estatisticas_contador;
	int flag = NUMEROZERO;
	int flag2 = NUMEROZERO;
	char tc;
	char tc2;

	strcpy (antoniovandre_estatisticas_buffer, STRINGVAZIA);

	filemathestatisticas = fopen (ARQUIVO_MATH_ESTATISTICAS, "r+");

	if (filemathestatisticas == NULL)
		{
		filemathestatisticas = fopen (ARQUIVO_MATH_ESTATISTICAS, "w");

		if (filemathestatisticas == NULL)
			{
			printf ("Erro ao abrir ou criar arquivo de estatísticas.\n");
			return -1;
			}

		flag2 = NUMEROUM;
		}

	while ((! feof (filemathestatisticas)) && flag2 == NUMEROZERO)
		{
		fscanf (filemathestatisticas, "%s", antoniovandre_estatisticas_buffer);

		if (! strcmp (antoniovandre_estatisticas_buffer, cabecalho))
			{
			fscanf (filemathestatisticas, "%s", antoniovandre_estatisticas_buffer);

			antoniovandre_estatisticas_contador = atoi (antoniovandre_estatisticas_buffer);
			antoniovandre_estatisticas_contador++;

			fseek (filemathestatisticas, (-1) * strlen (antoniovandre_estatisticas_buffer), SEEK_CUR);

			fprintf (filemathestatisticas, "%lu", antoniovandre_estatisticas_contador);

			if ((int) log10 (antoniovandre_estatisticas_contador - NUMEROUM) != (int) log10(antoniovandre_estatisticas_contador))
				{
				tc = fgetc (filemathestatisticas);
				if (! feof (filemathestatisticas)) fseek (filemathestatisticas, (-1) * sizeof (char), SEEK_CUR);
				fputc (CARACTEREFIMLINHA, filemathestatisticas);

				if (! feof (filemathestatisticas))
					do
						{
						tc2 = fgetc (filemathestatisticas);
						if (! feof (filemathestatisticas)) fseek (filemathestatisticas, (-1) * sizeof (char), SEEK_CUR);
						fputc (tc, filemathestatisticas);
						tc = tc2;
						} while (! feof (filemathestatisticas));
				}

			flag = NUMEROUM;
			}
		}

	if (flag == NUMEROZERO)
		{
		char cabecalho_buffer [strlen (cabecalho)];

		strcpy (cabecalho_buffer, cabecalho);
		strcat (cabecalho_buffer, " 1\n");

		fprintf (filemathestatisticas, "%s", cabecalho_buffer);
		}

	fclose (filemathestatisticas);
	}

// Função que retorna a precisão real (numérica) para floats.

int antoniovandre_precisao_real ()
	{
	FILE * fileprecisaoreal;
	char antoniovandre_precisao_real_buffer [TAMANHO_BUFFER_WORD];
	int antoniovandre_precisao_real_valor;

	strcpy (antoniovandre_precisao_real_buffer, STRINGVAZIA);

	fileprecisaoreal = fopen(ARQUIVO_PRECISAO_REAL, "r");

	if (fileprecisaoreal == NULL)
		{
		printf ("Erro ao abrir arquivo de precisão real.\n");
		return -1;
		}

	fscanf (fileprecisaoreal, "%s", antoniovandre_precisao_real_buffer);

	antoniovandre_precisao_real_valor = atoi (antoniovandre_precisao_real_buffer);

	if (antoniovandre_precisao_real_valor == NUMEROZERO)
		{
		printf ("Erro ao ler arquivo de precisão real.\n");
		return -1;
		}

	fclose (fileprecisaoreal);

	if (antoniovandre_precisao_real_valor < MINPRECISAO)
		return MINPRECISAO;
	else if (antoniovandre_precisao_real_valor > MAXPRECISAO)
		return MAXPRECISAO;
	else
		return antoniovandre_precisao_real_valor;
	}

// Array de letras.

const char * antoniovandre_letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Array de letras maiúsculas.

const char * antoniovandre_letrasmaiusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Array de letras minúsculas.

const char * antoniovandre_letrasminusculas = "abcdefghijklmnopqrstuvwxyz";

// Array de números.

const char * antoniovandre_numeros = ".-0123456789";

// Array de operadores.

const char * antoniovandre_operadores = "+-*/^%@#$><:~";

// Array de operadores especiais.

const char * antoniovandre_operadoresespeciais = "%@#$><:~";

// Array de operadores prioritários.

const char * antoniovandre_operadoresprioritarios = "^";

// Remover letras de uma string.

char * antoniovandre_removerletras (char * str)
	{
	int tam1 = strlen (str);
	int tam2 = strlen (antoniovandre_letras);
	char strf [TAMANHO_BUFFER_PHRASE];
	int i;
	int j;
	int flag;
	int contador = NUMEROZERO;

	strcpy (strf, STRINGVAZIA);

	for (i = NUMEROZERO; i < tam1; i++)
		{
		flag = NUMEROZERO;

		for (j = NUMEROZERO; j < tam2; j++)
			if (str [i] == antoniovandre_letras [j]) flag = NUMEROUM;

		if (flag == NUMEROZERO) strf [contador++] = str [i];
		}

	return strf;
	}

// Remover números de uma string.

char * antoniovandre_removernumeros (char * str)
	{
	int tam1 = strlen (str);
	int tam2 = strlen (antoniovandre_numeros);
	char strf [TAMANHO_BUFFER_PHRASE];
	int i;
	int j;
	int flag;

	strcpy (strf, STRINGVAZIA);

	for (i = NUMEROZERO; i < tam1; i++)
		{
		flag = NUMEROZERO;

		for (j = NUMEROZERO; j < tam2; j++)
			if (str [i] == antoniovandre_numeros [j]) flag = NUMEROUM;

		if (flag == NUMEROZERO) strncat (strf, & str [i], NUMEROUM);
		}

	return strf;
	}

// Verificar se string é monômio.

int antoniovandre_monomio (char * str)
	{
	int contador = NUMEROZERO;
	int flag;
	int i;
	int j;

	for (i = NUMEROUM; i < strlen (str); i++)
		{
		flag = NUMEROZERO;

		for (j = NUMEROZERO; j < strlen (antoniovandre_numeros); j++)
			if (str [i] == antoniovandre_numeros [j]) flag = NUMEROUM;

		if (flag == NUMEROUM)
			for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++)
				if (str [i - 1] == antoniovandre_letras [j]) return NUMEROZERO;
		}

	for (i = NUMEROUM; i < strlen (str); i++) if (str [i] == OPERADORSUBTRACAO) return NUMEROZERO;

	for (i = NUMEROZERO; i < strlen (str); i++)
		{if (str [i] == '.') contador++; if (contador == 2) return NUMEROZERO;}

	if (strcmp (antoniovandre_removerletras (antoniovandre_removernumeros (str)), STRINGVAZIA) || (! strcmp (str, "-")))
		return NUMEROZERO;
	else
		return -1;
	}

// Parte numérica de um monômio.

TIPONUMEROREAL antoniovandre_partenumericamonomio (char * str)
	{
	char * err;

	if (antoniovandre_monomio (str))
		{
		if (! strcmp (antoniovandre_removerletras (str), STRINGVAZIA))
			return NUMEROUM;
		else if (! strcmp (antoniovandre_removerletras (str), "-") && strlen (str) != NUMEROUM)
			return -1;
		else
			return (strtold (antoniovandre_removerletras (str), & err));
		}
	else
		return NUMEROZERO;
	}

// Parte literal de um monômio.

char * antoniovandre_parteliteralmonomio (char * str)
	{
	if (antoniovandre_monomio (str))
		return antoniovandre_removernumeros (str);
	else
		return NULL;
	}

// Número para string.

char * antoniovandre_numeroparastring (TIPONUMEROREAL numero)
	{
	int precisao = antoniovandre_precisao_real ();
	int potencia_min = (-1) * precisao;
	int potencia_max = log10 (VALOR_MAX);
	TIPONUMEROREAL fator = powl (10, potencia_max);
	char strr [TAMANHO_BUFFER_WORD];
	int algarismo;
	int i;
	int flag = NUMEROZERO;
	int contador = NUMEROZERO;

	strcpy (strr, STRINGVAZIA);

	if (numero < NUMEROZERO)
		{
		numero *= -1;
		strcat (strr, "-");
		}

	if ((numero > VALOR_MAX) || (numero < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

	for (i = potencia_max; i >= potencia_min; i--)
		{
		if (i == -1)
			{
			if (numero < NUMEROUM) strcat (strr, "0");

			strcat (strr, ".");
			}

		algarismo = (int) fmodl (((TIPONUMEROREAL) numero / (TIPONUMEROREAL) fator), 10);

		fator /= (TIPONUMEROREAL) 10;

		if (algarismo != NUMEROZERO) flag = NUMEROUM;

		if (flag == NUMEROUM) contador++;

		if ((flag == 1 || i < NUMEROZERO) && (contador <= precisao))
			{
			switch (algarismo)
				{
				case NUMEROZERO:
					strcat (strr, "0");
					break;
				case NUMEROUM:
					strcat (strr, "1");
					break;
				case 2:
					strcat (strr, "2");
					break;
				case 3:
					strcat (strr, "3");
					break;
				case 4:
					strcat (strr, "4");
					break;
				case 5:
					strcat (strr, "5");
					break;
				case 6:
					strcat (strr, "6");
					break;
				case 7:
					strcat (strr, "7");
					break;
				case 8:
					strcat (strr, "8");
					break;
				case 9:
					strcat (strr, "9");
					break;
				default:
					strcat (strr, "0");
				}
			}
		}

	return strr;
	}

// Comparar strings sem ordem.

int antoniovandre_compararstringssemorden (char * str1, char * str2)
	{
	int tam1 = strlen (str1);
	int tam2 = strlen (str2);
	char c;
	int contador1;
	int contador2;
	int i;
	int j;

	for (i = NUMEROZERO; i < tam1; i++)
		{
		c = str1 [i];

		contador1 = NUMEROZERO;

		for (j = NUMEROZERO; j < tam1; j++) if (c == str1 [j]) contador1++;

		contador2 = NUMEROZERO;

		for (j = NUMEROZERO; j < tam2; j++) if (c == str2 [j]) contador2++;

		if (contador1 != contador2) return -1;
		}

	if (tam1 != tam2) return -1;

	return NUMEROZERO;
	}

// Enésima substring de uma string separada por delimitadores. Inicia-se contando do NUMEROZERO;

char * antoniovandre_nthsubstr (char * str, int n)
	{
	char * strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);
	int tam = strlen (str);
	int inicio = NUMEROZERO;
	int fim = NUMEROZERO;
	int ponteiro = NUMEROZERO;
	int shifti = NUMEROZERO;
	int shiftf = NUMEROZERO;
	int contador = NUMEROZERO;
	int i;

	strcpy (strf, STRINGVAZIA);

	for (i = NUMEROZERO; i < tam; i++)
		if (str [i] == DELIMITADORSTRING)
			if (n == contador++)
				{
				inicio = ponteiro;
				fim = i;
				}
			else
				ponteiro = i;

	if (fim == NUMEROZERO)
		{
		inicio = ponteiro;
		fim = tam - NUMEROUM;
		}

	if (inicio != NUMEROZERO) shifti = NUMEROUM;
	if (fim != tam - NUMEROUM) shiftf = NUMEROUM;

	contador = NUMEROZERO;

	for (i = inicio + shifti; i <= fim - shiftf; i++) strf [contador++] = str [i];

	return strf;
	}

// Fatorial.

unsigned long int antoniovandre_fatorial (unsigned long int n)
	{
	if (n > NUMEROUM) return antoniovandre_fatorial (n - NUMEROUM) * (unsigned long int) n; else return NUMEROUM;
	}

// Reduzir termos semelhantes.

char * antoniovandre_reduzirtermossemelhantes (char * args)
	{
	int nargs = NUMEROUM;
	char strf [TAMANHO_BUFFER_WORD];
	char parteliteral [TAMANHO_BUFFER_WORD];
	char strt [TAMANHO_BUFFER_WORD];
	int i;
	int j;
	int flag;
	int contador = NUMEROZERO;

	for (i = NUMEROZERO; i < strlen (args); i++) if (args [i] == DELIMITADORSTRING) nargs++;

	char * strlit [nargs];
	TIPONUMEROREAL coefs [nargs];

	strcpy (strf, STRINGVAZIA);
	strcpy (parteliteral, STRINGVAZIA);
	strcpy (strt, STRINGVAZIA);

	for (i = NUMEROZERO; i < nargs; i++)
		{
		strlit [i] = (char *) malloc (TAMANHO_BUFFER_WORD);
		strcpy (strlit [i], STRINGVAZIA);
		}

	for (i = NUMEROZERO; i < nargs; i++)
		{
		flag = NUMEROZERO; j = NUMEROZERO;

		while (flag == 0 && j++ < TENTATIVASLOGICAS)
			if (antoniovandre_monomio (antoniovandre_nthsubstr (args, i))) flag = NUMEROUM;

		if (flag == NUMEROUM)
			{
			strcpy (parteliteral, antoniovandre_parteliteralmonomio (antoniovandre_nthsubstr (args, i)));

			flag = NUMEROZERO;

			for (j = NUMEROZERO; j < contador; j++)
				if (! antoniovandre_compararstringssemorden (strlit [j], parteliteral))
					{
					coefs [j] += (TIPONUMEROREAL) antoniovandre_partenumericamonomio (antoniovandre_nthsubstr (args, i));
					flag = NUMEROUM;
					break;
					}
			if (flag == NUMEROZERO)
				{
				strcpy (strlit [contador], parteliteral);
				coefs [contador++] = (TIPONUMEROREAL) antoniovandre_partenumericamonomio (antoniovandre_nthsubstr (args, i));
				}
			}
		else
			return (STRINGSAIDAERRO);
		}

	flag = NUMEROZERO;

	for (i = NUMEROZERO; i < contador; i++)
		if (coefs [i] != NUMEROZERO)
			{
			strcpy (strt, antoniovandre_numeroparastring (coefs [i]));

			if (! strcmp (strt, STRINGSAIDAERROOVER)) return (STRINGSAIDAERROOVER);

			if (i == NUMEROZERO) 
				memmove (strf, strt, strlen (antoniovandre_numeroparastring (coefs [i])));
			else
				strcat (strf, strt);
			strcat (strf, strlit [i]);
			if (i < contador - NUMEROUM) strf [strlen (strf)] = ESPACOBRANCO;

			flag = NUMEROUM;
			}

	for (i = NUMEROZERO; i < nargs; i++) free (strlit [i]);

	if (flag == NUMEROUM)
		return (strf);
	else
		return (antoniovandre_numeroparastring (0));
	}

// Valor numérico de um polinômio.

char * antoniovandre_valornumericopolinomio (char * args)
	{
	int nargs = NUMEROUM;
	int indice_inicio = -1;
	char strt [TAMANHO_BUFFER_WORD];
	char strt2 [TAMANHO_BUFFER_WORD];
	char str [TAMANHO_BUFFER_WORD];
	char str2 [TAMANHO_BUFFER_WORD];
	char str3 [TAMANHO_BUFFER_WORD];
	char str4 [TAMANHO_BUFFER_PHRASE];
	char str5 [TAMANHO_BUFFER_PHRASE];
	TIPONUMEROREAL coef;
	TIPONUMEROREAL fator;
	int i;
	int j;
	int k;
	int contador;
	int flag;
	int flag2 = NUMEROZERO;
	char c = DELIMITADORSTRING;
	char * err;

	strcpy (strt, STRINGVAZIA);
	strcpy (strt2, STRINGVAZIA);
	strcpy (str, STRINGVAZIA);
	strcpy (str2, STRINGVAZIA);
	strcpy (str3, STRINGVAZIA);
	strcpy (str4, STRINGVAZIA);
	strcpy (str5, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (args); i++)
		{
		if (args [i] == DELIMITADORSTRING) nargs++;
		if ((args [i] == '=') && (indice_inicio == -1)) indice_inicio = nargs - NUMEROUM;
		}

	if (indice_inicio != -1)
		{
		if (indice_inicio == NUMEROZERO) return STRINGSAIDAERRO;

		for (i = indice_inicio; i < nargs; i++)
			{
			flag = NUMEROZERO; contador = NUMEROZERO;

			while ((flag == NUMEROZERO) && (contador++ < TENTATIVASLOGICAS))
				{
				strcpy (strt, antoniovandre_nthsubstr (args, i));

				if (strt [NUMEROUM] == '=') flag = NUMEROUM;
				}

			if (flag == NUMEROZERO) return STRINGSAIDAERRO;

			flag = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++)
				if (strt [NUMEROZERO] == antoniovandre_letras [j]) flag = NUMEROUM;

			if (flag == NUMEROZERO) return STRINGSAIDAERRO;

			strcpy (strt2, STRINGVAZIA);

			for (j = 2; j < strlen (strt); j++) strncat (strt2, & strt [j], NUMEROUM);

			fator = strtold (strt2, & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((fator > VALOR_MAX) || (fator < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			for (j = NUMEROZERO; j < indice_inicio; j++)
				{
				flag = NUMEROZERO; contador = NUMEROZERO;

				while ((flag == NUMEROZERO) && (contador++ < TENTATIVASLOGICAS))
					{
					if (flag2 == NUMEROZERO)
						strcpy (str, antoniovandre_nthsubstr (args, j));
					else
						strcpy (str, antoniovandre_nthsubstr (str5, j));

					if (antoniovandre_monomio (str)) flag = NUMEROUM;
					}

				if (flag == NUMEROZERO) return STRINGSAIDAERRO;

				coef = antoniovandre_partenumericamonomio (str);

				if ((coef > VALOR_MAX) || (coef < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

				strcpy (str2, antoniovandre_parteliteralmonomio (str));

				strcpy (str3, STRINGVAZIA);

				for (k = NUMEROZERO; k < strlen (str2); k++)
					if (strt [NUMEROZERO] == str2 [k])
						coef *= fator;
					else
						strncat (str3, & str2 [k], NUMEROUM);

				if ((coef > VALOR_MAX) || (coef < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

				strcat (str4, antoniovandre_numeroparastring (coef));
				strcat (str4, str3);
				strncat (str4, &c, NUMEROUM);
				}

			str4 [strlen (str4) - 1] = '\0';
			strcpy (str5, str4);
			strcpy (str4, STRINGVAZIA);

			flag2 = NUMEROUM;
			}
		}

	if (indice_inicio != -1)
		return antoniovandre_reduzirtermossemelhantes (str5);
	else
		return antoniovandre_reduzirtermossemelhantes (args);
	}

// Função de verificação de uma expressão algébrica.

int antoniovandre_expressao (char * str)
	{
	int flag;
	int i;
	int j;

	for (i = NUMEROZERO; i < strlen (str); i++)
		{
		flag = NUMEROZERO;

		for (j = NUMEROZERO; j < strlen (antoniovandre_numeros); j++) if (str [i] == antoniovandre_numeros [j]) flag = NUMEROUM;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++) if (str [i] == antoniovandre_letras [j]) flag = NUMEROUM;

		for (j = NUMEROZERO; j < strlen (antoniovandre_operadores); j++) if (str [i] == antoniovandre_operadores [j]) flag = NUMEROUM;

		if ((str [i] == TOKENINICIOEVAL) || (str [i] == TOKENFIMEVAL)) flag = NUMEROUM;

		if (flag == NUMEROZERO) return NUMEROZERO;
		}

	return NUMEROUM;
	}

// Substring.

char * antoniovandre_substring (char * str, int inicio, int fim)
	{
	char strt [TAMANHO_BUFFER_PHRASE];
	int i;

	strcpy (strt, STRINGVAZIA);

	for (i = inicio; i <= fim; i++)
		strncat (strt, & str [i], NUMEROUM);

	return strt;
	}

// Função eval célula função. Os nomes das funções devem conter apenas letras minúsculas. Os nomes das constantes devem conter apenas letras maiúsculas. No escopo, as implementações das funções devem estar dispostas de modo a que os nomes das anteriores não sejam substrings das posteriores.

char * antoniovandre_evalcelulafuncao (char * str)
	{
	tokenfuncaoconstante funcoesconstantes [TAMANHO_BUFFER_SMALL];
	int tamanhotokenfuncaoconstante;
	int tamanhotokenfuncaoconstantemax = NUMEROZERO;
	int tokenid = -1;
	int tokeninicio;
	TIPONUMEROREAL resultado;
	TIPONUMEROREAL argumento;
	TIPONUMEROREAL coeficiente;
	char buffer [TAMANHO_BUFFER_WORD];
	char str2 [TAMANHO_BUFFER_PHRASE];
	int i;
	int j;
	char tc;
	char * err;
	char * err2;

	for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
		{
		strcpy (funcoesconstantes [i].token, STRINGVAZIA);
		funcoesconstantes [i].valor = (TIPONUMEROREAL) NUMEROZERO;
		strcpy (funcoesconstantes [i].comentario, STRINGVAZIA);
		}

	strcpy (funcoesconstantes [NUMEROZERO].token, "arccossec");
	strcpy (funcoesconstantes [NUMEROZERO].comentario, "Função arco-cossecante.");

	strcpy (funcoesconstantes [NUMEROUM].token, "arcsec");
	strcpy (funcoesconstantes [NUMEROUM].comentario, "Função arco-secante.");

	strcpy (funcoesconstantes [2].token, "arccotg");
	strcpy (funcoesconstantes [2].comentario, "Função arco-cotangente.");

	strcpy (funcoesconstantes [3].token, "arctg");
	strcpy (funcoesconstantes [3].comentario, "Função arco-tangente.");

	strcpy (funcoesconstantes [4].token, "arccos");
	strcpy (funcoesconstantes [4].comentario, "Função arco-cosseno.");

	strcpy (funcoesconstantes [5].token, "arcsen");
	strcpy (funcoesconstantes [5].comentario, "Função arco-seno.");

	strcpy (funcoesconstantes [6].token, "cossec");
	strcpy (funcoesconstantes [6].comentario, "Função cossecante.");

	strcpy (funcoesconstantes [7].token, "sec");
	strcpy (funcoesconstantes [7].comentario, "Função secante.");

	strcpy (funcoesconstantes [8].token, "sen");
	strcpy (funcoesconstantes [8].comentario, "Função seno.");

	strcpy (funcoesconstantes [9].token, "cos");
	strcpy (funcoesconstantes [9].comentario, "Função cosseno.");

	strcpy (funcoesconstantes [10].token, "cotg");
	strcpy (funcoesconstantes [10].comentario, "Função cotangente.");

	strcpy (funcoesconstantes [11].token, "tg");
	strcpy (funcoesconstantes [11].comentario, "Função tangente.");

	strcpy (funcoesconstantes [12].token, "logdois");
	strcpy (funcoesconstantes [12].comentario, "Função logaritmo na base 2.");

	strcpy (funcoesconstantes [13].token, "logdez");
	strcpy (funcoesconstantes [13].comentario, "Função logaritmo na base 10.");

	strcpy (funcoesconstantes [14].token, "ln");
	strcpy (funcoesconstantes [14].comentario, "Função logaritmo natural.");

	strcpy (funcoesconstantes [15].token, "PI");
	funcoesconstantes [15].valor = (TIPONUMEROREAL) M_PIl;
	strcpy (funcoesconstantes [15].comentario, "Constante pi, razão entre o comprimento e o diâmetro de uma circunferência.");

	strcpy (funcoesconstantes [16].token, "E");
	funcoesconstantes [16].valor = (TIPONUMEROREAL) M_El;
	strcpy (funcoesconstantes [16].comentario, "Constante e, base do logaritmo natural.");

	strcpy (funcoesconstantes [17].token, FISICA_C_SI);
	funcoesconstantes [17].valor = (TIPONUMEROREAL) FISICA_C_SI_VALOR;
	strcpy (funcoesconstantes [17].comentario, FISICA_C_SI_COMENTARIO);

	strcpy (funcoesconstantes [18].token, FISICA_G_SI);
	funcoesconstantes [18].valor = (TIPONUMEROREAL) FISICA_G_SI_VALOR;
	strcpy (funcoesconstantes [18].comentario, FISICA_G_SI_COMENTARIO);

	strcpy (funcoesconstantes [19].token, FISICA_QE_SI);
	funcoesconstantes [19].valor = (TIPONUMEROREAL) FISICA_QE_SI_VALOR;
	strcpy (funcoesconstantes [19].comentario, FISICA_QE_SI_COMENTARIO);

	strcpy (funcoesconstantes [20].token, FISICA_H_SI);
	funcoesconstantes [20].valor = (TIPONUMEROREAL) FISICA_H_SI_VALOR;
	strcpy (funcoesconstantes [20].comentario, FISICA_H_SI_COMENTARIO);

	strcpy (funcoesconstantes [21].token, FISICA_HH_SI);
	funcoesconstantes [21].valor = (TIPONUMEROREAL) FISICA_HH_SI_VALOR;
	strcpy (funcoesconstantes [21].comentario, FISICA_HH_SI_COMENTARIO);

	strcpy (funcoesconstantes [22].token, FISICA_K_SI);
	funcoesconstantes [22].valor = (TIPONUMEROREAL) FISICA_K_SI_VALOR;
	strcpy (funcoesconstantes [22].comentario, FISICA_K_SI_COMENTARIO);

	strcpy (funcoesconstantes [23].token, "senh");
	strcpy (funcoesconstantes [23].comentario, "Função seno hiperbólico.");

	strcpy (funcoesconstantes [24].token, "cosh");
	strcpy (funcoesconstantes [24].comentario, "Função cosseno hiperbólico.");

	strcpy (funcoesconstantes [25].token, "tgh");
	strcpy (funcoesconstantes [25].comentario, "Função tangente hiperbólica.");

	strcpy (funcoesconstantes [26].token, "cotgh");
	strcpy (funcoesconstantes [26].comentario, "Função cotangente hiperbólica.");

	strcpy (funcoesconstantes [27].token, "sech");
	strcpy (funcoesconstantes [27].comentario, "Função secante hiperbólica.");

	strcpy (funcoesconstantes [28].token, "cossech");
	strcpy (funcoesconstantes [28].comentario, "Função cossecante hiperbólica.");

	strcpy (funcoesconstantes [29].token, "arcsenh");
	strcpy (funcoesconstantes [29].comentario, "Função arco-seno hiperbólico.");

	strcpy (funcoesconstantes [30].token, "arccosh");
	strcpy (funcoesconstantes [30].comentario, "Função arco-cosseno hiperbólico.");

	strcpy (funcoesconstantes [31].token, "arctgh");
	strcpy (funcoesconstantes [31].comentario, "Função arco-tangente hiperbólico.");

	strcpy (funcoesconstantes [32].token, "arccotgh");
	strcpy (funcoesconstantes [32].comentario, "Função arco-cotangente hiperbólico.");

	strcpy (funcoesconstantes [33].token, "arcsech");
	strcpy (funcoesconstantes [33].comentario, "Função arco-secante hiperbólico.");

	strcpy (funcoesconstantes [34].token, "arccossech");
	strcpy (funcoesconstantes [34].comentario, "Função arco-cossecante hiperbólico.");

	strcpy (funcoesconstantes [35].token, "fatorial");
	strcpy (funcoesconstantes [35].comentario, "Função fatorial.");

	strcpy (funcoesconstantes [36].token, FISICA_ME_SI);
	funcoesconstantes [36].valor = (TIPONUMEROREAL) FISICA_ME_SI_VALOR;
	strcpy (funcoesconstantes [36].comentario, FISICA_ME_SI_COMENTARIO);

	strcpy (funcoesconstantes [37].token, FISICA_MP_SI);
	funcoesconstantes [37].valor = (TIPONUMEROREAL) FISICA_MP_SI_VALOR;
	strcpy (funcoesconstantes [37].comentario, FISICA_MP_SI_COMENTARIO);

	strcpy (funcoesconstantes [38].token, FISICA_A_SI);
	funcoesconstantes [38].valor = (TIPONUMEROREAL) FISICA_A_SI_VALOR;
	strcpy (funcoesconstantes [38].comentario, FISICA_A_SI_COMENTARIO);

	strcpy (funcoesconstantes [39].token, "modulo");
	strcpy (funcoesconstantes [39].comentario, "Função módulo.");

	strcpy (funcoesconstantes [40].token, "radparagrau");
	strcpy (funcoesconstantes [40].comentario, "Função para converter radianos para graus.");

	strcpy (funcoesconstantes [41].token, "radparagrado");
	strcpy (funcoesconstantes [41].comentario, "Função para converter radianos para grados.");

	strcpy (funcoesconstantes [42].token, "graupararad");
	strcpy (funcoesconstantes [42].comentario, "Função para converter graus para radianos.");

	strcpy (funcoesconstantes [43].token, "grauparagrado");
	strcpy (funcoesconstantes [43].comentario, "Função para converter graus para grados.");

	strcpy (funcoesconstantes [44].token, "gradopararad");
	strcpy (funcoesconstantes [44].comentario, "Função para converter grados para radianos.");

	strcpy (funcoesconstantes [45].token, "gradopargrau");
	strcpy (funcoesconstantes [45].comentario, "Função para converter grados para graus.");

	strcpy (funcoesconstantes [46].token, "kelvinparacelsius");
	strcpy (funcoesconstantes [46].comentario, "Função para converter temperatura em Kelvin para Celsius.");

	strcpy (funcoesconstantes [47].token, "kelvinparafahrenheit");
	strcpy (funcoesconstantes [47].comentario, "Função para converter temperatura em Kelvin para Fahrenheit.");

	strcpy (funcoesconstantes [48].token, "celsiusparakelvin");
	strcpy (funcoesconstantes [48].comentario, "Função para converter temperatura em Celsius para Kelvin.");

	strcpy (funcoesconstantes [49].token, "celsiusparafahrenheit");
	strcpy (funcoesconstantes [49].comentario, "Função para converter temperatura em Celsius para Fahrenheit.");

	strcpy (funcoesconstantes [50].token, "fahrenheitparakelvin");
	strcpy (funcoesconstantes [50].comentario, "Função para converter temperatura em Fahrenheit para Kelvin.");

	strcpy (funcoesconstantes [51].token, "fahrenheitparacelsius");
	strcpy (funcoesconstantes [51].comentario, "Função para converter temperatura em Fahrenheit para Celsius.");

	strcpy (funcoesconstantes [52].token, FISICA_AM_SI);
	funcoesconstantes [52].valor = (TIPONUMEROREAL) FISICA_AM_SI_VALOR;
	strcpy (funcoesconstantes [52].comentario, FISICA_AM_SI_COMENTARIO);

	strcpy (funcoesconstantes [53].token, FISICA_KE_SI);
	funcoesconstantes [53].valor = (TIPONUMEROREAL) FISICA_KE_SI_VALOR;
	strcpy (funcoesconstantes [53].comentario, FISICA_KE_SI_COMENTARIO);

	strcpy (funcoesconstantes [54].token, MATEMATICA_P);
	funcoesconstantes [54].valor = (TIPONUMEROREAL) MATEMATICA_P_VALOR;
	strcpy (funcoesconstantes [54].comentario, MATEMATICA_P_COMENTARIO);

	strcpy (funcoesconstantes [55].token, MATEMATICA_C);
	funcoesconstantes [55].valor = (TIPONUMEROREAL) MATEMATICA_C_VALOR;
	strcpy (funcoesconstantes [55].comentario, MATEMATICA_C_COMENTARIO);

	strcpy (funcoesconstantes [56].token, MATEMATICA_EMC);
	funcoesconstantes [56].valor = (TIPONUMEROREAL) MATEMATICA_EMC_VALOR;
	strcpy (funcoesconstantes [56].comentario, MATEMATICA_EMC_COMENTARIO);

	strcpy (funcoesconstantes [57].token, MATEMATICA_T);
	funcoesconstantes [57].valor = (TIPONUMEROREAL) MATEMATICA_T_VALOR;
	strcpy (funcoesconstantes [57].comentario, MATEMATICA_T_COMENTARIO);

	strcpy (funcoesconstantes [58].token, FISICA_R_SI);
	funcoesconstantes [58].valor = (TIPONUMEROREAL) FISICA_R_SI_VALOR;
	strcpy (funcoesconstantes [58].comentario, FISICA_R_SI_COMENTARIO);

	strcpy (funcoesconstantes [59].token, "piso");
	strcpy (funcoesconstantes [59].comentario, "Função piso.");

	strcpy (funcoesconstantes [60].token, "teto");
	strcpy (funcoesconstantes [60].comentario, "Função teto.");

	strcpy (funcoesconstantes [61].token, FISICA_SB_SI);
	funcoesconstantes [61].valor = (TIPONUMEROREAL) FISICA_SB_SI_VALOR;
	strcpy (funcoesconstantes [61].comentario, FISICA_SB_SI_COMENTARIO);

	strcpy (funcoesconstantes [62].token, FISICA_PM_SI);
	funcoesconstantes [62].valor = (TIPONUMEROREAL) FISICA_PM_SI_VALOR;
	strcpy (funcoesconstantes [62].comentario, FISICA_PM_SI_COMENTARIO);

	strcpy (funcoesconstantes [63].token, FISICA_PE_SI);
	funcoesconstantes [63].valor = (TIPONUMEROREAL) FISICA_PE_SI_VALOR;
	strcpy (funcoesconstantes [63].comentario, FISICA_PE_SI_COMENTARIO);

	strcpy (funcoesconstantes [64].token, FISICA_B_SI);
	funcoesconstantes [64].valor = (TIPONUMEROREAL) FISICA_B_SI_VALOR;
	strcpy (funcoesconstantes [64].comentario, FISICA_B_SI_COMENTARIO);

	strcpy (funcoesconstantes [65].token, FISICA_MN_SI);
	funcoesconstantes [65].valor = (TIPONUMEROREAL) FISICA_MN_SI_VALOR;
	strcpy (funcoesconstantes [65].comentario, FISICA_MN_SI_COMENTARIO);

	strcpy (funcoesconstantes [66].token, MATEMATICA_FA);
	funcoesconstantes [66].valor = (TIPONUMEROREAL) MATEMATICA_FA_VALOR;
	strcpy (funcoesconstantes [66].comentario, MATEMATICA_FA_COMENTARIO);

	strcpy (funcoesconstantes [67].token, MATEMATICA_FS);
	funcoesconstantes [67].valor = (TIPONUMEROREAL) MATEMATICA_FS_VALOR;
	strcpy (funcoesconstantes [67].comentario, MATEMATICA_FS_COMENTARIO);

	strcpy (funcoesconstantes [68].token, MATEMATICA_CO);
	funcoesconstantes [68].valor = (TIPONUMEROREAL) MATEMATICA_CO_VALOR;
	strcpy (funcoesconstantes [68].comentario, MATEMATICA_CO_COMENTARIO);

	strcpy (funcoesconstantes [69].token, MATEMATICA_K);
	funcoesconstantes [69].valor = (TIPONUMEROREAL) MATEMATICA_K_VALOR;
	strcpy (funcoesconstantes [69].comentario, MATEMATICA_K_COMENTARIO);

	strcpy (funcoesconstantes [70].token, MATEMATICA_GK);
	funcoesconstantes [70].valor = (TIPONUMEROREAL) MATEMATICA_GK_VALOR;
	strcpy (funcoesconstantes [70].comentario, MATEMATICA_GK_COMENTARIO);

	strcpy (funcoesconstantes [71].token, "system");
	strcpy (funcoesconstantes [71].comentario, "Valores do sistema.");

	for (i = NUMEROZERO; i < strlen (str); i++)
		for (j = NUMEROZERO; j < TAMANHO_BUFFER_SMALL; j++)
			if (! strcmp (antoniovandre_substring (str, i, i + strlen (funcoesconstantes [j].token) - NUMEROUM), funcoesconstantes [j].token))
				{
				tamanhotokenfuncaoconstante = strlen (funcoesconstantes [j].token);

				if (tamanhotokenfuncaoconstantemax < tamanhotokenfuncaoconstante)
					{
					tamanhotokenfuncaoconstantemax = tamanhotokenfuncaoconstante;
					tokenid = j;
					tokeninicio = i;
					}
				}

	if (tokenid != -1)
		if (funcoesconstantes [tokenid].valor != NUMEROZERO)
			{
			coeficiente = NUMEROUM;

			if (tokeninicio > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, tokeninicio - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}	
				}

			if (strcmp (antoniovandre_substring (str, tokeninicio + tamanhotokenfuncaoconstantemax, strlen (str) - NUMEROUM), STRINGVAZIA)) return STRINGSAIDAERRO;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * funcoesconstantes [tokenid].valor);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "teto"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			if (argumento <= NUMEROZERO)
				resultado = (long int) argumento;
			else
				{
					if (argumento == (long int) argumento)
						resultado = (long int) argumento;
					else
						resultado = (long int) argumento + NUMEROUM;
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) resultado);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "piso"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			if (argumento >= NUMEROZERO)
				resultado = (long int) argumento;
			else
				{
					if (argumento == (long int) argumento)
						resultado = (long int) argumento;
					else
						resultado = (long int) argumento - NUMEROUM;
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) resultado);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 20), "fahrenheitparacelsius"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 21, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (5 * (argumento - 32) / 9));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 19), "fahrenheitparakelvin"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 20, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((5 * (argumento - 32) / 9) + 273.15));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 20), "celsiusparafahrenheit"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 21, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((9 * argumento / 5) + 32));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 16), "celsiusparakelvin"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 17, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (argumento - 273.15));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 19), "kelvinparafahrenheit"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 20, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((9 * (argumento - 273.15) / 5) + 32));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 16), "kelvinparacelsius"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 17, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (argumento + 273.15));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 12), "gradoparagrau"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 13, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 9 / 10);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 11), "gradopararad"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 12, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * M_PIl / 200);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 12), "grauparagrado"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 13, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 10 / 9);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 10), "graupararad"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 11, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * M_PIl / 180);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 11), "radparagrado"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 12, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 200 / M_PIl);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 10), "radparagrau"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 11, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 180 / M_PIl);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "modulo"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) fabsl (argumento));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 7), "fatorial"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 8, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento != (long int) argumento) || argumento < NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) argumento));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 9), "arccossech"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 10, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) (logl ((TIPONUMEROREAL) (1 + (TIPONUMEROREAL) powl (1 + (TIPONUMEROREAL) powl ((TIPONUMEROREAL) argumento, 2), 0.5)) / ((TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "arcsech"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento <= NUMEROZERO) || (argumento > NUMEROUM))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) (logl ((TIPONUMEROREAL) (1 + (TIPONUMEROREAL) powl (1 - (TIPONUMEROREAL) powl ((TIPONUMEROREAL) argumento, 2), 0.5)) / ((TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 7), "arccotgh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 8, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento >= -1) && (argumento <= NUMEROUM))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) ((logl ((TIPONUMEROREAL) ((TIPONUMEROREAL) argumento + NUMEROUM) / ((TIPONUMEROREAL) argumento - NUMEROUM))) / 2))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "arctgh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento <= -1) || (argumento >= NUMEROUM))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) ((logl ((TIPONUMEROREAL) (1 + (TIPONUMEROREAL) argumento) / (1 - (TIPONUMEROREAL) argumento))) / 2))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "arccosh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento < NUMEROUM)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) logl ((TIPONUMEROREAL) (argumento + powl ((TIPONUMEROREAL) (powl ((TIPONUMEROREAL) argumento, 2) - NUMEROUM), 0.5))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "arcsenh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) logl ((TIPONUMEROREAL) (argumento + powl ((TIPONUMEROREAL) (powl ((TIPONUMEROREAL) argumento, 2) + NUMEROUM), 0.5))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "cossech"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (2 / (powl (M_El, (TIPONUMEROREAL) argumento) - powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "sech"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (2 / (powl (M_El, (TIPONUMEROREAL) argumento) + powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 4), "cotgh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 5, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_El, (TIPONUMEROREAL) argumento) + powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))) / (powl (M_El, (TIPONUMEROREAL) argumento) - powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 2), "tgh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 3, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_El, (TIPONUMEROREAL) argumento) - powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))) / (powl (M_El, (TIPONUMEROREAL) argumento) + powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))))));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "senh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_El, (TIPONUMEROREAL) argumento) - powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))) / 2)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "cosh"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_El, (TIPONUMEROREAL) argumento) + powl (M_El, ((-1) * (TIPONUMEROREAL) argumento))) / 2)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 8), "arccossec"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 9, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento > -1) && (argumento < NUMEROUM))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * asinl (1 / (TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "arcsec"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || ((argumento > -1) && (argumento < NUMEROUM))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * acosl (1 / (TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "arccotg"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			if (argumento == NUMEROZERO) resultado = (TIPONUMEROREAL) coeficiente * M_PI_2l; else if (argumento < NUMEROZERO) resultado = (TIPONUMEROREAL) coeficiente * (atanl (1 / (TIPONUMEROREAL) argumento) + M_PIl); else resultado = (TIPONUMEROREAL) coeficiente * atanl (1 / (TIPONUMEROREAL) argumento);

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) resultado);
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 4), "arctg"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 5, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * atanl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "arccos"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento < -1) || (argumento > NUMEROUM)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * acosl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "arcsen"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento < -1) || (argumento > NUMEROUM)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * asinl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "cossec"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PIl) == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / sinl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 2), "sec"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 3, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PIl) == strtold (antoniovandre_numeroparastring (M_PI_2l), & err2))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / cosl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 2), "sen"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 3, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * sinl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 2), "cos"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 3, strlen (str) - NUMEROUM), & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * cosl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 3), "cotg"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 4, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PIl) == NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / tanl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + NUMEROUM), "tg"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 2, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PIl) == strtold (antoniovandre_numeroparastring (M_PI_2l), & err2))) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * tanl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 6), "logdois"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 7, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento) / M_LN2l));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "logdez"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento) / M_LN10l));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + NUMEROUM), "ln"))
			{
			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				strcpy (buffer, antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM));

				if (! strcmp (buffer, "-"))
					coeficiente = -1;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) return STRINGSAIDAERRO;
					if ((coeficiente > VALOR_MAX) || (coeficiente < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					}
				}

			argumento = strtold (antoniovandre_substring (str, i + 2, strlen (str) - NUMEROUM), & err);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) return STRINGSAIDAERRO;

			if ((argumento > VALOR_MAX) || (argumento < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento)));
			}

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (! strcmp (antoniovandre_substring (str, i, i + 5), "system"))
			{
			strcpy (str2, antoniovandre_substring (str, i + 6, strlen (str) - NUMEROUM));

			if (! strcmp (str2, "tamanho_buffer_small"))
				return antoniovandre_numeroparastring (TAMANHO_BUFFER_SMALL);
			else if (! strcmp (str2, "tamanho_buffer_word"))
				return antoniovandre_numeroparastring (TAMANHO_BUFFER_WORD);
			else if (! strcmp (str2, "tamanho_buffer_phrase"))
				return antoniovandre_numeroparastring (TAMANHO_BUFFER_PHRASE);
			else if (! strcmp (str2, "valor_max"))
				return antoniovandre_numeroparastring (VALOR_MAX);
			else if (! strcmp (str2, "tamanho_max_arquivo"))
				return antoniovandre_numeroparastring (TAMANHO_MAX_ARQUIVO);
			else if (! strcmp (str2, "variavelpadrao"))
				{
				tc = VARIAVELPADRAO;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "delimitadorstring"))
				{
				tc = DELIMITADORSTRING;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "delimitadorstring2"))
				{
				tc = DELIMITADORSTRING2;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "delimitadorstring3"))
				{
				tc = DELIMITADORSTRING3;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "tentativaslogicas"))
				return antoniovandre_numeroparastring (TENTATIVASLOGICAS);
			else if (! strcmp (str2, "tokeninicioeval"))
				{
				tc = TOKENINICIOEVAL;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "tokenfimeval"))
				{
				tc = TOKENFIMEVAL;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "epsilon"))
				return antoniovandre_numeroparastring (EPSILON);
			else if (! strcmp (str2, "variaveldesubstituicao"))
				{
				tc = VARIAVELDESUBSTITUICAO;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "variaveldesubstituicao2"))
				{
				tc = VARIAVELDESUBSTITUICAO2;
				return antoniovandre_numeroparastring ((int) tc);
				}
			else if (! strcmp (str2, "numeroparticoessomariemann"))
				return antoniovandre_numeroparastring (NUMEROPARTICOESSOMARIEMANN);
			else if (! strcmp (str2, "intervaloprogresso"))
				return antoniovandre_numeroparastring (INTERVALOPROGRESSO);
			else if (! strcmp (str2, "intervaloprogresso2"))
				return antoniovandre_numeroparastring (INTERVALOPROGRESSO2);
			else if (! strcmp (str2, "intervaloprogresso3"))
				return antoniovandre_numeroparastring (INTERVALOPROGRESSO3);
			else if (! strcmp (str2, "intervaloprogresso4"))
				return antoniovandre_numeroparastring (INTERVALOPROGRESSO4);
			else if (! strcmp (str2, "aproximacao"))
				return antoniovandre_numeroparastring (APROXIMACAO);
			else if (! strcmp (str2, "aproximacao2"))
				return antoniovandre_numeroparastring (APROXIMACAO2);
			else if (! strcmp (str2, "aproximacao3"))
				return antoniovandre_numeroparastring (APROXIMACAO3);
			else if (! strcmp (str2, "aproximacao4"))
				return antoniovandre_numeroparastring (APROXIMACAO4);
			else if (! strcmp (str2, "aproximacao5"))
				return antoniovandre_numeroparastring (APROXIMACAO5);
			else if (! strcmp (str2, "aproximacao6"))
				return antoniovandre_numeroparastring (APROXIMACAO6);
			else if (! strcmp (str2, "maxnumeradorfracoes"))
				return antoniovandre_numeroparastring (MAXNUMERADORFRACOES);
			else if (! strcmp (str2, "minprecisao"))
				return antoniovandre_numeroparastring (MINPRECISAO);
			else if (! strcmp (str2, "maxprecisao"))
				return antoniovandre_numeroparastring (MAXPRECISAO);
			else if (! strcmp (str2, "version"))
				return antoniovandre_numeroparastring (VERSION);
			else
				return STRINGSAIDAERRO;
			}

	resultado = strtold (str, & err);

	if ((* err != NUMEROZERO) || (! strcmp (str, STRINGVAZIA)))
		return STRINGSAIDAERRO;
	else
		return antoniovandre_numeroparastring (resultado);
	}

// Função eval célula.

char * antoniovandre_evalcelula (char * str)
	{
	char strt [TAMANHO_BUFFER_PHRASE];
	char strt2 [TAMANHO_BUFFER_WORD];
	char strt3 [TAMANHO_BUFFER_WORD];
	char strtv1 [TAMANHO_BUFFER_WORD];
	char strtv2 [TAMANHO_BUFFER_WORD];
	char strt4 [TAMANHO_BUFFER_PHRASE];
	int posicoes_operadores [TAMANHO_BUFFER_PHRASE];
	TIPONUMEROREAL valor;
	TIPONUMEROREAL valort;
	TIPONUMEROREAL valort2;
	int contador;
	int contador2;
	int i;
	int j;
	int k;
	int flag;
	int flag2;
	int flag3;
	int flag4;
	int flag5;
	int ponteiro;
	int ponteiroinicio;
	int ponteirofim;
	int finalponteirocelula;
	char * err;
	char tc = ESPACOBRANCO;
	char tc2;

	strcpy (strt, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] != tc) strncat (strt, & str [i], NUMEROUM);

	if (! strcmp (strt, STRINGVAZIA)) return STRINGSAIDAERRO;

	tc = strt [NUMEROZERO];

	for (i = NUMEROZERO; i < strlen (antoniovandre_operadores); i++)
		{
		tc2 = antoniovandre_operadores [i];

		if ((tc == tc2) && (tc2 != OPERADORSUBTRACAO))
			return STRINGSAIDAERRO;
		}

	while (VERDADE)
		{
		for (i = NUMEROZERO; i < TAMANHO_BUFFER_PHRASE; i++) posicoes_operadores [i] = -1;

		contador = NUMEROZERO; flag4 = NUMEROZERO;

		for (i = NUMEROZERO; i < strlen (strt); i++)
			for (j = NUMEROZERO; j < strlen (antoniovandre_operadores); j++)
				{
				flag3 = NUMEROZERO;

				for (k = NUMEROZERO; k < strlen (antoniovandre_letrasminusculas); k++)
					{
					if (((i == NUMEROZERO) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)) || ((contador > NUMEROZERO) && (posicoes_operadores [contador - 1] == i - NUMEROUM) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)) || ((i > NUMEROZERO) && (strt [i - 1] == antoniovandre_letrasminusculas [k]) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)))
						{
						flag3 = NUMEROUM;
						flag4 = NUMEROUM;
						}
					}

				if ((strt [i] == antoniovandre_operadores [j]) && flag3 == NUMEROZERO) posicoes_operadores [contador++] = i;
				}

		if (posicoes_operadores [NUMEROZERO] == -1) break;

		for (i = NUMEROZERO; i < TAMANHO_BUFFER_PHRASE; i++)
			if (posicoes_operadores [i] > NUMEROZERO)
				{
				flag = NUMEROZERO;
				flag2 = NUMEROZERO;

				for (j = NUMEROZERO; j < TAMANHO_BUFFER_PHRASE; j++)
					if (strt [posicoes_operadores [j]] == '^') flag2 = NUMEROUM;

				for (j = NUMEROZERO; j < TAMANHO_BUFFER_PHRASE; j++)
					if (((strt [posicoes_operadores [j]] == OPERADORMULTIPLICACAO) || (strt [posicoes_operadores [j]] == '/'))) flag = NUMEROUM;

				strcpy (strt2, STRINGVAZIA);

				if (i > NUMEROZERO)
					ponteiro = posicoes_operadores [i - 1] + NUMEROUM;
				else
					ponteiro = NUMEROZERO;

				ponteiroinicio = ponteiro;

				for (j = ponteiro; j < posicoes_operadores [i]; j++)
					strncat (strt2, & strt [j], NUMEROUM);

				strcpy (strt3, STRINGVAZIA);

				if (posicoes_operadores [i + 1] == -1)
					ponteiro = strlen (strt);
				else
					ponteiro = posicoes_operadores [i + 1];

				ponteirofim = ponteiro;

				for (j = posicoes_operadores [i] + NUMEROUM; j < ponteiro; j++)
					strncat (strt3, & strt [j], NUMEROUM);

				if ((! strcmp (strt2, STRINGVAZIA)) || (! strcmp (strt3, STRINGVAZIA)))
					return STRINGSAIDAERRO;

				strcpy (strtv1, antoniovandre_evalcelulafuncao (strt2));
				strcpy (strtv2, antoniovandre_evalcelulafuncao (strt3));

				if (! strcmp (strtv1, STRINGSAIDAERRO)) return STRINGSAIDAERRO;
				if (! strcmp (strtv2, STRINGSAIDAERRO)) return STRINGSAIDAERRO;

				if (! strcmp (strtv1, STRINGSAIDAERROOVER)) return STRINGSAIDAERROOVER;
				if (! strcmp (strtv2, STRINGSAIDAERROOVER)) return STRINGSAIDAERROOVER;

				valort = strtold (strtv1, & err);
				if (* err != NUMEROZERO) return STRINGSAIDAERRO;

				valort2 = strtold (strtv2, & err);
				if (* err != NUMEROZERO) return STRINGSAIDAERRO;

				if (strt [posicoes_operadores [i]] == '^')
					{
					if (valort < NUMEROZERO)
						{
						if (fmodl (fabsl (valort2), 2) == NUMEROZERO)
							valor = powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
						else if (fmodl (fabsl (valort2), 2) == NUMEROUM)
							valor = (-1) * powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
						else
							{
							contador2 = NUMEROUM; flag5 = NUMEROZERO;

							do
								{
								if ((fmodl ((contador2 / fabsl (valort2)), 2) > 1 + (-1) * APROXIMACAO2) && (fmodl ((contador2 / fabsl (valort2)), 2) < 1 + APROXIMACAO2))
									{
									if (fmodl (contador2, 2) == NUMEROZERO)
										valor = powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
									else
										valor = (-1) * powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);

									flag5 = NUMEROUM;
									}

								contador2++;
								} while ((contador2 <= MAXNUMERADORFRACOES) && (flag5 == NUMEROZERO));

							if (flag5 == NUMEROZERO) return STRINGSAIDAERRO;
							}
						}
					else
						valor = powl ((TIPONUMEROREAL) valort, (TIPONUMEROREAL) valort2);

					if (isnan (valor) || isinf (valor)) return STRINGSAIDAERRO;
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == OPERADORMULTIPLICACAO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort * (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '/') && (flag2 == NUMEROZERO))
					{
					if (valort2 == NUMEROZERO) return STRINGSAIDAERRO;

					valor = (TIPONUMEROREAL) valort / (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '+') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort + (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == OPERADORSUBTRACAO) && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort - (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '%') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = fmodl ((TIPONUMEROREAL) valort, (TIPONUMEROREAL) valort2);
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '@') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if ((valort != (long int) valort) || (valort < NUMEROZERO) || (valort2 != (long int) valort2) || (valort2 < NUMEROZERO) || (valort < valort2)) return STRINGSAIDAERRO;
					valor = (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) valort) / antoniovandre_fatorial ((unsigned long int) (valort - valort2));
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '#') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if ((valort != (long int) valort) || (valort < NUMEROZERO) || (valort2 != (long int) valort2) || (valort2 < NUMEROZERO) || (valort < valort2)) return STRINGSAIDAERRO;
					valor = (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) valort) / (antoniovandre_fatorial ((unsigned long int) (valort - valort2)) * antoniovandre_fatorial ((unsigned long int) (valort2)));
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '$') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if (valort2 != (int) valort2) return STRINGSAIDAERRO;
					valor = roundl ((TIPONUMEROREAL) valort / powl (10, valort2)) * powl (10, valort2);
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '>') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					(valort > valort2) ? (valor = valort) : (valor = valort2);
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '<') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					(valort < valort2) ? (valor = valort) : (valor = valort2);
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == ':') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = logl (valort) / logl (valort2);
					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}

				if ((strt [posicoes_operadores [i]] == '~') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if (fabsl (logl (valort) - logl (valort2)) < APROXIMACAO)
						valor = NUMEROUM;
					else
						valor = NUMEROZERO;

					if ((valor > VALOR_MAX) || (valor < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
					break;
					}
				}

		strcpy (strt4, STRINGVAZIA);

		for (i = NUMEROZERO; i < ponteiroinicio; i++)
			strncat (strt4, & strt [i], NUMEROUM);

		strcat (strt4, antoniovandre_numeroparastring (valor));

		for (i = ponteirofim; i < strlen (strt); i++)
			strncat (strt4, & strt [i], NUMEROUM);

		strcpy (strt, strt4);
		}

	return antoniovandre_evalcelulafuncao (strt);
	}

// Função eval.

char * antoniovandre_eval (char * str)
	{
	char str2 [TAMANHO_BUFFER_PHRASE];
	char str2t [TAMANHO_BUFFER_PHRASE];
	char str3 [TAMANHO_BUFFER_PHRASE];
	char str4 [TAMANHO_BUFFER_PHRASE];
	char str4t [TAMANHO_BUFFER_PHRASE];
	char str5 [TAMANHO_BUFFER_PHRASE];
	char str6 [TAMANHO_BUFFER_WORD];
	int inicio;
	int fim;
	int i;
	int j;
	int k;
	int l;
	int m;
	int flag;
	int flag2;
	int flag3;
	int flag4;
	int flag5;
	int contador;
	char tc;
	char tc2;

	strcpy (str2, STRINGVAZIA);
	strcpy (str2t, STRINGVAZIA);
	strcpy (str3, STRINGVAZIA);
	strcpy (str4, STRINGVAZIA);
	strcpy (str4t, STRINGVAZIA);
	strcpy (str5, STRINGVAZIA);
	strcpy (str6, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] != ESPACOBRANCO) strncat (str2, & str [i], NUMEROUM);

	if (! strcmp (str2, STRINGVAZIA)) return STRINGSAIDAERRO;

	for (i = NUMEROUM; i < strlen (str2); i++)
		{
		tc = str2 [i - 1];
		tc2 = str2 [i];

		for (j = NUMEROZERO; j < strlen (antoniovandre_operadores); j++)
			{
			if ((tc == OPERADORSUBTRACAO) && (tc2 == antoniovandre_operadores [j])) return STRINGSAIDAERRO;

			if ((tc == antoniovandre_operadores [j]) && (tc2 == OPERADORSUBTRACAO)) return STRINGSAIDAERRO;
			}

		flag = NUMEROZERO;

		for (k = NUMEROZERO; k < strlen (antoniovandre_operadoresespeciais); k++)
			if (tc == antoniovandre_operadoresespeciais [k])
				{
				flag = NUMEROUM;
				break;
				}

		if (flag == NUMEROUM) break;
		}

	contador = NUMEROZERO;

	for (i = NUMEROZERO; i < strlen (str2); i++)
		{
		flag2 = NUMEROZERO;

		if ((i >= NUMEROUM) && (str2 [i] == OPERADORSUBTRACAO) && (str2 [i - 1] == TOKENINICIOEVAL))  flag2 = NUMEROUM;

		if ((((i == NUMEROZERO) && (str2 [NUMEROZERO] == OPERADORSUBTRACAO)) || (flag2 == NUMEROUM)) && ! ((i > NUMEROUM) && (str2 [i] == '1') && (str2 [i - 1] == OPERADORSUBTRACAO) && (str2 [i - 2] == TOKENINICIOEVAL)))
			{
			j = i + NUMEROUM;

			if (str2 [i] == TOKENINICIOEVAL) contador++;
			if (str2 [i] == TOKENFIMEVAL) contador--;

			do
				{
				flag = NUMEROZERO;

				for (k = NUMEROZERO; k < strlen (antoniovandre_numeros); k++)
					for (l = NUMEROZERO; l < strlen (antoniovandre_letras); l++)
						if ((! ((flag2 == NUMEROUM) && (contador == -1))) && ((str2 [j] == antoniovandre_numeros [k]) || (str2 [j] == antoniovandre_letras [l]) || (str2 [j] == TOKENINICIOEVAL) || (str2 [j] == TOKENFIMEVAL))) flag = NUMEROUM;

				if (flag == NUMEROUM) j++;
				} while (flag == NUMEROUM);

			flag = NUMEROZERO; flag3 = NUMEROUM;

			for (k = NUMEROZERO; k < strlen (antoniovandre_operadoresprioritarios); k++)
				if (str2 [j] == antoniovandre_operadoresprioritarios [k])
					{
					flag = NUMEROUM;

					l = j - NUMEROUM;

					do
						{
						flag3 = NUMEROZERO;

						for (m = NUMEROZERO; m < strlen (antoniovandre_numeros); m++)
							if ((str2 [l] == antoniovandre_numeros [m]) && (str2 [l] != OPERADORSUBTRACAO))
								flag3 = NUMEROUM;

						l--;
						} while ((flag3 == NUMEROUM) && ((str2 [l] != TOKENINICIOEVAL) || (l > NUMEROZERO)));
					}

			if (flag == NUMEROUM)
				{
				strcpy (str2t, STRINGVAZIA);

				if (flag3 == NUMEROUM)
					{
					tc = TOKENINICIOEVAL;
					strncat (str2t, & tc, NUMEROUM);

					tc = TOKENINICIOEVAL;
					strncat (str2t, & tc, NUMEROUM);

					strcat (str2t, STRINGMENOSUM);

					tc = TOKENFIMEVAL;
					strncat (str2t, & tc, NUMEROUM);

					tc = OPERADORMULTIPLICACAO;
					strncat (str2t, & tc, NUMEROUM);

					for (k = NUMEROZERO; k <= l; k++)
						strncat (str2t, & str2 [k], NUMEROUM);

					for (k = i + NUMEROUM; k < j; k++)
						strncat (str2t, & str2 [k], NUMEROUM);

					tc = TOKENFIMEVAL;
					strncat (str2t, & tc, NUMEROUM);
					}
				else
					{
					for (k = NUMEROZERO; k < i; k++)
						strncat (str2t, & str2 [k], NUMEROUM);

					tc = TOKENINICIOEVAL;
					strncat (str2t, & tc, NUMEROUM);

					strcat (str2t, STRINGMENOSUM);

					tc = TOKENFIMEVAL;
					strncat (str2t, & tc, NUMEROUM);

					tc = OPERADORMULTIPLICACAO;
					strncat (str2t, & tc, NUMEROUM);

					for (k = i + NUMEROUM; k < j; k++)
						strncat (str2t, & str2 [k], NUMEROUM);
					}

				for (k = j; k < strlen (str2); k++)
					strncat (str2t, & str2 [k], NUMEROUM);

				strcpy (str2, str2t);
				}
			}
		}

	if (strcmp (str2t, STRINGVAZIA)) strcpy (str2, str2t);

	for (i = NUMEROUM; i < strlen (str2); i++)
		{
		flag = NUMEROZERO;
		flag2 = NUMEROZERO;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letrasminusculas); j++)
			if (str2 [i] == antoniovandre_letrasminusculas [j]) flag = NUMEROUM;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letrasmaiusculas); j++)
			if (str2 [i - 1] == antoniovandre_letrasmaiusculas [j]) flag2 = NUMEROUM;

		if ((flag == NUMEROUM) && (flag2 == NUMEROUM))
			{
			strcpy (str2t, STRINGVAZIA);

			for (j = NUMEROZERO; j < i; j++)
				strncat (str2t, & str2 [j], NUMEROUM);

			tc = OPERADORMULTIPLICACAO;
			strncat (str2t, & tc, NUMEROUM);

			for (j = i; j < strlen (str2); j++)
				strncat (str2t, & str2 [j], NUMEROUM);

			strcpy (str2, str2t);
			}
		}

	do
		{
		inicio = NUMEROZERO;
		fim = strlen (str2) - NUMEROUM;
		flag = NUMEROZERO;
		flag2 = NUMEROZERO;

		for (i = NUMEROZERO; i < strlen (str2); i++)
			{
			if (str2 [i] == TOKENINICIOEVAL)
				{
				inicio = i + NUMEROUM;
				flag = NUMEROUM;
				}

			if (str2 [i] == TOKENFIMEVAL)
				{
				fim = i - NUMEROUM;
				flag2 = NUMEROUM;
				break;
				}
			}

		strcpy (str3, STRINGVAZIA);

		if (flag == flag2)
			{
			k = inicio - 2;
			flag4 = NUMEROZERO;

			do
				{
				flag3 = NUMEROZERO;
				tc = str2 [k];

				for (j = NUMEROZERO; j < strlen (antoniovandre_numeros); j++)
					if (tc == antoniovandre_numeros [j])
						{
						flag3 = NUMEROUM;
						flag4 = NUMEROUM;
						}

				for (j = NUMEROZERO; j < strlen (antoniovandre_letrasmaiusculas); j++)
					if (tc == antoniovandre_letrasmaiusculas [j])
						{
						flag3 = NUMEROUM;
						flag4 = NUMEROUM;
						}

				k--;
				} while (flag3 == NUMEROUM);

			strcpy (str6, STRINGVAZIA);

			if (flag4 == NUMEROUM) for (j = k; j < inicio - NUMEROUM; j++) strncat (str6, & str2 [j], NUMEROUM);

			if (flag4 == NUMEROUM)
				for (i = NUMEROZERO; i < k; i++) strncat (str3, & str2 [i], NUMEROUM);
			else
				for (i = NUMEROZERO; i < inicio - NUMEROUM; i++) strncat (str3, & str2 [i], NUMEROUM);

			i = strlen (str6);

			tc = str6 [i - 1];

			if (strcmp (str6, STRINGVAZIA))
				{
				strcat (str3, str6);
				if (tc != OPERADORSUBTRACAO) strcat (str3, "*");
				}

			if (!strcmp (str3, "-")) strcpy (str3, "-1*");

			strcpy (str4, STRINGVAZIA);

			for (i = inicio; i <= fim; i++)
				strncat (str4, & str2 [i], NUMEROUM);

			i = NUMEROZERO; contador = NUMEROZERO; strcpy (str4t, STRINGVAZIA);

			do
				{
				if (str4 [i++] == OPERADORSUBTRACAO) contador++; else break;
				} while (i < strlen (str4));

			if (contador % 2 == NUMEROUM)
				{
				tc = OPERADORSUBTRACAO;
				strncat (str4t, & tc, NUMEROUM);
				}

			for (i = contador; i < strlen (str4); i++)
				strncat (str4t, & str4 [i], NUMEROUM);

			strcpy (str5, antoniovandre_evalcelula (str4t));

			if (! strcmp (str5, STRINGSAIDAERRO)) return STRINGSAIDAERRO;
			if (! strcmp (str5, STRINGSAIDAERROOVER)) return STRINGSAIDAERROOVER;

			for (i = NUMEROZERO; i < strlen (str5); i++)
				strncat (str3, & str5 [i], NUMEROUM);

			flag5 = NUMEROZERO;

			for (i = NUMEROZERO; i < strlen (antoniovandre_numeros); i++)
				for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++)
					if (((str2 [fim + 2] == antoniovandre_numeros [i] && (str2 [fim + 2] != OPERADORSUBTRACAO))) || (str2 [fim + 2] == antoniovandre_letras [j]))
						flag5 = NUMEROUM;

			if ((flag5 == NUMEROUM) && (flag == NUMEROUM))
				{
				tc = OPERADORMULTIPLICACAO;
				strncat (str3, & tc, NUMEROUM);
				}

			for (i = fim + 2; i < strlen (str2); i++)
				strncat (str3, & str2 [i], NUMEROUM);

			strcpy (str2, str3);
			}
		else
			return STRINGSAIDAERRO;
		} while (! ((flag == NUMEROZERO) && (flag2 == NUMEROZERO)));

	return antoniovandre_evalcelula (str2);
	}

// Derivada em um ponto.

char * antoniovandre_derivada (char * str, TIPONUMEROREAL ponto)
	{
	char str2 [TAMANHO_BUFFER_PHRASE];
	char str3 [TAMANHO_BUFFER_PHRASE];
	TIPONUMEROREAL valorsup;
	TIPONUMEROREAL valorinf;
	int i;
	char tc;
	char * err;

	if ((ponto > VALOR_MAX) || (ponto < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

	strcpy (str2, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] == VARIAVELDESUBSTITUICAO)
			{
			tc = TOKENINICIOEVAL;
			strncat (str2, & tc, NUMEROUM);

			strcat (str2, antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) ponto + (TIPONUMEROREAL) EPSILON)));

			tc = TOKENFIMEVAL;
			strncat (str2, & tc, NUMEROUM);
			}
		else
			strncat (str2, & str [i], NUMEROUM);

	valorsup = strtold (antoniovandre_eval (str2), & err);

	if (* err != NUMEROZERO) return STRINGSAIDAERRO;

	strcpy (str3, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] == VARIAVELDESUBSTITUICAO)
			{
			tc = TOKENINICIOEVAL;
			strncat (str3, & tc, NUMEROUM);

			strcat (str3, antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) ponto - (TIPONUMEROREAL) EPSILON)));

			tc = TOKENFIMEVAL;
			strncat (str3, & tc, NUMEROUM);
			}
		else
			strncat (str3, & str [i], NUMEROUM);

	valorinf = strtold (antoniovandre_eval (str3), & err);

	if (* err != NUMEROZERO) return STRINGSAIDAERRO;

	return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) valorsup - (TIPONUMEROREAL) valorinf) / (TIPONUMEROREAL) (2 * (TIPONUMEROREAL) EPSILON));
	}

// Integral definida.

char * antoniovandre_integraldefinida (char * str, TIPONUMEROREAL a, TIPONUMEROREAL b)
	{
	char str2 [TAMANHO_BUFFER_PHRASE];
	char str3 [TAMANHO_BUFFER_PHRASE];
	TIPONUMEROREAL integral = NUMEROZERO;
	TIPONUMEROREAL norma;
	TIPONUMEROREAL parcela;
	int i;
	int j;
	char tc;
	char * err;

	norma = (TIPONUMEROREAL) ( (TIPONUMEROREAL) b - (TIPONUMEROREAL) a) / (TIPONUMEROREAL) NUMEROPARTICOESSOMARIEMANN;

	for (j = NUMEROZERO; j < NUMEROPARTICOESSOMARIEMANN; j++)
		{
		strcpy (str2, STRINGVAZIA);

		for (i = NUMEROZERO; i < strlen (str); i++)
			if (str [i] == VARIAVELDESUBSTITUICAO)
				{
				tc = TOKENINICIOEVAL;
				strncat (str2, & tc, NUMEROUM);

				strcat (str2, antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) a + (TIPONUMEROREAL) j * (TIPONUMEROREAL) norma + (TIPONUMEROREAL) ((TIPONUMEROREAL) norma / 2))));

				tc = TOKENFIMEVAL;
				strncat (str2, & tc, NUMEROUM);
				}
			else
				strncat (str2, & str [i], NUMEROUM);

		strcpy (str3, antoniovandre_eval (str2));

		if (! strcmp (str3, STRINGSAIDAERROOVER)) return STRINGSAIDAERROOVER;

		parcela = strtold (str3, & err) * (TIPONUMEROREAL) norma;

		if (* err != NUMEROZERO) return STRINGSAIDAERRO;

		integral += (TIPONUMEROREAL) parcela;

		if ((integral > VALOR_MAX) || (integral < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
		}

	return antoniovandre_numeroparastring (integral);
	}

// Retorna a função mais próxima, dados os pontos e as funções em arquivos.

char * antoniovandre_funcaomaisproxima (char * arquivopontospath, char * arquivofuncoespath, int log)
	{
	FILE * arquivopontos;
	FILE * arquivofuncoes;
	char buffer [TAMANHO_BUFFER_PHRASE];
	char buffert [TAMANHO_BUFFER_PHRASE];
	char buffertt [TAMANHO_BUFFER_PHRASE];
	char bufferr [TAMANHO_BUFFER_PHRASE];
	char bufferr2 [TAMANHO_BUFFER_PHRASE];
	char buffer1 [TAMANHO_BUFFER_WORD];
	char buffer2 [TAMANHO_BUFFER_WORD];
	char antoniovandre_funcoes_buffer_char;
	char antoniovandre_pontos_buffer_char;
	unsigned long int totalitens = NUMEROZERO;
	unsigned long int totalpontos = NUMEROZERO;
	unsigned long int totalfuncoes = NUMEROZERO;
	unsigned long int contadoritens = NUMEROZERO;
	TIPONUMEROREAL m = VALOR_MAX;
	TIPONUMEROREAL m2 = VALOR_MAX;
	TIPONUMEROREAL mt;
	TIPONUMEROREAL mt2;
	TIPONUMEROREAL x;
	TIPONUMEROREAL y;
	TIPONUMEROREAL yt;
	int i = NUMEROUM;
	int flag;
	int flag2 = NUMEROZERO;
	int flag3;
	int flag4;
	char tc;
	char tc2;
	char * err;

	if (log == NUMEROUM)
		{
		printf ("Verificando validade dos arquivos... ");
		fflush (stdout);
		}

	arquivopontos = fopen (arquivopontospath, "r");

	if (arquivopontos == NULL)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		return STRINGSAIDAERRO;
		}

	fseek (arquivopontos, NUMEROZERO, SEEK_END);

	if (ftell (arquivopontos) > (unsigned long int) TAMANHO_MAX_ARQUIVO)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		fclose (arquivopontos);
		return STRINGSAIDAERROOVER;
		}

	fseek (arquivopontos, NUMEROZERO, SEEK_SET);

	arquivofuncoes = fopen (arquivofuncoespath, "r");

	if (arquivofuncoes == NULL)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		return STRINGSAIDAERRO;
		}

	fseek (arquivofuncoes, NUMEROZERO, SEEK_END);

	if (ftell (arquivofuncoes) > (unsigned long int) TAMANHO_MAX_ARQUIVO)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		fclose (arquivofuncoes);
		return STRINGSAIDAERROOVER;
		}

	fseek (arquivofuncoes, NUMEROZERO, SEEK_SET);

	if (log == NUMEROUM) printf("Ok.\n");

	if (log == NUMEROUM)
		{
		printf ("Reunindo metadados...  ");
		fflush (stdout);
		}

	do
		{
		antoniovandre_pontos_buffer_char = fgetc (arquivopontos);

		if ((antoniovandre_pontos_buffer_char == DELIMITADORSTRING2) || (antoniovandre_pontos_buffer_char == CARACTEREFIMLINHA) || (feof (arquivopontos))) totalpontos++;

		if (i++ % INTERVALOPROGRESSO2 == NUMEROZERO)
			{
			switch (tc)
				{
				case OPERADORSUBTRACAO:
					tc = '\\';
					break;
				case '\\':
					tc = '|';
					break;
				case '|':
					tc = '/';
					break;
				case '/':
					tc = OPERADORSUBTRACAO;
					break;
				default:
					tc = OPERADORSUBTRACAO;
				}

			printf ("\b%c", tc);
			fflush (stdout);

			i = NUMEROUM;
			}
		} while (! feof (arquivopontos));

	if ((antoniovandre_pontos_buffer_char == DELIMITADORSTRING2) || (antoniovandre_pontos_buffer_char == CARACTEREFIMLINHA)) totalpontos--;

	do
		{
		antoniovandre_funcoes_buffer_char = fgetc (arquivofuncoes);

		if ((antoniovandre_funcoes_buffer_char == DELIMITADORSTRING) || (antoniovandre_funcoes_buffer_char == CARACTEREFIMLINHA) || (feof (arquivofuncoes))) totalfuncoes++;

		if (i++ % INTERVALOPROGRESSO2 == NUMEROZERO)
			{
			switch (tc)
				{
				case OPERADORSUBTRACAO:
					tc = '\\';
					break;
				case '\\':
					tc = '|';
					break;
				case '|':
					tc = '/';
					break;
				case '/':
					tc = OPERADORSUBTRACAO;
					break;
				default:
					tc = OPERADORSUBTRACAO;
				}

			printf ("\b%c", tc);
			fflush (stdout);

			i = NUMEROUM;
			}
		} while (! feof (arquivofuncoes));

	if ((antoniovandre_funcoes_buffer_char == DELIMITADORSTRING) || (antoniovandre_funcoes_buffer_char == CARACTEREFIMLINHA)) totalfuncoes--;

	totalitens = totalpontos * totalfuncoes;

	if (log == NUMEROUM) printf("\bOk.\n");

	fseek (arquivopontos, NUMEROZERO, SEEK_SET);
	fseek (arquivofuncoes, NUMEROZERO, SEEK_SET);

	strcpy (bufferr, STRINGVAZIA);

	do
		{
		if (flag2 == NUMEROUM)
			{
			strcpy (buffer, STRINGVAZIA);

			do
				{
				antoniovandre_funcoes_buffer_char = fgetc (arquivofuncoes);

				if ((! feof (arquivofuncoes)) && (antoniovandre_funcoes_buffer_char != DELIMITADORSTRING) && (antoniovandre_funcoes_buffer_char != ESPACOBRANCO) && (antoniovandre_funcoes_buffer_char != CARACTEREFIMLINHA))
					strncat (buffer, & antoniovandre_funcoes_buffer_char, NUMEROUM);
				} while (((! feof (arquivofuncoes))) && (antoniovandre_funcoes_buffer_char != DELIMITADORSTRING) && (antoniovandre_funcoes_buffer_char != CARACTEREFIMLINHA));

			fseek (arquivopontos, NUMEROZERO, SEEK_SET);
			flag = NUMEROZERO;
			flag2 = NUMEROZERO;
			flag3 = NUMEROZERO;
			flag4 = NUMEROZERO;
			mt = NUMEROZERO;
			mt2 = NUMEROZERO;
			}

		while (flag2 == NUMEROZERO)
			{
			if (feof (arquivopontos))
				{
				flag2 = NUMEROUM;
				break;
				}

			antoniovandre_pontos_buffer_char = fgetc (arquivopontos);

			if (antoniovandre_pontos_buffer_char != ESPACOBRANCO)
				{
				if (antoniovandre_pontos_buffer_char == DELIMITADORSTRING)
					{
					strcpy (buffer2, STRINGVAZIA);
					flag = NUMEROUM;
					continue;
					}

				if ((antoniovandre_pontos_buffer_char == DELIMITADORSTRING2) || (antoniovandre_pontos_buffer_char == CARACTEREFIMLINHA))
					{
					flag = NUMEROZERO;
					flag3 = NUMEROZERO;
					break;
					}

				if (flag == NUMEROZERO)
					{
					if (flag3 == NUMEROZERO) strcpy (buffer1, STRINGVAZIA);
					strncat (buffer1, & antoniovandre_pontos_buffer_char, NUMEROUM);
					flag3 = NUMEROUM;
					}
				else
					strncat (buffer2, & antoniovandre_pontos_buffer_char, NUMEROUM);
				}
			}

		if (flag2 == NUMEROZERO)
			{
			x = strtold (buffer1, & err);

			if (* err != NUMEROZERO) return STRINGSAIDAERRO;
			if ((x > VALOR_MAX) || (x < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;

			y = strtold (buffer2, & err);

			if ((y > VALOR_MAX) || (y < (-1) * VALOR_MAX)) return STRINGSAIDAERROOVER;
			if (* err != NUMEROZERO) return STRINGSAIDAERRO;

			strcpy (buffert, STRINGVAZIA);

			for (i = NUMEROZERO; i < strlen (buffer); i++)
				{
				tc = buffer [i];

				if (tc == VARIAVELPADRAO)
					{
					tc2 = TOKENINICIOEVAL;
					strncat (buffert, & tc2, NUMEROUM);

					strcat (buffert, antoniovandre_numeroparastring ((TIPONUMEROREAL) x));

					tc2 = TOKENFIMEVAL;
					strncat (buffert, & tc2, NUMEROUM);
					}
				else
					strncat (buffert, & tc, NUMEROUM);
				}

			strcpy (buffertt, antoniovandre_eval (buffert));

			if (! strcmp (buffertt, STRINGSAIDAERROOVER)) return STRINGSAIDAERROOVER;

			yt = strtold (buffertt, & err);
			}

		contadoritens++;

		if (flag2 == NUMEROZERO)
			{
			if ((flag4 == NUMEROZERO) && (* err == NUMEROZERO))
				{
				mt += (y - yt);
				mt2 += fabsl (y - yt);
				}
			else
				{
				if (! strcmp (bufferr, buffer)) strcpy (bufferr, bufferr2);
				flag4 = NUMEROUM;
				}
			}

		if ((flag4 == NUMEROZERO) && (flag2 == NUMEROUM) && (fabsl (mt) <= fabsl (m)))
			{
			m = mt;

			if (mt2 < m2)
				{
				m2 = mt2;
				strcpy (bufferr2, bufferr);
				strcpy (bufferr, buffer);
				}
			}

		if ((log == NUMEROUM) && ((contadoritens == NUMEROUM) || (contadoritens == totalitens - totalpontos) || (contadoritens % INTERVALOPROGRESSO == NUMEROZERO)))
			{
			printf ("\r%.13f%% concluído.", (double) (100.0 * (double) ((double) (contadoritens) / (double) (totalitens - (double) totalpontos))));

			fflush (stdout);
			}

		} while ((! feof (arquivofuncoes)) || (flag2 == NUMEROZERO));

	if (log == NUMEROUM) {printf ("\n"); fflush (stdout);}

	fclose (arquivopontos);
	fclose (arquivofuncoes);

	return bufferr;
	}

// Rízes de uma função. Por aproximação.

char * antoniovandre_raizesfuncao (char * funcao, char * mins, char * maxs, TIPONUMEROREAL step, int log)
	{
	TIPONUMEROREAL min;
	TIPONUMEROREAL max;
	TIPONUMEROREAL x;
	TIPONUMEROREAL y;
	TIPONUMEROREAL xi;
	TIPONUMEROREAL xf;
	TIPONUMEROREAL xr;
	TIPONUMEROREAL xrt = VALOR_MAX_2;
	char mins2 [TAMANHO_BUFFER_WORD];
	char maxs2 [TAMANHO_BUFFER_WORD];
	char str [TAMANHO_BUFFER_PHRASE];
	char strt [TAMANHO_BUFFER_PHRASE];
	char strr [TAMANHO_BUFFER_PHRASE];
	int i;
	int flag;
	int flag2;
	int flag3;
	int flag4;
	unsigned long int contador = NUMEROZERO;
	unsigned long int contador2 = NUMEROZERO;
	int contador3 = NUMEROZERO;
	char tc;
	char * err;

	strcpy (strr, STRINGVAZIA);

	strcpy (mins2, antoniovandre_eval (mins));
	strcpy (maxs2, antoniovandre_eval (maxs));

	if ((! strcmp (mins2, STRINGSAIDAERRO)) || (! strcmp (maxs2, STRINGSAIDAERRO)))
		return STRINGSAIDAERRO;

	if ((! strcmp (mins2, STRINGSAIDAERROOVER)) || (! strcmp (maxs2, STRINGSAIDAERROOVER)))
		return STRINGSAIDAERROOVER;

	min = strtold (mins2, & err);
	max = strtold (maxs2, & err);

	x = min;
	flag = NUMEROZERO;
	flag2 = NUMEROZERO;
	flag3 = NUMEROZERO;
	flag4 = NUMEROZERO;

	do
		{
		if ((log == NUMEROUM) && (contador % INTERVALOPROGRESSO4 == NUMEROZERO)) {printf ("\r%.5f%% concluído.", (double) 100 * fabs ((x - min) / (max - min + step))); fflush (stdout);}

		if (x > max + step) flag4 = NUMEROUM;

		strcpy (str, STRINGVAZIA);

		for (i = NUMEROZERO; i < strlen (funcao); i++)
			{
			if (funcao [i] == VARIAVELPADRAO)
				{
				tc = TOKENINICIOEVAL;
				strncat (str, & tc, NUMEROUM);
				strcat (str, antoniovandre_numeroparastring (x));
				tc = TOKENFIMEVAL;
				strncat (str, & tc, NUMEROUM);
				flag = NUMEROUM;
				}
			else
				strncat (str, & funcao [i], NUMEROUM);
			}

		strcpy (strt, antoniovandre_eval (str));

		if ((! strcmp (strt, STRINGSAIDAERRO)) || (! strcmp (strt, STRINGSAIDAERROOVER)))
			{
			x += EPSILON;
			contador++;
			continue;
			}

		y = strtold (strt, & err);

		if (* err == NUMEROZERO)
			{
			if ((fabsl (y) <= step / 20) && (flag4 == NUMEROZERO))
				{
				if ((flag == NUMEROZERO) || ((TIPONUMEROREAL) contador2 > (0.1 / step)))
					{
					if (log == NUMEROUM) {printf ("\r100.00000%% concluído.\nInfinitas raízes encontradas. Trata-se de uma possibilidade:\n"); fflush (stdout);}

					return "inf";
					}

				if (flag2 == NUMEROZERO) xi = x; else {flag2 = NUMEROUM; xf = x;}

				contador2++;
				flag3 = NUMEROUM;
				}
			else
				{
				if (flag3 == NUMEROUM)
					{
					if (flag2 == NUMEROZERO)
						xr = xi;
					else
						xr = (xi + xf) / 2;

					if (fabsl (xr - xrt) > step)
						{
						if (xr > max) xr = max;

						if (! strcmp (strr, STRINGVAZIA))
							strcpy (strr, antoniovandre_numeroparastring (xr));
						else
							{
							tc = DELIMITADORSTRING;
							strncat (strr, & tc, NUMEROUM);
							strcat (strr, antoniovandre_numeroparastring (xr));
							}

						contador3++;
						}

					xrt = xr;
					contador2 = NUMEROZERO;
					}

				flag3 = NUMEROZERO; flag2 = NUMEROZERO;
				}
			}

		contador++;
		x += step;
		} while (flag4 == NUMEROZERO);

	if (log == NUMEROUM)
		{
		printf ("\r100.00000%% concluído.\n");

		if (contador3 > 1)
			printf ("Tratam-se de aproximações:\n");
		else if (contador3 == 1)
			printf ("Trata-se de uma aproximação:\n");
		else
			printf ("Nenhuma raiz encontrada. Trata-se de uma possibilidade.\n");

		fflush (stdout);
		}

	return (strr);
	}

// Produto de números complexos.

NUMEROCOMPLEXO antoniovandre_produtocomplexo (NUMEROCOMPLEXO * numeroscomplexos, int numeroargumentos)
	{
	NUMEROCOMPLEXO result;
	TIPONUMEROREAL a;
	TIPONUMEROREAL b;
	int i;

	a = NUMEROUM;
	b = NUMEROZERO;

	for (i = NUMEROZERO; i < numeroargumentos; i++)
		{
		result.real = a * numeroscomplexos [i].real - b * numeroscomplexos [i].img;

		result.img = b * numeroscomplexos [i].real + a * numeroscomplexos [i].img;

		a = result.real; b = result.img;
		}

	return result;
	}

// Número dimensões de uma matriz. Segundo argumento NUMEROZERO para o número de linhas e NUMEROUM para o de colunas.

// Por conveniência, a última linha deve ser um ponteiro NULL, e a última coluna de cada linha deve ser MARCADORREAL.

int antoniovandre_dimensoesmatriz (TIPONUMEROREAL ** matriz, int lc)
	{
	int i = NUMEROZERO;

	switch (lc)
		{
		case NUMEROZERO:
			while (matriz [i] != NULL) i++;
			return i;
			break;
		case NUMEROUM:
			while (matriz [NUMEROZERO] [i] != MARCADORREAL) i++;
			return i;
			break;
		default:
			return NUMEROZERO;
		}
	}

// Remover linha e coluna de uma matriz.

// Lembrar-se de dar "free" na matriz-resultado após o uso.

TIPONUMEROREAL ** antoniovandre_removerlinhacoluna (TIPONUMEROREAL ** matriz, int i, int j)
	{
	TIPONUMEROREAL ** matrizt;
	int dl = antoniovandre_dimensoesmatriz (matriz, NUMEROZERO);
	int dc = antoniovandre_dimensoesmatriz (matriz, NUMEROUM);
	int shiftl;
	int shiftc;
	int k;
	int l;

	matrizt = (TIPONUMEROREAL **) malloc ((dl) * sizeof (TIPONUMEROREAL *));
	matrizt [dl - NUMEROUM] = NULL;

	for (k = NUMEROZERO; k < dl - NUMEROUM; k++)
		{
		matrizt [k] = (TIPONUMEROREAL *) malloc ((dc) * sizeof (TIPONUMEROREAL));
		matrizt [k] [dc - NUMEROUM] = MARCADORREAL;
		}

	for (k = NUMEROZERO; k < dl - NUMEROUM; k++)
		for (l = NUMEROZERO; l < dc - NUMEROUM; l++)
			{
			if (k >= i - NUMEROUM)
				shiftl = NUMEROUM;
			else
				shiftl = NUMEROZERO;


			if (l >= j - NUMEROUM)
				shiftc = NUMEROUM;
			else
				shiftc = NUMEROZERO;

			matrizt [k] [l] = matriz [k + shiftl] [l + shiftc];
			}

	return matrizt;
	}

// Determinante de uma matriz.

TIPONUMEROREAL antoniovandre_determinante (TIPONUMEROREAL ** matriz)
	{
	TIPONUMEROREAL det = NUMEROZERO;
	TIPONUMEROREAL ** matrizt;
	int i;
	int j;

	if (antoniovandre_dimensoesmatriz (matriz, NUMEROZERO) != antoniovandre_dimensoesmatriz (matriz, NUMEROUM))
		return NAN;

	if (antoniovandre_dimensoesmatriz (matriz, NUMEROZERO) == NUMEROUM)
		return (matriz [NUMEROZERO] [NUMEROZERO]);
	else
		for (i = NUMEROUM; i <= antoniovandre_dimensoesmatriz (matriz, NUMEROZERO); i++)
			{
			matrizt = antoniovandre_removerlinhacoluna (matriz, i, NUMEROUM);

			det += (powl (-1, i + NUMEROUM) * matriz [i - NUMEROUM] [NUMEROZERO] * antoniovandre_determinante (matrizt));

			for (j = NUMEROZERO; j < antoniovandre_dimensoesmatriz (matriz, NUMEROZERO); j++)
				free (matrizt [j]);

			free (matrizt);

			if ((det > VALOR_MAX) || (det < (-1) * VALOR_MAX)) return INFINITY;
			}

	return det;
	}
