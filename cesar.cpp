#include <iostream>
#include <string>
using namespace std;

class CifradoCesar
{
    string alfabeto;
    int clave;
public:
    CifradoCesar(){};
    CifradoCesar(int clave)
    {
        alfabeto="abcdefghijklmnopqrstuvwxyz "; 
        this->clave=clave;
    };
    int modulo(int a, int n)
    {
        int q=a/n;
        int r= a-(q*n);
        if(r<0)
            return r+n;
        return r;
    }
    string cifrar(string mensaje){
        for(int i=0; i<mensaje.size(); i++ ){
            int a= alfabeto.find(mensaje[i])+clave;
            if(a<26 && a>0)
                mensaje[i]=alfabeto[a];
            else if(a-clave==26)
                mensaje[i]== alfabeto[a-clave];
            else
            {
                int pos=modulo(a,26);
                mensaje[i]=alfabeto[pos];
            }
        }
    return mensaje;
    }

    string descifrar(string mensaje)
    {
         for(int i=0; i<mensaje.size(); i++ ){
            int a= alfabeto.find(mensaje[i])-clave;
            if(a<27 && a>0){
                mensaje[i]=alfabeto[a];
           }
           if(a+clave==26)
                mensaje[i]=alfabeto[26];
            else
            {
                int pos=modulo(a,26);
                mensaje[i]=alfabeto[pos];
            }
        }
        return mensaje;
    }

};

int main()
{

   CifradoCesar a(5);
   string mensaje;
   getline(cin, mensaje);
   string b=a.cifrar(mensaje);
   cout<<b<<endl;
   cout<<a.descifrar(b);
}
