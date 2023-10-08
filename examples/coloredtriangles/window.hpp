#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override; //chama uma vez
  void onPaint() override; 
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override; //liberaçao dos recursos alocados no create

private:
  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{};
  GLuint m_VBOPositions{}; //arranjo de tres tuplas de xy (vertices de cada triangulo) -> {(xo,y0), (x1,y1), (x2,y2)}
  GLuint m_VBOColors{};//Arranjo das cores RGBA (A-opacidade)
  GLuint m_program{};//Identificador dos shaders linkados

  std::default_random_engine m_randomEngine;

  std::array<glm::vec4, 3> m_colors{{{0.36f, 0.83f, 1.00f, 1}, //tres tuplas de 4 elementos
                                     {0.63f, 0.00f, 0.61f, 1},
                                     {1.00f, 0.69f, 0.30f, 1}}};
  abcg::Timer m_timer;

  void setupModel();
};

#endif