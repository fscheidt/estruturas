# Estruturas de dados

## Arquivos

- fopen
- fread / fwrite
- fclose

- formatação: 
  - texto    (w)
  - binário  (wb)

### Modularização e alocação dinâmica

- adicionar dados ao arquivo (ab)
- alocação dinâmica
- modularização

Alocação dinâmica
- fopen
  - fseek (descobrir o tamanho do arquivo)
  - malloc
- fread
- fclose

## Tamanho da lista

```c
int size = sizeof(&produtos) / sizeof(&produtos[0]);
printf("\n%d\n",size);
```

## Leitura dos dados do produto 

`estoque_write.c`

```c
Produto p;
printf("--- CADASTRO DE PRODUTO ---\n\n");

// Gerar o ID 
p.id = gerar_id();
printf("ID gerado: %d\n", p.id);

// Lê o Nome
printf("Digite o nome do produto: ");
fgets(p.nome, sizeof(p.nome), stdin);
p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o Enter
// REMOVENDO O '\n': O fgets salva o Enter na string. 
    
// strcspn procura onde está o '\n' e troca por '\0' (fim de string).
p.nome[strcspn(p.nome, "\n")] = '\0';

// Quantidade
printf("Digite a quantidade em estoque: ");
scanf("%d", &p.qtd);

// Valor
printf("Digite o valor (ex: 35.90): ");
scanf("%f", &p.valor);

printf("\nDados coletados:\n");
printf("- ID: %d\n", p.id);
printf("- Nome: '%s' \n", p.nome);
printf("- Qtd: %d\n", p.qtd);
printf("- Valor: R$ %.2f\n", p.valor);

printf("\nSalvando dados em %s\n", ARQUIVO_ESTOQUE);
if (salvar_produto(&p, ARQUIVO_ESTOQUE) == 0) {
    printf("Sucesso!\n");
}
return 0;
}
```

## Compilador

<pre>
# Compilar
gcc -g hello.c -o hello.app
# Executar
./hello.app
</pre>

## Compile and run c (vscode)

### Option 1: Code Runner Extension

Let's you use `Ctrl + Alt + N` to compile and run whatever file is currently open.

Setup Steps:

- Open Extensions (`Ctrl + Shift + X`) in VS Code and search for Code Runner - *formulahendry.code-runner* -, then click Install.

- Open Settings (`Ctrl + ,`), search for executorMap, and click Edit in settings.json.
- Add or update the "c" line in code-runner.executorMap to:

```json
"code-runner.executorMap": {
  "c": "cd $dir && gcc -g $fileName -o $fileNameWithoutExt.app && ./$fileNameWithoutExt.app"
},
"code-runner.runInTerminal": true
```

Usage: Press `Ctrl + Alt + N` 


### Option 2: Native VS Code Task

Only native, build-and-run task bound to a single shortcut.

Setup Steps:

In VS Code, press `Ctrl + Shift + P` and type **Tasks: Configure Task**.

Select Create/Open **tasks.json** file and replace the contents with:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Compile and Run C",
      "type": "shell",
      "command": "gcc -g ${file} -o ${fileDirname}/${fileBasenameNoExtension}.app && ${fileDirname}/${fileBasenameNoExtension}.app",
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "presentation": {
        "reveal": "always",
        "panel": "dedicated"
      }
    }
  ]
}
```

Usage:

Press `Ctrl + Shift + B` while viewing any C file to compile and execute it immediately in the integrated terminal.
