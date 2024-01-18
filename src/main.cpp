#include <QtWidgets>

class FigureWidget : public QWidget {
 public:
  FigureWidget(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawRect(10, 20, 130, 100);
  }
};

class FigureImage : public QWidget {
 public:
  FigureImage(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QImage image(180, 140, QImage::Format_RGB32);
    image.fill(qRgb(255, 255, 255));
    QPainter painter(&image);
    painter.drawRect(10, 20, 130, 100);
    QPainter widgetPaint(this);
    widgetPaint.drawImage(0, 0, image);
  }
};

class FigurePixmap : public QWidget {
 public:
  FigurePixmap(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPixmap pixmap(180, 140);
    pixmap.fill(qRgb(255, 255, 255));
    QPainter painter(&pixmap);
    painter.drawRect(10, 20, 130, 100);
    QPainter widgetPaint(this);
    widgetPaint.drawPixmap(0, 0, pixmap);
  }
};

class FigurePicture : public QWidget {
 public:
  FigurePicture(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPicture picture;
    QPainter painter(&picture);
    painter.drawRect(10, 20, 130, 100);
    painter.end();
    QPainter widgetPaint(this);
    widgetPaint.drawPicture(0, 0, picture);
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.resize(1000, 300);
  window.setStyleSheet("background-color: rgb(255, 255, 255);");

  QHBoxLayout nameLayout;
  QLabel *textWidget = new QLabel("QWidget");
  textWidget->setFixedSize(180, 20);
  nameLayout.addWidget(textWidget);
  QLabel *textImage = new QLabel("QImage");
  textImage->setFixedSize(180, 20);
  nameLayout.addWidget(textImage);
  QLabel *textPixmap = new QLabel("QPixmap");
  textPixmap->setFixedSize(180, 20);
  nameLayout.addWidget(textPixmap);
  QLabel *textPicture = new QLabel("QPicture");
  textPicture->setFixedSize(180, 20);
  nameLayout.addWidget(textPicture);

  QHBoxLayout layout;
  FigureWidget *widget = new FigureWidget;
  layout.addWidget(widget);
  FigureImage *image = new FigureImage;
  layout.addWidget(image);
  FigurePixmap *pixmap = new FigurePixmap;
  layout.addWidget(pixmap);
  FigurePicture *picture = new FigurePicture;
  layout.addWidget(picture);
  window.setWindowTitle("test task");

  QVBoxLayout mainLayout(&window);
  mainLayout.addLayout(&nameLayout);
  mainLayout.addLayout(&layout);


  window.show();
  return app.exec();
}