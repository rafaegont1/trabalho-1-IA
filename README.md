# Algoritmos BFS e DFS

Este projeto implementa os algoritmos de **Busca em Largura (BFS)** e **Busca em Profundidade (DFS)**, desenvolvidos em C. Este README explica como cada algoritmo funciona e apresenta as principais diferenças entre eles. 

---

## 📖 Busca em Largura (BFS)

### O que é?
A **Busca em Profundidade (Depth-First Search)** é um algoritmo que explora os caminhos de um grafo ou árvore profundamente antes de retroceder. Ele utiliza o conceito de recursão ou uma pilha para gerenciar os vértices visitados.

### 🔧 Funcionamento
1. Inicia no nó inicial e o marca como visitado.
2. Insere o nó inicial em uma **fila**.
3. Enquanto a fila não estiver vazia:
   - Remove o nó da frente da fila.
   - Visita todos os vizinhos não visitados, marca-os como visitados e os adiciona à fila.
  
## 📖 Busca em Prorundidade (DFS)

### O que é?
A **Busca em Largura (Breadth-First Search)** é um algoritmo que explora os vértices de um grafo em níveis, visitando primeiro os nós mais próximos do nó inicial antes de avançar para os mais distantes.

### 🔧 Funcionamento
1. Começa no nó inicial e o marca como visitado.
2. Explora recursivamente (ou utilizando uma pilha) os vizinhos não visitados do nó atual até atingir um vértice sem vizinhos não visitados.
3. Retrocede para continuar explorando outros caminhos.

### Tempo de Execução ⏰

Foi utilizada a função `clock_gettime()`, pertencente a biblioteca `GNU C Library` para medir o tempo de execução dos dois algoritmos. Para melhor precisão e comparação entre as formas de busca, foram executados cada código dez vezes e o tempo de execução usado como comparação é a média aritmética entre eles.
- `BFS`
  - O tempo de execução foi 495500 ns (0,0004975 segundos).
- `DFS`
  - O tempo de execução foi 541800 ns (0,0005418 segundos).
#### **Conclusões sobre os tempos**

O algoritmo BFS pode ser considerado mais "estável" no labirinto comparado. Os tempos de execução medidos tinham variações superiores a 0,0003 segundos, enquanto o DFS é bem menos previsível, tendo medições muito mais rápidas, como 0,0002 segundos e também muito mais demoradas, como 0,0008 segundos.

### 🚀 Como Executar

Siga os passos abaixo para compilar e executar o projeto:

1. Clone o repositório:
   ```bash
   git clone https://github.com/rafaegont1/trabalho-1-IA
   cd <nome-do-repositorio>
2. Configure o projeto: Crie uma pasta para os arquivos de compilação e configure o projeto com o CMake:

  ```bash
  mkdir build
  cd build
  cmake ..
```
3. Compile o projeto: Use o comando make para compilar:

  ```bash
  make
```
4. Execute o programa: O executável gerado terá o nome dfs. Para rodar:
 ```bash
./dfs
```
ou 
```bash
./bsf
```





