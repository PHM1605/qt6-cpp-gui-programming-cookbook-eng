#include <QApplication>
#include <QDateTime>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

QString style = R"(
  #centralWidget {
    background: rgba(32, 80, 96, 100);
  }
  #logo {
    border: 1px solid;
  }
)";

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Login Form");
  window.resize(800, 600);
  window.setObjectName("centralWidget");

  // Main vertical layout
  QVBoxLayout* mainLayout = new QVBoxLayout(&window);

  // ---------------- Horizontal layout at top -----------------
  QHBoxLayout* topRow = new QHBoxLayout();

  // Time label
  QLabel* dateTimeLabel = new QLabel();
  dateTimeLabel->setObjectName("currentDateTime");
  dateTimeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

  // Restart button
  QPushButton* restartButton = new QPushButton();
  restartButton->setObjectName("restartButton");
  restartButton->setMinimumSize(55, 55);
  restartButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  restartButton->setIcon(QIcon("icons/restart_icon.png"));
  restartButton->setIconSize(QSize(32, 32));
  
  // Shutdown button
  QPushButton* shutdownButton = new QPushButton();
  shutdownButton->setObjectName("shutdownButton");
  shutdownButton->setMinimumSize(55, 55);
  shutdownButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  shutdownButton->setIcon(QIcon("icons/shutdown_icon.png"));
  shutdownButton->setIconSize(QSize(32, 32));

  topRow->addWidget(dateTimeLabel);
  topRow->addStretch();
  topRow->addWidget(restartButton);
  topRow->addWidget(shutdownButton);
  // -----------------------------------------------------------------

  // ----- Horizontal layout in the middle (to contain logo) ---------
  QHBoxLayout* middleRow = new QHBoxLayout();
  // logo
  QLabel* logoLabel = new QLabel();
  logoLabel->setObjectName("logo");
  logoLabel->setText("");
  logoLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  logoLabel->setMinimumSize(150, 150);
  // centering logo
  middleRow->addStretch();
  middleRow->addWidget(logoLabel);
  middleRow->addStretch();
  // -----------------------------------------------------------------

  // -------------- Horizontal layout at bottom -----------------------
  QHBoxLayout* bottomRow = new QHBoxLayout();
  // create Widget first
  QWidget* loginForm = new QWidget();
  loginForm->setObjectName("loginForm");
  loginForm->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  loginForm->setMinimumSize(350, 200);
  // we put a VerticalLayout inside that Widget, as Layout doesn't have shape (it spans the whole containing area), but Widget does
  QVBoxLayout* loginFormLayout = new QVBoxLayout(loginForm);
  bottomRow->addLayout(loginFormLayout);

  
  // ------------------------------------------------------------------


  mainLayout->addLayout(topRow);
  mainLayout->addLayout(middleRow);
  mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
  

  app.setStyleSheet(style);
  window.show();
  return app.exec();
}