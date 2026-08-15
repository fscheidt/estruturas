#include <stdio.h>
typedef struct
{
  char nome[50];
  int  matricula;
  char situacao[10];
  float p1;
  float p2;
  int faltas;
  float media;
  // char nascimento[12];
  // char sexo;
  // char telefone[20];
} Aluno;

void listarAlunos(Aluno turma[], int total) {
  for (int i = 0; i < total; i++) {
    printf("Matrícula: %d\n", turma[i].matricula);
    printf("Nome: %s\n", turma[i].nome);
    printf("Média: %.1f\n", turma[i].media);
    printf("Situação: %s\n", turma[i].situacao);
  }
}
void obtem_lista_alunos(Aluno alunos[], int total){
  FILE *arq = fopen("alunos.bin", "rb");
  if (arq != NULL) {
    fread(alunos, sizeof(Aluno), total, arq);
    fclose(arq);
  }
}

int main() {
  // Inicialização
  Aluno a1 = {
      "Ana Maria Souza",
      20240101,
      "15/04/2002",
      'F',
      // "(11) 98765-4321"
  };

  // Exibição dos dados
  printf("\n--- Dados do Aluno ---\n");
  printf("Nome: \t\t%s\n", a1.nome);
  printf("Matrícula: \t%d\n", a1.matricula);
  // printf("Nascimento: \t%s\n", a1.nascimento);
  // printf("Telefone: \t%s\n", a1.telefone);
  // printf("Sexo: \t\t%c\n\n", a1.sexo);


  Aluno turma[40];
  // turma[0] = a1;

  obtem_lista_alunos(turma, 40);

  // consultar_funcionarios("colaboradores.bin");
  // salva_vetor_funcionarios("colaboradores.bin", lista);
  // ler_arquivo_memoria(); // malloc
  // sair();

  return 0;
}