/*
 Guia01E3 
 Author: 811197 - Nalberth
*/
// lista de dependencias
#include "karel.hpp" 
#include "myKarel.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
 // colocar paredes no mundo
    world->set ( 3, 6, HWALL ); // horizontal
    world->set ( 4, 6, HWALL ); // horizontal
    world->set ( 5, 6, HWALL ); // horizontal
    world->set ( 3, 2, HWALL ); // horizontal
    world->set ( 4, 2, HWALL ); // horizontal
    world->set ( 5, 2, HWALL ); // horizontal
    world->set ( 5, 3, VWALL ); // vertical
    world->set ( 5, 4, VWALL ); // vertical
    world->set ( 5, 5, VWALL ); // vertical
    world->set ( 2, 3, VWALL ); // vertical
    world->set ( 2, 4, VWALL ); // vertical
    world->set ( 2, 5, VWALL ); // vertical
    world->set ( 2, 6, VWALL ); // vertical
 // colocar um marcador no mundo
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
 // salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public robott
{
   public:
    /**
     turnRight - Procedimento para virar 'a direita.
    */
   void turnRight ( )
   {
     // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
         // o agente que executar esse metodo
         // devera' virar tres vezes 'a esquerda
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
        } // end if
   } // end turnRight ( )
     /**
     doTask - Relacao de acoes para qualquer robo executar.
     */
   void doTask ( )
   {

    // especificar acoes da tarefa
    // moveN mover o robo
      moveN ( 5 );
      turnLeft( );
      moveN ( 5 );
      turnLeft( );
      moveN ( 2 );
      turnLeft( );
      moveN ( 3 );
    // pickBeepers pegar a quantidade de beepers informada
      pickBeepers( 6 );
      turnLeft( );
      turnLeft( );
      moveN ( 3 );
      turnRight( );
      moveN ( 2 );
      turnRight( );
      moveN ( 3 );
    // putBeepers soltar a quantidade de beepers informada
      putBeepers ( 1 );
      moveN ( 1 );
      turnRight( );
      moveN ( 4 );
      turnRight( );
      moveN( 4 );
      putBeepers ( 2 );
      moveN ( 1 );
      turnRight( );
      moveN ( 3 );
      putBeepers ( 3 );
      moveN ( 1 );
      turnRight( );
      moveN ( 6 );
      turnRight( );
      moveN ( 5 );
      turnLeft( );
      turnLeft( );
      
     // encerrar
      turnOff ( ); // desligar-se
   }// end doTask ( )

}; // end class MyRobot
// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
 // definir o contexto
 // criar o ambiente e decorar com objetos
 // OBS.: executar pelo menos uma vez,
 // antes de qualquer outra coisa
 // (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia01E3.txt" );
    world->show ( );
 // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia01E3.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
 // criar robo
    MyRobot *robot = new MyRobot( );
 // posicionar robo no ambiente (situacao inicial):
 // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
 // executar tarefa
    robot->doTask( );
 // encerrar operacoes no ambiente
    world->close ( );
 // encerrar programa
 getchar ( );
    return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/**
Versao Data Modificacao
 0.1 
---------------------------------------------- testes
Versao Teste
 E.3    01. ( ok )
*/