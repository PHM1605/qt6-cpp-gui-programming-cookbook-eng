#include <QApplication>
#include <QDateTime>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Login Form");
  window.resize(800, 600);

  // Main vertical layout
  QVBoxLayout* mainLayout = new QVBoxLayout(&window);

  // Horizontal layout at top
  QHBoxLayout* topRow = new QHBoxLayout();

  // Time label
  QLabel* dateTimeLabel = new QLabel();
  dateTimeLabel->setObjectName("currentDateTime");
  dateTimeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

  topRow->addWidget(dateTimeLabel);

  mainLayout->addLayout(topRow);

  window.show();
  return app.exec();
}