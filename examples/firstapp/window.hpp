#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

// responsável pelo gerenciamento do conteúdo da janela da aplicação
class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override; //Chamada apenas uma vez no início do programa. Inicialização do estado da janela
  void onPaint() override; //Funções de desenho
  void onPaintUI() override; //Funções de desenho de widgets

private:
  std::array<float, 4> m_clearColor{0.906f, 0.910f, 0.918f, 1.0f};
};

#endif