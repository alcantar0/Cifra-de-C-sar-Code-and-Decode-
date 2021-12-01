//Pedro Henrique De Sousa Alcântara
//512237
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *to_decode(char *mensagem, int key){
    char * decoded=malloc((strlen(mensagem))*sizeof(char));
    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        decoded[i]=mensagem[i]-key; //No caso da decodificação se subtrai a chave da letra da mensagem
        decoded[i+1]='\0';
        if (isalpha(mensagem[i])){
            if(mensagem[i]-key>122){
                decoded[i]=mensagem[i]-key;
                decoded[i]-=26;
                decoded[i+1]='\0';
            }
            if(mensagem[i]-key<97){
                decoded[i]=mensagem[i]-key;
                decoded[i]+=26;
                decoded[i+1]='\0';
            }   
        }
        else{
            decoded[i]=mensagem[i];
            decoded[i+1]='\0';
        }
    }
    return decoded;
}

char *to_code(char *mensagem, int key){
    char *coded=malloc((strlen(mensagem))*sizeof(char));
    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        coded[i]=mensagem[i]+key;//No caso da codificação se soma a chave da letra da mensagem
        coded[i+1]='\0';
        if(isalpha(mensagem[i])){
            if(mensagem[i]+key>122){
            coded[i]=mensagem[i]+key;
            coded[i]-=26;
            coded[i+1]='\0';
        }
        if(mensagem[i]+key<97){
            coded[i]=mensagem[i]+key;
            coded[i]+=26;
            coded[i+1]='\0';
        }
        }
        else
        {
            coded[i]=mensagem[i];
            coded[i+1]='\0';
        }
    }
    return coded;
}

int main(){
    char mensagem[40];
    int chave;
    int modo;
    printf("Digite a mensagem: ");
    fgets(mensagem, 40, stdin);
    printf("Digite a chave: ");
    scanf("%d", &chave);
    for(int i=0; mensagem[i]; i++){// Transforma toda a mensagem em letras minusculas
        mensagem[i]=tolower(mensagem[i]);
    }

    printf("Codificar (digite 0); Decodificar (digite 1): ");
    scanf("%d", &modo);
    if (modo==0){
        printf("A mensagem codificada e: ");
        printf("%s", to_code(mensagem, chave));
    }
    else if(modo==1){
        printf("A mensagem decodificada e: ");
        printf("%s", to_decode(mensagem, chave));
    }
    else{
        printf("Digite uma função válida.");
    }
    return 0;
}
