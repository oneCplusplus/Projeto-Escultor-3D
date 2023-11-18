#include "Sculptor.h"

int main() {
  // Criar uma instância de Sculptor
  Sculptor Dog(70, 70, 70);

  // Criar o corpo (caixa)
  Dog.setColor(0.6, 0.4, 0.2, 1.0);
  Dog.putBox(5, 16, 5, 13, 4, 15);

  // Adicionar detalhes ao corpo (voxels)
  Dog.putVoxel(10, 13, 5); // Cabeça
  Dog.putVoxel(8, 5, 10);  // Perna dianteira esquerda
  Dog.putVoxel(12, 5, 10); // Perna dianteira direita
  Dog.putVoxel(8, 13, 10); // Perna traseira esquerda
  Dog.putVoxel(12, 13, 10); // Perna traseira direita

  // Modelar a cabeça (elipsoide)
  Dog.putEllipsoid(10, 13, 15, 5, 3, 4);

  // Adicionar esferas para os olhos e nariz
  Dog.putSphere(9, 14, 16, 1); // Olho esquerdo
  Dog.putSphere(11, 14, 16, 1); // Olho direito
  Dog.putSphere(10, 13, 17, 1); // Nariz

  // Refinar as pernas e a cauda (caixas, elipsoides e esferas)
  Dog.putBox(7, 9, 2, 8, 5, 7);    // Pata traseira esquerda
  Dog.putBox(11, 13, 2, 8, 5, 7);   // Pata traseira direita
  Dog.putBox(7, 9, 2, 8, 10, 12);    // Pata dianteira esquerda
  Dog.putBox(11, 13, 2, 8, 10, 12);   // Pata dianteira direita
  Dog.putEllipsoid(11, 7, 5, 2, 2, 8); // Cauda

  // Adicionar detalhes pretos na frente das patas (garras)
  Dog.setColor(0.0, 0.0, 0.0, 1.0); // Preto
  Dog.putVoxel(7, 2, 5);
  Dog.putVoxel(7, 2, 5);
  Dog.putVoxel(12, 2, 5);
  Dog.putVoxel(8, 3, 5);
  Dog.putVoxel(8, 5, 5);

  // Remover volumes para detalhes finos
  Dog.cutBox(9, 11, 14, 15, 17, 19); // Focinho
  Dog.cutBox(9, 11, 13, 14, 5, 7);   // Pescoço

  // Teste dos metodos
  // Adicionar voxel usando putVoxel
  Dog.putVoxel(55, 56, 57);

  // Adicionar caixa usando putBox
  Dog.putBox(58, 60, 66, 69, 52, 54);

  // Adicionar esfera usando putSphere
  Dog.putSphere(66, 68, 64, 52);

  // Adicionar elipsoide usando putEllipsoid
  Dog.putEllipsoid(53, 55, 66, 52, 54, 53);

  // Remover voxel usando cutVoxel
  Dog.cutVoxel(55, 56, 57);

  // Remover caixa usando cutBox
  Dog.cutBox(58, 60, 66, 69, 52, 54);

  // Remover esfera usando cutSphere
  Dog.cutSphere(66, 68, 64, 52);

  // Remover elipsoide usando cutEllipsoid
  Dog.cutEllipsoid(53, 55, 66, 52, 54, 53);
  
  // Salvar escultura em um arquivo OFF
  Dog.writeOFF("dog_model.off");

  return 0;
}