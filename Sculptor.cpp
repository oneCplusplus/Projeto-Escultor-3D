#include "Sculptor.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

  // Construtor
Sculptor ::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx;
  ny = _ny;
  nz = _nz;
  r = g = b = a = 0.5;

  // Alocacao dinamica da Matriz 3D
  v = new Voxel **[nx];

  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny];
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {

        v[i][j][k].show = false;

        v[i][j][k].r = r;
        v[i][j][k].g = g;
        v[i][j][k].b = b;
        v[i][j][k].a = a;
      }
    }
  }
}

// Destrutor
Sculptor ::~Sculptor() {
  // Liberacao da memoria alocada para a Matriz
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      delete[] v[i][j];
    }
  }
  for (int i = 0; i < nx; i++) {
    delete[] v[i];
  }
  delete[] v;
  nx = ny = nz = 0;
}

// Escolha das cores, implementação do método setColor
void Sculptor ::setColor(float mr, float mg, float mb, float ma) {
  r = mr;
  g = mg;
  b = mb;
  a = ma;
}

// Ativa o voxel da posicao (mx, my, mz)
void Sculptor ::putVoxel(int mx, int my, int mz) {
  v[mx][my][mz].show = true;
  v[mx][my][mz].r = r;
  v[mx][my][mz].g = g;
  v[mx][my][mz].b = b;
  v[mx][my][mz].a = a;
}

// Desativa voxel da posicao (mx, my, mz)
void Sculptor ::cutVoxel(int mx, int my, int mz) { v[mx][my][mz].show = false; }

// Ativa uma regiao em forma de cubo
void Sculptor ::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

  for (int i = x0; i < x1; i++) {
    for (int j = y0; j < y1; j++) {
      for (int k = z0; k < z1; k++) {
        v[i][j][k].show = true;
        v[i][j][k].r = r;
        v[i][j][k].g = g;
        v[i][j][k].b = b;
        v[i][j][k].a = a;
      }
    }
  }
}

// Desativa uma regiao em forma de cubo
void Sculptor ::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {

  for (int i = x0; i < x1; i++) {
    for (int j = y0; j < y1; j++) {
      for (int k = z0; k < z1; k++) {
        v[i][j][k].show = false;
      }
    }
  }
}

// Ativa uma esfera de raio r e centro x,y,z
void Sculptor ::putSphere(int x, int y, int z, int r) {
  double x2, y2, z2;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {

        x2 = (double)(i - x) * (double)(i - x);
        y2 = (double)(j - y) * (double)(j - y);
        z2 = (double)(k - z) * (double)(k - z);

        if ((x2 + y2 + z2) < (r * r)) {
          v[i][j][k].show = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

// Desativa os voxels na regiao da esfera
void Sculptor ::cutSphere(int x_, int y_, int z_, int r_) {
  double x02, y02, z02;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {

        x02 = (double)(i - x_) * (double)(i - x_);
        y02 = (double)(j - y_) * (double)(j - y_);
        z02 = (double)(k - z_) * (double)(k - z_);

        if ((x02 + y02 + z02) < (r_ * r_)) {
          v[i][j][k].show = false;
        }
      }
    }
  }
}

// Ativa os voxels na regiao da elipsoide
void Sculptor ::putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz) {
  double x0, y0, z0;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        x0 = ((double)(i - xc) * (double)(i - xc)) / (rx * rx);
        y0 = ((double)(j - yc) * (double)(j - yc)) / (ry * ry);
        z0 = ((double)(k - zc) * (double)(k - zc)) / (rz * rz);

        if ((x0 + y0 + z0) < 1) {
          v[i][j][k].show = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

// Desativa os voxels na regiao da elipsoide
void Sculptor ::cutEllipsoid(int cx, int cy, int cz, int rx0, int ry0,
                             int rz0) {
  double d1, d2, d3;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {

        d1 = ((double)(i - cx) * (double)(i - cx)) / (rx0 * rx0);
        d2 = ((double)(j - cy) * (double)(j - cy)) / (ry0 * ry0);
        d3 = ((double)(k - cz) * (double)(k - cz)) / (rz0 * rz0);

        if ((d1 + d2 + d3) < 1) {
          v[i][j][k].show = false;
        }
      }
    }
  }
}

// Criacao do arquivo .OFF
void Sculptor ::writeOFF(const char *filename) {
  ofstream fout;

  fixed(fout); // para corrigir precisao de casas decimais no arquivo .OFF

  int Nvertices = 0;
  int Nfaces = 0;
  int aux = 0;
  fout.open(filename);

  if (fout.is_open()) {
    cout << "Aguarde... Escrevendo a grade de voxels em um arquivo OFF...\n";
  } else {
    cout << "Arquivo OFF não foi gerado corretamente.\n";
    exit(1);
  }

  fout << "OFF" << endl;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {
          Nvertices = Nvertices + 8;
          Nfaces = Nfaces + 6;
        }
      }
    }
  }

  fout << Nvertices << " " << Nfaces << " " << 0 << endl;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {

          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
        }
      }
    }
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {
          fout << 4 << " " << aux + 0 << " " << aux + 3 << " " << aux + 2 << " "
               << aux + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          fout << 4 << " " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " "
               << aux + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          fout << 4 << " " << aux + 0 << " " << aux + 1 << " " << aux + 5 << " "
               << aux + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          fout << 4 << " " << aux + 0 << " " << aux + 4 << " " << aux + 7 << " "
               << aux + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          fout << 4 << " " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " "
               << aux + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          fout << 4 << " " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " "
               << aux + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << endl;
          aux = aux + 8;
        }
      }
    }
  }

  if (fout.is_open()) {
    cout << "Arquivo.OFF salvo!" << endl;
  }
  fout.close();
}
