#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief A estrutura Voxel representa um elemento volumétrico em um espaço tridimensional.
 *
 * Cada voxel possui propriedades como cor (componentes RGB), transparência (alfa), 
 * e uma flag indicando se deve ser mostrado ou não.
 */
typedef struct {
  float r, g, b; ///< Componentes de cor: vermelho, verde e azul.
  float a; ///< Valor de transparência do voxel.
  bool show; ///< Indica se o voxel deve ser mostrado ou não.
} Voxel;

#endif //VOXEL_H
