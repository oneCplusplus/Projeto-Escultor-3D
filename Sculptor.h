#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "Voxel.h"

/**
 * @brief A classe Sculptor representa um canvas de escultura tridimensional.
 *
 * A classe Sculptor desempenha o papel de um ambiente tridimensional para esculturas virtuais. 
 * Sua principal função reside na capacidade de criar e esculpir formas tridimensionais dentro de uma matriz de voxels.
 * Ao oferecer um conjunto de métodos especializados, a classe permite a adição precisa de elementos volumétricos, bem 
 * como a remoção estratégica, proporcionando um meio eficaz de expressão artística digital. Essa representação 
 * tridimensional serve como um canvas virtual, onde artistas e modeladores podem dar vida a suas criações através da 
 * manipulação intuitiva de voxels.
 */
class Sculptor {

private:
  Voxel ***v; ///< Matriz tridimensional de voxels representando o canvas do escultor.
  int nx, ny, nz;   ///< Dimensões da grade de voxels.
  float r, g, b, a; ///< Cor de desenho atual e transparência.

public:
  /**
   * @brief Constrói um objeto Sculptor com as dimensões especificadas.
   *
   * @param _nx O número de voxels na direção x.
   * @param _ny O número de voxels na direção y.
   * @param _nz O número de voxels na direção z.
   */
  Sculptor(int _nx, int _ny, int _nz);

  /**
   * @brief Destrói o objeto Sculptor e libera a memória alocada.
   */
  ~Sculptor();

  /**
   * @brief Define a cor de desenho atual e a transparência.
   *
   * @param r Componente vermelha da cor.
   * @param g Componente verde da cor.
   * @param b Componente azul da cor.
   * @param a Componente alfa (transparência) da cor.
   */
  void setColor(float r, float g, float b, float a);

  /**
   * @brief Desenha um voxel nas coordenadas especificadas.
   *
   * @param x Coordenada x do voxel.
   * @param y Coordenada y do voxel.
   * @param z Coordenada z do voxel.
   */
  void putVoxel(int x, int y, int z);

  /**
   * @brief Remove um voxel nas coordenadas especificadas.
   *
   * @param x Coordenada x do voxel a ser removido.
   * @param y Coordenada y do voxel a ser removido.
   * @param z Coordenada z do voxel a ser removido.
   */
  void cutVoxel(int x, int y, int z);

  /**
   * @brief Desenha uma caixa na grade de voxels.
   *
   * @param x0 Coordenada x inicial da caixa.
   * @param x1 Coordenada x final da caixa.
   * @param y0 Coordenada y inicial da caixa.
   * @param y1 Coordenada y final da caixa.
   * @param z0 Coordenada z inicial da caixa.
   * @param z1 Coordenada z final da caixa.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
   * @brief Remove uma caixa da grade de voxels.
   *
   * @param x0 Coordenada x inicial da caixa a ser removida.
   * @param x1 Coordenada x final da caixa a ser removida.
   * @param y0 Coordenada y inicial da caixa a ser removida.
   * @param y1 Coordenada y final da caixa a ser removida.
   * @param z0 Coordenada z inicial da caixa a ser removida.
   * @param z1 Coordenada z final da caixa a ser removida.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
   * @brief Desenha uma esfera na grade de voxels.
   *
   * @param xcenter Coordenada x do centro da esfera.
   * @param ycenter Coordenada y do centro da esfera.
   * @param zcenter Coordenada z do centro da esfera.
   * @param radius Raio da esfera.
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
   * @brief Remove uma esfera da grade de voxels.
   *
   * @param xcenter Coordenada x do centro da esfera.
   * @param ycenter Coordenada y do centro da esfera.
   * @param zcenter Coordenada z do centro da esfera.
   * @param radius Raio da esfera.
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
   * @brief Desenha uma elipsoide na grade de voxels.
   *
   * @param xcenter Coordenada x do centro da elipsoide.
   * @param ycenter Coordenada y do centro da elipsoide.
   * @param zcenter Coordenada z do centro da elipsoide.
   * @param rx Raio na direção x.
   * @param ry Raio na direção y.
   * @param rz Raio na direção z.
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
   * @brief Remove uma elipsoide da grade de voxels.
   *
   * @param xcenter Coordenada x do centro da elipsoide.
   * @param ycenter Coordenada y do centro da elipsoide.
   * @param zcenter Coordenada z do centro da elipsoide.
   * @param rx Raio na direção x.
   * @param ry Raio na direção y.
   * @param rz Raio na direção z.
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
   * @brief Escreve a grade de voxels em um arquivo OFF.
   *
   * Este método exporta a representação tridimensional dos voxels para um arquivo OFF.
   * O formato OFF é comumente utilizado para representar objetos tridimensionais por meio
   * de malhas poligonais. A função aceita um parâmetro de string, que é o nome do arquivo
   * OFF a ser criado.
   *
   * @param filename O nome do arquivo OFF.
   */
  void writeOFF(const std::string& filename);

};

/*! \mainpage Projeto de Esculturas 3D
 *
 * \image html project_logo.png
 *
 * \section intro_sec Introdução
 *
 * Bem-vindo à documentação oficial do Projeto de Esculturas 3D. Esta documentação abrange a implementação
 * e uso da classe Sculptor, que permite criar esculturas tridimensionais virtuais.
 *
 * \section license_sec Licença
 *
 * Este projeto é distribuído sob a licença MIT. Consulte o arquivo LICENSE para obter mais informações.
 * <insira a licença aqui>
 *
 * \section install_sec Instruções de Instalação
 *
 * Para instalar o projeto em seu ambiente de desenvolvimento, siga as instruções abaixo:
 *
 * - Clone o repositório Git:
 *   \code{bash}
 *   git clone https://github.com/seu-usuario/projeto-esculturas-3d.git
 *   \endcode
 * 
 * - Navegue até o diretório do projeto:
 *   \code{bash}
 *   cd projeto-esculturas-3d
 *   \endcode
 *
 * - Compile o código-fonte:
 *   \code{bash}
 *   make
 *   \endcode
 *
 * - Execute o programa:
 *   \code{bash}
 *   ./projeto_esculturas_3d
 *   \endcode
 *
 * \section usage_sec Uso
 *
 * A classe Sculptor oferece uma interface para criar e manipular esculturas virtuais tridimensionais. Consulte a
 * documentação da classe para obter detalhes sobre os métodos disponíveis.
 *
 * \section examples_sec Exemplos de Código
 *
 * A página de exemplos de código fornece demonstrações práticas de como usar a classe Sculptor para criar diferentes
 * formas e esculturas tridimensionais. Consulte os exemplos para aprender a utilizar efetivamente o projeto.
 *
 * \section images_sec Imagens
 *
 * O diretório "images" contém recursos visuais, como logotipos e capturas de tela do projeto. Esses recursos são
 * usados nesta documentação para fornecer uma representação visual do projeto.
 *
 * \section contact_sec Contato
 *
 * Se você tiver dúvidas, sugestões ou relatórios de bugs, entre em contato conosco em
 * (mailto:cauavitorfigueredo@gmail.com).
 *
 * \section contributors_sec Contribuidores
 *
 * Este projeto foi dedicado ao segundo processo de avaliação do Professor Agostinho de Medeiros Brito Junior da disciplina de Programação Avançada (DCA0803).
 *
 * \subsection professor_info Informações sobre o Professor
 *
 * Professor Agostinho possui graduação em Engenharia Elétrica pela Universidade Federal do Rio Grande do Norte (1994),
 * mestrado em Engenharia Elétrica pela Universidade Estadual de Campinas (1996) e doutorado em Engenharia Elétrica pela
 * Universidade Federal do Rio Grande do Norte (2005). Atualmente é professor da Universidade Federal do Rio Grande do
 * Norte, pesquisando nas áreas de redes de computadores, redes neurais, segurança da informação e processamento de
 * imagens.
 *
 * \subsection professor_achievements Conquistas e Contribuições
 *
 * - Possui vasta experiência em redes de computadores, redes neurais, segurança da informação e processamento de imagens.
 * - Orientou diversos trabalhos de mestrado e doutorado, contribuindo para o avanço do conhecimento em sua área.
 * - Participou ativamente de eventos e publicou trabalhos científicos relevantes em revistas e conferências especializadas.
 *
 * \subsection professor_contact Informações de Contato
 *
 * - **E-mail:** mailto:agostinhobritojr@gmail.com
 * - **Página do Lattes:** [Professor Agostinho](<http://lattes.cnpq.br/0958617290020120>)
 * - **Site:** https://agostinhobritojr.github.io/
 *
 * Agradecemos ao Professor Agostinho de Medeiros Brito Junior por sua dedicação e contribuições para o desenvolvimento
 * deste projeto.
 *
 *
 * \section version_sec Versão
 *
 * Esta documentação corresponde à versão 1.2.0 do Projeto de Esculturas 3D.
 */

#endif // SCULPTOR_H
