<p align ="center">
	<img src="images/fase1/pipex-badge.png">
</p>

<p>
	<h1> Pipex </h1>
</p>

<p>
	Esse projeto tem como objetivo recriar o comportamento do comando | pipe | do unix. Basicamente, direcionamos a saída de um processo para que sirva como entrada para o próximo.
</p>

<p>
	<h2> Pontuação </h2>
</p>
<p>
	<img src="images/100.jpg">
</p>

<p>
	<h2> Como usar o programa: </h2>
</p>

<p>
	<h3> O programa deve ser executado da seguinte forma: </h3>

```
$> ./pipex infile cmd1 cmd2 outfile
```
</p>

```bash
# Clone o projeto e acesse a pasta
git clone https://github.com/gustavdlima/pipex.git && cd pipex

# Compile o programa utilizando o Makefile
make

# Exemplo de execução Pipex
./pipex infile cat "tr ' ' '-'" outfile

# Comando original unix
<infile cmd1 | cmd2 > files/<choose-output-file>

# Limpe os objetos criados com
make fclean

# Fim!
```
