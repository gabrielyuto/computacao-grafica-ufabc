#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override; //Chamado uma vez quando é criada
  void onPaint() override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override; //Chamado uma vez quando é destruido a janela

private:
  glm::ivec2 m_viewportSize{};

  GLuint m_VAO{}; //Objeto interno do OpenGL que especifica como o VBO vai se comunicar com o shader
  GLuint m_VBOVertices{}; //Cria um buffer de vértices
  GLuint m_program{}; //Especifica quais os shaders que tem na memoria de vídeo

  std::default_random_engine m_randomEngine; //Gerador aleatorio
  std::array<glm::vec2, 3> const m_points{{{0, 1}, {-1, -1}, {1, -1}}}; //Coordenadas dos pontos do triângulo
  glm::vec2 m_P{}; //Ponto P

  void setupModel();
};

#endif