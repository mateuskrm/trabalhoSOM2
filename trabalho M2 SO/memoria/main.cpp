#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2){

        cout << 'Número de argumentos inválidos, por favor informe somente o número do endereço lógico.';
        return 1;
    }

    try{

      int tamEnderecoVirtual = 16;
      int tamanhoPagina = 4096;
      int enderecoVirtual = stoi(argv[1]);

      int bitOffset = log2(tamanhoPagina);
      int bitpagina = tamEnderecoVirtual - bitOffset;

      string enderecoBinario = bitset<16>(enderecoVirtual).to_string();
      string bitsPagina = enderecoBinario.substr(0, bitpagina);

      string bitsOffset = enderecoBinario.substr(bitpagina);


      int numeroPagina = bitset<16>(bitsPagina).to_ulong();
      cout << numeroPagina << endl;
      int indiceDeslocamento = bitset<16>(bitsOffset).to_ulong();
      cout << indiceDeslocamento << endl;

      return 0;

    }catch(invalid_argument const& e){

        cout << 'Valor informado invalido, por favor informe um endereço logico valido' << endl;
        return 1;

    }catch(domain_error const& e){

        cout << 'Nao foi possivel calcular o deslocamento' << endl;
        return 1;

    }catch(overflow_error const& e){

        cout <<  'O valor de bitset e alto demais para converter para inteiro' << endl;
        return 1;

    }catch(exception const& e){

        cout << 'Um erro inesperado ocorreu durante a execucao.Erro: ' << e.what() << endl;
        return 1;
    }


}
