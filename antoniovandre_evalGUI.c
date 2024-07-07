// Proprietário: Antonio Vandré Pedrosa Furtunato Gomes (bit.ly/antoniovandre_legadoontologico).

// Projeto Mathematical Ramblings (mathematicalramblings.blogspot.com).

// Biblioteca C de funções e constantes pertencentes a Antonio Vandré Pedrosa Furtunato Gomes, versão de distribuição para antoniovandre_eval GUI.

// Licença de uso: Atribuição-NãoComercial-CompartilhaIgual (CC BY-NC-SA).

// Última atualização: 07-07-2024. Não considerando alterações em variáveis globais.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define __USE_GNU
#include <math.h>
#include <float.h>

#include "antoniovandre_constantes.c"
#include "antoniovandre_extra.c"

#define VERSION 20240707
#define MENSAGEMNAOCOMPILADOR "Software não compilado em razão do compilador não ser compatível."
#define TAMANHO_BUFFER_SMALL 100 // Para pequenos buffers.
#define TAMANHO_BUFFER_WORD 1024 // Para strings pequenas.
#define TAMANHO_BUFFER_PHRASE 16384 // Para strings grandes.
#define TAMANHO_BUFFER_TEXT 500000000 // Para conteúdos de arquivos.
#define VALOR_MAX 1000000000 // A fim de evitar erros de saída.
#define VALOR_MAX_2 10000000 // Valor máximo. Segunda opção.
#define VALOR_MAX_3 50 // Valor máximo. Terceira opção.
#define MARCADORREAL VALOR_MAX + 1 // Útil para delimitar memórias alocadas.
#define TAMANHO_MAX_ARQUIVO 1000000000000 // A fim de evitar erros de saída.
#define MARGEMFORMATACAOREAIS 1 // Para formatação de outputs reais.
#define NUMEROSTRINGPERSONAL VERDADE // Método pessoal de conversao de números para strings.
#define NUMEROZERO 0
#define NUMEROUM 1
#define NUMEROMENOSUM -1
#define OPERADORSUBTRACAO '-'
#define OPERADORMULTIPLICACAO '*'
#define CHARUM '1'
#define STRINGMENOSUM "-1"
#define VARIAVELPADRAO 'X'
#define ESPACOBRANCO ' '
#define STRINGVAZIA ""
#define DELIMITADORSTRING ',' // Deve ser um char e diferente de DELIMITADORSTRING2, de DELIMITADORSTRING3 e DELIMITADORSTRINGARGUMENTOS.
#define DELIMITADORSTRING2 ';' // Deve ser um char e diferente de DELIMITADORSTRING, de DELIMITADORSTRING3 e DELIMITADORSTRINGARGUMENTOS.
#define DELIMITADORSTRING3 '\\' // Deve ser um char e diferente de DELIMITADORSTRING, de DELIMITADORSTRING2 e DELIMITADORSTRINGARGUMENTOS.
#define DELIMITADORSTRINGARGUMENTOS '|' // Para separar os argumentos de funcões com mais de um parâmetro. Deve ser um char, diferente de DELIMITADORSTRING, de DELIMITADORSTRING2 e DELIMITADORSTRING3.
#define CARACTEREFIMLINHA '\n' // Caractere de fim de linha.
#define STRINGSAIDAERRO "Erro de saida de uma string."
#define STRINGSAIDAERROOVER "Erro de saida de uma string por over."
#define MENSAGEM_ERRO_OVER "Um dos números atingiu o limite máximo."
#define TENTATIVASLOGICAS 4 // Podem ser necessárias mais de uma verificação lógica em alguns trechos.
#define TOKENINICIOEVAL '('
#define TOKENFIMEVAL ')'
#define EPSILON 0.001 // Para funções de Cálculo Diferencial.
#define VARIAVELDESUBSTITUICAO VARIAVELPADRAO // Deve ser uma letra não presente nos nomes das funções ou constantes.
#define VARIAVELDESUBSTITUICAO2 'Y' // Deve ser uma letra não presente nos nomes das funções ou constantes.
#define VARIAVELDESUBSTITUICAO3 'U' // Deve ser uma letra não presente nos nomes das funções ou constantes.
#define VARIAVELDESUBSTITUICAO4 'V' // Deve ser uma letra não presente nos nomes das funções ou constantes.
#define NUMEROPARTICOESSOMARIEMANN 100 // Para Cálculo Integral.
#define VERDADE NUMEROUM
#define FALSIDADE NUMEROZERO
#define INTERVALOPROGRESSO 100 // Para não haver flood quando mostrando progressos de processos.
#define INTERVALOPROGRESSO2 500000 // Para não haver flood quando mostrando progressos de processos, para processos mais rápidos.
#define INTERVALOPROGRESSO3 10 // Para não haver flood quando mostrando progressos de processos, para processos mais lentos.
#define INTERVALOPROGRESSO4 200 // Para não haver flood quando mostrando progressos de processos, quarta opção.
#define APROXIMACAO 0.0000000001 // Para verificação de aproximação numérica.
#define APROXIMACAO2 0.000001 // Para verificação de aproximação numérica. Segunda opção.
#define APROXIMACAO3 0.005 // Para verificação de aproximação numérica. Terceira opção.
#define APROXIMACAO4 0.05 // Para verificação de aproximação numérica. Quarta opção.
#define APROXIMACAO5 0.0005 // Para verificação de aproximação numérica. Quinta opção.
#define APROXIMACAO6 0.005 // Para verificação de aproximação numérica. Sexta opção.
#define MAXNUMERADORFRACOES 100000 // Para a conversão de números em frações. Útil para, dentre outras coisas, calcular potências de bases negativas.
#define MINPRECISAO 4 // A fim de garantir retornos corretos de algumas funções.
#define MAXPRECISAO 17 // A fim de evitar erros de saída.

typedef long double TIPONUMEROREAL;

typedef struct {char * token; TIPONUMEROREAL valor; char * comentario;} tokenfuncaoconstante; // Estrutura para funções e constantes.

typedef struct {TIPONUMEROREAL real; TIPONUMEROREAL img;} NUMEROCOMPLEXO; // Estrutura número complexo.

#define ARQUIVO_MATHSOBRE "/usr/share/antoniovandre_sobre.txt"

#define ESCREVER_ESTATISTICAS FALSIDADE

#define ARQUIVO_PRECISAO_REAL "/usr/share/antoniovandre_precisao_real.txt"

// Definições internas.

#ifdef __GNUC__

#if __GNUC__ > 6

#define MACROALOCACAODINAMICA VERDADE

#define DECLARACAO_antoniovandre_precisao_real_buffer char * antoniovandre_precisao_real_buffer = (char *) malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_estatisticas_buffer char * antoniovandre_estatisticas_buffer = (char *) malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_buffer char * buffer = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_funcoesconstantes tokenfuncaoconstante * funcoesconstantes = (tokenfuncaoconstante *) malloc (sizeof (tokenfuncaoconstante) * TAMANHO_BUFFER_SMALL);

#define ALOCACAO_funcoesconstantestoken funcoesconstantes [i].token = (char *) malloc (TAMANHO_BUFFER_WORD);

#define ALOCACAO_funcoesconstantescomentario funcoesconstantes [i].comentario = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelulafuncao_buffer char * buffer = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_evalcelulafuncao_str2 char * str2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt char strt [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt2 char * strt2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt3 char * strt3 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strtv1 char * strtv1 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strtv2 char * strtv2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt4 char * strt4 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str2 char str2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str2t char * str2t = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str3 char * str3 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str4 char * str4 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str4t char * str4t = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str5 char * str5 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str6 char * str6 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer char * buffer = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffert char * buffert = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffertt char * buffertt = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_bufferr2 char * bufferr2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer1 char * buffer1 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer2 char * buffer2 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_strf_antoniovandre_removerletras char * strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_strf_antoniovandre_removernumeros char * strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#else

#define MACROALOCACAODINAMICA FALSIDADE

#define DECLARACAO_antoniovandre_precisao_real_buffer char antoniovandre_precisao_real_buffer [TAMANHO_BUFFER_WORD];

#define DECLARACAO_antoniovandre_estatisticas_buffer char antoniovandre_estatisticas_buffer [TAMANHO_BUFFER_WORD];

#define DECLARACAO_buffer char buffer [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_funcoesconstantes tokenfuncaoconstante funcoesconstantes [TAMANHO_BUFFER_SMALL];

#define ALOCACAO_funcoesconstantestoken ;

#define ALOCACAO_funcoesconstantescomentario ;

#define DECLARACAO_antoniovandre_evalcelulafuncao_buffer char buffer [TAMANHO_BUFFER_WORD];

#define DECLARACAO_antoniovandre_evalcelulafuncao_str2 char str2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt char strt [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt2 char strt2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt3 char strt3 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strtv1 char strtv1 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strtv2 char strtv2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt4 char strt4 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str2 char str2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str2t char str2t [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str3 char str3 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str4 char str4 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str4t char str4t [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str5 char str5 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str6 char str6 [TAMANHO_BUFFER_WORD];

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer char buffer [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffert char buffert [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffertt char buffertt [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_funcaomaisproxima_bufferr2 char bufferr2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer1 char buffer1 [TAMANHO_BUFFER_WORD];

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer2 char buffer2 [TAMANHO_BUFFER_WORD];

#define DECLARACAO_strf_antoniovandre_removerletras char strf [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_strf_antoniovandre_removernumeros char strf [TAMANHO_BUFFER_PHRASE];

#endif

#else

#define MACROALOCACAODINAMICA VERDADE

#define DECLARACAO_antoniovandre_precisao_real_buffer char * antoniovandre_precisao_real_buffer = (char *) malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_estatisticas_buffer char * antoniovandre_estatisticas_buffer = (char *) malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_buffer char * buffer = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_funcoesconstantes tokenfuncaoconstante * funcoesconstantes = (tokenfuncaoconstante *) malloc (sizeof (tokenfuncaoconstante) * TAMANHO_BUFFER_SMALL);

#define ALOCACAO_funcoesconstantestoken funcoesconstantes [i].token = (char *) malloc (TAMANHO_BUFFER_WORD);

#define ALOCACAO_funcoesconstantescomentario funcoesconstantes [i].comentario = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelulafuncao_buffer char * buffer = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_evalcelulafuncao_str2 char * str2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt char strt [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_evalcelula_strt2 char * strt2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt3 char * strt3 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strtv1 char * strtv1 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strtv2 char * strtv2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_evalcelula_strt4 char * strt4 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str2 char str2 [TAMANHO_BUFFER_PHRASE];

#define DECLARACAO_antoniovandre_eval_str2t char * str2t = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str3 char * str3 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str4 char * str4 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str4t char * str4t = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str5 char * str5 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_eval_str6 char * str6 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer char * buffer = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffert char * buffert = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffertt char * buffertt = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_bufferr2 char * bufferr2 = malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer1 char * buffer1 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_antoniovandre_funcaomaisproxima_buffer2 char * buffer2 = malloc (TAMANHO_BUFFER_WORD);

#define DECLARACAO_strf_antoniovandre_removerletras char * strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#define DECLARACAO_strf_antoniovandre_removernumeros char * strf = (char *) malloc (TAMANHO_BUFFER_PHRASE);

#endif

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

// Copiando strings de forma segura.

int antoniovandre_copiarstring (char * dest, char * orig)
	{
	unsigned long int tam = TAMANHO_BUFFER_PHRASE;
	unsigned long int i;
	char buffer;

	for (i = NUMEROZERO; i < tam; i++)
		{
		if (dest[i] == '\0') break;
		dest[i] = (char) NULL;
		}

	for (i = NUMEROZERO; i < tam; i++)
		{
		buffer = orig[i];
		dest[i] = buffer;

		if (buffer == '\0') break;
		}

	return NUMEROZERO;
	}

// Comparar strings com free nos argumentos.

int antoniovandre_compararstringsfree (char * str1, char * str2)
	{
	int tam1 = strlen (str1);
	int tam2 = strlen (str2);
	int i;
	int resultado;

	if (tam1 != tam2) return  NUMEROMENOSUM;

	for (i = NUMEROZERO; i < tam1; i++)
		if (str1[i] != str2 [i])
			{
			resultado = FALSIDADE;
			break;
			}

	resultado = VERDADE;

	if (MACROALOCACAODINAMICA)
		{
		free (str1);
		free (str2);
		}

	return resultado;
	}

// Concatenando strings de forma segura.

int antoniovandre_concatenarstring (char * dest, char * orig)
	{
	unsigned long int tam = TAMANHO_BUFFER_PHRASE;
	unsigned long int inicio = NUMEROZERO;
	unsigned long int i;
	char buffer;

	for (i = NUMEROZERO; i < tam; i++)
		{
		if (dest[i] == '\0') break;
		inicio++;
		}

	for (i = NUMEROZERO; i < tam; i++)
		{
		buffer = orig[i];
		dest[inicio + i] = buffer;

		if (buffer == '\0') break;
		}

	return NUMEROZERO;
	}

// Função de output do sobre/about dos softwares matemáticos.

int antoniovandre_mathsobre ()
	{
	FILE * filesobre;
	char antoniovandre_sobre_buffer_char;

	filesobre = fopen (ARQUIVO_MATHSOBRE, "r");

	if (filesobre == NULL)
		{
		printf ("Erro ao abrir arquivo sobre.\n");
		return  NUMEROMENOSUM;
		}

	while (! feof (filesobre))
		{
		antoniovandre_sobre_buffer_char = fgetc (filesobre);
		if (! feof (filesobre)) printf ("%c", antoniovandre_sobre_buffer_char);
		}

	fclose (filesobre);
	}

// Função de salvar as estatísticas de uso dos softwares matemáticos.

int antoniovandre_salvarmathestatisticas (char * cabecalho)
	{
	if (ESCREVER_ESTATISTICAS)
		{
		FILE * filemathestatisticas;

		DECLARACAO_antoniovandre_estatisticas_buffer

		unsigned long int antoniovandre_estatisticas_contador;
		unsigned long int cursor;
		unsigned long int tam = NUMEROZERO;
		int i;

		DECLARACAO_buffer

		int flag = NUMEROZERO;
		int flag2 = NUMEROZERO;
		int flag3;
		char tc;
		char tc2;

		antoniovandre_copiarstring (antoniovandre_estatisticas_buffer, STRINGVAZIA);

		filemathestatisticas = fopen (ARQUIVO_MATH_ESTATISTICAS, "r+");

		if (filemathestatisticas == NULL)
			{
			filemathestatisticas = fopen (ARQUIVO_MATH_ESTATISTICAS, "w");

			if (filemathestatisticas == NULL)
				{
				printf ("Erro ao abrir ou criar arquivo de estatísticas.\n");
				return  NUMEROMENOSUM;
				}

			flag2 = NUMEROUM;
			}

		while ((! feof (filemathestatisticas)) && flag2 == NUMEROZERO)
			{
			fscanf (filemathestatisticas, "%s", antoniovandre_estatisticas_buffer);

			if (! strcmp (antoniovandre_estatisticas_buffer, cabecalho))
				{
				fseek (filemathestatisticas, sizeof (char), SEEK_CUR);
				cursor = ftell (filemathestatisticas);
				antoniovandre_copiarstring (antoniovandre_estatisticas_buffer, STRINGVAZIA);

				while (VERDADE)
					{
					flag3 = NUMEROZERO;

					fread (& tc, sizeof (char), 1, filemathestatisticas);

					for (i = NUMEROZERO; i < strlen (antoniovandre_numeros); i++)
						if (antoniovandre_numeros[i] == tc) flag3 = NUMEROUM;

					if (flag3 == NUMEROUM)
						strncpy (antoniovandre_estatisticas_buffer, & tc, NUMEROUM);
					else
						break;
					}
				
				antoniovandre_estatisticas_contador = atoi (antoniovandre_estatisticas_buffer);
				antoniovandre_estatisticas_contador++;

				fseek (filemathestatisticas, (NUMEROMENOSUM) * (sizeof (char)), SEEK_CUR);

				antoniovandre_copiarstring (buffer, STRINGVAZIA);

				while (! feof (filemathestatisticas))
					{
					fread (& tc, sizeof (char), 1, filemathestatisticas);
					buffer[tam++] = tc;
					}

				fseek (filemathestatisticas, cursor, SEEK_SET);

				char * temp = (char *) malloc (TAMANHO_BUFFER_WORD);
				sprintf (temp, "%ld", antoniovandre_estatisticas_contador);
				fwrite (temp, 1, strlen (temp), filemathestatisticas);
				free (temp);

				fwrite (buffer , 1, --tam, filemathestatisticas);

				flag = NUMEROUM;
				}
			}

		if (flag == NUMEROZERO)
			{
			char cabecalho_buffer [strlen (cabecalho)];

			antoniovandre_copiarstring (cabecalho_buffer, cabecalho);

			tc = ESPACOBRANCO;
			strncat (cabecalho_buffer, & tc, NUMEROUM);

			tc = CHARUM;
			strncat (cabecalho_buffer, & tc, NUMEROUM);

			tc = CARACTEREFIMLINHA;
			strncat (cabecalho_buffer, & tc, NUMEROUM);

			fprintf (filemathestatisticas, "%s", cabecalho_buffer);
			}

		if (MACROALOCACAODINAMICA)
			{
			free (buffer);
			free (antoniovandre_estatisticas_buffer);
			}

		fclose (filemathestatisticas);
		}
	else
		return NUMEROZERO;
	}

// Função que retorna a precisão real (numérica) para floats.

int antoniovandre_precisao_real ()
	{
	FILE * fileprecisaoreal;

	DECLARACAO_antoniovandre_precisao_real_buffer

	int antoniovandre_precisao_real_valor;

	antoniovandre_copiarstring (antoniovandre_precisao_real_buffer, STRINGVAZIA);

	fileprecisaoreal = fopen (ARQUIVO_PRECISAO_REAL, "r");

	if (fileprecisaoreal == NULL)
		{
		printf ("Erro ao abrir arquivo de precisão real.\n");
		return  NUMEROMENOSUM;
		}

	fscanf (fileprecisaoreal, "%s", antoniovandre_precisao_real_buffer);

	antoniovandre_precisao_real_valor = atoi (antoniovandre_precisao_real_buffer);

	if (antoniovandre_precisao_real_valor == NUMEROZERO)
		{
		printf ("Erro ao ler arquivo de precisão real.\n");
		return  NUMEROMENOSUM;
		}

	if (MACROALOCACAODINAMICA) free (antoniovandre_precisao_real_buffer);

	fclose (fileprecisaoreal);

	if (antoniovandre_precisao_real_valor < MINPRECISAO)
		return MINPRECISAO;
	else if (antoniovandre_precisao_real_valor > MAXPRECISAO)
		return MAXPRECISAO;
	else
		return antoniovandre_precisao_real_valor;
	}

// Remover letras de uma string.

char * antoniovandre_removerletras (char * str)
	{
	int tam1 = strlen (str);
	int tam2 = strlen (antoniovandre_letras);

	DECLARACAO_strf_antoniovandre_removerletras
	
	int i;
	int j;
	int flag;
	int contador = NUMEROZERO;

	antoniovandre_copiarstring (strf, STRINGVAZIA);

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

	DECLARACAO_strf_antoniovandre_removernumeros

	int i;
	int j;
	int flag;

	antoniovandre_copiarstring (strf, STRINGVAZIA);

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
				if (str [i - NUMEROUM] == antoniovandre_letras [j]) return VERDADE;
		}

	for (i = NUMEROUM; i < strlen (str); i++) if (str [i] == OPERADORSUBTRACAO) return VERDADE;

	for (i = NUMEROZERO; i < strlen (str); i++)
		{if (str [i] == '.') contador++; if (contador == 2) return VERDADE;}

	if (antoniovandre_compararstringsfree (antoniovandre_removerletras (antoniovandre_removernumeros (str)), STRINGVAZIA))
		return VERDADE;
	else
		return FALSIDADE;
	}

// Parte numérica de um monômio.

TIPONUMEROREAL antoniovandre_partenumericamonomio (char * str)
	{
	char * err;

	if (antoniovandre_monomio (str))
		{
		if (! antoniovandre_compararstringsfree (antoniovandre_removerletras (str), STRINGVAZIA))
			return NUMEROUM;
		else if (! antoniovandre_compararstringsfree (antoniovandre_removerletras (str), "-") && strlen (str) != NUMEROUM)
			return  NUMEROMENOSUM;
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

char * antoniovandre_numeroparastring (TIPONUMEROREAL numero, int precisao)
	{
	char * strr = (char *) malloc (TAMANHO_BUFFER_WORD);
	int parteinteira = (int) (log10 (fabsl (numero)) + NUMEROUM);
	int potencia_min;
	int potencia_max = (int) log10 (fabsl(numero)) + NUMEROUM;
	TIPONUMEROREAL fator;
	int algarismo;
	int i;

	if (numero != VERSION) if ((numero > VALOR_MAX) || (numero < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

	if (precisao > MAXPRECISAO) precisao = MAXPRECISAO;

	if (precisao < MINPRECISAO) precisao = MINPRECISAO;

	if (numero == NUMEROZERO)
		{
		int i;
		char tc = '0';

		antoniovandre_copiarstring (strr, STRINGVAZIA);
		strcat (strr, "0.");

		for (i = NUMEROUM; i < precisao; i++) strncat (strr, &tc, NUMEROUM);
		}
	else
		{
		if (NUMEROSTRINGPERSONAL)
			{
			potencia_min = (precisao - parteinteira) * NUMEROMENOSUM;

			if (potencia_max < NUMEROUM) potencia_max = NUMEROUM;

			fator = powl (10, -(potencia_max - NUMEROUM));

			antoniovandre_copiarstring (strr, STRINGVAZIA);

			if (numero < NUMEROZERO)
				{
				numero *= NUMEROMENOSUM;
				antoniovandre_concatenarstring (strr, "-");
				}

			for (i = potencia_max; i > potencia_min; i--)
				{
				if (i == NUMEROZERO)
					antoniovandre_concatenarstring (strr, ".");

				algarismo = (int) fmodl ((numero * fator), 10);

				fator *= 10;

				switch (algarismo)
					{
					case NUMEROZERO:
						antoniovandre_concatenarstring (strr, "0");
						break;
					case NUMEROUM:
						antoniovandre_concatenarstring (strr, "1");
						break;
					case 2:
						antoniovandre_concatenarstring (strr, "2");
						break;
					case 3:
						antoniovandre_concatenarstring (strr, "3");
						break;
					case 4:
						antoniovandre_concatenarstring (strr, "4");
						break;
					case 5:
						antoniovandre_concatenarstring (strr, "5");
						break;
					case 6:
						antoniovandre_concatenarstring (strr, "6");
						break;
					case 7:
						antoniovandre_concatenarstring (strr, "7");
						break;
					case 8:
						antoniovandre_concatenarstring (strr, "8");
						break;
					case 9:
						antoniovandre_concatenarstring (strr, "9");
						break;
					default:
						antoniovandre_concatenarstring (strr, "0");
					}
				}
			}
		else
			{
			if (parteinteira > NUMEROZERO)
				sprintf (strr, "%.*Lf", precisao - parteinteira, numero);
			else
				sprintf (strr, "%.*Lf", precisao, numero);
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

		if (contador1 != contador2) return  NUMEROMENOSUM;
		}

	if (tam1 != tam2) return  NUMEROMENOSUM;

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

	antoniovandre_copiarstring (strf, STRINGVAZIA);

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

	int precisao = antoniovandre_precisao_real ();

	for (i = NUMEROZERO; i < strlen (args); i++) if (args [i] == DELIMITADORSTRING) nargs++;

	char * strlit [nargs];
	TIPONUMEROREAL coefs [nargs];

	antoniovandre_copiarstring (strf, STRINGVAZIA);
	antoniovandre_copiarstring (parteliteral, STRINGVAZIA);
	antoniovandre_copiarstring (strt, STRINGVAZIA);

	for (i = NUMEROZERO; i < nargs; i++)
		{
		strlit [i] = (char *) malloc (TAMANHO_BUFFER_WORD);
		antoniovandre_copiarstring (strlit [i], STRINGVAZIA);
		}

	for (i = NUMEROZERO; i < nargs; i++)
		{
		flag = NUMEROZERO; j = NUMEROZERO;

		while ((flag == NUMEROZERO) && j++ < TENTATIVASLOGICAS)
			if (antoniovandre_monomio (antoniovandre_nthsubstr (args, i))) flag = NUMEROUM;

		if (flag == NUMEROUM)
			{
			antoniovandre_copiarstring (parteliteral, antoniovandre_parteliteralmonomio (antoniovandre_nthsubstr (args, i)));

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
				antoniovandre_copiarstring (strlit [contador], parteliteral);
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
			char * temp = antoniovandre_numeroparastring (coefs [i], precisao);
			antoniovandre_copiarstring (strt, temp);
			free (temp);

			if (! strcmp (strt, STRINGSAIDAERROOVER)) return (STRINGSAIDAERROOVER);

			if (i == NUMEROZERO)
				{
				char * temp = antoniovandre_numeroparastring (coefs [i], precisao);
				memmove (strf, strt, strlen (temp));
				free (temp);
				}
			else
				antoniovandre_concatenarstring (strf, strt);

			antoniovandre_concatenarstring (strf, strlit [i]);
			if (i < contador - NUMEROUM) strf [strlen (strf)] = ESPACOBRANCO;

			flag = NUMEROUM;
			}

	for (i = NUMEROZERO; i < nargs; i++) free (strlit [i]);

	if (flag == NUMEROUM)
		return (strf);
	else
		return (antoniovandre_numeroparastring (0, precisao));
	}

// Valor numérico de um polinômio.

char * antoniovandre_valornumericopolinomio (char * args)
	{
	int nargs = NUMEROUM;
	int indice_inicio = NUMEROMENOSUM;
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

	int precisao = antoniovandre_precisao_real ();

	antoniovandre_copiarstring (strt, STRINGVAZIA);
	antoniovandre_copiarstring (strt2, STRINGVAZIA);
	antoniovandre_copiarstring (str, STRINGVAZIA);
	antoniovandre_copiarstring (str2, STRINGVAZIA);
	antoniovandre_copiarstring (str3, STRINGVAZIA);
	antoniovandre_copiarstring (str4, STRINGVAZIA);
	antoniovandre_copiarstring (str5, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (args); i++)
		{
		if (args [i] == DELIMITADORSTRING) nargs++;
		if ((args [i] == '=') && (indice_inicio == NUMEROMENOSUM)) indice_inicio = nargs - NUMEROUM;
		}

	if (indice_inicio != -1)
		{
		if (indice_inicio == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

		for (i = indice_inicio; i < nargs; i++)
			{
			flag = NUMEROZERO; contador = NUMEROZERO;

			while ((flag == NUMEROZERO) && (contador++ < TENTATIVASLOGICAS))
				{
				antoniovandre_copiarstring (strt, antoniovandre_nthsubstr (args, i));

				if (strt [NUMEROUM] == '=') flag = NUMEROUM;
				}

			if (flag == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			flag = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++)
				if (strt [NUMEROZERO] == antoniovandre_letras [j]) flag = NUMEROUM;

			if (flag == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			antoniovandre_copiarstring (strt2, STRINGVAZIA);

			for (j = 2; j < strlen (strt); j++) strncat (strt2, & strt [j], NUMEROUM);

			fator = strtold (strt2, & err);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			if ((fator > VALOR_MAX) || (fator < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

			for (j = NUMEROZERO; j < indice_inicio; j++)
				{
				flag = NUMEROZERO; contador = NUMEROZERO;

				while ((flag == NUMEROZERO) && (contador++ < TENTATIVASLOGICAS))
					{
					if (flag2 == NUMEROZERO)
						antoniovandre_copiarstring (str, antoniovandre_nthsubstr (args, j));
					else
						antoniovandre_copiarstring (str, antoniovandre_nthsubstr (str5, j));

					if (antoniovandre_monomio (str)) flag = NUMEROUM;
					}

				if (flag == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

				coef = antoniovandre_partenumericamonomio (str);

				if ((coef > VALOR_MAX) || (coef < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

				antoniovandre_copiarstring (str2, antoniovandre_parteliteralmonomio (str));

				antoniovandre_copiarstring (str3, STRINGVAZIA);

				for (k = NUMEROZERO; k < strlen (str2); k++)
					if (strt [NUMEROZERO] == str2 [k])
						coef *= fator;
					else
						strncat (str3, & str2 [k], NUMEROUM);

				if ((coef > VALOR_MAX) || (coef < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

				char temps [TAMANHO_BUFFER_WORD];

				char * temp = antoniovandre_numeroparastring (coef, precisao);
				antoniovandre_copiarstring (temps, temp);
				free (temp);

				antoniovandre_concatenarstring (str4, temps);
				antoniovandre_concatenarstring (str4, str3);
				strncat (str4, &c, NUMEROUM);
				}

			str4 [strlen (str4) - NUMEROUM] = '\0';
			antoniovandre_copiarstring (str5, str4);
			antoniovandre_copiarstring (str4, STRINGVAZIA);

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
	char * strt = (char *) malloc (fim - inicio + 2);
	int i;

	antoniovandre_copiarstring (strt, STRINGVAZIA);

	for (i = inicio; (i <= fim) && (i - inicio < strlen (str)); i++)
		strncat (strt, & str [i], NUMEROUM);

	return strt;
	}

// Formatar reais.

char * antoniovandre_formatarreal (char * result, int precisao)
	{
	int i;
	int j;
	char * err;
	TIPONUMEROREAL valor;

	valor = strtold (result, & err);
	free (result);

	for (i = NUMEROZERO; i < precisao; i++)
		{
		if (fabsl ((floorl (valor * powl (10, i))) - valor * powl(10, i)) < powl (10, -precisao + NUMEROUM) * powl(10, i))
			return antoniovandre_numeroparastring (floorl (valor * powl (10, i)) / powl (10, i), precisao);

		for (j = NUMEROUM; j <= MARGEMFORMATACAOREAIS; j++)
			{
			if (fabsl ((floorl (valor * powl (10, i) + j)) - valor * powl(10, i)) < powl (10, -precisao + NUMEROUM) * powl(10, i))
				return antoniovandre_numeroparastring (floorl (valor * powl (10, i) + j) / powl (10, i), precisao);

			if (fabsl ((floorl (valor * powl (10, i) - j)) - valor * powl(10, i)) < powl (10, -precisao + NUMEROUM) * powl(10, i))
				return antoniovandre_numeroparastring (floorl (valor * powl (10, i) - j) / powl (10, i), precisao);
			}

		if (i == precisao - NUMEROUM) return antoniovandre_numeroparastring (valor, precisao);
		}
	}

// Função eval célula função. Os nomes das funções devem conter apenas letras minúsculas. Os nomes das constantes devem conter apenas letras maiúsculas. No escopo, as implementações das funções devem estar dispostas de modo a que os nomes das anteriores não sejam substrings das posteriores.

char * antoniovandre_evalcelulafuncao (char * str, int precisao)
	{
	DECLARACAO_funcoesconstantes

	int tamanhotokenfuncaoconstante;
	int tamanhotokenfuncaoconstantemax = NUMEROZERO;
	int tokenid = NUMEROMENOSUM;
	int tokeninicio;
	TIPONUMEROREAL resultado;
	TIPONUMEROREAL argumento;
	TIPONUMEROREAL coeficiente;

	DECLARACAO_antoniovandre_evalcelulafuncao_buffer

	DECLARACAO_antoniovandre_evalcelulafuncao_str2

	int len = strlen (str);
	int i;
	int j;
	int flag;
	int flagargumentos = NUMEROZERO;
	char tc;
	char * err;
	char * err2;

	for (i = NUMEROZERO; i < len; i++)
		if (str [i] == DELIMITADORSTRINGARGUMENTOS)
			flagargumentos = NUMEROUM;

	for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
		{
		ALOCACAO_funcoesconstantestoken
		ALOCACAO_funcoesconstantescomentario

		antoniovandre_copiarstring (funcoesconstantes [i].token, STRINGVAZIA);
		funcoesconstantes [i].valor = (TIPONUMEROREAL) NUMEROZERO;
		antoniovandre_copiarstring (funcoesconstantes [i].comentario, STRINGVAZIA);
		}

	antoniovandre_copiarstring (funcoesconstantes [NUMEROZERO].token, "arccossec");
	antoniovandre_copiarstring (funcoesconstantes [NUMEROZERO].comentario, "Função arco-cossecante.");

	antoniovandre_copiarstring (funcoesconstantes [NUMEROUM].token, "arcsec");
	antoniovandre_copiarstring (funcoesconstantes [NUMEROUM].comentario, "Função arco-secante.");

	antoniovandre_copiarstring (funcoesconstantes [2].token, "arccotg");
	antoniovandre_copiarstring (funcoesconstantes [2].comentario, "Função arco-cotangente.");

	antoniovandre_copiarstring (funcoesconstantes [3].token, "arctg");
	antoniovandre_copiarstring (funcoesconstantes [3].comentario, "Função arco-tangente.");

	antoniovandre_copiarstring (funcoesconstantes [4].token, "arccos");
	antoniovandre_copiarstring (funcoesconstantes [4].comentario, "Função arco-cosseno.");

	antoniovandre_copiarstring (funcoesconstantes [5].token, "arcsen");
	antoniovandre_copiarstring (funcoesconstantes [5].comentario, "Função arco-seno.");

	antoniovandre_copiarstring (funcoesconstantes [6].token, "cossec");
	antoniovandre_copiarstring (funcoesconstantes [6].comentario, "Função cossecante.");

	antoniovandre_copiarstring (funcoesconstantes [7].token, "sec");
	antoniovandre_copiarstring (funcoesconstantes [7].comentario, "Função secante.");

	antoniovandre_copiarstring (funcoesconstantes [8].token, "senh");
	antoniovandre_copiarstring (funcoesconstantes [8].comentario, "Função seno hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [9].token, "cosh");
	antoniovandre_copiarstring (funcoesconstantes [9].comentario, "Função cosseno hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [10].token, "cotg");
	antoniovandre_copiarstring (funcoesconstantes [10].comentario, "Função cotangente.");

	antoniovandre_copiarstring (funcoesconstantes [11].token, "tg");
	antoniovandre_copiarstring (funcoesconstantes [11].comentario, "Função tangente.");

	antoniovandre_copiarstring (funcoesconstantes [12].token, "logdois");
	antoniovandre_copiarstring (funcoesconstantes [12].comentario, "Função logaritmo na base 2.");

	antoniovandre_copiarstring (funcoesconstantes [13].token, "logdez");
	antoniovandre_copiarstring (funcoesconstantes [13].comentario, "Função logaritmo na base 10.");

	antoniovandre_copiarstring (funcoesconstantes [14].token, "ln");
	antoniovandre_copiarstring (funcoesconstantes [14].comentario, "Função logaritmo natural.");

	antoniovandre_copiarstring (funcoesconstantes [15].token, "PI");
	funcoesconstantes [15].valor = (TIPONUMEROREAL) M_PI;
	antoniovandre_copiarstring (funcoesconstantes [15].comentario, "Constante pi, razão entre o comprimento e o diâmetro de uma circunferência.");

	antoniovandre_copiarstring (funcoesconstantes [16].token, "E");
	funcoesconstantes [16].valor = (TIPONUMEROREAL) M_E;
	antoniovandre_copiarstring (funcoesconstantes [16].comentario, "Constante e, base do logaritmo natural.");

	antoniovandre_copiarstring (funcoesconstantes [17].token, FISICA_C_SI);
	funcoesconstantes [17].valor = (TIPONUMEROREAL) FISICA_C_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [17].comentario, FISICA_C_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [18].token, FISICA_G_SI);
	funcoesconstantes [18].valor = (TIPONUMEROREAL) FISICA_G_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [18].comentario, FISICA_G_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [19].token, FISICA_QE_SI);
	funcoesconstantes [19].valor = (TIPONUMEROREAL) FISICA_QE_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [19].comentario, FISICA_QE_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [20].token, FISICA_H_SI);
	funcoesconstantes [20].valor = (TIPONUMEROREAL) FISICA_H_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [20].comentario, FISICA_H_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [21].token, FISICA_HH_SI);
	funcoesconstantes [21].valor = (TIPONUMEROREAL) FISICA_HH_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [21].comentario, FISICA_HH_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [22].token, FISICA_K_SI);
	funcoesconstantes [22].valor = (TIPONUMEROREAL) FISICA_K_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [22].comentario, FISICA_K_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [23].token, "sen");
	antoniovandre_copiarstring (funcoesconstantes [23].comentario, "Função seno.");

	antoniovandre_copiarstring (funcoesconstantes [24].token, "cos");
	antoniovandre_copiarstring (funcoesconstantes [24].comentario, "Função cosseno.");

	antoniovandre_copiarstring (funcoesconstantes [25].token, "tgh");
	antoniovandre_copiarstring (funcoesconstantes [25].comentario, "Função tangente hiperbólica.");

	antoniovandre_copiarstring (funcoesconstantes [26].token, "cotgh");
	antoniovandre_copiarstring (funcoesconstantes [26].comentario, "Função cotangente hiperbólica.");

	antoniovandre_copiarstring (funcoesconstantes [27].token, "sech");
	antoniovandre_copiarstring (funcoesconstantes [27].comentario, "Função secante hiperbólica.");

	antoniovandre_copiarstring (funcoesconstantes [28].token, "cossech");
	antoniovandre_copiarstring (funcoesconstantes [28].comentario, "Função cossecante hiperbólica.");

	antoniovandre_copiarstring (funcoesconstantes [29].token, "arcsenh");
	antoniovandre_copiarstring (funcoesconstantes [29].comentario, "Função arco-seno hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [30].token, "arccosh");
	antoniovandre_copiarstring (funcoesconstantes [30].comentario, "Função arco-cosseno hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [31].token, "arctgh");
	antoniovandre_copiarstring (funcoesconstantes [31].comentario, "Função arco-tangente hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [32].token, "arccotgh");
	antoniovandre_copiarstring (funcoesconstantes [32].comentario, "Função arco-cotangente hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [33].token, "arcsech");
	antoniovandre_copiarstring (funcoesconstantes [33].comentario, "Função arco-secante hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [34].token, "arccossech");
	antoniovandre_copiarstring (funcoesconstantes [34].comentario, "Função arco-cossecante hiperbólico.");

	antoniovandre_copiarstring (funcoesconstantes [35].token, "fatorial");
	antoniovandre_copiarstring (funcoesconstantes [35].comentario, "Função fatorial.");

	antoniovandre_copiarstring (funcoesconstantes [36].token, FISICA_ME_SI);
	funcoesconstantes [36].valor = (TIPONUMEROREAL) FISICA_ME_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [36].comentario, FISICA_ME_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [37].token, FISICA_MP_SI);
	funcoesconstantes [37].valor = (TIPONUMEROREAL) FISICA_MP_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [37].comentario, FISICA_MP_SI_COMENTARIO);

	/* Comentando para maior compatibilidade.

	antoniovandre_copiarstring (funcoesconstantes [38].token, FISICA_A_SI);
	funcoesconstantes [38].valor = (TIPONUMEROREAL) FISICA_A_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [38].comentario, FISICA_A_SI_COMENTARIO);

	*/

	antoniovandre_copiarstring (funcoesconstantes [39].token, "modulo");
	antoniovandre_copiarstring (funcoesconstantes [39].comentario, "Função módulo.");

	antoniovandre_copiarstring (funcoesconstantes [40].token, "radparagrau");
	antoniovandre_copiarstring (funcoesconstantes [40].comentario, "Função para converter radianos para graus.");

	antoniovandre_copiarstring (funcoesconstantes [41].token, "radparagrado");
	antoniovandre_copiarstring (funcoesconstantes [41].comentario, "Função para converter radianos para grados.");

	antoniovandre_copiarstring (funcoesconstantes [42].token, "graupararad");
	antoniovandre_copiarstring (funcoesconstantes [42].comentario, "Função para converter graus para radianos.");

	antoniovandre_copiarstring (funcoesconstantes [43].token, "grauparagrado");
	antoniovandre_copiarstring (funcoesconstantes [43].comentario, "Função para converter graus para grados.");

	antoniovandre_copiarstring (funcoesconstantes [44].token, "gradopararad");
	antoniovandre_copiarstring (funcoesconstantes [44].comentario, "Função para converter grados para radianos.");

	antoniovandre_copiarstring (funcoesconstantes [45].token, "gradopargrau");
	antoniovandre_copiarstring (funcoesconstantes [45].comentario, "Função para converter grados para graus.");

	antoniovandre_copiarstring (funcoesconstantes [46].token, "kelvinparacelsius");
	antoniovandre_copiarstring (funcoesconstantes [46].comentario, "Função para converter temperatura em Kelvin para Celsius.");

	antoniovandre_copiarstring (funcoesconstantes [47].token, "kelvinparafahrenheit");
	antoniovandre_copiarstring (funcoesconstantes [47].comentario, "Função para converter temperatura em Kelvin para Fahrenheit.");

	antoniovandre_copiarstring (funcoesconstantes [48].token, "celsiusparakelvin");
	antoniovandre_copiarstring (funcoesconstantes [48].comentario, "Função para converter temperatura em Celsius para Kelvin.");

	antoniovandre_copiarstring (funcoesconstantes [49].token, "celsiusparafahrenheit");
	antoniovandre_copiarstring (funcoesconstantes [49].comentario, "Função para converter temperatura em Celsius para Fahrenheit.");

	antoniovandre_copiarstring (funcoesconstantes [50].token, "fahrenheitparakelvin");
	antoniovandre_copiarstring (funcoesconstantes [50].comentario, "Função para converter temperatura em Fahrenheit para Kelvin.");

	antoniovandre_copiarstring (funcoesconstantes [51].token, "fahrenheitparacelsius");
	antoniovandre_copiarstring (funcoesconstantes [51].comentario, "Função para converter temperatura em Fahrenheit para Celsius.");

	antoniovandre_copiarstring (funcoesconstantes [52].token, FISICA_AM_SI);
	funcoesconstantes [52].valor = (TIPONUMEROREAL) FISICA_AM_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [52].comentario, FISICA_AM_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [53].token, FISICA_KE_SI);
	funcoesconstantes [53].valor = (TIPONUMEROREAL) FISICA_KE_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [53].comentario, FISICA_KE_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [54].token, MATEMATICA_P);
	funcoesconstantes [54].valor = (TIPONUMEROREAL) MATEMATICA_P_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [54].comentario, MATEMATICA_P_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [55].token, MATEMATICA_C);
	funcoesconstantes [55].valor = (TIPONUMEROREAL) MATEMATICA_C_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [55].comentario, MATEMATICA_C_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [56].token, MATEMATICA_EMC);
	funcoesconstantes [56].valor = (TIPONUMEROREAL) MATEMATICA_EMC_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [56].comentario, MATEMATICA_EMC_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [57].token, MATEMATICA_T);
	funcoesconstantes [57].valor = (TIPONUMEROREAL) MATEMATICA_T_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [57].comentario, MATEMATICA_T_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [58].token, FISICA_R_SI);
	funcoesconstantes [58].valor = (TIPONUMEROREAL) FISICA_R_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [58].comentario, FISICA_R_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [59].token, "piso");
	antoniovandre_copiarstring (funcoesconstantes [59].comentario, "Função piso.");

	antoniovandre_copiarstring (funcoesconstantes [60].token, "teto");
	antoniovandre_copiarstring (funcoesconstantes [60].comentario, "Função teto.");

	antoniovandre_copiarstring (funcoesconstantes [61].token, FISICA_SB_SI);
	funcoesconstantes [61].valor = (TIPONUMEROREAL) FISICA_SB_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [61].comentario, FISICA_SB_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [62].token, FISICA_PM_SI);
	funcoesconstantes [62].valor = (TIPONUMEROREAL) FISICA_PM_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [62].comentario, FISICA_PM_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [63].token, FISICA_PE_SI);
	funcoesconstantes [63].valor = (TIPONUMEROREAL) FISICA_PE_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [63].comentario, FISICA_PE_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [64].token, FISICA_B_SI);
	funcoesconstantes [64].valor = (TIPONUMEROREAL) FISICA_B_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [64].comentario, FISICA_B_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [65].token, FISICA_MN_SI);
	funcoesconstantes [65].valor = (TIPONUMEROREAL) FISICA_MN_SI_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [65].comentario, FISICA_MN_SI_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [66].token, MATEMATICA_FA);
	funcoesconstantes [66].valor = (TIPONUMEROREAL) MATEMATICA_FA_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [66].comentario, MATEMATICA_FA_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [67].token, MATEMATICA_FS);
	funcoesconstantes [67].valor = (TIPONUMEROREAL) MATEMATICA_FS_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [67].comentario, MATEMATICA_FS_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [68].token, MATEMATICA_CO);
	funcoesconstantes [68].valor = (TIPONUMEROREAL) MATEMATICA_CO_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [68].comentario, MATEMATICA_CO_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [69].token, MATEMATICA_K);
	funcoesconstantes [69].valor = (TIPONUMEROREAL) MATEMATICA_K_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [69].comentario, MATEMATICA_K_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [70].token, MATEMATICA_GK);
	funcoesconstantes [70].valor = (TIPONUMEROREAL) MATEMATICA_GK_VALOR;
	antoniovandre_copiarstring (funcoesconstantes [70].comentario, MATEMATICA_GK_COMENTARIO);

	antoniovandre_copiarstring (funcoesconstantes [71].token, "system");
	antoniovandre_copiarstring (funcoesconstantes [71].comentario, "Valores do sistema.");

	antoniovandre_copiarstring (funcoesconstantes [72].token, "seigual");
	antoniovandre_copiarstring (funcoesconstantes [72].comentario, "Função condicional se igual.");

	antoniovandre_copiarstring (funcoesconstantes [73].token, "sediferente");
	antoniovandre_copiarstring (funcoesconstantes [73].comentario, "Função condicional se diferente.");

	antoniovandre_copiarstring (funcoesconstantes [74].token, "semaiorouigual");
	antoniovandre_copiarstring (funcoesconstantes [74].comentario, "Função condicional se maior ou igual.");

	antoniovandre_copiarstring (funcoesconstantes [75].token, "semenorouigual");
	antoniovandre_copiarstring (funcoesconstantes [75].comentario, "Função condicional se menor ou igual.");

	antoniovandre_copiarstring (funcoesconstantes [76].token, "semaior");
	antoniovandre_copiarstring (funcoesconstantes [76].comentario, "Função condicional se maior.");

	antoniovandre_copiarstring (funcoesconstantes [77].token, "semenor");
	antoniovandre_copiarstring (funcoesconstantes [77].comentario, "Função condicional se menor.");

	antoniovandre_copiarstring (funcoesconstantes [78].token, "seerroover");
	antoniovandre_copiarstring (funcoesconstantes [78].comentario, "Função condicional se ocorrer um erro over.");

	antoniovandre_copiarstring (funcoesconstantes [79].token, "seerro");
	antoniovandre_copiarstring (funcoesconstantes [79].comentario, "Função condicional se ocorrer um erro de saída inválida.");

	antoniovandre_copiarstring (funcoesconstantes [80].token, "pitagoras");
	antoniovandre_copiarstring (funcoesconstantes [80].comentario, "Função que retorna a hipotenusa dados os catetos.");

	antoniovandre_copiarstring (funcoesconstantes [81].token, "diagonalparalelepipedo");
	antoniovandre_copiarstring (funcoesconstantes [81].comentario, "Função que retorna a diagonal de um paralelepípedo dadas as arestas.");

	antoniovandre_copiarstring (funcoesconstantes [82].token, "pat");
	antoniovandre_copiarstring (funcoesconstantes [82].comentario, "Função que retorna o n-ésimo termo de uma PA.");

	antoniovandre_copiarstring (funcoesconstantes [83].token, "par");
	antoniovandre_copiarstring (funcoesconstantes [83].comentario, "Função que retorna a razão de uma PA.");

	antoniovandre_copiarstring (funcoesconstantes [84].token, "pasr");
	antoniovandre_copiarstring (funcoesconstantes [84].comentario, "Função que retorna a soma dos termos de uma PA tomando a razão.");

	antoniovandre_copiarstring (funcoesconstantes [85].token, "pas");
	antoniovandre_copiarstring (funcoesconstantes [85].comentario, "Função que retorna a soma dos termos de uma PA.");

	antoniovandre_copiarstring (funcoesconstantes [86].token, "pgt");
	antoniovandre_copiarstring (funcoesconstantes [86].comentario, "Função que retorna o n-ésimo termo de uma PG.");

	antoniovandre_copiarstring (funcoesconstantes [87].token, "pgr");
	antoniovandre_copiarstring (funcoesconstantes [87].comentario, "Função que retorna a razão de uma PG.");

	antoniovandre_copiarstring (funcoesconstantes [88].token, "pgsr");
	antoniovandre_copiarstring (funcoesconstantes [88].comentario, "Função que retorna a soma dos termos de uma PG tomando a razão.");

	antoniovandre_copiarstring (funcoesconstantes [89].token, "pgs");
	antoniovandre_copiarstring (funcoesconstantes [89].comentario, "Função que retorna a soma dos termos de uma PG.");

	antoniovandre_copiarstring (funcoesconstantes [90].token, "mmc");
	antoniovandre_copiarstring (funcoesconstantes [90].comentario, "Mínimo múltiplo comum.");

	antoniovandre_copiarstring (funcoesconstantes [91].token, "mdc");
	antoniovandre_copiarstring (funcoesconstantes [91].comentario, "Máximo divisor comum.");

	for (i = NUMEROZERO; i < len; i++)
		for (j = NUMEROZERO; j < TAMANHO_BUFFER_SMALL; j++)
			{
			char * temp = antoniovandre_substring (str, i, i + strlen (funcoesconstantes [j].token) - NUMEROUM);

			if (! strcmp (temp, funcoesconstantes [j].token))
				{
				tamanhotokenfuncaoconstante = strlen (funcoesconstantes [j].token);

				if (tamanhotokenfuncaoconstantemax < tamanhotokenfuncaoconstante)
					{
					tamanhotokenfuncaoconstantemax = tamanhotokenfuncaoconstante;
					tokenid = j;
					tokeninicio = i;
					}
				}

			free (temp);
			}

	if (tokenid != NUMEROMENOSUM)
		if (funcoesconstantes [tokenid].valor != NUMEROZERO)
			{
			coeficiente = NUMEROUM;

			if (tokeninicio > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, tokeninicio - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			char * temp = antoniovandre_substring (str, tokeninicio + tamanhotokenfuncaoconstantemax, len - NUMEROUM);

			if (strcmp (temp, STRINGVAZIA)) {free (temp); {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}}

			free (temp);

			argumento = funcoesconstantes [tokenid].valor;

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "seigual"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 == argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 10);

		if (! strcmp (temp, "sediferente"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 11, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 != argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 13);

		if (! strcmp (temp, "semaiorouigual"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 14, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 >= argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 13);

		if (! strcmp (temp, "semenorouigual"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 14, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 <= argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "semaior"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 > argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "semenor"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			int posicoes [3];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 3) posicoes [contador] = j; contador++;}

			if (contador != 3) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, posicoes [2] - NUMEROUM);

			char * argumentos3 = antoniovandre_substring (temp, posicoes[2] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);
			TIPONUMEROREAL argumento3 = strtold (argumentos3, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);
			free (argumentos3);

			argumento = (argumento0 < argumento1 ? argumento2 : argumento3);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 9);

		if (! strcmp (temp, "seerroover"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 10, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			if (! strcmp (argumentos0, STRINGSAIDAERROOVER))
				{free (temp); free (argumentos0); free (argumentos2);temp = antoniovandre_evalcelulafuncao (argumentos1, precisao); TIPONUMEROREAL result = strtold (temp, & err); free (temp); return antoniovandre_numeroparastring (coeficiente * result, precisao);}
			else
				{free (temp); free (argumentos0); free (argumentos1);temp = antoniovandre_evalcelulafuncao (argumentos2, precisao); TIPONUMEROREAL result = strtold (temp, & err); free (temp); return antoniovandre_numeroparastring (coeficiente * result, precisao);}
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "seerro"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			if (! strcmp (argumentos0, STRINGSAIDAERRO))
				{free (temp); free (argumentos0); free (argumentos2);temp = antoniovandre_evalcelulafuncao (argumentos1, precisao); TIPONUMEROREAL result = strtold (temp, & err); free (temp); return antoniovandre_numeroparastring (coeficiente * result, precisao);}
			else
				{free (temp); free (argumentos0); free (argumentos1);temp = antoniovandre_evalcelulafuncao (argumentos2, precisao); TIPONUMEROREAL result = strtold (temp, & err); free (temp); return antoniovandre_numeroparastring (coeficiente * result, precisao);}
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 8);

		if (! strcmp (temp, "pitagoras"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 9, len - NUMEROUM);

			int posicoes [NUMEROUM];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < NUMEROUM) posicoes [contador] = j; contador++;}

			if (contador != NUMEROUM) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);

			free (argumentos0);
			free (argumentos1);

			argumento = sqrtl (argumento0 * argumento0 + argumento1 * argumento1);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 21);

		if (! strcmp (temp, "diagonalparalelepipedo"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 22, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes[NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			argumento = sqrtl (argumento0 * argumento0 + argumento1 * argumento1 + argumento2 * argumento2);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "pat"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}
			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if (argumento2 != (long long int) argumento2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = argumento0 + (argumento2 - NUMEROUM) * argumento1;

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "par"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if ((argumento2 != (long long int) argumento2) || (argumento2 == NUMEROUM)) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = (argumento1 - argumento0) / (argumento2 - NUMEROUM);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "pasr"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if (argumento2 != (long long int) argumento2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = (2 * argumento0 + (argumento2 - NUMEROUM) * argumento1) * argumento2 / 2;

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "pas"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if (argumento2 != (long long int) argumento2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = (argumento0 + argumento1) * argumento2 / 2;

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "pgt"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if (argumento2 != (long long int) argumento2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = argumento0 * powl (argumento1, (argumento2 - NUMEROUM));

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "pgr"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if ((argumento2 != (long long int) argumento2) || (argumento2 == NUMEROUM) || argumento0 == NUMEROZERO) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			argumento = powl (argumento1 / argumento0, 1 / (argumento2 - NUMEROUM));

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "pgsr"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if ((argumento2 != (long long int) argumento2) || (argumento2 == NUMEROUM)) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (argumento1 == NUMEROUM)
				argumento = argumento0 * argumento2;
			else
				argumento = argumento0 * (NUMEROUM - powl (argumento1, argumento2)) / (NUMEROUM - argumento1);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "pgs"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [2];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < 2) posicoes [contador] = j; contador++;}

			if (contador != 2) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos0 = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);

			char * argumentos1 = antoniovandre_substring (temp, posicoes[NUMEROZERO] + NUMEROUM, posicoes [NUMEROUM] - NUMEROUM);

			char * argumentos2 = antoniovandre_substring (temp, posicoes[NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);

			TIPONUMEROREAL argumento0 = strtold (argumentos0, & err);
			TIPONUMEROREAL argumento1 = strtold (argumentos1, & err);
			TIPONUMEROREAL argumento2 = strtold (argumentos2, & err);

			free (argumentos0);
			free (argumentos1);
			free (argumentos2);

			if ((argumento2 != (long long int) argumento2) || (argumento2 == NUMEROUM)) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (argumento0 == NUMEROZERO)
				argumento = NUMEROZERO;
			else
				argumento = argumento0 * (NUMEROUM - powl (powl (argumento1 / argumento0, 1 / (argumento2 - NUMEROUM)), argumento2)) / (NUMEROUM - powl (argumento1 / argumento0, 1 / (argumento2 - NUMEROUM)));

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "mmc"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [TAMANHO_BUFFER_SMALL];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < TAMANHO_BUFFER_SMALL) posicoes [contador] = j; contador++;}

			if (contador > TAMANHO_BUFFER_SMALL) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos [contador];
			TIPONUMEROREAL argumenton [contador];

			for (j = NUMEROZERO; j <= contador; j++)
				{
				if (j == NUMEROZERO)
					argumentos [j] = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);
				else if (j == contador)
					argumentos [j] = antoniovandre_substring (temp, posicoes[j - NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);
				else
					argumentos [j] = antoniovandre_substring (temp, posicoes[j - NUMEROUM] + NUMEROUM, posicoes [j] - NUMEROUM);

				argumenton [j] = strtold (argumentos [j], & err);
				free (argumentos [j]);

				if ((argumenton [j] != (unsigned long long int) argumenton [j]) || (argumenton [j] == NUMEROZERO)) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
				}

			unsigned long long int max = NUMEROZERO;

			for (j = NUMEROZERO; j <= contador; j++)
				if (argumenton [j] > max) max = argumenton [j];

			unsigned long long int fator = NUMEROUM;

			do
				{
				if (max * fator > VALOR_MAX) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

				flag = NUMEROZERO;

				for (j = NUMEROZERO; j <= contador; j++)
					if ((max * fator) % ((long long int) argumenton [j]) != NUMEROZERO)
						{flag = NUMEROUM; break;}

				fator++;
				} while ((flag == NUMEROUM) && (max * fator <= VALOR_MAX));

			argumento = max * (--fator);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "mdc"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			int posicoes [TAMANHO_BUFFER_SMALL];
			int contador = NUMEROZERO;

			for (j = NUMEROZERO; j < strlen (temp); j++)
				if (temp [j] == DELIMITADORSTRINGARGUMENTOS)
					{if (contador < TAMANHO_BUFFER_SMALL) posicoes [contador] = j; contador++;}

			if (contador > TAMANHO_BUFFER_SMALL) {free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			char * argumentos [contador];
			TIPONUMEROREAL argumenton [contador];

			for (j = NUMEROZERO; j <= contador; j++)
				{
				if (j == NUMEROZERO)
					argumentos [j] = antoniovandre_substring (temp, NUMEROZERO, posicoes [NUMEROZERO] - NUMEROUM);
				else if (j == contador)
					argumentos [j] = antoniovandre_substring (temp, posicoes[j - NUMEROUM] + NUMEROUM, strlen (temp) - NUMEROUM);
				else
					argumentos [j] = antoniovandre_substring (temp, posicoes[j - NUMEROUM] + NUMEROUM, posicoes [j] - NUMEROUM);

				argumenton [j] = strtold (argumentos [j], & err);
				free (argumentos [j]);

				if ((argumenton [j] != (unsigned long long int) argumenton [j]) || (argumenton [j] == NUMEROZERO)){free (temp); char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
				}

			unsigned long long int min = VALOR_MAX;

			for (j = NUMEROZERO; j <= contador; j++)
				if (argumenton [j] < min) min = argumenton [j];

			unsigned long long int parcela = NUMEROZERO;

			do
				{
				flag = NUMEROZERO;

				for (j = NUMEROZERO; j <= contador; j++)
					if (((long long int) argumenton [j]) % (min - parcela) != NUMEROZERO)
						{flag = NUMEROUM; break;}

				parcela++;
				} while (flag == NUMEROUM);

			argumento = min - (--parcela);

			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "teto"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (argumento <= NUMEROZERO)
				resultado = (long int) argumento;
			else
				{
					if (argumento == (long int) argumento)
						resultado = (long int) argumento;
					else
						resultado = (long int) argumento + NUMEROUM;
				}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) resultado, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "piso"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (argumento >= NUMEROZERO)
				resultado = (long int) argumento;
			else
				{
					if (argumento == (long int) argumento)
						resultado = (long int) argumento;
					else
						resultado = (long int) argumento - NUMEROUM;
				}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) resultado, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 20);

		if (! strcmp (temp, "fahrenheitparacelsius"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 21, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (5 * (argumento - 32) / 9), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 19);

		if (! strcmp (temp, "fahrenheitparakelvin"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 20, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((5 * (argumento - 32) / 9) + 273.15), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 20);

		if (! strcmp (temp, "celsiusparafahrenheit"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 21, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((9 * argumento / 5) + 32), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 16);

		if (! strcmp (temp, "celsiusparakelvin"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 17, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (argumento - 273.15), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 19);

		if (! strcmp (temp, "kelvinparafahrenheit"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 20, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((9 * (argumento - 273.15) / 5) + 32), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 16);

		if (! strcmp (temp, "kelvinparacelsius"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 17, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (argumento + 273.15), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 12);

		if (! strcmp (temp, "gradoparagrau"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 13, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 9 / 10, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 11);

		if (! strcmp (temp, "gradopararad"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 12, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * M_PI / 200, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 12);

		if (! strcmp (temp, "grauparagrado"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 13, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 10 / 9, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 10);

		if (! strcmp (temp, "graupararad"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 11, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * M_PI / 180, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 11);

		if (! strcmp (temp, "radparagrado"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 12, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 200 / M_PI, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 10);

		if (! strcmp (temp, "radparagrau"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 11, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) argumento * 180 / M_PI, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "modulo"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) fabsl (argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 7);

		if (! strcmp (temp, "fatorial"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 8, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento != (long int) argumento) || argumento < NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) argumento), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 9);

		if (! strcmp (temp, "arccossech"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 10, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) (logl ((TIPONUMEROREAL) (NUMEROUM + (TIPONUMEROREAL) powl (NUMEROUM + (TIPONUMEROREAL) powl ((TIPONUMEROREAL) argumento, 2), 0.5)) / ((TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "arcsech"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento <= NUMEROZERO) || (argumento > NUMEROUM))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) (logl ((TIPONUMEROREAL) (NUMEROUM + (TIPONUMEROREAL) powl (1 - (TIPONUMEROREAL) powl ((TIPONUMEROREAL) argumento, 2), 0.5)) / ((TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 7);

		if (! strcmp (temp, "arccotgh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 8, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento >= -1) && (argumento <= NUMEROUM))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) ((logl ((TIPONUMEROREAL) ((TIPONUMEROREAL) argumento + NUMEROUM) / ((TIPONUMEROREAL) argumento - NUMEROUM))) / 2))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "arctgh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento <= -1) || (argumento >= NUMEROUM))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) ((logl ((TIPONUMEROREAL) (NUMEROUM + (TIPONUMEROREAL) argumento) / (1 - (TIPONUMEROREAL) argumento))) / 2))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "arccosh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento < NUMEROUM)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) logl ((TIPONUMEROREAL) (argumento + powl ((TIPONUMEROREAL) (powl ((TIPONUMEROREAL) argumento, 2) - NUMEROUM), 0.5))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "arcsenh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((TIPONUMEROREAL) logl ((TIPONUMEROREAL) (argumento + powl ((TIPONUMEROREAL) (powl ((TIPONUMEROREAL) argumento, 2) + NUMEROUM), 0.5))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "cossech"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (2 / (powl (M_E, (TIPONUMEROREAL) argumento) - powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "sech"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) (2 / (powl (M_E, (TIPONUMEROREAL) argumento) + powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 4);

		if (! strcmp (temp, "cotgh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 5, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_E, (TIPONUMEROREAL) argumento) + powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))) / (powl (M_E, (TIPONUMEROREAL) argumento) - powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "tgh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_E, (TIPONUMEROREAL) argumento) - powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))) / (powl (M_E, (TIPONUMEROREAL) argumento) + powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))))), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "senh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_E, (TIPONUMEROREAL) argumento) - powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))) / 2)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "cosh"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * (TIPONUMEROREAL) ((powl (M_E, (TIPONUMEROREAL) argumento) + powl (M_E, ((NUMEROMENOSUM) * (TIPONUMEROREAL) argumento))) / 2)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 8);

		if (! strcmp (temp, "arccossec"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 9, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento > -1) && (argumento < NUMEROUM))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * asin (1 / (TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "arcsec"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || ((argumento > -1) && (argumento < NUMEROUM))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * acos (1 / (TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "arccotg"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (argumento == NUMEROZERO) resultado = (TIPONUMEROREAL) coeficiente * M_PI_2; else if (argumento < NUMEROZERO) resultado = (TIPONUMEROREAL) coeficiente * (atan (1 / (TIPONUMEROREAL) argumento) + M_PI); else resultado = (TIPONUMEROREAL) coeficiente * atan (1 / (TIPONUMEROREAL) argumento);

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) resultado, precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 4);

		if (! strcmp (temp, "arctg"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 5, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * atan ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "arccos"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento < -1) || (argumento > NUMEROUM)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * acos ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "arcsen"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento < -1) || (argumento > NUMEROUM)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * asin ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "cossec"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PI) == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / sin ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "sec"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			temp = antoniovandre_numeroparastring (M_PI_2, precisao);
			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PI) == strtold (temp, & err2))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / cos ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "sen"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * sinl ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 2);

		if (! strcmp (temp, "cos"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 3, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * cosl ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 3);

		if (! strcmp (temp, "cotg"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 4, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PI) == NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente / tan ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + NUMEROUM);

		if (! strcmp (temp, "tg"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 2, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			temp = antoniovandre_numeroparastring (M_PI_2, precisao);

			if ((* err != NUMEROZERO) || (fmodl (argumento, M_PI) == strtold (temp, & err2))) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
			free (temp);

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * tan ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 6);

		if (! strcmp (temp, "logdois"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 7, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento) / M_LN2), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "logdez"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento) / M_LN10), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + NUMEROUM);

		if (! strcmp (temp, "ln"))
			{
			free (temp);

			coeficiente = NUMEROUM;

			if (i > NUMEROZERO)
				{
				char * temp = antoniovandre_substring (str, NUMEROZERO, i - NUMEROUM);

				antoniovandre_copiarstring (buffer, temp);

				free (temp);

				if (! strcmp (buffer, "-"))
					coeficiente = NUMEROMENOSUM;
				else
					{
					coeficiente = strtold (buffer, & err);
					if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					if ((coeficiente > VALOR_MAX) || (coeficiente < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
					}
				}

			temp = antoniovandre_substring (str, i + 2, len - NUMEROUM);

			argumento = strtold (temp, & err);

			free (temp);

			if ((* err != NUMEROZERO) || (argumento <= NUMEROZERO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if ((argumento > VALOR_MAX) || (argumento < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}

			if (MACROALOCACAODINAMICA)
				{
				free (str2);
				free (buffer);

				for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
					{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

				free (funcoesconstantes);
				}

			return antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) coeficiente * logl ((TIPONUMEROREAL) argumento)), precisao);
			}

		free (temp);
		}

	for (i = NUMEROZERO; i < len; i++)
		{
		char * temp = antoniovandre_substring (str, i, i + 5);

		if (! strcmp (temp, "system"))
			{
			free (temp);

			temp = antoniovandre_substring (str, i + 6, len - NUMEROUM);

			antoniovandre_copiarstring (str2, temp);

			free (temp);

			if (! strcmp (str2, "tamanho_buffer_small"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (TAMANHO_BUFFER_SMALL, precisao);
				}
			else if (! strcmp (str2, "tamanho_buffer_word"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (TAMANHO_BUFFER_WORD, precisao);
				}
			else if (! strcmp (str2, "tamanho_buffer_phrase"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (TAMANHO_BUFFER_PHRASE, precisao);
				}
			else if (! strcmp (str2, "valor_max"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (VALOR_MAX, precisao);
				}
			else if (! strcmp (str2, "tamanho_max_arquivo"))
				return antoniovandre_numeroparastring (TAMANHO_MAX_ARQUIVO, precisao);
			else if (! strcmp (str2, "variavelpadrao"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = VARIAVELPADRAO;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "delimitadorstring"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = DELIMITADORSTRING;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "delimitadorstring2"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = DELIMITADORSTRING2;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "DELIMITADORSTRINGARGUMENTOS"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = DELIMITADORSTRINGARGUMENTOS;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "tentativaslogicas"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (TENTATIVASLOGICAS, precisao);
				}
			else if (! strcmp (str2, "tokeninicioeval"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = TOKENINICIOEVAL;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "tokenfimeval"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = TOKENFIMEVAL;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "epsilon"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (EPSILON, precisao);
				}
			else if (! strcmp (str2, "variaveldesubstituicao"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = VARIAVELDESUBSTITUICAO;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "variaveldesubstituicao2"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = VARIAVELDESUBSTITUICAO2;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "variaveldesubstituicao3"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = VARIAVELDESUBSTITUICAO3;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "variaveldesubstituicao4"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				tc = VARIAVELDESUBSTITUICAO4;
				return antoniovandre_numeroparastring ((int) tc, precisao);
				}
			else if (! strcmp (str2, "numeroparticoessomariemann"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (NUMEROPARTICOESSOMARIEMANN, precisao);
				}
			else if (! strcmp (str2, "intervaloprogresso"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (INTERVALOPROGRESSO, precisao);
				}
			else if (! strcmp (str2, "intervaloprogresso2"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (INTERVALOPROGRESSO2, precisao);
				}
			else if (! strcmp (str2, "intervaloprogresso3"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (INTERVALOPROGRESSO3, precisao);
				}
			else if (! strcmp (str2, "intervaloprogresso4"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (INTERVALOPROGRESSO4, precisao);
				}
			else if (! strcmp (str2, "aproximacao"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO, precisao);
				}
			else if (! strcmp (str2, "aproximacao2"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO2, precisao);
				}
			else if (! strcmp (str2, "aproximacao3"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO3, precisao);
				}
			else if (! strcmp (str2, "aproximacao4"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO4, precisao);
				}
			else if (! strcmp (str2, "aproximacao5"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO5, precisao);
				}
			else if (! strcmp (str2, "aproximacao6"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (APROXIMACAO6, precisao);
				}
			else if (! strcmp (str2, "maxnumeradorfracoes"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (MAXNUMERADORFRACOES, precisao);
				}
			else if (! strcmp (str2, "minprecisao"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (MINPRECISAO, precisao);
				}
			else if (! strcmp (str2, "maxprecisao"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (MAXPRECISAO, precisao);
				}
			else if (! strcmp (str2, "version"))
				{
				if (MACROALOCACAODINAMICA)
					{
					free (str2);
					free (buffer);

					for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
						{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

					free (funcoesconstantes);
					}

				return antoniovandre_numeroparastring (VERSION, precisao);
				}
			else
				{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); if (MACROALOCACAODINAMICA) {free (str2); free (buffer); for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++) {free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);} free (funcoesconstantes); return result;}}
			}

		free (temp);
		}

	if (MACROALOCACAODINAMICA)
		{
		free (str2);
		free (buffer);

		for (i = NUMEROZERO; i < TAMANHO_BUFFER_SMALL; i++)
			{free (funcoesconstantes [i].token); free (funcoesconstantes [i].comentario);}

		free (funcoesconstantes);
		}

	resultado = strtold (str, & err);

	if ((* err != NUMEROZERO) || (! strcmp (str, STRINGVAZIA)))
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
	else
		{
		return antoniovandre_formatarreal (antoniovandre_numeroparastring (resultado, precisao), precisao);
		}
	}

// Função eval célula.

char * antoniovandre_evalcelula (char * str, int precisao)
	{
	DECLARACAO_antoniovandre_evalcelula_strt

	DECLARACAO_antoniovandre_evalcelula_strt2

	DECLARACAO_antoniovandre_evalcelula_strt3

	DECLARACAO_antoniovandre_evalcelula_strtv1

	DECLARACAO_antoniovandre_evalcelula_strtv2

	DECLARACAO_antoniovandre_evalcelula_strt4

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

	antoniovandre_copiarstring (strt, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] != tc) strncat (strt, & str [i], NUMEROUM);

	if (! strcmp (strt, STRINGVAZIA)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

	tc = strt [NUMEROZERO];

	for (i = NUMEROZERO; i < strlen (antoniovandre_operadores); i++)
		{
		tc2 = antoniovandre_operadores [i];

		if ((tc == tc2) && (tc2 != OPERADORSUBTRACAO))
			{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
		}

	while (VERDADE)
		{
		for (i = NUMEROZERO; i < TAMANHO_BUFFER_PHRASE; i++) posicoes_operadores [i] = NUMEROMENOSUM;

		contador = NUMEROZERO; flag4 = NUMEROZERO;

		for (i = NUMEROZERO; i < strlen (strt); i++)
			for (j = NUMEROZERO; j < strlen (antoniovandre_operadores); j++)
				{
				flag3 = NUMEROZERO;

				for (k = NUMEROZERO; k < strlen (antoniovandre_letrasminusculas); k++)
					{
					if (((i == NUMEROZERO) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)) || ((contador > NUMEROZERO) && (posicoes_operadores [contador - NUMEROUM] == i - NUMEROUM) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)) || ((i > NUMEROZERO) && (strt [i - NUMEROUM] == antoniovandre_letrasminusculas [k]) && (antoniovandre_operadores [j] == OPERADORSUBTRACAO)))
						{
						flag3 = NUMEROUM;
						flag4 = NUMEROUM;
						}
					}

				if ((strt [i] == antoniovandre_operadores [j]) && flag3 == NUMEROZERO) posicoes_operadores [contador++] = i;
				}

		if (posicoes_operadores [NUMEROZERO] == NUMEROMENOSUM) break;

		for (i = NUMEROZERO; i < TAMANHO_BUFFER_PHRASE; i++)
			if (posicoes_operadores [i] > NUMEROZERO)
				{
				flag = NUMEROZERO;
				flag2 = NUMEROZERO;

				for (j = NUMEROZERO; j < TAMANHO_BUFFER_PHRASE; j++)
					if (strt [posicoes_operadores [j]] == '^') flag2 = NUMEROUM;

				for (j = NUMEROZERO; j < TAMANHO_BUFFER_PHRASE; j++)
					if (((strt [posicoes_operadores [j]] == OPERADORMULTIPLICACAO) || (strt [posicoes_operadores [j]] == '/'))) flag = NUMEROUM;

				antoniovandre_copiarstring (strt2, STRINGVAZIA);

				if (i > NUMEROZERO)
					ponteiro = posicoes_operadores [i - NUMEROUM] + NUMEROUM;
				else
					ponteiro = NUMEROZERO;

				ponteiroinicio = ponteiro;

				for (j = ponteiro; j < posicoes_operadores [i]; j++)
					strncat (strt2, & strt [j], NUMEROUM);

				antoniovandre_copiarstring (strt3, STRINGVAZIA);

				if (posicoes_operadores [i + NUMEROUM] == NUMEROMENOSUM)
					ponteiro = strlen (strt);
				else
					ponteiro = posicoes_operadores [i + NUMEROUM];

				ponteirofim = ponteiro;

				for (j = posicoes_operadores [i] + NUMEROUM; j < ponteiro; j++)
					strncat (strt3, & strt [j], NUMEROUM);

				if ((! strcmp (strt2, STRINGVAZIA)) || (! strcmp (strt3, STRINGVAZIA)))
					{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

				char * temp2 = antoniovandre_evalcelulafuncao (strt2, precisao);
				antoniovandre_copiarstring (strtv1, temp2);
				free (temp2);

				temp2 = antoniovandre_evalcelulafuncao (strt3, precisao);
				antoniovandre_copiarstring (strtv2, temp2);
				free (temp2);

				if (! strcmp (strtv1, STRINGSAIDAERRO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
				if (! strcmp (strtv2, STRINGSAIDAERRO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

				if (! strcmp (strtv1, STRINGSAIDAERROOVER)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
				if (! strcmp (strtv2, STRINGSAIDAERROOVER)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

				valort = strtold (strtv1, & err);
				if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

				valort2 = strtold (strtv2, & err);
				if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

				if (strt [posicoes_operadores [i]] == '^')
					{
					if (valort < NUMEROZERO)
						{
						if (fmodl (fabsl (valort2), 2) == NUMEROZERO)
							valor = powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
						else if (fmodl (fabsl (valort2), 2) == NUMEROUM)
							valor = (NUMEROMENOSUM) * powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
						else
							{
							contador2 = NUMEROUM; flag5 = NUMEROZERO;

							do
								{
								if ((fmodl ((contador2 / fabsl (valort2)), 2) > NUMEROUM + (NUMEROMENOSUM) * APROXIMACAO2) && (fmodl ((contador2 / fabsl (valort2)), 2) < NUMEROUM + APROXIMACAO2))
									{
									if (fmodl (contador2, 2) == NUMEROZERO)
										valor = powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);
									else
										valor = (NUMEROMENOSUM) * powl (fabsl ((TIPONUMEROREAL) valort), (TIPONUMEROREAL) valort2);

									flag5 = NUMEROUM;
									}

								contador2++;
								} while ((contador2 <= MAXNUMERADORFRACOES) && (flag5 == NUMEROZERO));

							if (flag5 == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
							}
						}
					else
						valor = powl ((TIPONUMEROREAL) valort, (TIPONUMEROREAL) valort2);

					if (isnan (valor) || isinf (valor)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == OPERADORMULTIPLICACAO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort * (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '/') && (flag2 == NUMEROZERO))
					{
					if (valort2 == NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

					valor = (TIPONUMEROREAL) valort / (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '+') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort + (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == OPERADORSUBTRACAO) && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = (TIPONUMEROREAL) valort - (TIPONUMEROREAL) valort2;
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '%') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					valor = fmodl ((TIPONUMEROREAL) valort, (TIPONUMEROREAL) valort2);
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '@') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if ((valort != (long int) valort) || (valort < NUMEROZERO) || (valort2 != (long int) valort2) || (valort2 < NUMEROZERO) || (valort < valort2)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
					valor = (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) valort) / antoniovandre_fatorial ((unsigned long int) (valort - valort2));
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '#') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if ((valort != (long int) valort) || (valort < NUMEROZERO) || (valort2 != (long int) valort2) || (valort2 < NUMEROZERO) || (valort < valort2)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
					valor = (TIPONUMEROREAL) antoniovandre_fatorial ((unsigned long int) valort) / (antoniovandre_fatorial ((unsigned long int) (valort - valort2)) * antoniovandre_fatorial ((unsigned long int) (valort2)));
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '$') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if (valort2 != (int) valort2) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
					valor = roundl ((TIPONUMEROREAL) valort / powl (10, valort2)) * powl (10, valort2);
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '>') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					(valort > valort2) ? (valor = valort) : (valor = valort2);
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '<') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					(valort < valort2) ? (valor = valort) : (valor = valort2);
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == ':') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if ((valort2 == 1) || (valort2 <= 0)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
					valor = logl (valort) / logl (valort2);
					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}

				if ((strt [posicoes_operadores [i]] == '~') && (flag == NUMEROZERO) && (flag2 == NUMEROZERO))
					{
					if (fabsl (logl (valort) - logl (valort2)) < APROXIMACAO)
						valor = NUMEROUM;
					else
						valor = NUMEROZERO;

					if ((valor > VALOR_MAX) || (valor < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
					break;
					}
				}

		antoniovandre_copiarstring (strt4, STRINGVAZIA);

		for (i = NUMEROZERO; i < ponteiroinicio; i++)
			strncat (strt4, & strt [i], NUMEROUM);

		char temps [TAMANHO_BUFFER_WORD];

		char * temp = antoniovandre_numeroparastring (valor, precisao);
		antoniovandre_copiarstring (temps, temp);
		free (temp);

		antoniovandre_concatenarstring (strt4, temps);

		for (i = ponteirofim; i < strlen (strt); i++)
			strncat (strt4, & strt [i], NUMEROUM);

		antoniovandre_copiarstring (strt, strt4);
		}

	if (MACROALOCACAODINAMICA)
		{
		free (strt4);
		free (strtv2);
		free (strtv1);
		free (strt3);
		free (strt2);
		}

	return antoniovandre_evalcelulafuncao (strt, precisao);
	}

// Função eval.

char * antoniovandre_eval (char * str)
	{
	DECLARACAO_antoniovandre_eval_str2

	DECLARACAO_antoniovandre_eval_str2t

	DECLARACAO_antoniovandre_eval_str3

	DECLARACAO_antoniovandre_eval_str4

	DECLARACAO_antoniovandre_eval_str4t

	DECLARACAO_antoniovandre_eval_str5

	DECLARACAO_antoniovandre_eval_str6

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
	int flagargumentos;
	int numerotokens;
	int contador;
	char tc;
	char tc2;

	int precisao = antoniovandre_precisao_real ();

	antoniovandre_copiarstring (str2, STRINGVAZIA);
	antoniovandre_copiarstring (str2t, STRINGVAZIA);
	antoniovandre_copiarstring (str3, STRINGVAZIA);
	antoniovandre_copiarstring (str4, STRINGVAZIA);
	antoniovandre_copiarstring (str4t, STRINGVAZIA);
	antoniovandre_copiarstring (str5, STRINGVAZIA);
	antoniovandre_copiarstring (str6, STRINGVAZIA);

	flag = NUMEROZERO;

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] == DELIMITADORSTRINGARGUMENTOS)
			flag = NUMEROUM;

	if (flag == NUMEROUM)
		{
		for (i = NUMEROZERO; i < strlen (str); i++)
			if (str [i] != ESPACOBRANCO)
				{
				if (str [i] == DELIMITADORSTRINGARGUMENTOS)
					{tc = TOKENFIMEVAL; strncat (str2, & tc, NUMEROUM); tc = DELIMITADORSTRINGARGUMENTOS; strncat (str2, & tc, NUMEROUM); tc = TOKENINICIOEVAL; strncat (str2, & tc, NUMEROUM);}
				else
					strncat (str2, & str [i], NUMEROUM);
				}
		}
	else
		for (i = NUMEROZERO; i < strlen (str); i++) if (str [i] != ESPACOBRANCO) strncat (str2, & str [i], NUMEROUM);

	if (! strcmp (str2, STRINGVAZIA)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

	for (i = NUMEROUM; i < strlen (str2); i++)
		{
		tc = str2 [i - NUMEROUM];
		tc2 = str2 [i];

		for (j = NUMEROZERO; j < strlen (antoniovandre_operadores); j++)
			{
			if ((tc == OPERADORSUBTRACAO) && (tc2 == antoniovandre_operadores [j])) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			if ((tc == antoniovandre_operadores [j]) && (tc2 == OPERADORSUBTRACAO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
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

		if ((i >= NUMEROUM) && (str2 [i] == OPERADORSUBTRACAO) && (str2 [i - NUMEROUM] == TOKENINICIOEVAL))  flag2 = NUMEROUM;

		if ((((i == NUMEROZERO) && (str2 [NUMEROZERO] == OPERADORSUBTRACAO)) || (flag2 == NUMEROUM)) && ! ((i > NUMEROUM) && (str2 [i] == CHARUM) && (str2 [i - NUMEROUM] == OPERADORSUBTRACAO) && (str2 [i - 2] == TOKENINICIOEVAL)))
			{
			j = i + NUMEROUM;

			if (str2 [i] == TOKENINICIOEVAL) contador++;
			if (str2 [i] == TOKENFIMEVAL) contador--;

			do
				{
				flag = NUMEROZERO;

				for (k = NUMEROZERO; k < strlen (antoniovandre_numeros); k++)
					for (l = NUMEROZERO; l < strlen (antoniovandre_letras); l++)
						if ((! ((flag2 == NUMEROUM) && (contador == NUMEROMENOSUM))) && ((str2 [j] == antoniovandre_numeros [k]) || (str2 [j] == antoniovandre_letras [l]) || (str2 [j] == TOKENINICIOEVAL) || (str2 [j] == TOKENFIMEVAL))) flag = NUMEROUM;

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
				antoniovandre_copiarstring (str2t, STRINGVAZIA);

				if (flag3 == NUMEROUM)
					{
					tc = TOKENINICIOEVAL;
					strncat (str2t, & tc, NUMEROUM);

					tc = TOKENINICIOEVAL;
					strncat (str2t, & tc, NUMEROUM);

					antoniovandre_concatenarstring (str2t, STRINGMENOSUM);

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

					antoniovandre_concatenarstring (str2t, STRINGMENOSUM);

					tc = TOKENFIMEVAL;
					strncat (str2t, & tc, NUMEROUM);

					tc = OPERADORMULTIPLICACAO;
					strncat (str2t, & tc, NUMEROUM);

					for (k = i + NUMEROUM; k < j; k++)
						strncat (str2t, & str2 [k], NUMEROUM);
					}

				for (k = j; k < strlen (str2); k++)
					strncat (str2t, & str2 [k], NUMEROUM);

				antoniovandre_copiarstring (str2, str2t);
				}
			}
		}

	if (strcmp (str2t, STRINGVAZIA)) antoniovandre_copiarstring (str2, str2t);

	for (i = NUMEROUM; i < strlen (str2); i++)
		{
		flag = NUMEROZERO;
		flag2 = NUMEROZERO;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letrasminusculas); j++)
			if (str2 [i] == antoniovandre_letrasminusculas [j]) flag = NUMEROUM;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letrasmaiusculas); j++)
			if (str2 [i - NUMEROUM] == antoniovandre_letrasmaiusculas [j]) flag2 = NUMEROUM;

		if ((flag == NUMEROUM) && (flag2 == NUMEROUM))
			{
			antoniovandre_copiarstring (str2t, STRINGVAZIA);

			for (j = NUMEROZERO; j < i; j++)
				strncat (str2t, & str2 [j], NUMEROUM);

			tc = OPERADORMULTIPLICACAO;
			strncat (str2t, & tc, NUMEROUM);

			for (j = i; j < strlen (str2); j++)
				strncat (str2t, & str2 [j], NUMEROUM);

			antoniovandre_copiarstring (str2, str2t);
			}
		}

	do
		{
		inicio = NUMEROZERO;
		fim = strlen (str2) - NUMEROUM;
		flag = NUMEROZERO;
		flag2 = NUMEROZERO;
		flagargumentos = NUMEROZERO;
		numerotokens = NUMEROZERO;

		for (i = NUMEROZERO; i < strlen (str2); i++)
			if (str2 [i] == DELIMITADORSTRINGARGUMENTOS)
				flagargumentos = NUMEROUM;

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

		for (i = NUMEROZERO; i < strlen (str2); i++)
			if ((str2 [i] == TOKENINICIOEVAL) || (str2 [i] == TOKENFIMEVAL))
				numerotokens++;

		if ((flagargumentos == NUMEROUM) && (numerotokens == 2))
			{
			char * temp = (char *) malloc (TAMANHO_BUFFER_PHRASE);

			antoniovandre_copiarstring (temp, STRINGVAZIA);

			for (i = NUMEROZERO; i < strlen (str2); i++)
				if ((str2 [i] != TOKENINICIOEVAL) && (str2 [i] != TOKENFIMEVAL))
					strncat (temp, & str2 [i], NUMEROUM);

			if (MACROALOCACAODINAMICA)
				{
				free (str6);
				free (str5);
				free (str4t);
				free (str4);
				free (str3);
				free (str2t);
				}

			return antoniovandre_evalcelulafuncao (temp, precisao);
			}

		antoniovandre_copiarstring (str3, STRINGVAZIA);

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

			antoniovandre_copiarstring (str6, STRINGVAZIA);

			if (flag4 == NUMEROUM) for (j = k; j < inicio - NUMEROUM; j++) strncat (str6, & str2 [j], NUMEROUM);

			if (flag4 == NUMEROUM)
				for (i = NUMEROZERO; i < k; i++) strncat (str3, & str2 [i], NUMEROUM);
			else
				for (i = NUMEROZERO; i < inicio - NUMEROUM; i++) strncat (str3, & str2 [i], NUMEROUM);

			i = strlen (str6);

			tc = str6 [i - NUMEROUM];

			if (strcmp (str6, STRINGVAZIA))
				{
				antoniovandre_concatenarstring (str3, str6);
				if (tc != OPERADORSUBTRACAO) antoniovandre_concatenarstring (str3, "*");
				}

			if (!strcmp (str3, "-")) antoniovandre_copiarstring (str3, "-1*");

			antoniovandre_copiarstring (str4, STRINGVAZIA);

			for (i = inicio; i <= fim; i++)
				strncat (str4, & str2 [i], NUMEROUM);

			i = NUMEROZERO; contador = NUMEROZERO; antoniovandre_copiarstring (str4t, STRINGVAZIA);

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

			char * temp = antoniovandre_evalcelula (str4t, precisao);
			antoniovandre_copiarstring (str5, temp);
			free (temp);

			if (! strcmp (str5, STRINGSAIDAERRO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
			if (! strcmp (str5, STRINGSAIDAERROOVER)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

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

			antoniovandre_copiarstring (str2, str3);
			}
		else
			{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
		} while (! ((flag == NUMEROZERO) && (flag2 == NUMEROZERO)));

	if (MACROALOCACAODINAMICA)
		{
		free (str6);
		free (str5);
		free (str4t);
		free (str4);
		free (str3);
		free (str2t);
		}

	char * result = antoniovandre_evalcelula (str2, precisao);

	for (i = NUMEROZERO; i < strlen (result); i++)
		{
		flag = NUMEROZERO;

		for (j = NUMEROZERO; j < strlen (antoniovandre_letras); j++)
			if (result [i] == antoniovandre_letras [j]) flag = NUMEROUM;

		if (flag == NUMEROUM)
			{antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
		}

	return result;
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

	int precisao = antoniovandre_precisao_real ();

	if ((ponto > VALOR_MAX) || (ponto < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

	antoniovandre_copiarstring (str2, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] == VARIAVELDESUBSTITUICAO)
			{
			char temps [TAMANHO_BUFFER_WORD];

			char * temp = antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) ponto + (TIPONUMEROREAL) EPSILON), precisao);
			antoniovandre_copiarstring (temps, temp);
			free (temp);

			tc = TOKENINICIOEVAL;
			strncat (str2, & tc, NUMEROUM);
			antoniovandre_concatenarstring (str2, temps);
			tc = TOKENFIMEVAL;
			strncat (str2, & tc, NUMEROUM);
			}
		else
			strncat (str2, & str [i], NUMEROUM);

	char * temp = antoniovandre_eval (str2);
	valorsup = strtold (temp, & err);
	free (temp);

	if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

	antoniovandre_copiarstring (str3, STRINGVAZIA);

	for (i = NUMEROZERO; i < strlen (str); i++)
		if (str [i] == VARIAVELDESUBSTITUICAO)
			{
			char temps [TAMANHO_BUFFER_WORD];

			char * temp = antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) ponto - (TIPONUMEROREAL) EPSILON), precisao);
			antoniovandre_copiarstring (temps, temp);
			free (temp);

			tc = TOKENINICIOEVAL;
			strncat (str3, & tc, NUMEROUM);
			antoniovandre_concatenarstring (str3, temps);
			tc = TOKENFIMEVAL;
			strncat (str3, & tc, NUMEROUM);
			}
		else
			strncat (str3, & str [i], NUMEROUM);

	temp = antoniovandre_eval (str3);
	valorinf = strtold (temp, & err);
	free (temp);

	if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

	return antoniovandre_formatarreal(antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) valorsup - (TIPONUMEROREAL) valorinf) / (TIPONUMEROREAL) (2 * (TIPONUMEROREAL) EPSILON), precisao), precisao);
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

	int precisao = antoniovandre_precisao_real ();

	norma = (TIPONUMEROREAL) ( (TIPONUMEROREAL) b - (TIPONUMEROREAL) a) / (TIPONUMEROREAL) NUMEROPARTICOESSOMARIEMANN;

	for (j = NUMEROZERO; j < NUMEROPARTICOESSOMARIEMANN; j++)
		{
		antoniovandre_copiarstring (str2, STRINGVAZIA);

		for (i = NUMEROZERO; i < strlen (str); i++)
			if (str [i] == VARIAVELDESUBSTITUICAO)
				{
				char temps [TAMANHO_BUFFER_WORD];

				char * temp = antoniovandre_numeroparastring ((TIPONUMEROREAL) ((TIPONUMEROREAL) a + (TIPONUMEROREAL) j * (TIPONUMEROREAL) norma + (TIPONUMEROREAL) ((TIPONUMEROREAL) norma / 2)), precisao);
				antoniovandre_copiarstring (temps, temp);
				free (temp);

				tc = TOKENINICIOEVAL;
				strncat (str2, & tc, NUMEROUM);
				antoniovandre_concatenarstring (str2, temps);
				tc = TOKENFIMEVAL;
				strncat (str2, & tc, NUMEROUM);
				}
			else
				strncat (str2, & str [i], NUMEROUM);

		char * temp = antoniovandre_eval (str2);
		antoniovandre_copiarstring (str3, temp);
		free (temp);

		if (! strcmp (str3, STRINGSAIDAERROOVER)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

		parcela = strtold (str3, & err) * (TIPONUMEROREAL) norma;

		if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

		integral += (TIPONUMEROREAL) parcela;

		if ((integral > VALOR_MAX) || (integral < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
		}

	return antoniovandre_formatarreal (antoniovandre_numeroparastring (integral, precisao), precisao);
	}

// Retorna a função mais próxima, dados os pontos e as funções em arquivos.

char * antoniovandre_funcaomaisproxima (char * arquivopontospath, char * arquivofuncoespath, int log)
	{
	FILE * arquivopontos;
	FILE * arquivofuncoes;

	DECLARACAO_antoniovandre_funcaomaisproxima_buffer

	DECLARACAO_antoniovandre_funcaomaisproxima_buffert

	DECLARACAO_antoniovandre_funcaomaisproxima_buffertt

	char * bufferr = (char *) malloc (TAMANHO_BUFFER_PHRASE);

	DECLARACAO_antoniovandre_funcaomaisproxima_bufferr2

	DECLARACAO_antoniovandre_funcaomaisproxima_buffer1

	DECLARACAO_antoniovandre_funcaomaisproxima_buffer2

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
	int flag2 = NUMEROUM;
	int flag3;
	int flag4;
	char tc;
	char tc2;
	char * err;

	int precisao = antoniovandre_precisao_real ();

	if (log == NUMEROUM)
		{
		printf ("Verificando validade dos arquivos... ");
		fflush (stdout);
		}

	arquivopontos = fopen (arquivopontospath, "r");

	if (arquivopontos == NULL)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
		}

	fseek (arquivopontos, NUMEROZERO, SEEK_END);

	if (ftell (arquivopontos) > (unsigned long int) TAMANHO_MAX_ARQUIVO)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		fclose (arquivopontos);
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
		}

	fseek (arquivopontos, NUMEROZERO, SEEK_SET);

	arquivofuncoes = fopen (arquivofuncoespath, "r");

	if (arquivofuncoes == NULL)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
		}

	fseek (arquivofuncoes, NUMEROZERO, SEEK_END);

	if (ftell (arquivofuncoes) > (unsigned long int) TAMANHO_MAX_ARQUIVO)
		{
		if (log == NUMEROUM) printf ("Erro.\n");
		fclose (arquivofuncoes);
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
		}

	fseek (arquivofuncoes, NUMEROZERO, SEEK_SET);

	if (log == NUMEROUM) printf ("Ok.\n");

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

	if (log == NUMEROUM) printf ("\bOk.\n");

	fseek (arquivopontos, NUMEROZERO, SEEK_SET);
	fseek (arquivofuncoes, NUMEROZERO, SEEK_SET);

	antoniovandre_copiarstring (bufferr, STRINGVAZIA);

	do
		{
		if (flag2 == NUMEROUM)
			{
			antoniovandre_copiarstring (buffer, STRINGVAZIA);

			do
				{
				antoniovandre_funcoes_buffer_char = fgetc (arquivofuncoes);

				if ((! feof (arquivofuncoes)) && (antoniovandre_funcoes_buffer_char != DELIMITADORSTRING) && (antoniovandre_funcoes_buffer_char != ESPACOBRANCO) && (antoniovandre_funcoes_buffer_char != CARACTEREFIMLINHA))
					strncat (buffer, & antoniovandre_funcoes_buffer_char, NUMEROUM);

				} while ((! feof (arquivofuncoes)) && (antoniovandre_funcoes_buffer_char != DELIMITADORSTRING) && (antoniovandre_funcoes_buffer_char != CARACTEREFIMLINHA));

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
					antoniovandre_copiarstring (buffer2, STRINGVAZIA);
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
					if (flag3 == NUMEROZERO) antoniovandre_copiarstring (buffer1, STRINGVAZIA);
					strncat (buffer1, & antoniovandre_pontos_buffer_char, NUMEROUM);
					flag3 = NUMEROUM;
					}
				else
					strncat (buffer2, & antoniovandre_pontos_buffer_char, NUMEROUM);
				}
			}

		if ((flag2 == NUMEROZERO) && (strcmp (buffer, STRINGVAZIA)))
			{
			x = strtold (buffer1, & err);

			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}
			if ((x > VALOR_MAX) || (x < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

			y = strtold (buffer2, & err);

			if ((y > VALOR_MAX) || (y < (NUMEROMENOSUM) * VALOR_MAX)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}
			if (* err != NUMEROZERO) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			antoniovandre_copiarstring (buffert, STRINGVAZIA);

			for (i = NUMEROZERO; i < strlen (buffer); i++)
				{
				tc = buffer [i];

				if (tc == VARIAVELPADRAO)
					{
					char temps [TAMANHO_BUFFER_WORD];

					char * temp = antoniovandre_numeroparastring ((TIPONUMEROREAL) x, precisao);
					antoniovandre_copiarstring (temps, temp);
					free (temp);

					tc2 = TOKENINICIOEVAL;
					strncat (buffert, & tc2, NUMEROUM);
					antoniovandre_concatenarstring (buffert, temps);
					tc2 = TOKENFIMEVAL;
					strncat (buffert, & tc2, NUMEROUM);
					}
				else
					strncat (buffert, & tc, NUMEROUM);
				}

			char * temp = antoniovandre_eval (buffert);
			antoniovandre_copiarstring (buffertt, temp);
			free (temp);

			if (! strcmp (buffertt, STRINGSAIDAERRO)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

			if (! strcmp (buffertt, STRINGSAIDAERROOVER)) {char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

			yt = strtold (buffertt, & err);
			}

		contadoritens++;

		if (flag2 == NUMEROZERO)
			{
			if (flag4 == NUMEROZERO)
				{
				mt += (y - yt);
				mt2 += fabsl (y - yt);
				}
			else
				{
				if (! strcmp (bufferr, buffer)) antoniovandre_copiarstring (bufferr, bufferr2);
				flag4 = NUMEROUM;
				}
			}

		if ((flag4 == NUMEROZERO) && (flag2 == NUMEROUM) && (fabsl (mt) <= fabsl (m)))
			{
			m = mt;

			if (mt2 < m2)
				{
				m2 = mt2;
				antoniovandre_copiarstring (bufferr2, bufferr);
				antoniovandre_copiarstring (bufferr, buffer);
				}
			}

		if ((log == NUMEROUM) && ((contadoritens == NUMEROUM) || (contadoritens == totalitens - totalpontos) || (contadoritens % INTERVALOPROGRESSO == NUMEROZERO)))
			{
			printf ("\r%.13f%% concluído.", (TIPONUMEROREAL) (100.0 * (TIPONUMEROREAL) ((TIPONUMEROREAL) (contadoritens) / (TIPONUMEROREAL) (totalitens - (TIPONUMEROREAL) totalpontos))));

			fflush (stdout);
			}

		} while ((! feof (arquivofuncoes)) || (flag2 == NUMEROZERO));

	if (log == NUMEROUM) {printf ("\n"); fflush (stdout);}

	fclose (arquivopontos);
	fclose (arquivofuncoes);

	if (MACROALOCACAODINAMICA)
		{
		free (buffer2);
		free (buffer1);
		free (bufferr2);
		free (buffertt);
		free (buffert);
		free (buffer);
		}

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
	char * strr = (char *) malloc (TAMANHO_BUFFER_PHRASE);
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

	int precisao = antoniovandre_precisao_real ();

	antoniovandre_copiarstring (strr, STRINGVAZIA);

	char * temp = antoniovandre_eval (mins);
	antoniovandre_copiarstring (mins2, temp);
	free (temp);

	temp = antoniovandre_eval (maxs);
	antoniovandre_copiarstring (maxs2, temp);
	free (temp);

	if ((! strcmp (mins2, STRINGSAIDAERRO)) || (! strcmp (maxs2, STRINGSAIDAERRO)))
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERRO); return result;}

	if ((! strcmp (mins2, STRINGSAIDAERROOVER)) || (! strcmp (maxs2, STRINGSAIDAERROOVER)))
		{char * result = (char *) malloc (TAMANHO_BUFFER_PHRASE); antoniovandre_copiarstring (result, STRINGSAIDAERROOVER); return result;}

	min = strtold (mins2, & err);
	max = strtold (maxs2, & err);

	x = min;
	flag = NUMEROZERO;
	flag2 = NUMEROZERO;
	flag3 = NUMEROZERO;
	flag4 = NUMEROZERO;

	do
		{
		if ((log == NUMEROUM) && (contador % INTERVALOPROGRESSO4 == NUMEROZERO)) {printf ("\r%.5f%% concluído.", (TIPONUMEROREAL) 100 * fabsl ((x - min) / (max - min + step))); fflush (stdout);}

		if (x > max + step) flag4 = NUMEROUM;

		antoniovandre_copiarstring (str, STRINGVAZIA);

		for (i = NUMEROZERO; i < strlen (funcao); i++)
			{
			if (funcao [i] == VARIAVELPADRAO)
				{
				char temps [TAMANHO_BUFFER_WORD];

				char * temp = antoniovandre_numeroparastring (x, precisao);
				antoniovandre_copiarstring (temps, temp);
				free (temp);

				tc = TOKENINICIOEVAL;
				strncat (str, & tc, NUMEROUM);
				antoniovandre_concatenarstring (str, temps);
				tc = TOKENFIMEVAL;
				strncat (str, & tc, NUMEROUM);
				flag = NUMEROUM;
				}
			else
				strncat (str, & funcao [i], NUMEROUM);
			}

		char * temp = antoniovandre_eval (str);
		antoniovandre_copiarstring (strt, temp);
		free (temp);

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
					if (log == NUMEROUM) {printf ("\r100.00000%% concluído.\n\nInfinitas raízes encontradas. Trata-se de uma possibilidade.\n"); fflush (stdout);}

					return "";
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
							{
							char * temp = antoniovandre_numeroparastring (xr, precisao);
							antoniovandre_copiarstring (strr, temp);
							free (temp);
							}
						else
							{
							char temps [TAMANHO_BUFFER_WORD];

							char * temp = antoniovandre_numeroparastring (xr, precisao);
							antoniovandre_copiarstring (temps, temp);
							free (temp);

							tc = DELIMITADORSTRING;
							strncat (strr, & tc, NUMEROUM);
							antoniovandre_concatenarstring (strr, temps);
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
		printf ("\r100.00000%% concluído.\n\n");

		if (contador3 > NUMEROUM)
			printf ("Tratam-se de aproximações:\n");
		else if (contador3 == NUMEROUM)
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

			if ((det > VALOR_MAX) || (det < (NUMEROMENOSUM) * VALOR_MAX)) return INFINITY;
			}

	return det;
	}
