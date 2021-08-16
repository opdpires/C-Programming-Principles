#include <iostream> // Para realizar a comunicação com o usuário.
#include <stdint.h> // Definição dos tipo uint8_t e uint16_t.
#include <stdlib.h> // Para utilizar alocação de memória dinâmica.

#include "Fletcher16.h"
#include "Message.h"

//Pré condições: receber um byte
//Pós condições: mostra o byte recebido em binário e imprime um espaço ao final.
void printa_em_binario(uint8_t value);

int main(){
    unsigned short a, b, c; // preferível declarar o valor em inteiro para ter uma utilização mais intuitiva.
    uint8_t byte1, byte2, byte3;
    std::cout << "insira os bytes com espacos: "; // com isso, não é preciso utilizar a tabela ASCII para verificar o resultado.
    std::cin >> a;
    byte1 = a;
    std::cin >> b;
    byte2 = b;
    std::cin >> c;
    byte3 = c;
    
    std::cout << "Primeiro teste: primeiro byte" << std::endl;
    Message mensagem1;
    mensagem1.append_byte(byte1);
    std::cout << "Byte1: ";
    mensagem1.print_message();
    mensagem1.print_checksum();
    mensagem1.print_checksum_value();

    uint8_t sequencia[3] = {byte1, byte2, byte3};

std::cout << "\n\nSegundo teste: sequencia de bytes" << std::endl;
    Message mensagem2(sequencia, 3);
    std::cout << "bytes utilizados: " << std::endl;
    mensagem2.print_message();
    mensagem2.print_checksum();
    mensagem2.print_checksum_value();

    std::cout << "Numero de bytes na mensagem (sem checksum): " << mensagem2.num_bytes() << std::endl;
    std::cout << "Numero de bytes na mensagem (com checksum): " << mensagem2.total_num_bytes();
    
    uint8_t *seq1 = (uint8_t*) malloc(mensagem2.num_bytes()*sizeof(uint8_t));
    uint8_t *seq2 = (uint8_t*) malloc(mensagem2.total_num_bytes()*sizeof(uint8_t));;
    
    
    
    seq1 = mensagem2.get_sequence_copy();
    
    seq2 = mensagem2.get_sequence();
    
    
    std::cout << "\nmensagem sem checksum:\n";
    for(int i = 0; i < mensagem2.num_bytes(); i++){
        printa_em_binario(seq1[i]);
    }
    std::cout << std::endl;
    
    std::cout << "mensagem com checksum:\n";
    for(int i = 0; i < mensagem2.total_num_bytes(); i++){
        printa_em_binario(seq2[i]);
    }
    
    free(seq1);
    free(seq2);
    
    return 0;
}

void printa_em_binario(uint8_t value){
    for(int i = 0; i < 8; i++){
        int num = 1;
        for(int j = 7-i; j > 0; j--){
            num *= 2;
        }
        std::cout << (value % num > 0);
    }
    std::cout << " ";
}