# Programação e Algoritmos - [IADE - UE](https://www.iade.europeia.pt/) <!-- omit in toc -->

## Lista de Tarefas

Pretende-se um programa que permite o registo, consulta, e execução de tarefas pessoais.

## Instruções

- `RT Descrição`: Permite registar uma tarefa, e responde com um identificador único para a tarefa.
- `LT` : Permite listar todas as tarefas registadas.
- `MT IdTarefa`: Permite marcar uma tarefa como *completa*. Precisa do identificador único da tarefa a marcar.
- `Q`: Termina o programa.

## Compilação

    gcc -c -Wall -Wextra -Werror -g models/tasks.c
    gcc -c -Wall -Wextra -Werror -g controllers/task_list.c
    gcc -c -Wall -Wextra -Werror -g views/cli.c
    gcc -Wall -Wextra -Werror -g -o main tasks.o task_list.o cli.o main.c

Alternativa 1

    gcc -Wextra -Wall -g -o main models/tasks.c controllers/task_list.c views/cli.c main.c

Alternativa 2

    make

### Flags de Compilação

- `-Wall`: Ativa os warnings mais comuns.
- `-Wextra`: Ativa alguns warnings adicionais.
- `-Werror`: Trata os warnings como erros.
- `-g`: Adiciona informação de debug ao executável ou objeto.
- `-o main`: Define o nome do executável ou objeto.
- `-c`: Compila um objeto. Não executa o linker.

Mais informação sobre as fags de compilação em [https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html).
