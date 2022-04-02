Projeto

O projeto o qual foi pensado é de realizar um controle do sistema de iluminação pública de uma região determinada, a fim de que diminuísse a burocracia do processo, conectando o usuário diretamente com o governo, facilitando dessa forma a comunicação e o controle. O usuário poderia através desse programa indicar irregularidades em determinados postes, solicitar reparo e outras coisas. Numa aplicação prática, o projeto
seria integrado com o google maps, no entanto, haja visto que é um projeto acadêmico e respeitando o escopo da matéria, foi resolvido entre os integrantes do grupo, fazer a organização dos postes utilizando as estruturas as quais iremos aprender, visando cumprir a proposta inicial do trabalho.

Organização e disposição das funções do projeto:
Projeto foi separado em MVC a fim de que houvesse um maior controle e uma melhor divisão das partes. Não será totalmente seguido essa divisão, haja visto que não usaremos uma interface, mas achamos interessante disponibilizar as funções e características do projeto dessa forma.

Foi proposto a realização de um CRUD, para a realização do cadastro dos postes. Repositório de postes e ruas (Vetores ou algo do tipo de Struct).

"View":
- Representada pela a main do programa. Nela está a chamada de todas as funções do programa proposto. É seraparada em duas partes: operador e cliente
- O operador pode ser represetado por um agente da prefeitura, ele seria responsavel pelo cadastra de ruas e atualização do nome das mesma, alem disso teria no seu alcance todas funções possiveis para fazer com postes(criação, atualização, remover, exibir lista entre outras);
- O cliente apenas poderia ver qual ruas esta no programa, mas teria acesso a todas funções de postes tambem. Numa aplicação prática, as alterações feitas pelo cliente passaria por uma etapa de verificação e caso fosse informado um problema/reclamação, então o operador iria ao local efetuar o reparo. 
- Possibiltamos o cliente inserir e remover postes para facilitar o uso no programa, mas numa aplicação real, talvez seria melhor se esse pudesse apenas efetuar reclamações.

Controller e model:
- Atualizar a view e o model 
- Create, Retrieve, Update e Delete(CRUD)- envolve listas, struct e etc;  - Postes
- Create e update - Ruas
- Repositório de postes e ruas (Lista encadeada)
- Aqui temos toda a parte logica do programa, oque faz a view funcionar

Considerações finais e resultados alcançados:

Como já mencionado, na aplicação final fizemos uma combinação de listas, a qual tem uma lista para ruas e para cada nó dessa lista, há uma lista de poste, representando os postes dessa determinada rua. O programa poderia ser ampliado, poderiamos ter bairros, cidades, estados e etc. Mas como já explicado anteriormente, a aplicação final seria seria integrado ao maps, ou a outro gps. Para fazer a etapa de verificação, o usuario poderia tirar fotos comprovando a reclamação. Além disso, fica claro que há muitas possibilidade para uma aplicação similar, mas oque tambem é notório é que essa ideia pode ser explorada a fim de melhorarmos a qualidade de vida da população, melhorando esse serviço publico o qual é essencial em qualquer cidade do mundo.
Portanto, consideramos que o projeto foi bem sucedido haja vista que conseguimos explorar varias áreas da matéria, alem de fazer um projeto oqual poderia atingir varias pessoas e melhorar a qualidade de vida das mesmas, logo consideramos o resultado satisfatório.
