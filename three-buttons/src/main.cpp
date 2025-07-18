#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>



int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Styled Qt6 Buttons");

  QHBoxLayout* layout = new QHBoxLayout(&window);

  // Create 3 buttons
  QPushButton *btn1 = new QPushButton("One");
  QPushButton *btn2 = new QPushButton("Two");
  QPushButton *btn3 = new QPushButton("Three");

  btn1->setObjectName("pushButton_1");
  btn2->setObjectName("pushButton_2");
  btn3->setObjectName("pushButton_3");

  layout->addWidget(btn1);
  layout->addWidget(btn2);
  layout->addWidget(btn3);

  QString style = R"(
    QPushButton {
      color: red;
      border: 0px;
      padding: 0 8px;
      background: white;
    }
    QPushButton#pushButton_2 {
      border: 1px solid red;
      border-radius: 10px;
    }
    QPushButton#pushButton_3 {
      border: 2px solid gray;
      border-radius: 10px;
      padding: 0 8px;
      background: yellow;
    }
    * {
      background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #fff, stop: 1 #888);
      color: rgb(255, 255, 255);
      border: 1px solid #ffffff;
    }
  )";

  app.setStyleSheet(style);
  window.show();
  return app.exec();
}