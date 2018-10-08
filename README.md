# Programação e Desenvolvimento de Software II
Grupo 3 - Rede Social (Twitter)

**User Stories e Cartões CRC**
> **Observação:** As Users Stories e os Cartões CRC's também estão disponíveis em PDF/PNG no repositório para download, este markdown é para a melhor visualização das entregas.

## User Stories

|Como o |Eu quero...|para que...|
|-----|------------|------------|
|Usuário  |Cadastrar uma nova conta|Eu possa logar no sistema|
|Usuário|Editar minhas informações|Eu possa utilizar vários nomes de usuário ou trocar minha senha, em caso de esquecê-la|
|Usuário|Criar publicações|Eu possa compartilhar minhas experiências com meus seguidores|
|Usuário|Eu possa Interagir com as publicações|Eu possa demonstrar meu interesse ou comentar algo|
|Usuário|Entrar no perfil de outros usuários|Eu possa ver suas informações e seguí-los|
|Usuário|Pesquisar|Eu possa ver postagens antigas e encontrar novos usuários|
|Usuário|Mandar mensagem|Eu possa me comunicar diretamente com algum usuário|
|Usuário|Fazer Login e Logout|Eu possa entrar e sair do sistema|


## Cartões CRC / Diagrama de Classes
+-------------------+-------------------+
| <center>System</center>
+===================+===================+
+-------------------+-------------------+
| Responsabilidades | Colaborações
+===================+===================+
| loggedUsers       | User
+-------------------+-------------------+
| registeredUsers   | 
+-------------------+-------------------+
| login             | 
+-------------------+-------------------+
| logout            | 
+-------------------+-------------------+
| signup            | 
+-------------------+-------------------+
| signout           | 
+-------------------+-------------------+

+-------------------+-------------------+
| <center>User</center>
+===================+===================+
+-------------------+-------------------+
| Responsabilidades | Colaborações
+===================+===================+
| id                | Post
+-------------------+-------------------+
| name              | Search
+-------------------+-------------------+
| qtPosts           | Message
+-------------------+-------------------+
| qtLikes           | System
+-------------------+-------------------+
| qtFollowing       | 
+-------------------+-------------------+
| qtFollowers       | 
+-------------------+-------------------+
| faz login         | 
+-------------------+-------------------+
| faz logout        | 
+-------------------+-------------------+
| posta algo        | 
+-------------------+-------------------+
| reposta algo      | 
+-------------------+-------------------+
| comenta algo      | 
+-------------------+-------------------+
| pesquisa usuarios |
| e posts           |
+-------------------+-------------------+
| segue e deixa de  |
| seguir            |
+-------------------+-------------------+
| envia mensagens   | 
+-------------------+-------------------+
| visualiza perfis  | 
+-------------------+-------------------+

+-------------------+-------------------+
| <center>Post</center>
+===================+===================+
+-------------------+-------------------+
| Responsabilidades | Colaborações
+===================+===================+
| id                | User
+-------------------+-------------------+
| userId            | 
+-------------------+-------------------+
| qtLikes           | 
+-------------------+-------------------+
| qtReplies         | 
+-------------------+-------------------+
| qtReposts         | 
+-------------------+-------------------+
| isReply           | 
+-------------------+-------------------+
| isRepost          | 
+-------------------+-------------------+

+-------------------+-------------------+
| <center>Search</center>
+===================+===================+
+-------------------+-------------------+
| Responsabilidades | Colaborações
+===================+===================+
| returnedId        | User
+-------------------+-------------------+
| userId            | Post
+-------------------+-------------------+
| faz a busca,      |
| por posts,        |
| reposts ou        |
| comentàrios       |
+-------------------+-------------------+

+-------------------+-------------------+
| <center>Message</center>
+===================+===================+
+-------------------+-------------------+
| Responsabilidades | Colaborações
+===================+===================+
| id                | User
+-------------------+-------------------+
| content           | 
+-------------------+-------------------+
| senderId          | 
+-------------------+-------------------+
| recipientId       | 
+-------------------+-------------------+