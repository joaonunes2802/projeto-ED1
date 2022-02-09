O projeto o qual foi pensado é de realizar um controle do sistema de iluminação pública de uma região determinada, a fim de que diminuísse a burocracia do processo, conectando o usuário diretamente com o governo, facilitando dessa forma a comunicação e o controle. O usuário poderia através desse programa indicar irregularidades em determinados postes, solicitar reparo e outras coisas. Numa aplicação prática, o projeto
seria integrado com o google maps, no entanto, haja visto que é um projeto acadêmico e respeitando o escopo da matéria, foi resolvido entre os integrantes do grupo, fazer a organização dos postes utilizando as estruturas as quais iremos aprender, visando cumprir a proposta inicial do trabalho.

Organização e disposição das funções do projeto:
Projeto foi separado em MVC a fim de que houvesse um maior controle e uma melhor divisão das partes. Não será totalmente seguido essa divisão, haja visto que não usaremos uma interface, mas achamos interessante disponibilizar as funções e características do projeto dessa forma.

Foi proposto a realização de um CRUD, para a realização do cadastro dos postes. Repositório de postes e ruas (Vetores ou algo do tipo de Struct).

"View":
- Chama a função de update(reclamação de um poste já existente)
- Chama a função de create(cadastro de um poste, sendo indicado no cadastro a condição de iluminação do citado, além de possibilitar realizar uma reclamação)
- Chama a função de delete(retira reclamação, ou o poste do cadastro)
- Chama o histórico de atividades. (Log)

Controller:
- Atualizar a view e o model
- Create, Retrieve, Update e Delete(CRUD)- envolve listas, struct e etc;
- Exibe histórico na view

Model:
- Repositório de postes e ruas (Vetores ou algo do tipo de Struct)
- Histórico de reclamações (arquivo txt)