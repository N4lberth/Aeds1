#include <stdio.h>

//struct data guarda uma data(ano, mes, dia)
typedef struct data
{
    int ano, mes, dia;
}data;//end data

//função diaDeHoje recebe a data de um dia
data diaDeHoje(void)
{
    data x;

    printf("digite o ano: ");
    scanf("%d", &x.ano);

 //validando o ano
    if(x.ano <=0 ){
        printf("ano invalido\n");
        x.ano=0;
    }//end if


    printf("digite o mes: ");
    scanf("%d", &x.mes);    

 //validando o mes
    if(x.mes < 1 || x.mes > 12){
        printf("mes invalido\n");
        x.mes=0;
    }//end if


    printf("digite o dia: ");
    scanf("%d", &x.dia);    

 //validando o dia
    if(x.mes==1 || x.mes==3 || x.mes==5 || x.mes==7 || x.mes==8 || x.mes==10 || x.mes==12){
        if(x.dia < 1 || x.dia > 31){
            printf("dia invalido\n");
            x.dia=0;
        }//end if
    }//end if

    else if(x.mes==4 || x.mes==6 || x.mes==9 || x.mes==11){
        if(x.dia < 1 || x.dia > 30){
            printf("dia invalido\n");
            x.dia=0;
        }//end if
    }//end else if

    else{
        if(x.ano%400==0 || (x.ano%4==0 && x.ano%100!=0)){
            if(x.dia < 1 || x.dia > 29){
                printf("dia invalido\n");
                x.dia=0;
            }//end if
        }//end if
        else if(x.dia < 1 || x.dia > 28){
            printf("dia invalido\n");
            x.dia=0;
        }//end else if
    }//end else

    return x;
}//end diaDeHoje


//função diferencaDeDias entrega um numero inteiro q representa a diferença de dias entre duas datas
int diferencaDeDias(data x, data y){
    int quntdias=0;

    while (x.dia != y.dia || x.mes != y.mes || x.ano != y.ano) 
    {
        switch (x.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(x.dia<31){
                x.dia++;
                quntdias++;
            }//end if
            else{
                x.dia=1;
                x.mes++;
                quntdias++;
            }//end else
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(x.dia<30){
                x.dia++;
                quntdias++;
            }//end if
            else{
                x.dia=1;
                x.mes++;
                quntdias++;
            }//end else
            break;
        case 2:
            if(x.dia%400==0 ||(x.dia%4==0 && x.dia%100!=0)){
                if(x.dia<29){
                    x.dia++;
                    quntdias++;
                }//end if
                else{
                    x.dia=1;
                    x.mes++;
                    quntdias++;
                }//end else
            }//end if
            else{
                if(x.dia<28){
                    x.dia++;
                    quntdias++;
                }//end if
                else{
                    x.dia=1;
                    x.mes++;
                    quntdias++;
                }//end else
            }//end else
            break;
        default:
            x.mes=1;
            x.ano++;
            quntdias++;
        }//end switch
    }//end while
    return quntdias;

}//end diferencaDeDias



//test da função
int main(void){

    data D1, D2;

    D1 = diaDeHoje();

    printf("%d/%d/%d\n",D1.dia, D1.mes, D1.ano);

    D2 = diaDeHoje();

    printf("%d/%d/%d\n",D2.dia, D2.mes, D2.ano);
    printf("difrenca de dias= %d",diferencaDeDias(D1, D2));
    return 0;
}